#ifndef WIDGETSFACTORY_H
#define WIDGETSFACTORY_H

#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QComboBox>
#include <QStringList>
#include <QTextEdit>
#include <QToolButton>

class WidgetsFactory {
public:
    static QLabel* createLblMenu(const QString &text,QWidget *parent=nullptr);

    static QTextEdit* createTextEditInfo(const QString &text, QWidget *parent=nullptr);

    static QPushButton* createButton(const QString &text,QWidget *parent=nullptr);

    static QToolButton* createBtnPeriphelal(const QString &text, const QString &iconPath, QWidget *parent=nullptr);

    static QPushButton* createControlButton(const QString &text, QWidget *parent=nullptr);

    static QPushButton* createIconButton(QWidget *parent=nullptr);

    static QComboBox* createComboBoxSearchable(const QStringList &itemList, QWidget *parent=nullptr);

    /**
     * @brief Ajusta el ancho del desplegable del QComboBox en función del contenido más largo.
     * @details Se debe utilizar cuando se cambian lo estilos del QComboBox con qss.
     * @param comboBox Puntero al QComboBox que se desea ajustar.
     */
    static void adjustComboBoxWidth(QComboBox* comboBox);

    static QFrame* createMenuSeparator();

    static QLabel* createLblGui(const QString &text,QWidget *parent=nullptr);

    /*Botones de periféricos*/
    static QToolButton* createBtnAdc(QWidget *parent=nullptr);

    static QToolButton* createBtnCpp(QWidget *parent=nullptr);

    static QToolButton* createBtnComparator(QWidget *parent=nullptr);

    static QToolButton* createBtnComparatorVRef(QWidget *parent=nullptr);

    static QToolButton* createBtnCrystal(QWidget *parent=nullptr);

    static QToolButton* createBtnDac(QWidget *parent=nullptr);

    static QToolButton* createBtnEccp(QWidget *parent=nullptr);

    static QToolButton* createBtnEeprom(QWidget *parent=nullptr);

    static QToolButton* createBtnEusart(QWidget *parent=nullptr);

    static QToolButton* createBtnExtInt(QWidget *parent=nullptr);

    static QToolButton* createBtnInt(QWidget *parent=nullptr);

    static QToolButton* createBtnMssp(QWidget *parent=nullptr);

    static QToolButton* createBtnTimers(QWidget *parent=nullptr);

    static QToolButton* createBtnUsart(QWidget *parent=nullptr);

    static QToolButton* createBtnUSB(QWidget *parent=nullptr);

};

#endif // WIDGETSFACTORY_H
