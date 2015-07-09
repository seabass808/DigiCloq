#ifndef COLON_HPP_INCLUDED
#define COLON_HPP_INCLUDED

#include <GL/glut.h>
#include <iostream>

using namespace std;


void drawCircle( double x, double y, double z, double r)
{
	glBegin(GL_POLYGON);
		glVertex3d(x+r, y, 0);
		glVertex3d(x+0.7*r, y+0.7*r, z);
		glVertex3d(x, y+r, 0);
		glVertex3d(x-0.7*r, y+0.7*r, z);
		glVertex3d(x-r, y, 0);
		glVertex3d(x-0.7*r, y-0.7*r, z);
		glVertex3d(x, y-r, 0);
		glVertex3d(x+0.7*r, y-0.7*r, z);
	glEnd();
		
	}

void colon ()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPushMatrix();
		glTranslated( 0.0, 0.8, 0.0 );
		drawCircle(0.0, 0.0, 0.0, 0.15);
		glTranslated( 0.0, -1.6, 0.0 );
		drawCircle(0.0, 0.0, 0.0, 0.15 );
	glPopMatrix();
	
	};

#endif

















