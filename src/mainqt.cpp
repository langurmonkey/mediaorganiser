#include <iostream>
#include <string>
#include <QtCore>
#include <QApplication>
#include <QWidget>

using namespace std;


int main(int argc, char *argv[])
{
    cout << "Qt version: " << qVersion() << endl;
    QApplication app(argc, argv);

    QWidget window;

    window.resize(800, 600);
    window.setWindowTitle("Media organiser");
    window.show();

    return app.exec();

}

