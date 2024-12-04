#pragma once

#include <QWidget>

#include "DScopesQT.h"

class DScopesQTWidget : public QWidget, public DScopesQT
{
    Q_OBJECT

public:
    DScopesQTWidget(unsigned _x, unsigned _y, unsigned _w, unsigned _h, bool _alpha = false, unsigned scale = 1, QWidget *parent = 0);
    ~DScopesQTWidget();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    QImage pixmap;
    unsigned basex, basey;
    unsigned scale;
    // double rt;
    // double pt;
};