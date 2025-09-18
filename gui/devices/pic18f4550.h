#ifndef PIC18F455__H
#define PIC18F455__H

#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QToolButton>

class GuiPic18f4550 : public QWidget {
    Q_OBJECT
public:
    explicit GuiPic18f4550(QWidget *panelOptions, QWidget *panelConf, QWidget *parent=nullptr);

private:
    QLabel *labelPinout, *labelTest2;
    QLabel *labelImgDisp, *labelCaract, *labelPerip;
    QTextEdit *txtEditFeatures;
    QPushButton *btnHideImg, *btnHideFeatures;
    QToolButton *tBtnOscillator, *tBtnEEprom, *tBtnInterrupts,
                *tBtnTimers, *tBtnCpp, *tBtnEccp, *tBtnUsb,
                *tBtnMssp, *tBtnEusart, *tBtnADC, *tBtnComparator,
                *tBtnComparatorVoltRef;
};

#endif // PIC18F455__H
