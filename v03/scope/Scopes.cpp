#include "Scopes.h"

#include <algorithm>

Scopes::Scopes(unsigned _w, unsigned _h)
    : w(_w),
      h(_h)
{
}

Scopes::~Scopes()
{
}

void Scopes::Resize(unsigned nw, unsigned nh)
{
    // w = nw;
    // h = nh;
    // Reshape();
}

unsigned Scopes::_AddScope()
{
    unsigned h = GenerateHandle();
    handles.push_back(h);
    return h;
}

unsigned Scopes::GenerateHandle()
{
    unsigned handle = 0;
    while (std::find(handles.begin(), handles.end(), handle) != handles.end())
        handle++;
    return handle;
}

void Scopes::Reshape()
{
    // unsigned scopew, scopeh;

    // Clear();

    // if (handles.size() == 0)
    //     return;
    // nx = ny = static_cast<unsigned>(ceil(sqrt((double)handles.size())));

    // scopew = w / nx;
    // scopeh = h / ny;

    // for (unsigned i = 0; i < handles.size(); i++)
    // {
    //     InitScope(i, hscope == i && magnify);
    //     scopes[handles[i]].scope->NoHighlight();
    // }
    // if (!magnify)
    //     scopes[handles[hscope]].scope->Highlight();
}