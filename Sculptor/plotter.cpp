#include "plotter.h"
#include "sculptor.h"
#include <iostream>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QDebug>
#include <QColor>
#include <QRect>
#include "QMessageBox"

Plotter::Plotter(QWidget *parent) : QWidget(parent){
    nx = 30; ny = 30; nz = 30;
    s = new Sculptor(nx,ny,nz);
    dim=0; plano=XY;

    x=0; y=0; z=0; rad=0; rx=0;ry=0;rz=0;
    r = 0; g = 0; b = 0; a = 255;

    forma=1;
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter Painter(this);
    QBrush Brush;
    QPen Pen;

    Brush.setColor(QColor(255,255,255));
    Brush.setStyle(Qt::SolidPattern);
    Painter.setBrush(Brush);

    Pen.setColor(QColor(0,0,0));
    Pen.setWidth(1);
    Painter.setPen(Pen);

    m.clear();
    m = s->readMx(dim,plano);

    int dim1 = width()/m[0].size();
        int dim2 = height()/m.size();
        (dim1>=dim2) ? Quadrado=dim2 : Quadrado=dim1;
        largura = dim1;
        altura = dim2;
        for(unsigned int i =0; i<m.size(); i++){
            for(unsigned int j =0; j<m[0].size(); j++){
                Painter.drawRect(i*Quadrado,j*Quadrado,Quadrado, Quadrado);
            }
        }

        for(unsigned int i=0; i<m.size();i++){
            for(unsigned int j=0; j<m[0].size();j++){
                if(m[i][j].isOn){
                    Brush.setStyle(Qt::SolidPattern);
                    Brush.setColor(QColor(m[i][j].r,m[i][j].g,m[i][j].b,m[i][j].a));
                    Painter.setBrush(Brush);
                    qDebug() << m[i][j].r <<m[i][j].g <<m[i][j].b;
                    Painter.drawRect(i*Quadrado,j*Quadrado,Quadrado, Quadrado);
                }
            }
        }
}

void Plotter::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton ){
        emit ClickX(event->x());
        emit ClickY(event->y());
        press = true;
          mx = (event->x())/Quadrado;
          my = (event->y())/Quadrado;
        emit MoverX(mx);
        emit MoverY(my);

          if(plano == XY)
              {
                  cx=mx;
                  cy=my;
                  cz=dim;
              }

              else if(plano == YZ)
              {
                  cy=mx;
                  cz=my;
                  cx=dim;
              }

              else if(plano == ZX)
              {
                  cz=mx;
                  cx=my;
                  cy=dim;
              }
          Plotter::Forma(forma);
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->button() == Qt::LeftButton)){
        press = false;
        }
}

void Plotter::Forma(int forma)
{
    if(forma == 1){
        s->setColor(r,g,b,a);
        s->putVoxel(cx,cy,cz);
    }

    if(forma == 2){
        s->cutVoxel(cx,cy,cz);
    }

    if(forma == 3){
        s->setColor(r,g,b,a);
        s->putBox(cx,(cx+x),cy,(cy+y),cz,(cz+z));
    }

    if(forma == 4){
        s->cutBox(cx,(cx+x),cy,(cy+y),cz,(cz+z));
    }

    if(forma == 5){
        s->setColor(r,g,b,a);
        s->putSphere(cx,cy,cz,rad);
    }

    if(forma == 6){
        s->cutSphere(cx,cy,cz,rad);
    }
    if(forma == 7){
        s->setColor(r,g,b,a);
        s->putEllipsoid(cx,cy,cz,rx,ry,rz);
    }

    if(forma == 8){
        s->cutEllipsoid(cx,cy,cz,rx,ry,rz);
    }

    repaint();
}

void Plotter::MudarDimx(int x)
{
    this->x=x;
}

void Plotter::MudarDimy(int y)
{
    this->y=y;
}

void Plotter::MudarDimz(int z)
{
    this->z=z;
}

void Plotter::MudarRad(int rad)
{
    this->rad=rad;
}

void Plotter::MudarRx(int radx)
{
    rx=radx;
}

void Plotter::MudarRy(int rady)
{
    ry=rady;
}

void Plotter::MudarRz(int radz)
{
    rz=radz;
}

void Plotter::MudarRed(int red)
{
    r = red;
}

void Plotter::MudarGreen(int green)
{
    g=green;
}

void Plotter::MudarBlue(int blue)
{
    b=blue;
}

void Plotter::MudarAlpha(int alpha)
{
    a=alpha;
}

void Plotter::MudarPlano(int plano)
{
    this->dim = plano;
    repaint();
}

void Plotter::OFF()
{
    s->writeOFF("Sculptor.off");
    QMessageBox box;
    QString msg;
    msg = "Arquivo OOF gerado com sucesso";
    box.setText(msg);
    box.exec();
}

