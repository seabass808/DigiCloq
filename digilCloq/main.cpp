#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "digit.hpp"
#include "colon.hpp"
#include "watch.hpp"

using namespace std;

int WindowPositionX = 100;
int WindowPositionY = 100;
int WindowWidth = 800;
int WindowHeight = 400;
char WindowTitle[] = "Digital Watch";
int sec;
int minute ;
int hour;


class digits
{
		
	public:
		static void timer(int);
		static void times();
		static void colons();
		static void twoDigitizer(int);
		static void multitize(int, int, int );
		static void display();
		static void reShape(int, int);
		static void keyboard(unsigned char, int, int);
		static void Idle();
};

void digits::timer( int value){
	times();
	colons();
	glutPostRedisplay();
	glutTimerFunc(1, timer, 0 );
	
	}
	
void digits::times(){
	Watch* wh = new Watch();
	sec = wh->seconds();
	minute = wh->mutes();
	hour = wh->hours();

	}

void digits::colons(){
	glPushMatrix();
		glTranslated( -3.3, 0.0, 0.0 );
		colon();
		glTranslated( 6.7, 0.0, 0.0 );
		colon();
	glPopMatrix();
	}
	
void digits::twoDigitizer( int tm ){
	Eights eig;
	int array[2];
	array[0] = tm/10;
	array[1] = tm % 10;
	
	for (int i=0; i<2; ++i) {
		glPushMatrix();
		glTranslated( (double)i*2.7, 0.0, 0.0);
		switch (array[i]) {
				case 0:	eig.zero();
					break;
				case 1:	eig.one();
					break;
				case 2:	eig.two();
					break;
				case 3:	eig.three();
					break;
				case 4:	eig.four();
					break;
				case 5:	eig.five();
					break;
				case 6:	eig.six();
					break;
				case 7:	eig.seven();
					break;
				case 8:	eig.eight();
					break;
				case 9:	eig.nine();
					break;
				default:	eig.zero();
					break;
					}
			glPopMatrix();
				}
	
	}

void digits::multitize( int hr, int mn, int sc )
{
	
	int array[3];
	array[0] = hr;
	array[1] = mn;
	array[2] = sc;
	
	for (int j=0; j<3; ++j){
			glPushMatrix();
				glTranslated(-8.2+(double)j*6.8, 0.0, 0.0);
				twoDigitizer(array[j]);
			glPopMatrix();
		}
	}

void digits::display()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, WindowWidth, WindowHeight);
	glOrtho( -10.0, 10.5, -5.0, 5.0, -1.0, 1.0 );
	multitize(hour, minute, sec);
	colons();
		
	glutSwapBuffers();
	}
	
void digits::reShape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, WindowWidth, WindowHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-(GLfloat)w/300.0, (GLfloat)w/300.0, -(GLfloat)h/300.0, (GLfloat)h/300.0, -1.0, 1.0 );
	
	}
	
void digits::keyboard(unsigned char key, int x, int y)
{
	if (key == '\033' || key == 'q' ) {
		exit(0);
		}
	}
	
void digits::Idle()
{
	glutPostRedisplay();
	}


int main(int argc, char** argv )
{
	mapping();
	digits dg;
	dg.times();
	
	glutInit(&argc, argv);
	glutInitWindowPosition(WindowPositionX, WindowPositionY);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA );
	
	glutCreateWindow(WindowTitle);
	glutDisplayFunc(dg.display);
	
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
	
	glClearColor(0.01, 0.01, 0.15, 0.0);
	glutReshapeFunc(dg.reShape);
	glutTimerFunc(1, dg.timer, 0 );
	glutIdleFunc(dg.Idle);
	glutKeyboardFunc(dg.keyboard);
	glutMainLoop();
	
	return 0;
	
	}










