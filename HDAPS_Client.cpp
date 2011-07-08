#include <QApplication>
#include <QtOpenGL>
#include <QtNetwork>

#include "HDAPS_GLWidget.h"
#include "HDAPS_NetworkListener.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	HDAPS_GLWidget glw;
	HDAPS_NetworkListener nwl;
	QObject::connect(&nwl, SIGNAL(updateRecieved(int,int)), &glw, SLOT(updatePosition(int, int)));
	glw.show();
	return app.exec();
} 

