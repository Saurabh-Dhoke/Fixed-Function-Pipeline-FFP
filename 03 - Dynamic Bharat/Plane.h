
#pragma once

#include<gl/GL.h>
#include<GL/glu.h>   
#include<math.h>   

GLfloat x = 0.0, y = 0.0;

void Start_Plane(int color_no)
{
	// Function declarations 
	void planes();
	void dhurrr();


	// Code
	glPushMatrix();
		glTranslatef(-0.1, 0.0, 0.0);
		glScalef(0.3, 0.3, 0.3);
			planes();		

		if(color_no == 1)
			glColor3f(1, 0.4, 0.12);  // orange
		if(color_no == 2)
			glColor3f(1, 1, 1);        // white
		if(color_no == 3)
			glColor3f(0.02, 0.42, 0.22);      // green

		dhurrr();

	glPopMatrix();
}

void dhurrr()
{
	glEnable(GL_BLEND);
	glPushMatrix();
			glScalef(1.42, 0.6, 1.0);
			glBegin(GL_POLYGON); 
				glVertex3f(-0.3, -0.10, 0.0);
				glVertex3f(-0.3, 0.10, 0.0);

				glColor4f(0, 0, 0, 0.0);
				glVertex3f(-0.5, 0.40, 0.0);
				glVertex3f(-0.5,-0.40, 0.0);
			glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);

}

void planes()
{
	// Function declarations 
	void Misail();
	void Logo();

	glPushMatrix();
	    // Misails middle
		glPushMatrix();
			glTranslatef(0.1, 0.4, 0.0);
			glScalef(0.3, 0.2, 0.2);
				Misail();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.1, -0.4, 0.0);
			glScalef(0.3, 0.2, 0.2);
				Misail();
		glPopMatrix();	



		// wings 2
		glBegin(GL_QUADS);
			glColor3f(0.36, 0.54, 0.66);

				glVertex3f(-0.1, 0.6, 0.0); // RT
				glVertex3f(-0.4, 0.6, 0.0); // LT
				glVertex3f(-0.4, 0.0, 0.0); // LB
				glVertex3f( 0.7, 0.0, 0.0); // RB

				glVertex3f( 0.7, 0.0, 0.0); // RB
				glVertex3f(-0.4,0.0, 0.0); // LT
				glVertex3f(-0.4,-0.6, 0.0); // LB
				glVertex3f(-0.1,-0.6, 0.0); // RB
		glEnd();

		// madhala polygon
		Misail();
		
		// misails
		glPushMatrix();
			glTranslatef(-0.3, 0.6, 0.0);
			glScalef(0.3, 0.2, 0.2);
				Misail();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-0.3, -0.6, 0.0);
			glScalef(0.3, 0.2, 0.2);
				Misail();
		glPopMatrix();

		// logos 
		glPushMatrix();
			Logo();
			glTranslatef(0.0, -0.8, 0.0);
				Logo();
		glPopMatrix();
		
	glPopMatrix();
}

void Misail()
{
	glPushMatrix();
			glScalef(1.42, 0.6, 1.0);
			glBegin(GL_POLYGON); 
				glColor3f(0.29, 0.59, 0.71); 
				glColor3f(0.36, 0.54, 0.76);
					glVertex3f(0.775, 0.0, 0.0);
					glVertex3f(0.4, 0.15, 0.0);
					glVertex3f(0.0, 0.15, 0.0);
					glVertex3f(-0.2,0.15, 0.0);
					glVertex3f(-0.3,0.10, 0.0);

					glVertex3f(-0.3,-0.10, 0.0);				
					glVertex3f(-0.2,-0.15, 0.0);
					glVertex3f(0.0,-0.15, 0.0);
					glVertex3f(0.4,-0.15, 0.0);
					glVertex3f(0.775 ,0.0, 0.0); 
			glEnd();
		glPopMatrix();
}

void Logo()
{
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 0, 0);
		for (float i = 0; i < 360; i++)
		{
			x = -0.3 + (0.06 * cos(i * (3.14 / 180)));
			y = 0.4 + (0.06 * sin(i * (3.14 / 180)));

			glVertex2f(x, y);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		for (float i = 0; i < 360; i++)
		{
			x = -0.3 + (0.04 * cos(i * (3.14 / 180)));
			y = 0.4 + (0.04 * sin(i * (3.14 / 180)));

			glVertex2f(x, y);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.02, 0.01, 0.55);
		for (float i = 0; i < 360; i++)
		{
			x = -0.3 + (0.02 * cos(i * (3.14 / 180)));
			y = 0.4 + (0.02 * sin(i * (3.14 / 180)));

			glVertex2f(x, y);
		}
	glEnd();

}
