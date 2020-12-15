#include "sculptor.h"
#include "mainwindow.h"
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <queue>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    //Guarda os valores das variaveis
    nx = _nx;
    ny = _ny;
    nz = _nz;

    //Fixa os valores para 0, caso forem menor que 0
    if((nx<=0) || (ny<=0) || (nz<=0) ){
        nx=ny=nz=0;
    }

    int i,j,k;

    //Cria a matriz Voxel em 3 dimensões
    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    v[0][0] = new Voxel[nx*ny*nz];

    for(i=1;i<nz;i++){
        v[i] = v[i-1] + ny;
    }

    for(i=1;i<nz*ny;i++){
        v[0][i] = v[0][i-1] + nx;
    }

    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                v[i][j][k].isOn=false;
            }
        }
    }
}

Sculptor::~Sculptor()
{
    // Deleta a matriz Voxel
    if(nx==0||ny==0||nz==0){
        return;
    }
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    // Cores e a opacidade do solido
    rv = r;
    gv = g;
    bv = b;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    // Atribui as cores e opacidade para cada voxel
    if((x>=nx)||(y>=ny)||(z>=nz)){
        return;
    }
    if((x<0)||(y<0)||(z<0)){
        return;
    }
    v[x][y][z].isOn = true;
    v[x][y][z].r = rv;
    v[x][y][z].g = gv;
    v[x][y][z].b = bv;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    // Esconde a matriz Voxel do solido
    v[x][y][z].isOn=false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i,j,k;

    // Atribui as cores e opacidade para cada cubo
    for(i=x0;i<x1;i++){
        for(j=y0;j<y1;j++){
            for(k=z0;k<z1;k++){
                putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i,j,k;

    // Esconde o cubo do solido
    for(i=x0;i<x1;i++){
        for(j=y0;j<y1;j++){
            for(k=z0;k<z1;k++){
                cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i,j,k;
    int xc,yc,zc,r;

    xc = xcenter;
    yc = ycenter;
    zc = zcenter;
    r = radius;

    // Atribui as cores e opacidade para cada esfera
    for(i=xc-r;i<xc+r;i++){
        for(j=yc-r;j<yc+r;j++){
            for(k=zc-r;k<zc+r;k++){
                // Verifica de o raio é menor ou igual a distancia do centro até a sua extremidade
                float d = (powf((float)(i-xc)/r,2))+(powf((float)(j-yc)/r,2))+(powf((float)(k-zc)/r,2));
                if(d <=1.0){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i,j,k;
    int xc,yc,zc,r;

    xc = xcenter;
    yc = ycenter;
    zc = zcenter;
    r = radius;

    // Esconde a esfera do solido
    for(i=xc-r;i<xc+r;i++){
        for(j=yc-r;j<yc+r;j++){
            for(k=zc-r;k<zc+r;k++){
                // Verifica de o raio é menor ou igual a distancia do centro até a sua extremidade
                float d = (powf(((float)i-xc)/r,2))+(powf((float)(j-yc)/r,2))+(powf((float)(k-zc)/r,2));
                if(d <=1.0){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    int xc,yc,zc;

    xc = xcenter;
    yc = ycenter;
    zc = zcenter;

    // Atribui as cores e opacidade para cada elipse
    for(i=xc-rx;i<xc+rx;i++){
        for(j=yc-ry;j<yc+ry;j++){
            for(k=zc-rz;k<zc+rz;k++){
                // Verifica de o raio é menor ou igual a distancia do centro até a sua extremidade
                float d = (powf((float)(i-xc)/rx,2))+(powf(float(j-yc)/ry,2))+(powf((float)(k-zc)/rz,2));
                if(d <=1.0){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    int xc,yc,zc;

    xc = xcenter;
    yc = ycenter;
    zc = zcenter;

    // Atribui as cores e opacidade para cada elipse
    for(i=xc-rx;i<xc+rx;i++){
        for(j=yc-ry;j<yc+ry;j++){
            for(k=zc-rz;k<zc+rz;k++){
                // Verifica de o raio é menor ou igual a distancia do centro até a sua extremidade
                float d = pow((float)(i-xc)/rx,2)+pow((float)(j-yc)/ry,2)+pow((float)(k-zc)/rz,2);
                if(d <=1.0){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(string filename)
{
    int i,j,k;
    int nvox = 0;
    ofstream outfile (filename);
    outfile<<"OFF"<<endl;
    //Soma 1 a nvox se o voxel for isOn=true
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].isOn==true){
                    nvox++;
                }
            }
        }
    }
    //8*nvoxels vertices, 6*nvoxels faces e 0 arestas
    outfile<<8*nvox<<" "<<6*nvox<<" "<<0<<endl;

    //Coordenadas dos nvoxels
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].isOn==true){
                    //Linha 1
                    outfile<<-0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                    //Linha 2
                    outfile<<-0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                    //Linha 3
                    outfile<<0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                    //Linha 4
                    outfile<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                    //Linha 5
                    outfile<<-0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                    //Linha 6
                    outfile<<-0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                    //Linha 7
                    outfile<<0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                    //Linha 8
                    outfile<<0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                }
            }
        }
    }

    //Faces da figura e suas caracteristicas(cores, opacidade)
    int nf=0;
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].isOn==true){
                    //Face 1
                    outfile<<"4 "<<0+nf*8<<" "<<3+nf*8<<" "<<2+nf*8<<" "<<1+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 2
                        <<"4 "<<4+nf*8<<" "<<5+nf*8<<" "<<6+nf*8<<" "<<7+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 3
                        <<"4 "<<0+nf*8<<" "<<1+nf*8<<" "<<5+nf*8<<" "<<4+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 4
                        <<"4 "<<0+nf*8<<" "<<4+nf*8<<" "<<7+nf*8<<" "<<3+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 5
                        <<"4 "<<3+nf*8<<" "<<7+nf*8<<" "<<6+nf*8<<" "<<2+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                    //Face 6
                        <<"4 "<<1+nf*8<<" "<<2+nf*8<<" "<<6+nf*8<<" "<<5+nf*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    nf++;
                }
            }
        }
    }
    outfile.close();
    cout<<"Arquivo criado com sucesso"<<endl;
}

vector<vector<Voxel>> Sculptor::readMx(int dim, int plano){
    vector<vector<Voxel>> m;
    vector<Voxel> l;
    if (plano == XY){
        l.resize(ny);
        for(int i = 0; i<nx; i++){
            for(int j = 0; j<ny; j++){
                l[j].isOn = v[i][j][dim].isOn;
                l[j].r = v[i][j][dim].r;
                l[j].g = v[i][j][dim].g;
                l[j].b = v[i][j][dim].b;
                l[j].a = v[i][j][dim].a;
            }
            m.push_back(l);
        }
    }
    if (plano == YZ){
        l.resize(nz);
        for(int i = 0; i<ny; i++){
            for(int j = 0; j<nz; j++){
                l[j].isOn = v[dim][i][j].isOn;
                l[j].r = v[dim][i][j].r;
                l[j].g = v[dim][i][j].g;
                l[j].b = v[dim][i][j].b;
                l[j].a = v[dim][i][j].a;
            }
            m.push_back(l);
        }
    }

    if (plano == ZX){
        l.resize(nx);
        for(int i = 0; i<nz; i++){
            for(int j = 0; j<nx; j++){
                l[j].isOn = v[j][dim][i].isOn;
                l[j].r = v[j][dim][i].r;
                l[j].g = v[j][dim][i].g;
                l[j].b = v[j][dim][i].b;
                l[j].a = v[j][dim][i].a;
            }
            m.push_back(l);
        }
    }
    l.clear();
    return m;
}
