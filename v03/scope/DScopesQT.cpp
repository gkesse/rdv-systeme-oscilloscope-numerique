#include "DScopesQT.h"
#include "DScopeQT.h"

#include <QImage>

DScopesQT::DScopesQT(QImage *s, unsigned _w, unsigned _h, bool _alpha)
    : Scopes(_w, _h)
{
    surface = s;
    // alpha = _alpha;
    // dirty = true;
}

DScopesQT::~DScopesQT()
{
}

void DScopesQT::Resize(QImage *s, unsigned nw, unsigned nh, bool _alpha)
{
    // surface = s;
    // alpha = _alpha;
    // for (int i = 0; i < handles.size(); i++)
    // {
    //     static_cast<DScopeQT *>(scopes[handles[i]].scope)->SetAlpha(alpha);
    // }
    // Scopes::Resize(nw, nh);
}