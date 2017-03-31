#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include "afmxthmbimg.h"



int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);
	
	QQmlApplicationEngine engine;
	
	AfmxThmbMngr manager; 
	AfmxThmbRegister::afmxThmbRegister(manager,engine);	
	

	engine.load(QUrl(QLatin1String("qrc:/main.qml")));
	
	return app.exec();
}
