/*Esta clase crea un QPushButton y gestiona su slot desde aquí,
 * su propósito es evitar usar slots en cada parte del programa
 * y que se gestione el dialogo de ayuda desde aquí, su texto
 * cambia según los parámetros que se le pasan al constructor*/

#ifndef HELPBUTTON_H
#define HELPBUTTON_H

#include <QPushButton>
#include <QString>
class HelpButton: public QPushButton{
    Q_OBJECT
public:
    explicit HelpButton(const QString &helpText, QWidget *parent=nullptr);

    QString helpText() const;   //Obtiene y retorna el texto de helpText

    void setHelpText (const QString &helpText);

private slots:
    void showHelp();

private:
    QString m_helpText;
};

#endif // HELPBUTTON_H
