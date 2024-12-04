#pragma once

class Scopes
{
public:
    Scopes(unsigned _w, unsigned _h);
    virtual ~Scopes();
    virtual void Resize(unsigned nw, unsigned nh);

private:
    virtual void Reshape();

protected:
    unsigned w, h;
    // unsigned nx, ny;
};
