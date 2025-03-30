
#pragma once

#include<gl/GL.h>
#include<GL/glu.h>   
#include<math.h>   



// Gloabal Variables 
//GLfloat x = 0.0, y = 0.0;
GLfloat translate_z = -6.0;
GLfloat translate_jet = -0.2;


#include"Bharat.h"   
#include"Plane.h"   
#include"Map.h"   


// Function definations 

void Animations()
{
	// rotating earth
	if (Rotating_Angle <= 640.0)  // 640
	{
		Rotating_Angle = Rotating_Angle + 0.20;
	}

	// back to front earth
	if (Rotating_Angle >= 640 && translate_z <= -1.20)
		translate_z = translate_z + 0.01;

	// single jet translation 
	if (translate_z >= -1.20 && translate_jet < 0.5)
		translate_jet = translate_jet + 0.00025;
}


void Start_Earth()
{
	// Calling to animation 
	Animations();

	// Function declarations 
	void Earth();
	void Background();

	// Code
	
	Background();
	
	glPushMatrix();
		glTranslatef(0.0, -0.16, 0.0);
			Earth();
	glPopMatrix();

			/*if (translate_z >= -1.20)
				Start_Map();*/

	glPushMatrix();
		    if (translate_z >= -1.20)
			{
				glTranslatef(0.0, -0.01, -0.06);
					Start_Bharat();
             
				glTranslatef(translate_jet, 0.017, 0.0);
					Start_Plane(0);
			}
	glPopMatrix();

	glPushMatrix();
		if (translate_jet >= 0.4)
		{
			glTranslatef(0.0, 0.01,0.0);
				plane_anim();
		}
		glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
}

void Earth()
{
	glPushMatrix();
		glTranslatef(0.0 ,0.0 , translate_z);
		glRotatef(-80, 1.0, 0.0, 0.0);
		glRotatef(Rotating_Angle, 0.0, 0.0, 1.0);
	
		glBindTexture(GL_TEXTURE_2D, Texture_Earth);
			gluQuadricTexture(quadric, GL_TRUE); // to bind the texture on Sphere  
			gluSphere(quadric, 0.75, 50, 50);
		glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();
}

void Background()
{
	glBindTexture(GL_TEXTURE_2D, Texture_Background);

	glPushMatrix();
		glTranslatef(0.0, 0.0, -8.0);
		glScalef(6.0, 4.0, 4.0);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0, 1.0);
				glVertex3f( 1.0,  1.0, 0.0);  
		
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, 1.0, 0.0);  
		
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 0.0); 

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, -1.0, 0.0);
			glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
}