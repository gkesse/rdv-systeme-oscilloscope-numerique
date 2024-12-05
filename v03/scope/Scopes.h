#pragma once

#include <vector>
#include <map>
class Scopes
{
public:
    Scopes(unsigned _w, unsigned _h);
    virtual ~Scopes();
    virtual void Resize(unsigned nw, unsigned nh);

private:
    virtual unsigned _AddScope();
    virtual unsigned GenerateHandle();
    virtual void Reshape();

protected:
    // typedef struct
    // {
    //     unsigned x, y, w, h;
    //     Scope *scope;
    // } scopeholder;

    // std::map<unsigned, scopeholder> scopes;
    std::vector<unsigned> handles;

    unsigned w, h;
    // unsigned nx, ny;
    // unsigned hscope;
    // bool magnify;
    // bool transparentmagnify;
};
