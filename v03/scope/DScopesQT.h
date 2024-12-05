#pragma once

#include <map>
#include <QPainter>

#include "Scopes.h"

class QImage;

class Scope;

class DScopesQT : public Scopes
{
public:
    DScopesQT(QImage *s, unsigned _w, unsigned _h, bool _alpha = false);
    virtual ~DScopesQT();
    virtual void Render();
    virtual void Resize(QImage *s, unsigned nw, unsigned nh, bool _alpha = false);

protected:
    QImage *surface;
    // std::map<unsigned, QImage *> surfaces;
    // bool alpha;

    QPainter painter;

    // bool dirty;
};
