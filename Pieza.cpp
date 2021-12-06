#include "Pieza.h"
#include "qtetrixboard.h"
#include <QtCore>
#include <iostream>
#include "Forma.h"

void Pieza::setRandomShape(){//original
    setShape((int)(QRandomGenerator::global()->bounded(7)+1));//+1 para evitar el 0 que es la forma nula(sinForma)
}

void Pieza::setBastardShape(){
    if(this->getRandomGeneradas()!=5)
        setShape((int)(QRandomGenerator::global()->bounded(3)+1));

    else{
        setShape((int)(QRandomGenerator::global()->bounded(4)+3));
        this->numRandomGeneradas++;
    }
}

/*void Pieza::receiveSpace(QTetrixBoard *board){
    std::cout<<board->freeSpaceinLine();
}*/

void Pieza::setShape(int forma){
    ZForma *z= new ZForma();
    SForma *s= new SForma();
    LineForma *ln= new LineForma();
    TForma *t= new TForma();
    SqForma *sq= new SqForma();
    LForma *l= new LForma();
    ReflejForma *rf= new ReflejForma();

   /* static constexpr int coordsTable[8][4][2] = {
            { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },//sin forma    0
            { { 0, -1 },  { 0, 0 },   { -1, 0},   { -1, 1} },//forma Z      1
            { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },//forma S      2
            { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },//forma Line   3
            { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },//forma T      4
            { { 0, 0  },  { 1, 0 },   { 0, 1 },   { 1, 1 } },//forma Sq     5
            { { -1, -1},  { 0, -1},   { 0, 0 },   { 0, 1 } },//forma L      6
            { { 1, -1 },  { 0, -1},   { 0, 0 },   { 0, 1 } } //forma reflejo7
        };
    */

        for (int i = 0; i < 4 ; i++) {
            for (int j = 0; j < 2; ++j){

                    if(forma == 1)
                        coords[i][j]=s->coords[i][j];
                    if(forma== 2)
                        coords[i][j]=z->coords[i][j];
                    if(forma== 3)
                        coords[i][j]=ln->coords[i][j];
                    if(forma== 4)
                        coords[i][j]=t->coords[i][j];
                    if(forma== 5)
                        coords[i][j]=sq->coords[i][j];
                    if(forma== 6)
                        coords[i][j]=l->coords[i][j];
                    if(forma== 7)
                        coords[i][j]=rf->coords[i][j];

                }
               // coords[i][j] = coordsTable[forma][i][j];

        }
        formaPieza = forma;
}

int Pieza::minX() const
{
    int min = coords[0][0];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][0]);
    return min;
}

int Pieza::maxX() const

{
    int max = coords[0][0];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][0]);
    return max;
}

int Pieza::minY() const
{
    int min = coords[0][1];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][1]);
    return min;
}

int Pieza::maxY() const

{
    int max = coords[0][1];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][1]);
    return max;
}

Pieza Pieza::rotateLeft() const
{
    if (formaPieza == 5)
        return *this;

    Pieza result;
    result.formaPieza = formaPieza;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, y(i));
        //qDebug()<<y(i)<<"\n";
        result.setY(i, -x(i));
       // qDebug()<<-x(i)<<"\n";
    }

    return result;
}

Pieza Pieza::rotateRight() const
{
    if (formaPieza == 5)
        return *this;

    Pieza result;
    result.formaPieza = formaPieza;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, -y(i));
        result.setY(i, x(i));
    }

    return result;
}
Pieza Pieza::changePiece(){
    Pieza result;
    result.formaPieza=formaPieza;// idk
    result.setRandomShape();
    return result;
}
