#include <QtWidgets>
#include <QDebug>

class MainWindow : public QMainWindow{
    public:
        MainWindow();
    private:
        QString filePath ="../config.ini";
        int heightWindow = 400;
        int widthWindow = 100;
        QString strWidth,strHeight;
        QString strConfig;
        QString strEqual="=";
        QMap <QString,QString> mapConfig;
    };

MainWindow::MainWindow(){
    mapConfig.insert("widthwindow","500");
    mapConfig.insert("heightwindow","500");
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly)){
        QMessageBox::information(0,"Information"," Configuration File \n not found at path: \n " +filePath);
    }
    while (!file.atEnd()){
        strConfig = file.readLine();
        int posEqual = strConfig.indexOf(strEqual);
        if (!mapConfig[strConfig.left(posEqual)].isEmpty()){
            mapConfig[strConfig.left(posEqual)]=strConfig.right(strConfig.size()-posEqual-1);
        }
    }
    file.close();
    widthWindow=mapConfig["widthwindow"].toInt();
    heightWindow=mapConfig["heightwindow"].toInt();
    resize(widthWindow,heightWindow);
}

int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
