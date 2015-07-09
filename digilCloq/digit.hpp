#ifndef DIGIT_HPP_INCLUDED
#define DIGIT_HPP_INCLUDED

#include <GL/glut.h>
#include <iostream>

using namespace std;
		
const GLdouble vertex[] = {
						0.0, 0.85, -0.25, 0.6, -0.25, -0.6, 0.0, -0.85, 0.25, -0.6, 0.25, 0.6};
						
const GLdouble vertexDown[] = {
						-0.6, 0.25, -0.85, 0.0, -0.6, -0.25, 0.6, -0.25, 0.85, 0.0, 0.6, 0.25};

double array[][3] = { { 0.9, 0.9, 0 },
						{ -0.9, 0.9, 0 },
						{ 0.9, -0.9, 0 },
						{ -0.9, -0.9, 0 },
						{ 0, 1.8, 0 },
						{ 0, 0, 0 },
						{ 0, -1.8, 0 } };
						
GLfloat gold_amb[] = { 0.24725, 0.1995, 0.0745, 1.0 };
GLfloat gold_diff[] = { 0.75164, 0.60648 , 0.22648, 1.0 };
GLfloat gold_spe[] = { 0.628281, 0.555802,0.366065,1.0 };
GLfloat gold_shin[] = { 51.2 };
		
struct POS {
	double x, y, z; 
};

POS pos[7];
void mapping() {
	for ( int i=0; i<7; ++i) {
		pos[i].x = array[i][0];
		pos[i].y = array[i][1];
		pos[i].z = array[i][2];
	}
}
		
class Eights
{
	private:
		void hexagon (const GLdouble* ver)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, gold_amb);
			glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, gold_diff );
			glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, gold_spe );
			glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, gold_shin);
			glColor3d(1.0, 0.0, 0.0);
	
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(2,  GL_DOUBLE, 0, ver);
	
			glDrawArrays(GL_POLYGON, 0, 6);	
			}
	
		void pushMatrix(double x, double y, double z, const GLdouble* ver)
		{
			glPushMatrix();
				glTranslated( x, y, z);
				hexagon(ver);
			glPopMatrix();
	
			}
	
	public:
		void zero ()
		{
			pushMatrix( pos[0].x, pos[0].y, pos[0].z, vertex );		// 右上
			pushMatrix( pos[1].x, pos[1].y, pos[1].z, vertex );		// 左上
			pushMatrix( pos[2].x, pos[2].y, pos[2].z,  vertex ); 	// 右下
			pushMatrix( pos[3].x, pos[3].y, pos[3].z,  vertex );		// 左下
	
			pushMatrix( pos[4].x, pos[4].y, pos[4].z,  vertexDown );
			pushMatrix( pos[6].x, pos[6].y, pos[6].z,  vertexDown );
		}
		
		void one() 
		{
			pushMatrix( pos[0].x, pos[0].y, pos[0].z,  vertex );
			pushMatrix( pos[2].x, pos[2].y, pos[2].z,  vertex );
			}
		
		void two ()
		{
			pushMatrix( pos[0].x, pos[0].y, pos[0].z, vertex );		// 右上
			pushMatrix( pos[3].x, pos[3].y, pos[3].z,  vertex );		// 左下
			
			pushMatrix( pos[4].x, pos[4].y, pos[4].z,  vertexDown );
			pushMatrix( pos[5].x, pos[5].y, pos[5].z,  vertexDown );
			pushMatrix( pos[6].x, pos[6].y, pos[6].z,  vertexDown );
			}
			
		void three ()
		{
			pushMatrix( pos[0].x, pos[0].y, pos[0].z, vertex );		// 右上
			pushMatrix( pos[2].x, pos[2].y, pos[2].z,  vertex ); 		// 右下
			
			pushMatrix( pos[4].x, pos[4].y, pos[4].z,  vertexDown );
			pushMatrix( pos[5].x, pos[5].y, pos[5].z,  vertexDown );
			pushMatrix( pos[6].x, pos[6].y, pos[6].z,  vertexDown );
			}
			
		void four ()
		{
			pushMatrix( pos[0].x, pos[0].y, pos[0].z, vertex );		// 右上
			pushMatrix( pos[1].x, pos[1].y, pos[1].z, vertex );		// 左上
			pushMatrix( pos[2].x, pos[2].y, pos[2].z,  vertex ); 		// 右下
			
			pushMatrix( pos[5].x, pos[5].y, pos[5].z,  vertexDown );
			}
			
		void five ()
		{
			pushMatrix( pos[1].x, pos[1].y, pos[1].z, vertex );		// 左上
			pushMatrix( pos[2].x, pos[2].y, pos[2].z,  vertex ); 		// 右下
			
			pushMatrix( pos[4].x, pos[4].y, pos[4].z,  vertexDown );
			pushMatrix( pos[5].x, pos[5].y, pos[5].z,  vertexDown );
			pushMatrix( pos[6].x, pos[6].y, pos[6].z,  vertexDown );
			}
			
		void six()
		{
			pushMatrix( pos[1].x, pos[1].y, pos[1].z, vertex );		// 左上
			pushMatrix( pos[2].x, pos[2].y, pos[2].z,  vertex ); 		// 右下
			pushMatrix( pos[3].x, pos[3].y, pos[3].z,  vertex );		// 左下
			
			pushMatrix( pos[4].x, pos[4].y, pos[4].z,  vertexDown );
			pushMatrix( pos[5].x, pos[5].y, pos[5].z,  vertexDown );
			pushMatrix( pos[6].x, pos[6].y, pos[6].z,  vertexDown );
			}
			
		void seven()
		{
			pushMatrix( pos[0].x, pos[0].y, pos[0].z, vertex );		// 右上
			pushMatrix( pos[2].x, pos[2].y, pos[2].z,  vertex ); 		// 右下
			
			pushMatrix( pos[4].x, pos[4].y, pos[4].z,  vertexDown );
			}
			
		void eight()
		{
			pushMatrix( pos[0].x, pos[0].y, pos[0].z, vertex );		// 右上
			pushMatrix( pos[1].x, pos[1].y, pos[1].z, vertex );		// 左上
			pushMatrix( pos[2].x, pos[2].y, pos[2].z,  vertex ); 		// 右下
			pushMatrix( pos[3].x, pos[3].y, pos[3].z,  vertex );		// 左下
	
			pushMatrix( pos[4].x, pos[4].y, pos[4].z,  vertexDown );
			pushMatrix( pos[5].x, pos[5].y, pos[5].z,  vertexDown );
			pushMatrix( pos[6].x, pos[6].y, pos[6].z,  vertexDown );
			}
			
		void nine()
		{
			pushMatrix( pos[0].x, pos[0].y, pos[0].z, vertex );		// 右上
			pushMatrix( pos[1].x, pos[1].y, pos[1].z, vertex );		// 左上
			pushMatrix( pos[2].x, pos[2].y, pos[2].z,  vertex ); 		// 右下
			
			pushMatrix( pos[4].x, pos[4].y, pos[4].z,  vertexDown );
			pushMatrix( pos[5].x, pos[5].y, pos[5].z,  vertexDown );
			pushMatrix( pos[6].x, pos[6].y, pos[6].z,  vertexDown );
			}

	};

#endif






