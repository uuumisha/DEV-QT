#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>
#include <QPainter>

class Spider : public QWidget
{
    Q_OBJECT

private:
    bool isDrawingSp;
    bool isDrawingRect;
    QPoint Vertex;
    QRect nowRect;
    QCursor *spiCursor;
    QCursor *runCursor;
    QVector<QRect> savedRect;
    QVector<QPoint> savedPoints;
    QRect runningSpider;
    char direction;

public:
    Spider(QWidget *parent = nullptr);
    ~Spider();

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent * event);
    virtual void timerEvent(QTimerEvent*);
};
#endif // SPIDER_H
