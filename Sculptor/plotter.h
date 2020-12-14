#ifndef PLOTTER_H
#define PLOTTER_H
#include <iostream>
#include <QWidget>
#include <QWidget>
#include <QAction>
#include <QMouseEvent>
#include <QColor>
#include "vector"
#include "sculptor.h"

/**
 * @brief A Classe Plotter
 */
class Plotter : public QWidget
{
    Q_OBJECT
private:
    /**
     * @brief m (matriz)
     */
    vector<vector<Voxel>> m;
    /**
     * @brief lineColor
     */
    QColor lineColor;
    /**
     * @brief cor
     */
    int cor;
    /**
     * @brief actionMudaCor
     */
    QAction *actionMudaCor;
    /**
     * @brief Cubo
     */
    int Cubo;
    /**
     * @brief Quadrado
     */
    int Quadrado;
    /**
     * @brief cx (Posição do X)
     */
    int cx;
    /**
     * @brief cy (Posição do Y)
     */
    int cy;
    /**
     * @brief cz (Posição do Z)
     */
    int cz;
    /**
     * @brief press (Pressionado)
     */
    bool press;
    /**
     * @brief mx (X do mouse)
     */
    int mx;
    /**
     * @brief my (Y do mouse)
     */
    int my;
public:
    /**
     * @brief Seta os valores iniciais das variáveis
     * @param parent
     */
    explicit Plotter(QWidget *parent = nullptr);
    /**
     * @brief Pinta o grid do canvas para desenhar
     * @param event
     */
    void paintEvent(QPaintEvent *event);
    /**
     * @brief Identifica se o mouse está pressionado
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);
    /**
     * @brief Identifica se o mouse é solto
     * @param event
     */
    void mouseReleaseEvent(QMouseEvent *event);
    /**
     * @brief Forma que será usada para desenhar no Canvas (Voxel, Box, Sphere, Ellipsoid)
     * @param forma
     */
    void Forma(int forma);
    /**
     * @brief s (Sculptor)
     */
    Sculptor *s;
    /**
     * @brief forma
     */
    int forma = 1;
    /**
     * @brief dim (Dimensão)
     */
    int dim;
    /**
     * @brief plano
     */
    int plano;
    /**
     * @brief nx (Dimensão em X)
     */
    int nx;
    /**
     * @brief ny (Dimensão em Y)
     */
    int ny;
    /**
     * @brief nz (Dimensão em Z)
     */
    int nz;
    /**
     * @brief r (Cor Vermenha)
     */
    int r;
    /**
     * @brief g (Cor Verde)
     */
    int g;
    /**
     * @brief b (Cor Azul)
     */
    int b;
    /**
     * @brief a (Grau de Transparencia)
     */
    int a;
    /**
     * @brief rad (Raio da Esfera)
     */
    int rad;
    /**
     * @brief rx (Raio X da Elipse)
     */
    int rx;
    /**
     * @brief ry (Raio Y da Elipse)
     */
    int ry;
    /**
     * @brief rz (Raio Z da Elipse)
     */
    int rz;
    /**
     * @brief x
     */
    int x;
    /**
     * @brief y
     */
    int y;
    /**
     * @brief z
     */
    int z;
    /**
     * @brief altura (Dimensão da Altura)
     */
    int altura;
    /**
     * @brief largura (Dimensão da Largura)
     */
    int largura;
signals:
    /**
     * @brief MoverX
     */
    void MoverX(int);
    /**
     * @brief MoverY
     */
    void MoverY(int);
    /**
     * @brief ClickX
     */
    void ClickX(int);
    /**
     * @brief ClickY
     */
    void ClickY(int);
    /**
     * @brief PlanoEscolhido
     */
    void PlanoEscolhido(int);
public slots:
    /**
     * @brief Mudar a Dimensão x da Caixa
     * @param x
     */
    void MudarDimx(int x);
    /**
     * @brief Mudar a Dimensão y da Caixa
     * @param y
     */
    void MudarDimy(int y);
    /**
     * @brief Mudar a Dimensão z da Caixa
     * @param z
     */
    void MudarDimz(int z);
    /**
     * @brief Mudar o Raio da Esfera
     * @param rad
     */
    void MudarRad(int rad);
    /**
     * @brief Mudar o Raio x da Elipse
     * @param rx
     */
    void MudarRx(int rx);
    /**
     * @brief Mudar o Raio y da Elipse
     * @param ry
     */
    void MudarRy(int ry);
    /**
     * @brief Mudar o Raio z da Elipse
     * @param rz
     */
    void MudarRz(int rz);
    /**
     * @brief Mudar a cor Vermelha
     * @param red
     */
    void MudarRed(int red);
    /**
     * @brief Mudar a cor Verde
     * @param green
     */
    void MudarGreen(int green);
    /**
     * @brief Mudar a cor Azul
     * @param blue
     */
    void MudarBlue(int blue);
    /**
     * @brief Mudaro Grau de Transparencia
     * @param alpha
     */
    void MudarAlpha(int alpha);
    /**
     * @brief Mudar o Plano de desenho
     * @param plano
     */
    void MudarPlano(int plano);
    /**
     * @brief Cria o arquiva .off
     */
    void OFF();
};

#endif // PLOTTER_H
