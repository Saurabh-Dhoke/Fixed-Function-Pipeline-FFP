#pragma once
#include"Map.h"

// Global Variables 
GLfloat Translate_End = 0.0f; 

// Function Definations 
void Start_Scene3()
{
	// function declarations 
	void Scrolling_End();

	// Code
	glPushMatrix();
		Scrolling_End();
		
		Start_Map();
		glColor3f(1,1,1);

	glPopMatrix();


}

void Scrolling_End()
{
	// Animation 
	if (Translate_End <= 6.0)
		Translate_End = Translate_End + 0.00075;

	// Code
	glPushMatrix();
		glTranslatef(0.1,Translate_End,0.0); // For Animation 

		glTranslatef(0.0, 0.0, -2.5);
		glScalef(2.0, 1.05, 1.0);

		// image 1
			glBindTexture(GL_TEXTURE_2D, Texture_0Last);
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
			glBindTexture(GL_TEXTURE_2D, 0);
		
		// image 2
		glTranslatef(0.0, -1.9, 0.001);
			glBindTexture(GL_TEXTURE_2D, Texture_1Last);
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
			glBindTexture(GL_TEXTURE_2D, 0);
	
		// image 3
		glTranslatef(0.0, -1.9, 0.001);
			glBindTexture(GL_TEXTURE_2D, Texture_2Last);
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
			glBindTexture(GL_TEXTURE_2D, 0);

		// image 4
		glTranslatef(0.0, -1.9, 0.001);
			glBindTexture(GL_TEXTURE_2D, Texture_3Last);
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
			glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();
}

