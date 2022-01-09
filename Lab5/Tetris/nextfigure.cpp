#include "nextfigure.h"
#include <QtDebug>

NextFigure::NextFigure(QWidget *parent) : QWidget(parent)
{
    nextFigure=nullptr;
}

void NextFigure::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    QPoint point = this->rect().topLeft();
    if(nextFigure)
        nextFigure->paintFigure(painter, point,0,2);
}

void NextFigure::slotChangePattern(Figure *pfig) {
    nextFigure = pfig;
    update();
}
