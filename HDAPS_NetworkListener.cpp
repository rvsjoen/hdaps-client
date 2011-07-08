#include "HDAPS_NetworkListener.h"

typedef struct hdaps_update {
	int x;
	int y;
	int keyboard;
	int mouse;
} HDAPS_update ;

HDAPS_NetworkListener::HDAPS_NetworkListener(QObject* parent) : QObject(parent){
	s = new QUdpSocket();
	s->bind(6767);
	connect(s, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}

void HDAPS_NetworkListener::processPendingDatagrams()
{
	while (s->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(s->pendingDatagramSize());
		s->readDatagram(datagram.data(), datagram.size());
		char* buf = datagram.data();
		HDAPS_update* msg = (HDAPS_update*) buf;
		emit updateRecieved(msg->x,msg->y);
     } 
}
