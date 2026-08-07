#ifndef MAINMENUGENERATOR_H
#define MAINMENUGENERATOR_H

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class MainMenuGenerator: public QWidget {
    Q_OBJECT
public:
    explicit MainMenuGenerator(QWidget *parent=nullptr);

signals:
    void menuOptionSelected(int index);

private slots:
    void onMenuButtonClicked();

private:
    QLabel *lblTitPeriferico, *lblOtrasHerr, *lblSoporte;
    QPushButton *btnConfPeriferico, *btnMonitorSerial, *btnFiltros, *btnDivVolt, *btnConBase, *btnAyuda,
        *btnAcercaDe, *activeButton=nullptr;

    void actualizaEstado(QPushButton *newActiveButton);
};



#endif // MAINMENUGENERATOR_H
