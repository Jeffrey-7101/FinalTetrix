#ifndef FORMA_H
#define FORMA_H


class Forma
{
public:
    Forma(){};
    const unsigned int id=0;
    const int coords[4][2]={ { 0, 0 },{ 0, 0 },{ 0, 0 },{ 0, 0 } };
};

class SForma:public Forma{//S
public:
    SForma(){};
    const unsigned int id=1;
    const int coords[4][2]={ { 0, -1 },  { 0, 0 },   { -1, 0},   { -1, 1} };
};

class ZForma:public Forma{//Z
public:
    ZForma(){};
    const unsigned int id=2;
    const int coords[4][2]={{ 0, -1 },{ 0, 0 },{ 1, 0 },{ 1, 1 }};
};

class LineForma:public Forma{//I
public:
    LineForma(){};
    const unsigned int id=3;
    const int coords[4][2]={{ 0, -1 },{ 0, 0 },{ 0, 1 },{ 0, 2 }};
};

class TForma: public Forma{//T
public:
    TForma(){};
    const unsigned int id=4;
    const int coords[4][2]={{ -1, 0 },{ 0, 0 },{ 1, 0 },{ 0, 1 }};
};

class SqForma: public Forma{//C
public:
    SqForma(){};
    const unsigned int id=5;
    const int coords[4][2]={ { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 }};
};

class LForma: public Forma{//_L
public:
    LForma(){};
    const unsigned int id=6;
    const int coords[4][2] = {{ -1, -1 },{ 0, -1 },{ 0, 0 },{ 0, 1 }};
};

class ReflejForma: public Forma{//L
public:
    ReflejForma(){};
    const unsigned int id=7;
    const int coords[4][2]={{ 1, -1 },{ 0, -1 },{ 0, 0 },{ 0, 1 }};
};

#endif // FORMA_H
