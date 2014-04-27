#include "futa.h"
#include "iostream"
#include <QDebug>
#include "mainwindow.h"

FuTa::FuTa(int& argc, char ** argv) : QApplication(argc, argv)
{
    setOrganizationName("hanfer");
    setOrganizationDomain("hanfer.org");
    setApplicationName("FuTa");

    fileManager = new WoWFileManager();
    mainWindow = new MainWindow();
    mainWindow->show();
}

QStringList *FuTa::getLastFiles()
{
    return instance()->mainWindow->getLastFiles();
}


bool FuTa::notify(QObject * receiver, QEvent * event)
{
    try
    {
        return QApplication::notify(receiver, event);
    }
    catch(std::exception& e)
    {
        qCritical() << "Uncaught Exception thrown:" << e.what();
    }
    return false;
}
