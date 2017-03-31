#ifndef AFMXTHMBIMG_H
#define AFMXTHMBIMG_H

#include <QObject>
#include <QPixmap>
#include <QQmlApplicationEngine>
#include <QQuickPaintedItem>
#include <QQmlEngine>
#include <QPainter>


/* This is a container for the image */
class AfmxThmbContainer: public QObject {
	
	Q_OBJECT
public:
	explicit AfmxThmbContainer(QObject * parent = 0):QObject(parent){
		
	}

	QPixmap	thumbnail_pm; // Thumbnail pixmap
};

/* This is a information mngr */

class AfmxThmbMngr: public QObject {
	Q_OBJECT

public:
	explicit AfmxThmbMngr(QObject * parent = 0);
	Q_INVOKABLE QObject * getThmbContainer(QString pathString);
	
};

class AfmxThmbImg : public QQuickPaintedItem
{
	Q_OBJECT
public:
	AfmxThmbImg(QQuickItem * parent = 0);
	Q_INVOKABLE void setThmb(QObject * afmxThmbContainer);
	
protected:
	virtual void paint(QPainter * painter) Q_DECL_OVERRIDE;

private:
	AfmxThmbContainer m_thmbContainer;

};

class AfmxThmbRegister {
public:
	static void afmxThmbRegister(AfmxThmbMngr & thmbMngr, QQmlApplicationEngine & engine);
};


#endif // AFMXTHMBIMG_H
