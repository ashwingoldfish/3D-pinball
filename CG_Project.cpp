
#include <iostream>
#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#include "texture.h"

GLint FPS = 30;		// Frames per Second

int width = 800;
int height = 600;

int spin_x = 0, old_x = 0;		// spin_ amount of spinning
int spin_y = 0, old_y = 0;		// old_  previous value
int phase = 0;	


Texture background, backface;

bool flag=0;

float slabx = 0.0, slabz = 0.0;

double slabws = 0.0;
double slabad = 0.0;

float ballx = 0.0, bally = 0.0, ballz = 0.0;
float deltaballx = 0.0,deltabally = -0.1, deltaballz = 0.0;
float temp = 0.0;

/*
 * menu function
 * op - integer representing the chosen action
 */

void menu(int op) {

  switch(op) {
  case 'Q':
  case 'q':
    exit(0);
  }
}

void check_y_condition()
{	
	if (bally<-7.0)
	{
		glutPostRedisplay();
		exit(0);
	}
}

void check_collision() {

void check_collision_of_plate(); {
	if((bally <= -3.1) && (bally >= -3.4) && (ballx >= (-1.3 + slabx)) && (ballx <= (1.3 + slabx)) && (ballz >= (-1.3 + slabz)) && (ballz <= (1.3 + slabz)))
	{
		deltaballx = (slabad)/150.0;
		deltaballz = -1.0 * (slabws)/150.0;
		deltabally = deltabally * -1.0;
	}	
}

void check_surface_back (); {
	if (ballx >= -5 && ballx <= 5 && bally >= -5 && bally <= 7 && ballz >= 2.5 && ballz <= 2.75)
	{
		flag=1;
		deltaballz = deltaballz * -1.0;
	}
}

void check_surface_front(); {
	if (ballx >= -5 && ballx <= 5 && bally >= -5 && bally <= 7 && ballz >= -2.75 && ballz <= -2.5)
	{
		flag=1;
		deltaballz = deltaballz * -1.0;
	}
}

void check_surface_1(); {
	if (/*ballx >= -5.25 &&*/ ballx <= -4.6 && bally >= 0 && bally <= 7 && ballz >= -2.5 && ballz <= 2.5)
	{
		flag=1;
		deltaballx = deltaballx * -1.0;
	}
}

void check_surface_2(); {
	if (ballx >= 4.6 && /*ballx <= 5.25 &&*/ bally >= 0 && bally <= 7 && ballz >= -2.5 && ballz <= 2.5)
	{
		flag=1;
		deltaballx = deltaballx * -1.0;
	}
}

void check_surface_3(); {
	if (/*ballx >= -2.75 &&*/ ballx <= -2.1 && bally >= -5 && bally <= 0 && ballz >= -2.5 && ballz <= 2.5)
	{
		flag=1;
		deltaballx = deltaballx * -1.0;
	}
}

void check_surface_4(); {
	if (ballx >= 2.1 && /*ballx <= 2.75 &&*/ bally >= -5 && bally <= 0 && ballz >= -2.5 && ballz <= 2.5)
	{
		flag=1;
		deltaballx = deltaballx * -1.0;
	}
}

void check_surface_5(); {
	if (ballx >= -5 && ballx <= 5 && bally >= 6.7 && bally <= 7.25 && ballz >= -2.5 && ballz <= 2.5)
	{
		flag=1;
		deltabally = deltabally * -1.0;
	}
}

void check_surface_6(); {
	if (ballx >= -5 && ballx <= -2.5 && bally >= 0 && bally <= 0.3 && ballz >= -2.5 && ballz <= 2.5)
	{
		flag=1;
		deltabally = deltabally * -1.0;
	}
}

void check_surface_7(); {
	if (ballx >= 2.5 && ballx <= 5 && /*bally >= -0.25 &&*/ bally <= 0.3 && ballz >= -2.5 && ballz <= 2.5)
	{
		flag=1;
		deltabally = deltabally * -1.0;
	}
}

//void check_surface_8(); {
//	if (ballx >= -2.5 && ballx <= 2.5 && bally >= -4.25 && bally <= -4 && ballz >= -2.5 && ballz <= 2.5)
//		exit (0);
//}

void check_surface_a1(); {
	if (ballx >= -2.5 && ballx <= -1.5 && bally >= 5.0 && bally <= 5.1 && ballz >= -0.5 && ballz <= 0.5)
	{
		flag=1;
		deltabally = deltabally * -1.0;
	}
}

void check_surface_a2(); {
	if (ballx >= -2.5 && ballx <= -1.5 && bally >= 1.9 && bally <= 2.0 && ballz >= -0.5 && ballz <= 0.5)
	{
		flag=1;
		deltabally = deltabally * -1.0;
	}
}

void check_surface_a3(); {
	if (ballx >= -2.5 && ballx <= -1.5 && bally >= 2.0 && bally <= 5.0 && ballz >= -0.8 && ballz <= -0.4)
	{
		flag=1;
		deltaballz = deltaballz * -1.0;
	}
}

void check_surface_a4(); {
	if (ballx >= -2.5 && ballx <= -1.5 && bally >= 2.0 && bally <= 5.0 && ballz >= 0.4 && ballz <= 0.8)
	{
		flag=1;
		deltaballz = deltaballz * -1.0;
	}
}

void check_surface_a5(); {
	if (ballx >= -2.8 && ballx <= -2.4 && bally >= 2.0 && bally <= 5.0 && ballz >= -0.5 && ballz <= 0.5)
	{
		flag=1;
		deltaballx = deltaballx * -1.0;
	}
}

void check_surface_a6(); {
	if (ballx >= -1.6 && ballx <= -1.2 && bally >= 2.0 && bally <= 5.0 && ballz >= -0.5 && ballz <= 0.5)
	{
		flag=1;
		deltaballx = deltaballx * -1.0;
	}
}

void check_surface_b1(); {
	if (ballx >= 1.5 && ballx <= 2.5 && bally >= 5.0 && bally <= 5.1 && ballz >= -0.5 && ballz <= 0.5)
	{
		flag=1;
		deltabally = deltabally * -1.0;
	}
}

void check_surface_b2(); {
	if (ballx >= 1.5 && ballx <= 2.5 && bally >= 1.9 && bally <= 2.0 && ballz >= -0.5 && ballz <= 0.5)
	{
		flag=1;
		deltabally = deltabally * -1.0;
	}
}

void check_surface_b3(); {
	if (ballx >= 2.5 && ballx <= 1.5 && bally >= 2.0 && bally <= 5.0 && ballz >= -0.8 && ballz <= -0.4)
	{
		flag=1;
		deltaballz = deltaballz * -1.0;
	}
}

void check_surface_b4(); {
	if (ballx >= 2.5 && ballx <= 1.5 && bally >= 2.0 && bally <= 5.0 && ballz >= 0.4 && ballz <= 0.8)
	{
		flag=1;
		deltaballz = deltaballz * -1.0;
	}
}

void check_surface_b5(); {
	if (ballx >= 1.2 && ballx <= 1.6 && bally >= 2.0 && bally <= 5.0 && ballz >= -0.5 && ballz <= 0.5)
	{
		flag=1;
		deltaballx = deltaballx * -1.0;
	}
}

void check_surface_b6(); {
	if (ballx >= 2.4 && ballx <= 2.8 && bally >= 2.0 && bally <= 5.0 && ballz >= -0.5 && ballz <= 0.5)
	{
		flag=1;
		deltaballx = deltaballx * -1.0;
	}
}
}
void Phase_ball_1()
{
	ballx = ballx + deltaballx;
	bally = bally + deltabally;
	ballz = ballz + deltaballz;
	
	//check for collision	
	check_y_condition();
	
	if(flag==0)
	{
		check_collision();
	}
	if(flag==1)
	{
			flag=0;
	}
	
	
}

