#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
#include <QPixmap>

class MyPicture : public QWidget
{
    Q_OBJECT
private:
    QPixmap pixmap;
    double scale;
public:
    explicit MyPicture(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
public slots:
    void ScaleChanged(int val);

signals:

};

#endif // MYPICTURE_H
