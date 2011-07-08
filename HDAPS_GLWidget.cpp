#include "HDAPS_GLWidget.h"

HDAPS_GLWidget::HDAPS_GLWidget(QWidget* parent) : QGLWidget(parent)
{
	x_rot = 0;
	y_rot = 0;
}

void HDAPS_GLWidget::initializeGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH); 
	glEnable(GL_DEPTH_TEST);
}

void HDAPS_GLWidget::updatePosition(int x, int y)
{
	x_rot = x;
	y_rot = y;
	this->updateGL();
}

void HDAPS_GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 2.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	glRotated(-x_rot, 1.0, 0.0, 0.0);
	glRotated(y_rot, 0.0, 1.0, 0.0);
	drawComputer();
}

void HDAPS_GLWidget::drawComputer()
{
	glBegin(GL_QUADS);		// Draw The Cube Using quads
	    glColor3f(0.0f,1.0f,0.0f);	// Color Blue

	    glVertex3f( 1.0f, 1.0f,-1.0f);	// Top Right Of The Quad (Top)
	    glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Top)
	    glVertex3f(-1.0f, 1.0f, 1.0f);	// Bottom Left Of The Quad (Top)
	    glVertex3f( 1.0f, 1.0f, 1.0f);	// Bottom Right Of The Quad (Top)
	    
		glColor3f(1.0f,0.5f,0.0f);	// Color Orange
	    
		glVertex3f( 1.0f,-1.0f, 1.0f);	// Top Right Of The Quad (Bottom)
	    glVertex3f(-1.0f,-1.0f, 1.0f);	// Top Left Of The Quad (Bottom)
	    glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Bottom)
	    glVertex3f( 1.0f,-1.0f,-1.0f);	// Bottom Right Of The Quad (Bottom)
	    
		glColor3f(1.0f,0.0f,0.0f);	// Color Red	
	    
		glVertex3f( 1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Front)
	    glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Left Of The Quad (Front)
	    glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Left Of The Quad (Front)
	    glVertex3f( 1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Front)
	    
		glColor3f(1.0f,1.0f,0.0f);	// Color Yellow
	    
		glVertex3f( 1.0f,-1.0f,-1.0f);	// Top Right Of The Quad (Back)
	    glVertex3f(-1.0f,-1.0f,-1.0f);	// Top Left Of The Quad (Back)
	    glVertex3f(-1.0f, 1.0f,-1.0f);	// Bottom Left Of The Quad (Back)
	    glVertex3f( 1.0f, 1.0f,-1.0f);	// Bottom Right Of The Quad (Back)
	    
		glColor3f(0.0f,0.0f,1.0f);	// Color Blue
	    
		glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Left)
	    glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Left)
	    glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Left)
	    glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Left)
	    
		glColor3f(1.0f,0.0f,1.0f);	// Color Violet
	    
		glVertex3f( 1.0f, 1.0f,-1.0f);	// Top Right Of The Quad (Right)
	    glVertex3f( 1.0f, 1.0f, 1.0f);	// Top Left Of The Quad (Right)
	    glVertex3f( 1.0f,-1.0f, 1.0f);	// Bottom Left Of The Quad (Right)
	    glVertex3f( 1.0f,-1.0f,-1.0f);	// Bottom Right Of The Quad (Right)
	  glEnd();			// End Drawing The Cube	
}


void HDAPS_GLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, (GLint)w, (GLint)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLdouble)w/(GLdouble)h, 1,10);
	glMatrixMode(GL_MODELVIEW);
}