/*
 * invoked by GLUT when a key is pressed
 * key - pressed key
 * x, y - mouse coordinates
 */
void keyboardDown(unsigned char key, int x, int y) 
{
	
   switch (key) 
   {
	   case 'Q':
	   case 'q': exit(0);
				 break;  	   
	   case 'o': if(slabz <= 1.2) 
				 {
					slabz = slabz+0.2;
					glutPostRedisplay();
				 }
				 break;			
	   case 'l': if(slabz >= -1.2) 
				 {
					slabz = slabz -0.2;
					glutPostRedisplay();
				 }
				 break;
	   case ';': if(slabx <= 1.2) 
				 {
					slabx = slabx + 0.2;
					glutPostRedisplay();
				 }
				 break;
	   case 'k': if(slabx >= -1.2) 
				 {
					slabx = slabx -0.2;
					glutPostRedisplay();
				 }
				 break;
	   case 'w': if(slabws >=- 20.0)
				 {
					slabws = slabws -1.0;
					glutPostRedisplay();
				 }
				 break;
	   case 's': if(slabws <= 20.0)
				 {
					slabws = slabws +1.0;
					glutPostRedisplay();
				 }
				 break;
	   case 'a': if(slabad >= -20.0)
				 {
					slabad = slabad -1.0;
					glutPostRedisplay();
				 }
				 break;
	   case 'd': if(slabad <= 20.0)
				 {
					slabad = slabad +1.0;
					glutPostRedisplay();
				 }
				 break;
		case 'e':Phase_ball_1();
				 glutPostRedisplay();
				 break;
   }
}


