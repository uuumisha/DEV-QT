#include "glass.h"
#include <QDebug>
#include <QMessageBox>

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    cur = next = nullptr;
    gameOn = false;
    score = 0;
    idt = 0;
    setFocusPolicy(Qt::StrongFocus);
}

void Glass::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QBrush brush(emptyCell, Qt::SolidPattern);
    painter.setPen(Qt::NoPen);

    // отрисовка стакана
    QPoint point = this->rect().topLeft();
    for(int i=0; i < m_rows; i++) {
        for(int j = 0; j < m_columns; j++) {
            QRect rect(QPoint(point.rx() + W*j +1, point.ry() + W*i +1), QPoint(point.rx()+W*(j+1) -1, point.ry()+W*(i+1) -1));
            brush.setColor(glassArray[i][j]);
            painter.setBrush(brush);
            painter.drawRect(rect);
        }
    }

    // отрисовка фигурок
    if(gameOn) {
        cur->paintFigure(painter, point);
    }

}

// обработка событий таймера
void Glass::timerEvent(QTimerEvent*) {
    uint nowpos[2];
    uint lepos;
    cur->GetPosition(nowpos);
    lepos = SearchLastEmptyIndex(nowpos[1]);
    if(lepos < 2) {
        killTimer(idt);
        gameOn = false;
        QMessageBox msgBox;
        msgBox.setText("Game Over");
        msgBox.exec();
        return;
    }
    if(nowpos[0]+3 > lepos) {
        QColor *saveFigColors = cur->GetColors();
        glassArray[lepos-2][nowpos[1]] = saveFigColors[0];
        glassArray[lepos-1][nowpos[1]] = saveFigColors[1];
        glassArray[lepos][nowpos[1]]   = saveFigColors[2];

        Figure buffFig(W);
        buffFig = *cur;
        *cur = *next;
        *next = buffFig;
        next->makeRandomColors();
        next->SetPosition(0,4);
        emit PaintNextFigure(next);

        CheckCount();
    }
    else {
       cur->SetPosition(nowpos[0]+1, nowpos[1]);
       update();
    }
}

// обработка событий нажатия клавишей
void Glass::keyPressEvent(QKeyEvent *event) {
    if(gameOn) {
        uint pos[2];
        cur->GetPosition(pos);
        switch(event->key()) {
        case Qt::Key_Left:
            if((pos[1] > 0) && (glassArray[pos[0]+2][pos[1]-1]==emptyCell))
                cur->SetPosition(pos[0], pos[1]-1);
            break;
        case Qt::Key_Right:
            if((pos[1] < m_columns-3) && (glassArray[pos[0]+2][pos[1]+1]==emptyCell))
                cur->SetPosition(pos[0], pos[1]+1);
            break;
        case Qt::Key_Space:
            AcceptColors();
            update();
            break;
        case Qt::Key_Up:
            cur->RotateColors(0);
            break;
        case Qt::Key_Down:
            cur->RotateColors(1);
            break;
        default:
            QWidget::keyPressEvent(event);
            break;
        }
        update();
    }
    else QWidget::keyPressEvent(event);
}

// начать новую игру
void Glass::startGame() {
    setFocus();
    gameOn = true;
    if(idt)
        killTimer(idt);
    SetEmptyGlass();
    idt = startTimer(1000);
    if(cur == nullptr) {
        cur = new Figure(W);
        next = new Figure(W);
        next->SetPosition(0,4);
    }
    cur->SetPosition(0,4);
    emit PaintNextFigure(next);
}

// поиск последнего свободного индекса в матрице
uint Glass::SearchLastEmptyIndex(uint column){
    uint ind = 0;
    while(ind < m_rows) {
        if(glassArray[ind][column] != emptyCell) {
            if(!ind)    return 0;
            else        return ind-1;
        }
        ind++;
    }
    return m_rows-1;
}

Glass::~Glass() {
    delete cur;
    delete next;
}

// начальная инициализация матрицы
void Glass::GlassInit() {
    setFixedHeight(W * m_rows);
    for(int i=0; i < m_rows; i++) {
        glassArray.push_back(*(new QVector<QColor>));
        for(int j = 0; j < m_columns; j++) {
            glassArray[i].push_back(emptyCell);
        }
    }
}

// закрасить стакан дефолтным цветом
void Glass::SetEmptyGlass() {
    for(int i=0; i < m_rows; i++)
        for(int j = 0; j < m_columns; j++)
            glassArray[i][j] = emptyCell;
}

void Glass::AcceptColors() {
    uint pos[2];
    uint lepos;
    QColor *saveFigColors;
    cur->GetPosition(pos);
    lepos = SearchLastEmptyIndex(pos[1]);
    if(lepos < 2) {
       killTimer(idt);
       QMessageBox msgBox;
       msgBox.setText("Game Over");
       msgBox.exec();
       return;
    }
    cur->SetPosition(lepos-2, pos[1]);
    saveFigColors = cur->GetColors();
    glassArray[lepos-2][pos[1]] = saveFigColors[0];
    glassArray[lepos-1][pos[1]] = saveFigColors[1];
    glassArray[lepos][pos[1]]   = saveFigColors[2];
    Figure buffFig(W);
    buffFig = *cur;
    *cur = *next;
    *next = buffFig;
    next->makeRandomColors();
    next->SetPosition(0,4);
    emit PaintNextFigure(next);
    CheckCount();
}

// проверка и уничтожение одинаковых последовательностей из трех цветов
void Glass::CheckCount() {
    for(int i=0; i < m_rows; i++) {
        for(int j = 0; j < m_columns-2; j++) {
            if(glassArray[i][j] != emptyCell) {
                if((glassArray[i][j] == glassArray[i][j]) && (glassArray[i][j] == glassArray[i][j+1]) && (glassArray[i][j] == glassArray[i][j+2])) {
                    for(int ii=i; ii > 0; ii--) {
                        for(int jj = j; jj < j+3; jj++) {
                            glassArray[ii][jj] = glassArray[ii-1][jj];
                        }
                    }
                    for(int jj = j; jj < j+3; jj++) glassArray[0][jj] = emptyCell;
                    score+=3;
                    emit SetScore(score);
                }
            }

        }
    }
}
