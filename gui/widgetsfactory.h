#ifndef WIDGETSFACTORY_H
#define WIDGETSFACTORY_H

#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QComboBox>
#include <QStringList>

class WidgetsFactory {
public:
    static QLabel* createLblMenu(const QString &text,QWidget *parent=nullptr);

    static QPushButton* createButton(const QString &text,QWidget *parent=nullptr);

    static QPushButton* createControlButton(const QString &text, QWidget *parent=nullptr);

    static QComboBox* createComboBoxSearchable(const QStringList &itemList, QWidget *parent=nullptr);

    /**
     * @brief Ajusta el ancho del desplegable del QComboBox en función del contenido más largo.
     * @details Se debe utilizar cuando se cambian lo estilos del QComboBox con qss.
     * @param comboBox Puntero al QComboBox que se desea ajustar.
     */
    static void adjustComboBoxWidth(QComboBox* comboBox);

    static QFrame* createMenuSeparator();

};

#endif // WIDGETSFACTORY_H
