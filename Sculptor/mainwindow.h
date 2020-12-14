#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sculptor.h"
#include "plotter.h"
#include "vector"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief A Classe MainWindow
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Configurações da MainWindow (Front End)
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     *@brief Destruidor da classe
     */
    ~MainWindow();

public slots:
    /**
     * @brief Plano XY
     */
    void PlanoXY();
    /**
     * @brief Plano YZ
     */
    void PlanoYZ();
    /**
     * @brief Plano ZX
     */
    void PlanoZX();
    /**
     * @brief Acessa a opção de desenhar o Voxel
     */
    void PutVoxel();
    /**
     * @brief Acessa a opção de apagar o Voxel
     */
    void CutVoxel();
    /**
     * @brief Acessa a opção de desenhar a Caixa
     */
    void PutBox();
    /**
     * @brief Acessa a opção de apagar a Caixa
     */
    void CutBox();
    /**
     * @brief Acessa a opção de desenhar a Esfera
     */
    void PutSphere();
    /**
     * @brief Acessa a opção de apagar a Esfera
     */
    void CutSphere();
    /**
     * @brief Acessa a opção de desenhar a Elipse
     */
    void PutEllipsoid();
    /**
     * @brief Acessa a opção de apagar a Elipse
     */
    void CutEllipsoid();
    /**
     * @brief Selecionar o Plano de desenho
     */
    void SelecionarPlano();
    /**
     * @brief Abre o MeshLab
     */
    void AbrirMesh();
    /**
     * @brief Fecha o programa
     */
    void Sair();

private:
    /**
     * @brief ui
     */
    Ui::MainWindow *ui;
    /**
     * @brief m (matriz)
     */
    std::vector<std::vector<Voxel>> m;
};
#endif // MAINWINDOW_H
