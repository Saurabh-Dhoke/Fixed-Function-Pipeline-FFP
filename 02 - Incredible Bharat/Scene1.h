
#pragma once

#include<gl/GL.h>
#include<GL/glu.h>   
#include<math.h>   

GLfloat cam_angle = 180.0f;

void Start_Scene1()
{
	// function definations 
	void Intro_Scene();

	// Code
	Intro_Scene();

}

void Intro_Scene()
{
	//  Animation
	if (cam_angle >= 0.0)
		cam_angle = cam_angle - 0.1;


	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, Texture_intro);

		////gluLookAt(tx, ty, tz, sx, sy, 100, 0, 1, 0);

		glRotatef(180, 0, 1, 0); // saral rotate kela 
		glRotatef(cam_angle, 0, 0, 1);  // rotate karun aat jato

				glBegin(GL_QUADS);
					glColor3f(1,1,1);
					glTexCoord2f(1.0, 1.0);
					glVertex3f( 1.0,  1.0, 0.0);  
		
					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.0, 1.0, 0.0);  
		
					glTexCoord2f(0.0, 0.0);
					glVertex3f(-1.0, -1.0, 0.0); 

					glTexCoord2f(1.0, 0.0);
					glVertex3f(1.0, -1.0, 0.0);
				glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glBegin(GL_QUADS);
				glColor3f(0,0,0.4);
					glVertex3f( 1.0,  1.0, -0.1);  
					glVertex3f(-1.0, 1.0,  -0.1);  
					glVertex3f(-1.0, -1.0, -0.1); 
					glVertex3f(1.0, -1.0,  -0.1);
				glEnd();

	glPopMatrix();

}

