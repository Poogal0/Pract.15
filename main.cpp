#include <QtWidgets>
#include <QDebug>
class MainWindow : public QMainWindow {
public:
MainWindow();
private:
QLabel * textLabel;
};

MainWindow::MainWindow(){
setWindowTitle("Pract.15");
textLabel = new QLabel(this);
textLabel -> setText("Text QLabel");
textLabel ->setGeometry(50,100,350,120);
textLabel ->setFont(QFont("Time", 28, QFont::Bold));
}

int main (int argc , char *argv[]){
	QApplication app (argc , argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
}
