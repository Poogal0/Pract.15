#include <QtWidgets>
#include <QDebug>
#define CONFIG_WIDTH "widthwindow"
#define CONFIG_HEIGHT "heightwindow"

class MainWindow : public QMainWindow{
    public:
        MainWindow();
    private:
        QString filePath;
        int heightWindow = 600;
        int widthWindow = 400;
        QString strWidth;
        QString strHeight;
        QString strConfig;
        QString strEqual="=";
        QMap <QString, QString > mapConfig;
};  
    
MainWindow::MainWindow(){
	filePath = "../config.ini";
    QFile file (filePath);

    

    if (!file.open(QFile::ReadOnly)){
        QMessageBox::information (0, "Information", " Configuration File not found at path: \n " + filePath);
    }
    while (!file.atEnd()){
        strConfig = file.readLine();
        int posEqual = strConfig.indexOf(strEqual);
        if (!strConfig.left(posEqual).compare(CONFIG_WIDTH)){
            strWidth = strConfig.right(strConfig.size() - posEqual - 1);
        }
        if (!strConfig.left(posEqual).compare(CONFIG_HEIGHT)){
            strHeight = strConfig.right(strConfig.size() - posEqual - 1);
        }
        if (!mapConfig[strConfig.left(posEqual)].isEmpty()) {
            mapConfig[strConfig.left(posEqual)] = strConfig.right(strConfig.size() - posEqual - 1);
        }
    }
 

    file.close();
    widthWindow=strWidth.toInt();
    heightWindow=strHeight.toInt();
    widthWindow = mapConfig["widthwindow"].toInt();
    heightWindow = mapConfig["heightwindow"].toInt();
    qDebug()<<widthWindow;
    qDebug()<<heightWindow;
    resize(widthWindow,heightWindow);
}
    
int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
