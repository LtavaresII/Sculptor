#ifndef SCULPTORDIALOG_H
#define SCULPTORDIALOG_H

#include <QDialog>

namespace Ui {
class SculptorDialog;
}
/**
 * @brief A Classe SculptorDialog
 */
class SculptorDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Configurações do SculptorDialog
     * @param parent
     */
    explicit SculptorDialog(QWidget *parent = nullptr);
    /**
     *@brief Destruidor da classe
     */
    ~SculptorDialog();
    /**
     * @brief getX (guarda o x)
     * @return x
     */
    int getX();
    /**
     * @brief getY (guarda o y)
     * @return x
     */
    int getY();
    /**
     * @brief getZ (guarda o z)
     * @return x
     */
    int getZ();

private:
    /**
     * @brief ui
     */
    Ui::SculptorDialog *ui;
};

#endif // SCULPTORDIALOG_H
