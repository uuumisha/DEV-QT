#ifndef GLASS_H
#define GLASS_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include "figure.h"

#define  emptyCell       QColor(150,150,150) //серый цвет

class Glass : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(unsigned int columns READ columns WRITE setColumns)
public:
    explicit Glass(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    uint SearchLastEmptyIndex(uint column);
    void SetEmptyGlass();
    void AcceptColors();
    void CheckCount();
    ~Glass();

    uint rows() const
    {
        return m_rows;
    }

    unsigned int columns() const
    {
        return m_columns;
    }

public slots:
    void GlassInit();
    void setRows(uint rows)
    {
        m_rows = rows;
    }

    void setColumns(unsigned int columns)
    {
        m_columns = columns;
    }
    void startGame();

private:
    static const uint W=20;
    uint timerinterval;
    uint m_rows;
    unsigned int m_columns;
    bool gameOn;
    uint score;
    int idt;
    Figure *cur, *next;
    QVector<QVector<QColor>> glassArray;

protected:
    virtual void timerEvent(QTimerEvent*);
    virtual void keyPressEvent(QKeyEvent *event);

signals:
    void SetScore(int val);
    void PaintNextFigure(Figure*);
};

#endif // GLASS_H
