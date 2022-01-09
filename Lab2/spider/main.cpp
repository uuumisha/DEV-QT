#include "spider.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("spider_ru.qm", ".");
    QApplication::installTranslator(&translator);

    Spider w;
    w.show();
    return a.exec();
}
