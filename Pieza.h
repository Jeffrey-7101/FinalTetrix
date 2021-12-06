#ifndef PIEZA_H
#define PIEZA_H

#include <QObject>




class Pieza{

private:

    //cambia la forma
    void setX(int index, int x){coords[index][0]=x;}
    void setY(int index, int y){coords[index][1]=y;}
    //forma de la pieza
    int formaPieza;

    //espacio general para cada pieza
    int coords[4][2];
    int piezasRandomGeneradas=0;
public:
    Pieza(){
        setShape(0);
    }
    void setRandomShape();
    void setBastardShape();

    void setShape(int forma);



    int shape() const{return formaPieza; }
    int x(int index) const{return coords[index][0];}//getX
    int y(int index) const{return coords[index][1];}//getY

    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;

    Pieza rotateLeft() const;
    Pieza rotateRight() const;
    Pieza changePiece();
    int getRandomGeneradas()const{return this->numRandomGeneradas;};
    int numRandomGeneradas=0;

};

#endif // PIEZA_H
