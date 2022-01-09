#include "figure.h"
#include <QTime>
#include <QRandomGenerator>
#include <QDateTime>
#include <QCoreApplication>

Figure::Figure()
{
    m_i = m_j = 0;
}

Figure::Figure(uint W) {
    m_W = W;
    makeRandomColors();
}

void Figure::SetPosition(uint i, uint j) {
    m_i = i;
    m_j = j;
}

void Figure::GetPosition(uint *pos) {
    pos[0] = m_i;
    pos[1] = m_j;
}

QColor* Figure::GetColors() {
    return m_colors;
}

void Figure::paintFigure(QPainter &painter, QPoint &topLeft, uint i, uint j) {

    if(!(i+j)) {
        QBrush brush0(m_colors[0], Qt::SolidPattern);
        painter.setBrush(brush0);
        QRect rect1(QPoint(topLeft.rx() + m_W*m_j +1, topLeft.ry() + m_W*m_i +1), QPoint(topLeft.rx()+m_W*(m_j+1) -1, topLeft.ry()+m_W*(m_i+1) -1));
        painter.drawRect(rect1);

        QBrush brush1(m_colors[1], Qt::SolidPattern);
        painter.setBrush(brush1);
        QRect rect2(QPoint(topLeft.rx() + m_W*m_j +1, topLeft.ry() + m_W*(m_i+1) +1), QPoint(topLeft.rx()+m_W*(m_j+1) -1, topLeft.ry()+m_W*(m_i+2) -1));
        painter.drawRect(rect2);

        QBrush brush2(m_colors[2], Qt::SolidPattern);
        painter.setBrush(brush2);
        QRect rect3(QPoint(topLeft.rx() + m_W*m_j +1, topLeft.ry() + m_W*(m_i+2) +1), QPoint(topLeft.rx()+m_W*(m_j+1) -1, topLeft.ry()+m_W*(m_i+3) -1));
        painter.drawRect(rect3);
    }
    else {
        QBrush brush0(m_colors[0], Qt::SolidPattern);
        painter.setBrush(brush0);
        QRect rect1(QPoint(topLeft.rx() + m_W*j +1, topLeft.ry() + m_W*i +1), QPoint(topLeft.rx()+m_W*(j+1) -1, topLeft.ry()+m_W*(i+1) -1));
        painter.drawRect(rect1);

        QBrush brush1(m_colors[1], Qt::SolidPattern);
        painter.setBrush(brush1);
        QRect rect2(QPoint(topLeft.rx() + m_W*j +1, topLeft.ry() + m_W*(i+1) +1), QPoint(topLeft.rx()+m_W*(j+1) -1, topLeft.ry()+m_W*(i+2) -1));
        painter.drawRect(rect2);

        QBrush brush2(m_colors[2], Qt::SolidPattern);
        painter.setBrush(brush2);
        QRect rect3(QPoint(topLeft.rx() + m_W*j +1, topLeft.ry() + m_W*(i+2) +1), QPoint(topLeft.rx()+m_W*(j+1) -1, topLeft.ry()+m_W*(i+3) -1));
        painter.drawRect(rect3);
    }
}

void Figure::makeRandomColors() {

    m_colors[0] = myColors[rand()%4];
    m_colors[1] = myColors[rand()%4];
    m_colors[2] = myColors[rand()%4];
}

void Figure::RotateColors(bool pr) {
    QColor buff[3] = {m_colors[0], m_colors[1], m_colors[2]};
    if(pr) {
        m_colors[0] = buff[2];
        m_colors[1] = buff[0];
        m_colors[2] = buff[1];
    }
    else {
        m_colors[0] = buff[1];
        m_colors[1] = buff[2];
        m_colors[2] = buff[0];
    }
}
