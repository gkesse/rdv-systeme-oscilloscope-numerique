#include "DScopesQTWidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>

#define format QImage::Format_RGB32

DScopesQTWidget::DScopesQTWidget(unsigned _x, unsigned _y, unsigned _w, unsigned _h, bool _alpha, unsigned _scale, QWidget *parent)
    : QWidget(parent),
      DScopesQT(&pixmap, _w / _scale, _h / _scale, _alpha),
      pixmap(_w / _scale, _h / _scale, format),
      basex(_x),
      basey(_y),
      scale(_scale)
{
    setMinimumSize(QSize(320, 200));
    setCursor(QCursor(Qt::CrossCursor));
    QPainter painter;
    painter.begin(&pixmap);
    painter.fillRect(_x, _y, w, h, Qt::black);
    painter.end();
    // rt = pt = 0;
}

DScopesQTWidget ::~DScopesQTWidget()
{
}

void DScopesQTWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QRect validRect = rect() & event->rect();
    p.setClipRect(validRect);
    p.drawImage(basex, basey, surface->scaled(surface->width() * scale, surface->height() * scale));
}

void DScopesQTWidget::resizeEvent(QResizeEvent *event)
{
    pixmap = pixmap.scaled(QSize(event->size().width() / scale, event->size().height() / scale));
    //  DScopesQT::Resize(&pixmap, event->size().width() / scale, event->size().height() / scale, alpha);
}
