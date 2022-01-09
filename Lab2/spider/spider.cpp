#include "spider.h"
#include <QApplication>
#include <QDebug>
#include <QPixmap>
#include <QBitmap>
#include <QCursor>
#include <QIcon>
#include <QPalette>
#include <QGuiApplication>
#include <QScreen>
#include <QColorDialog>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QToolTip>
#include <QPainter>
#include <QLabel>

#include "windows.h"

Spider::Spider(QWidget *parent)
    : QWidget(parent)
{
    isDrawingSp = false;
    isDrawingRect = false;
    // ---------------------------------------------------------------------------------------------
    // Установить заголовок окна
    setWindowTitle(tr("Spider"));
    // ---------------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------------
    // Установить иконки приложения
    QIcon icon("images/icon2.ico");
    setWindowIcon(icon);
    // ---------------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------------

    QPixmap pix("images/spman4.jpg");
    QBrush brush(pix);
    QPalette palleteImg;
    palleteImg.setBrush(QPalette::All, QPalette::Window, brush);
    setPalette(palleteImg);
    //this->setMinimumSize(pix.size());
    //setWindowOpacity(0.9);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen->availableGeometry();
    QPoint center = rect.center();
    center.rx()-=pix.size().rwidth()/2;
    center.ry()-=pix.size().rheight()/2;

    // расположим окно по центру экрана
    move(center.rx(), center.ry());
    // заменить стандартную стрелку
    QCursor cursor = Qt::PointingHandCursor;
    setCursor(cursor);

    // формирование курсора в виде паучка для отображения при рисовании
    QPixmap cpix("images/cursor1.cur");
    cpix.setMask(QBitmap("images/cursor1.cur"));
    spiCursor = new QCursor(cpix);

    QPixmap crpix("images/spider1.bmp");
    crpix.setMask(QBitmap("images/spider1.bmp"));
    runCursor = new QCursor(crpix);

    // создание паучка для таймера
    runningSpider = QRect(this->rect().topLeft(), QPoint(this->rect().topLeft().rx() + 16, this->rect().topLeft().ry() + 17));
    direction = 1;

    savedPoints.push_back(runningSpider.topLeft());
}

Spider::~Spider()
{
    delete spiCursor;
}


// событие нажатия на кнопку мыши
void Spider::mousePressEvent(QMouseEvent *event)
{
    static bool isTimerStart = false;
    static int idt;
    Qt::MouseButton pbutton = event -> button();
    QPoint point;
    QString outstr;

    if((pbutton == Qt::RightButton) && ((event ->modifiers() & Qt::ControlModifier))) {
        //qDebug("Someone press the mouse button");
        qDebug("Someone press the right mouse button");
        //point = mapToGlobal(event->pos());
        point = event->pos();
        QString strX=QString().setNum(point.rx());
        QString strY=QString::number(point.ry());
        QToolTip::showText(event->globalPos(), "x: " + strX + "\ny: " + strY);
        return;
    }

    if(pbutton == Qt::MiddleButton) {
        setCursor(*runCursor);
        if(!isTimerStart){
            idt = startTimer(50);
            isTimerStart = true;
        }
        else {
            killTimer(idt);
            isTimerStart = false;
            direction = 1;
        }
    }

    if(pbutton == Qt::LeftButton)  {
        isDrawingSp = true;
        setCursor(*spiCursor);
    }

    if(pbutton == Qt::RightButton)  {
        isDrawingRect = true;
        Vertex = QWidget::mapFromGlobal(QCursor::pos());
    }

    update();
}

// событие отпускания кнопок мыши
void Spider::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        isDrawingSp = false;
        setCursor(Qt::PointingHandCursor);
    }

    if(event->button() == Qt::RightButton) {
        isDrawingRect = false;
        savedRect.push_back(nowRect);
    }

    update();
}

// событие передвижения мыши
void Spider::mouseMoveEvent(QMouseEvent *event) {
    if(!rect().contains(event->pos())) {
        spiCursor->setPos(QWidget::mapToGlobal(rect().center()));
    };
    update();
}

