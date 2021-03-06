#include "dificultwindow.h"
#include <QGridLayout>
#include <QDebug>
DificultWindow::DificultWindow(QWidget *parent)
    :QWidget(parent),window(new QTetrixWindow)
{


    //int *pe;
   // int x=9;
    //pe=&x;
    //qDebug()<<x<<" "<<pe;

    QTetrixWindow* newWindow= new QTetrixWindow(parent);

    //int y= newWindow->getX();
    //qDebug()<<y;


    easyMode= new QPushButton(tr("&Easy"));
    normalMode= new QPushButton(tr("&Normal"));
    bastardMode= new QPushButton(tr("&BASTARD"));

    QGridLayout *layout = new QGridLayout;


    layout->addWidget(createLabel(tr("ELIJA DIFICULTAD")),0,1);
    layout->addWidget(easyMode,1,1);
    layout->addWidget(normalMode,2,1);
    layout->addWidget(bastardMode,3,1);

    connect(easyMode, &QPushButton::clicked, window, &QTetrixWindow::easy);
    connect(easyMode, SIGNAL(clicked()), this, SLOT(closeWindow()));

    connect(normalMode, &QPushButton::clicked, window, &QTetrixWindow::normal);
    connect(normalMode, SIGNAL(clicked()), this, SLOT(closeWindow()));

    connect(bastardMode, &QPushButton::clicked, window, &QTetrixWindow::bastard);
    connect(bastardMode, SIGNAL(clicked()), this, SLOT(closeWindow()));


    //conectamos la ventana principal con la board pasando la dificultad

    connect(window,&QTetrixWindow::dificultSignal,window->board,&QTetrixBoard::difficult);

    connect(window->board, &QTetrixBoard::gameOver, window, &QTetrixWindow::gameOver);


    setLayout(layout);
    resize(200,100);
}

QLabel *DificultWindow::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return label;
}

