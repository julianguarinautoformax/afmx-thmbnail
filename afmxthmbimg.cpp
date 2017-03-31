#include "afmxthmbimg.h"
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>



AfmxThmbMngr::AfmxThmbMngr(QObject *parent) :
    QObject(parent)
{
}

QObject *AfmxThmbMngr::getThmbContainer(QString pathString)
{
	const char * path_to_image = pathString.toUtf8().data();
    AfmxThmbContainer * tc = new AfmxThmbContainer();
    tc->thumbnail_pm.load(path_to_image);
    Q_ASSERT(!tc->thumbnail_pm.isNull());
    QQmlEngine::setObjectOwnership(tc, QQmlEngine::JavaScriptOwnership);
    return tc;
}



AfmxThmbImg::AfmxThmbImg(QQuickItem * parent):QQuickPaintedItem(parent){
	setAntialiasing(true);
}


void AfmxThmbImg::setThmb(QObject * afmxThmbContainer){

	AfmxThmbContainer *	tc = qobject_cast<AfmxThmbContainer*>(afmxThmbContainer);
	Q_ASSERT(tc);
	m_thmbContainer.thumbnail_pm = tc -> thumbnail_pm;
	/* Schedule for painting */
	update();
}

/* This is a CallBack */
void AfmxThmbImg::paint(QPainter *painter){
    painter->drawPixmap(0, 0, width(), height(), m_thmbContainer.thumbnail_pm);
}

void AfmxThmbRegister::afmxThmbRegister(AfmxThmbMngr & thmbMngr, QQmlApplicationEngine & engine){
	
	qmlRegisterType<AfmxThmbContainer>("afmx.ui.thmb", 1, 0, "AfmxThmbContainer");
	qmlRegisterType<AfmxThmbMngr>("afmx.ui.thmb", 1, 0, "AfmxThmbMngr");
	qmlRegisterType<AfmxThmbImg>("afmx.ui.thmb", 1, 0, "AfmxThmbImg");
	engine.rootContext()->setContextProperty("manager",&thmbMngr);
	
}


