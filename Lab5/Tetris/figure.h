#ifndef FIGURE_H
#define FIGURE_H

#include <QColor>
#include <QPainter>

class Figure
{
private:
    QColor m_colors[3];
    uint m_i, m_j, m_W;
    QColor myColors[4] = {Qt::red, Qt::green, Qt::blue, Qt::yellow};
public:
    explicit Figure();
    explicit Figure(uint W);
    void SetPosition(uint i, uint j);
    void GetPosition(uint *pos);
    void paintFigure(QPainter &painter, QPoint &topLeft, uint i = 0, uint j = 0);
    void makeRandomColors();
    QColor* GetColors();
    void RotateColors(bool pr);
signals:

};

#endif // FIGURE_H
