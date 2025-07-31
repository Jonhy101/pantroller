#ifndef WIDGETSFACTORY_H
#define WIDGETSFACTORY_H

#include <QPushButton>
#include <QLabel>

class WidgetsFactory {
public:
    static QLabel* createLblMenu(const QString &text,QWidget *parent=nullptr);
    static QPushButton* createButton(const QString &text,QWidget *parent=nullptr);
};

#endif // WIDGETSFACTORY_H
