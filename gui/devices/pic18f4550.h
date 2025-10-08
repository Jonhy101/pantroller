#ifndef PIC18F455__H
#define PIC18F455__H

#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QIcon>
#include <QTabWidget>

class GuiPic18f4550 : public QWidget {
    Q_OBJECT
public:
    explicit GuiPic18f4550(QWidget *panelOptions, QWidget *panelConf, QWidget *parent=nullptr);

private:    
    //Componentes gráficos
    QLabel *labelPinout, *labelTest2;
    QLabel *labelImgDisp, *labelCaract, *labelPerip;
    QTextEdit *txtEditFeatures;
    QPushButton *btnHideImg, *btnHideFeatures;
    QToolButton *tBtnOscillator, *tBtnEEprom, *tBtnInterrupts,
                *tBtnTimers, *tBtnCpp, *tBtnEccp, *tBtnUsb,
                *tBtnMssp, *tBtnEusart, *tBtnADC, *tBtnComparator,
                *tBtnComparatorVoltRef;
    QVBoxLayout *mainLayoutOptions;     //layout del panelOptions
    QVBoxLayout *mainLayoutConf;        //layout del panelConf        

    QIcon iconShow, iconHide;           //íconos de mostrar/ocultar
    QIcon iconHelp;                     //ícono para botones de ayuda

    //Widgets de configuración de periféricos
    QTabWidget *tabWidgetPeripheal;
    QWidget *tabOscillator;

    //Agrega la imagen del pinout del microcontrolador
    void setupPinout();

    //Agrega el listado de características principales
    void setupFeatures();

    //Agrega y gestiona el menu de periféricos del micro
    void periphealMenu();

private slots:
    void clickedBtnOscillator();
};

#endif // PIC18F455__H
