#ifndef __hdaps_glwidget_h__
#define __hdaps_glwidget_h__

#include <QGLWidget>

class HDAPS_GLWidget : public QGLWidget
{
	Q_OBJECT

	public:
		HDAPS_GLWidget ( QWidget* parent = 0 );
		int x_rot;
		int y_rot;

	protected:
		virtual void initializeGL();
		virtual void paintGL();
		virtual void resizeGL(int w, int h);

	public slots:
		void updatePosition(int x, int y);

	private:
		void drawComputer();
};

#endif
