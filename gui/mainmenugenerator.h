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
    void onConfPerifericoClicked();
    void onFiltrosClicked();
    void onDivVoltClicked();
    void onConBaseClicked();
    void onAyudaClicked();
    void onAcercaDeClicked();

private:
    QLabel *lblTitPeriferico, *lblOtrasHerr, *lblSoporte;
    QPushButton *btnConfPeriferico, *btnFiltros, *btnDivVolt, *btnConBase, *btnAyuda,
        *btnAcercaDe;
};



#endif // MAINMENUGENERATOR_H