/*
 * invoked by GLUT when a key is released
 * key - pressed key
 * x, y - mouse coordinates
 */
void keyboardUp(unsigned char key, int x, int y) {}

/*
 * invoked by GLUT when the window is modified
 * width. height - new size of the window
 */
void reshape(int width, int height) 
{
  GLfloat fieldOfView = 45.0f;
  glViewport (0, 0, (GLsizei) width, (GLsizei) height);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fieldOfView, (GLfloat) width/(GLfloat) height, 0.5, 100.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

/*
 * invoked by GLUT when a mouse button is released or pressed
 * button - identifier of the button
 * state - current state of the button
 * x, y - mouse coordinates
 */
void mouseClick(int button, int state, int x, int y) 
{
	old_x = x;
	old_y = y;
	
	glutPostRedisplay();
}

/*
 * invoked by GLUT when the mouse moves
 * x, y - mouse coordinates
 */
void mouseMotion(int x, int y) 
{
	spin_x = x - old_x;
	spin_y = y - old_y;

	glutPostRedisplay();
}

/*
 * draws the axis
 * length - length of the 3 axis
 */
void DrawAxes(float length)
{
	glPushMatrix();
	glScalef(length, length, length);

		glLineWidth(2.f);
		glBegin(GL_LINES);

		// x red
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(0.f, 0.f, 0.f);
		glVertex3f(1.f, 0.f, 0.f);

		// y green
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.f, 0.f, 0.f);
		glVertex3f(0.f, 1.f, 0.f);

		// z blue
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.f, 0.f);
		glVertex3f(0.f, 0.f, 1.f);

		glEnd();
		glLineWidth(1.f);

	glPopMatrix();
}

//Draws the ball
void ball(float diam)
{
	//assign inner texture
	glPushMatrix();
		glTranslatef(ballx,ballz,bally);
		glutSolidSphere(0.3, 25, 10);
	glPopMatrix();
} 

//Draws plate
void plate(float dim)
{
	glPushMatrix();
		glTranslatef(slabx,slabz,-4.5);
		glRotatef(slabad, 0.0f, 1.0f, 0.0f);		
		glRotatef(slabws, 1.0f, 0.0f, 0.0f);
		glTranslatef(-slabx,-slabz,4.5);
		glTranslatef(slabx,slabz,0);
		glTranslatef(0.0, 0.0, -4.5);
		glScalef(2.5, 2.5,0.10);
		glutSolidCube(1.0);
	glPopMatrix();
}

