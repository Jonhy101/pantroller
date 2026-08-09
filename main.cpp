/*Commit features: cambio de look
 * Cambio de la ubicación de los menús para mejorar
 * el espacio de trabajo del usuario. Se colocan los
 * menús en la parte superior, al lado del logo.
 * Se usa una hoja de estilos global para mejorar
 * la escalabilidad.
 */

#include "mainwindow.h"
#include <QFile>
#include "guiColors.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //Cargar hoja de estilos
    QFile file(":/styles/styles/styles.qss");
    if(file.open(QFile::ReadOnly)){
        QString styleSheet=file.readAll();
        //Remplazar nombres de guiColor.h a la hoja de estilos cargada
        styleSheet.replace("@BLUE_1", Color::BLUE_1);
        styleSheet.replace("@BLUE_2", Color::BLUE_2);
        styleSheet.replace("@BLUE_3", Color::BLUE_3);
        styleSheet.replace("@BLUE_4", Color::BLUE_4);
        styleSheet.replace("@BLUE_5", Color::BLUE_5);
        styleSheet.replace("@BLUE_6", Color::BLUE_6);
        styleSheet.replace("@BLUE_7", Color::BLUE_7);
        styleSheet.replace("@BLUE_BUTTON_1", Color::BLUE_BUTTON_1);
        styleSheet.replace("@BLUE_BUTTON_2", Color::BLUE_BUTTON_2);
        styleSheet.replace("@BLUE_BUTTON_3", Color::BLUE_BUTTON_3);
        styleSheet.replace("@BLUE_BUTTON_4", Color::BLUE_BUTTON_4);
        styleSheet.replace("@BLUE_BUTTON_5", Color::BLUE_BUTTON_5);
        styleSheet.replace("@BLUE_BUTTON_6", Color::BLUE_BUTTON_6);
        styleSheet.replace("@BLUE_BUTTON_7", Color::BLUE_BUTTON_7);
        styleSheet.replace("@QLINE_BACKGROUND", Color::QLINE_BACKGROUND);
        styleSheet.replace("@QLINE_ERROR_BORDER", Color::QLINE_ERROR_BORDER);
        a.setStyleSheet(styleSheet);
        qDebug() << "QSS cargado, bytes:" << styleSheet.size();
    }
    MainWindow w;
    w.show();
    return a.exec();
}
