#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include "figure.h"

class NextFigure : public QWidget
{
    Q_OBJECT
public:
    explicit NextFigure(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
private:
    Figure *nextFigure;

public slots:
    void slotChangePattern(Figure*);

};

#endif // NEXTFIGURE_H