//Draws the Frame of the game space
void frame (float dim)
{
	//Draws the lower part of the frame
	void frame_lower ();
	{
	glPushMatrix();
		//Write the transformation code for the lower frame here
		glTranslatef(0.0, 0.0, -3.0);
	
	//Face A bottom
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-2.5, 2.5, -1.98);		
		glTexCoord2f(1, 0); glVertex3f(2.5, 2.5, -1.98);
		glTexCoord2f(1, 1); glVertex3f(2.5, -2.5, -1.98);
		glTexCoord2f(0, 1); glVertex3f(-2.5, -2.5, -1.98);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//assign outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-2.5, 2.5, -2.02);		
		glTexCoord2f(1, 0); glVertex3f(2.5, 2.5, -2.02);
		glTexCoord2f(1, 1); glVertex3f(2.5, -2.5, -2.02);
		glTexCoord2f(0, 1); glVertex3f(-2.5, -2.5, -2.02);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
		
	glPushMatrix();
		glTranslatef(0.0, 0.0, -2.0);
		glScalef(5, 5, 0);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//Face B left
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-2.48, 2.5, 2);		
		glTexCoord2f(1, 0); glVertex3f(-2.48, 2.5, -2);
		glTexCoord2f(1, 1); glVertex3f(-2.48, -2.5, -2);
		glTexCoord2f(0, 1); glVertex3f(-2.48, -2.5, 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//assign outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-2.52, 2.5, 2);		
		glTexCoord2f(1, 0); glVertex3f(-2.52, 2.5, -2);
		glTexCoord2f(1, 1); glVertex3f(-2.52, -2.5, -2);
		glTexCoord2f(0, 1); glVertex3f(-2.52, -2.5, 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glPushMatrix();
		glTranslatef(-2.5, 0.0, 0.0);
		glScalef(0, 5, 4);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//Face B right
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(2.48, 2.5, 2);		
		glTexCoord2f(1, 0); glVertex3f(2.48, 2.5, -2);
		glTexCoord2f(1, 1); glVertex3f(2.48, -2.5, -2);
		glTexCoord2f(0, 1); glVertex3f(2.48, -2.5, 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//assign outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(2.52, 2.5, 2);		
		glTexCoord2f(1, 0); glVertex3f(2.52, 2.5, -2);
		glTexCoord2f(1, 1); glVertex3f(2.52, -2.5, -2);
		glTexCoord2f(0, 1); glVertex3f(2.52, -2.5, 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	//Draws the lower backface
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-2.5, 2.48, 2);		
		glTexCoord2f(1, 0); glVertex3f(2.5, 2.48, 2);
		glTexCoord2f(1, 1); glVertex3f(2.5, 2.48, -2);
		glTexCoord2f(0, 1); glVertex3f(-2.5, 2.48, -2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);	
	//assign outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-2.5, 2.52, 2);		
		glTexCoord2f(1, 0); glVertex3f(2.5, 2.52, 2);
		glTexCoord2f(1, 1); glVertex3f(2.5, 2.52, -2);
		glTexCoord2f(0, 1); glVertex3f(-2.5, 2.52, -2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	/*glPushMatrix();
		glTranslatef(2.5, 0.0, 0.0);
		glScalef(0.02*dim, 5*dim, 4*dim);
		glutSolidCube(1.0);
	glPopMatrix();*/
	
	glPushMatrix();
		glTranslatef(0.0, 2.5, 0.0);
		glScalef(5, 0, 4);
		glutSolidCube(1.0);
	glPopMatrix();
	}
	glPopMatrix();

	//Draws the upper part of the frame
	void frame_upper ();
	{
	glPushMatrix();
	//Write the transformation code for the upper frame here

	//Face A top
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-5, 2.5, 5.98);		
		glTexCoord2f(1, 0); glVertex3f(5, 2.5, 5.98);
		glTexCoord2f(1, 1); glVertex3f(5, -2.5, 5.98);
		glTexCoord2f(0, 1); glVertex3f(-5, -2.5, 5.98);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//assign outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-5, 2.5, 6.02);		
		glTexCoord2f(1, 0); glVertex3f(5, 2.5, 6.02);
		glTexCoord2f(1, 1); glVertex3f(5, -2.5, 6.02);
		glTexCoord2f(0, 1); glVertex3f(-5, -2.5, 6.02);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glPushMatrix();
		glTranslatef(0.0, 0.0, 6.0);
		glScalef(10, 5, 0);
		glutSolidCube(1.0);
	glPopMatrix();

	//Face D bottom left
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(5, 2.5, -0.98);		
		glTexCoord2f(1, 0); glVertex3f(2.5, 2.5, -0.98);
		glTexCoord2f(1, 1); glVertex3f(2.5, -2.5, -0.98);
		glTexCoord2f(0, 1); glVertex3f(5, -2.5, -0.98);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//assign outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(5, 2.5, -1.02);		
		glTexCoord2f(1, 0); glVertex3f(2.5, 2.5, -1.02);
		glTexCoord2f(1, 1); glVertex3f(2.5, -2.5, -1.02);
		glTexCoord2f(0, 1); glVertex3f(5, -2.5, -1.02);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPushMatrix();
		glTranslatef(-3.75, 0.0, -1.0);
		glRotatef(-90, 0, 1, 0);
		glScalef(0, 5, 2.5);
		glutSolidCube(1.0);
	glPopMatrix();

	//Face D bottom right
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-5, 2.5, -0.98);		
		glTexCoord2f(1, 0); glVertex3f(-2.5, 2.5, -0.98);
		glTexCoord2f(1, 1); glVertex3f(-2.5, -2.5, -0.98);
		glTexCoord2f(0, 1); glVertex3f(-5, -2.5, -0.98);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//assign outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-5, 2.5, -1.02);		
		glTexCoord2f(1, 0); glVertex3f(-2.5, 2.5, -1.02);
		glTexCoord2f(1, 1); glVertex3f(-2.5, -2.5, -1.02);
		glTexCoord2f(0, 1); glVertex3f(-5, -2.5, -1.02);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPushMatrix();
		glTranslatef(3.75, 0.0, -1.0);
		glRotatef(90, 0, 1, 0);
		glScalef(0, 5, 2.5);
		glutSolidCube(1.0);
	glPopMatrix();

	//Face C left
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-4.98, 2.5, 6);		
		glTexCoord2f(1, 0); glVertex3f(-4.98, 2.5, -1);
		glTexCoord2f(1, 1); glVertex3f(-4.98, -2.5, -1);
		glTexCoord2f(0, 1); glVertex3f(-4.98, -2.5, 6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//assign outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-5.02, 2.5, 6);		
		glTexCoord2f(1, 0); glVertex3f(-5.02, 2.5, -1);
		glTexCoord2f(1, 1); glVertex3f(-5.02, -2.5, -1);
		glTexCoord2f(0, 1); glVertex3f(-5.02, -2.5, 6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glPushMatrix();
		glTranslatef(-5.0, 0.0, 2.5);
		glScalef(0, 5, 7);
		glutSolidCube(1.0);
	glPopMatrix();

	//Face C right
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(4.98, 2.5, 6);		
		glTexCoord2f(1, 0); glVertex3f(4.98, 2.5, -1);
		glTexCoord2f(1, 1); glVertex3f(4.98, -2.5, -1);
		glTexCoord2f(0, 1); glVertex3f(4.98, -2.5, 6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	//assigng outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(5.02, 2.5, 6);		
		glTexCoord2f(1, 0); glVertex3f(5.02, 2.5, -1);
		glTexCoord2f(1, 1); glVertex3f(5.02, -2.5, -1);
		glTexCoord2f(0, 1); glVertex3f(5.02, -2.5, 6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glPushMatrix();
		glTranslatef(5.0, 0.0, 2.5);
		glScalef(0, 5, 7);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//Back face
	glPushMatrix();	
	//assign inner texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-5, 2.48, -1);		
		glTexCoord2f(1, 0); glVertex3f(5, 2.48, -1);
		glTexCoord2f(1, 1); glVertex3f(5, 2.48, 6);
		glTexCoord2f(0, 1); glVertex3f(-5, 2.48, 6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);	
	//assign outter texture
	glBindTexture(GL_TEXTURE_2D, backface.ID);	
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0);	glVertex3f(-5, 2.51, -1);		
		glTexCoord2f(1, 0); glVertex3f(5, 2.51, -1);
		glTexCoord2f(1, 1); glVertex3f(5, 2.51, 6);
		glTexCoord2f(0, 1); glVertex3f(-5, 2.51, 6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glTranslatef(0.0, 2.5, 2.5);
		glScalef(10, 0, 7);
		glutSolidCube(1.0);
	glPopMatrix();
	
	}
	glPopMatrix();
}

//Draws four obstacles
void obstacle (float dim)
{
	glPushMatrix();
		glTranslatef(2.0, 0.0, 2.50);
		glScalef(dim, dim, 3*dim);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0, 0.0, 2.50);
		glScalef(dim, dim, 3*dim);
		glutSolidCube(1.0);
	glPopMatrix();
}

/*
 * draws the background (ortographic mode)
 */
void DrawBackground() {
	// -- begin ortographic mode
	glMatrixMode(GL_PROJECTION);					//selects the projection matrix
	glPushMatrix();									//saves the projection matrix
	glLoadIdentity();								//resets the projection matrix
	glOrtho(0, width, 0, height, -1, 1);			//sets orto coordinates
	glMatrixMode(GL_MODELVIEW);						//selects modelview matrix
	
	glPushMatrix();	
	glLoadIdentity();

	glDepthMask(GL_FALSE);							// disables z-buffer write

	glColor3f(1.f, 1.f, 1.f);
	glBindTexture(GL_TEXTURE_2D, background.ID);	// uses texture
	glBegin(GL_QUADS);								// draws the background
		glTexCoord2f(0, 0);	glVertex3f(0, 0, 0);		
		glTexCoord2f(1, 0); glVertex3f(width, 0, 0);// maps a vertex to a texel
		glTexCoord2f(1, 1); glVertex3f(width, height, 0);
		glTexCoord2f(0, 1); glVertex3f(0, height, 0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glPopMatrix();									// restores the previous projection matrix
	glMatrixMode(GL_PROJECTION);					
	glPopMatrix();	
	glDepthMask(GL_TRUE);							// enables z-buffer write
	// -- end ortographic mode
}

//Drawing of the scene
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	DrawBackground(); // draws the background
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(  0.0, -20.0, 1.0,	// eye position
				0.0, 0.0, 2.0,		// center
				0.0, -2.0, 0.0);	// vector UP

	//DrawAxes(2.0);
	glRotatef(spin_y, 1.0, 0.0, 0.0);
	glRotatef(spin_x, 0.0, 1.0, 0.0);

	//Drawing of the ball
	glColor3f (0.7, 0.6, 0.1);
	glPushMatrix();
		ball(1.0);
	glPopMatrix();

	//Drawing of the frame
	glTranslatef(0.0, 0.0, 1.0);
	glColor3f (0.9, 0.5, 0.1);
	frame(1.0);

	//Drawing of the plate
	glColor3f (0.2, 0.5, 0.1);
	plate(1.0);

	//Drawing of the obstacles
	glColor3f (0.05, 0.5, 0.1);
	obstacle(1.0);

	glutSwapBuffers();
}


//invoked when there are no other events to process
void idle() { }

/*
 * initializes the state of OpenGL
 * width, height - size of the OpenGL window
 */
void initGL(int width, int height) 
{
	// color and type of the lights	
	GLfloat light_ambient_0[] = {0.3, 0.3, 0.3, 1.0};	// ambient color of light 0
	GLfloat light_diffuse_0[] = {0.4, 0.4, 0.4, 1.0};	// diffuse color of light 0
	GLfloat light_specular_0[] = {0.05, 0.05, 0.05, 0.0};	// specular color of light 0
	GLfloat light_position_0[] = {-4.0, 3.0, 0.0, 1.0};	// position of light 0
	
	glLightfv (GL_LIGHT0, GL_AMBIENT,	light_ambient_0);
	glLightfv (GL_LIGHT0, GL_DIFFUSE,	light_diffuse_0);
	glLightfv (GL_LIGHT0, GL_SPECULAR,	light_specular_0);
	glLightfv (GL_LIGHT0, GL_POSITION,	light_position_0);
	
	GLfloat light_ambient_1[] = {0.3, 0.3, 0.3, 1.0};	// ambient color of light 1
	GLfloat light_diffuse_1[] = {0.4, 0.4, 0.4, 1.0};	// diffuse color of light 1
	GLfloat light_specular_1[] = {0.05, 0.05, 0.05, 0.0};	// specular color of light 1
	GLfloat light_position_1[] = {4.0, 3.0, 0.0, 1.0};	// position of light 1
	
	glLightfv (GL_LIGHT1, GL_AMBIENT,	light_ambient_1);
	glLightfv (GL_LIGHT1, GL_DIFFUSE,	light_diffuse_1);
	glLightfv (GL_LIGHT1, GL_SPECULAR,	light_specular_1);
	glLightfv (GL_LIGHT1, GL_POSITION,	light_position_1);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	GLfloat material_ambient_0[] = {0.2, 0.2, 0.2, 1.0};	// ambient color of material 0
	GLfloat material_diffuse_0[] = {0.5, 0.5, 0.5, 1.0};	// diffuse color of material 0
	GLfloat material_specular_0[] = {0.2, 0.2, 0.2, 1.0};	// specular color of material 0
	GLfloat material_emission_0[] = {0.10, 0.10, 0.10, 1.0};	// emission colour of material 0
	GLfloat material_shininess_0[] = {20};					//shininess of material
	
	glMaterialfv (GL_FRONT, GL_AMBIENT,	material_ambient_0);
	glMaterialfv (GL_FRONT, GL_DIFFUSE,	material_diffuse_0);
	glMaterialfv (GL_FRONT, GL_SPECULAR, material_specular_0);
	glMaterialfv (GL_FRONT, GL_EMISSION, material_emission_0);
	glMaterialfv (GL_FRONT, GL_SHININESS, material_shininess_0);
	
	GLfloat material_ambient_1[] = {0.2, 0.2, 0.2, 1.0};	// ambient color of material 1
	GLfloat material_diffuse_1[] = {0.5, 0.5, 0.5, 1.0};	// diffuse color of material 1
	GLfloat material_specular_1[] = {0.2, 0.2, 0.2, 1.0};	// specular color of material 1
	GLfloat material_emission_1[] = {0.10, 0.10, 0.10, 1.0};	// emission colour of material 1
	GLfloat material_shininess_1[] = {20};					//shininess of material
	
	glMaterialfv (GL_FRONT, GL_AMBIENT,	material_ambient_1);
	glMaterialfv (GL_FRONT, GL_DIFFUSE,	material_diffuse_1);
	glMaterialfv (GL_FRONT, GL_SPECULAR, material_specular_1);
	glMaterialfv (GL_FRONT, GL_EMISSION, material_emission_1);
	glMaterialfv (GL_FRONT, GL_SHININESS, material_shininess_1);
	
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	reshape(width, height);
	
	//glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	//glClearDepth(1.0f);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_TEXTURE_2D);
		
	background.LoadTGA("grass1.tga", GL_LINEAR, GL_LINEAR);
	background.LoadTGA("grass2.tga", GL_LINEAR, GL_LINEAR);
	backface.LoadTGA("wood.tga", GL_LINEAR, GL_LINEAR);
	
}

/*
 * invoked each 1000/FPS milliseconds.
 * In this function you need to change the value of the parameters for next frame.
 * whenever the state changes, call glutPostRedisplay() to update the visualization.
 * t - is the last parameter of the glutTimerFunc
 */
void animation(int t)
{
	switch (phase) {
	case 0: // standby state
		break;
    }
	Phase_ball_1();
	glutPostRedisplay();
	glutTimerFunc((int) 1000/FPS, animation, 1);
// The glutTimerFunc is an alarm that rings after x milliseconds. 
// If you need it to ring again, you need to invoke it again.
}

/*
 * initializes GLUT, defines the callback functions, enters the main loop
 * argc : number of command line parameters
 * argv : vector of the command line parameters
 *
 */

int main(int argc, char** argv) 
{
	int width = 900;
	int height = 700;
	
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Pinball 3D");
	
	// callback functions
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(reshape);
	glutDisplayFunc(draw);  
	glutIdleFunc(idle);
	glutTimerFunc((int) 1000/FPS, animation, 1);
	glutIgnoreKeyRepeat(false); // process keys held down

	//collision check functions
	Phase_ball_1();
			
	// creates the main menu (right button)
	glutCreateMenu(menu);
	glutAddMenuEntry("Quit", 'q');
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	// initializes OpenGL
	initGL(width, height);
	
	// starts the main loop	
	glutMainLoop();
	return 0;
}