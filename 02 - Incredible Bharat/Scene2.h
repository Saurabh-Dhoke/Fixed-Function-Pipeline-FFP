
#pragma once


#include<gl/GL.h>
#include<GL/glu.h>   
#include<math.h>  

#include"Earth.h"  

GLfloat Blend_Value = 0.0f;


void Start_Scene2()
{
	// function Declarations
	void BlackQuad();

	// Code	


	glPushMatrix();
		Start_Earth();
	glPopMatrix();
	
	if (x_translate_plane >= 0.99)
		BlackQuad();



}

void BlackQuad()
{
	// Animation 
	if (Blend_Value <= 1.0)
		Blend_Value = Blend_Value + 0.002;

	// Code
	glPushMatrix();
		glTranslatef(0.0, 0.0, -0.110);
		//glTranslatef(0,0,tz);
			glEnable(GL_BLEND);
			glColor4f(1,1,1, Blend_Value); // Black Color
			glBegin(GL_QUADS);
				glVertex3f(2.0, 2.0, 0.0);
				glVertex3f(-2.0, 2.0, 0.0);
				glVertex3f(-2.0, -2.0, 0.0);
				glVertex3f(2.0, -2.0, 0.0);
			glEnd();
			glDisable(GL_BLEND);
	glPopMatrix();
}
