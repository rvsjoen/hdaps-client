#ifndef __hdaps_networklistener__
#define __hdaps_networklistener__

#include <QObject>
#include <QtNetwork>

class HDAPS_NetworkListener : public QObject
{
	Q_OBJECT

	public:
		HDAPS_NetworkListener( QObject* parent = 0);
	public slots:
		void processPendingDatagrams();

	signals:
		void updateRecieved(int x, int y);

	private:
		QUdpSocket* s;
};
#endif