// отрисовка всего что нужно
void Spider::paintEvent(QPaintEvent *event)
{
    QPoint mPoint;
    QPainter painter(this);
    QRect rect = this->rect();

    // настройка кисти
    QPen pen;
    pen.setWidth(5);

    if(isDrawingSp) {
        mPoint = QWidget::mapFromGlobal(QCursor::pos());

        pen.setColor(Qt::darkMagenta);
        painter.setPen(pen);

        painter.drawLine(mPoint,rect.topRight());
        painter.drawLine(mPoint,rect.topLeft());
        painter.drawLine(mPoint,rect.bottomRight());
        painter.drawLine(mPoint,rect.bottomLeft());

        painter.drawLine(mPoint,QPoint(rect.center().rx(), rect.center().ry() + rect.height()/2));
        painter.drawLine(mPoint,QPoint(rect.center().rx() + rect.width()/2, rect.center().ry()));
        painter.drawLine(mPoint,QPoint(rect.center().rx() - rect.width()/2, rect.center().ry()));
        painter.drawLine(mPoint,QPoint(rect.center().rx(), rect.center().ry() - rect.height()/2));
    }
    if(isDrawingRect) {
        pen.setColor(Qt::green);
        painter.setPen(pen);

        // текущее положение курсора
        mPoint = QWidget::mapFromGlobal(QCursor::pos());

        nowRect = QRect(Vertex, mPoint);
        painter.drawRect(nowRect);
    }
    // отрисовка всех сохраненных прямоугольников
    pen.setColor(Qt::darkYellow);
    painter.setPen(pen);
    for(int i = 0; i<savedRect.size(); i++) painter.drawRect(savedRect[i]);

    // отрисовка траектории паучка
    pen.setColor(Qt::darkCyan);
    painter.setPen(pen);
    for(int i = 0; i<savedPoints.size()-1; i++)   painter.drawLine(savedPoints[i],savedPoints[i+1]);

    // отрисовка бегущего паучка
    QImage simg;
    simg.load("images/spider1.bmp");
    painter.drawImage(runningSpider, simg);
}

// изменение размеров окна
void Spider::resizeEvent(QResizeEvent * event) {
    setWindowTitle(tr("Spider: ") + "width=" + QString().setNum(rect().width()) + " height=" + QString().setNum(rect().height()));
    // смотрим, чтобы паучок был в пределах окна
    if(!rect().contains(runningSpider.center())) {
        runningSpider = QRect(this->rect().topLeft(), QPoint(this->rect().topLeft().rx() + 16, this->rect().topLeft().ry() + 17));
        direction = 1;
    }
}

// событие таймера
void Spider::timerEvent(QTimerEvent *event) {

    QRect newrunningSpider;
    QPoint tl = runningSpider.topLeft();
    QPoint br = runningSpider.bottomRight();
    int width = runningSpider.width();
    int height = runningSpider.height();

    switch(direction) {
    case 1:
        newrunningSpider = QRect(QPoint(tl.rx() + width, tl.ry() + height), QPoint(br.rx() + width, br.ry() + height));
        if(rect().contains(newrunningSpider.bottomRight())) break;
        else direction = 2;

    case 2:
        newrunningSpider = QRect(QPoint(tl.rx() + width, tl.ry() - height), QPoint(br.rx() + width, br.ry() - height));
        if(rect().contains(newrunningSpider.topRight())) break;
        else direction = 3;
    case 3:
        newrunningSpider = QRect(QPoint(tl.rx() - width, tl.ry() - height), QPoint(br.rx() - width, br.ry() - height));
        if(rect().contains(newrunningSpider.topLeft())) break;
        else direction = 4;
    case 4:
        newrunningSpider = QRect(QPoint(tl.rx() - width, tl.ry() + height), QPoint(br.rx() - width, br.ry() + height));
        if(rect().contains(newrunningSpider.bottomLeft())) break;
        else  {
            newrunningSpider = QRect(QPoint(tl.rx() + width, tl.ry() + height), QPoint(br.rx() + width, br.ry() + height));
            direction = 1;
        }
        break;
    default:
        break;
    }
    runningSpider = newrunningSpider;
    savedPoints.push_back(runningSpider.center());
    update();
}
