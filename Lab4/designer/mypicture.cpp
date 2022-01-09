#include "mypicture.h"
#include <QPainter>


MyPicture::MyPicture(QWidget *parent) : QWidget(parent)
{
    pixmap.load(":/Pictures/WomenAndDog.jpg");
    scale = 50;
}

void MyPicture::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    QRectF source(0.0, 0.0, pixmap.width()*scale/100, pixmap.height() * scale/100);
    QRectF target(0.0, 0.0, this->width()*scale/100,this->height()*scale/100);
    painter.drawPixmap(target, pixmap, source);
}

void MyPicture::ScaleChanged(int val) {
    scale = val;
    repaint();
}
