
#pragma once

#include<gl/GL.h>
#include<GL/glu.h>   
#include<math.h>

#include"Bharat.h"  

GLfloat x = 0.0, y = 0.0;
GLfloat Rotating_Angle = 0.0f;

GLfloat c_angle = 360.0f;

GLfloat x_translate_plane = 0.0;
GLfloat translate_decreses = 0.0;
GLfloat translate_middle = -3.4;


void Start_Plane(int color_no)
{
	// Function declarations 
	void planes();
	void dhurrr();
	void dhurrr3();
	void IAF(); 

	// Code
	glPushMatrix();
		glTranslatef(-0.1, 0.0, -0.4);
		glScalef(0.1, 0.1, 0.1);
		//glRotatef(Rotating_Angle, 1, 0, 0);
				

		switch (color_no)
		{
		case 0:
			glPushMatrix();
				if (translate_jet >= -0.01 && translate_jet <= 0.28)
					dhurrr3();

				glScalef(1.0, 0.7, 1.0);
					planes();	
			glPopMatrix();
			break;

		case 1: 
			planes();
			glColor3f(1, 0.4, 0.12);  // orange
				dhurrr();
			break;
		
		case 2:
			planes();
			glColor3f(1, 1, 1);        // white
				dhurrr();
			break;
		
		case 3:
			planes();
			glColor3f(0.02, 0.42, 0.22);      // green
				dhurrr();
			break;
		}

		
	glPopMatrix();
}

void Animation_jets()
{
	// For flags  show after jet pass
	if (translate_middle >= -0.34)
		flag_1 = TRUE;
	if (translate_middle >= -0.14)
		flag_2 = TRUE;
	if (translate_middle >=  0.095)
		flag_3 = TRUE;
	if (translate_middle >= 0.32)
		flag_4 = TRUE;
	if (translate_middle >= 0.50)
		flag_5 = TRUE;
	if (translate_middle >= 0.68)
		flag_6 = TRUE;


		// Plane animation middle 
		if (translate_middle < 3.0)
			translate_middle = translate_middle + 0.0027;

		// plane animation  upper and lower 
		if (c_angle > 270.0)                 // come from left side
			c_angle = c_angle - 0.08;

		else if (x_translate_plane < 0.99)  // go strate
			x_translate_plane = x_translate_plane + 0.0027;

		else if (c_angle > 180)             // go back to right side
			c_angle = c_angle - 0.08;

		//// Plane animation middle 
		//if (translate_middle < 3.0)
		//	translate_middle = translate_middle + 0.00135;

		//// plane animation  upper and lower 
		//if (c_angle > 270.0)                 // come from left side
		//	c_angle = c_angle - 0.04;

		//else if (x_translate_plane < 0.99)  // go strate
		//	x_translate_plane = x_translate_plane + 0.00135;

		//else if (c_angle > 180)             // go back to right side
		//	c_angle = c_angle - 0.04;

	
}

void plane_anim()
{
	Animation_jets();

	glPushMatrix();
		glScalef(0.15, 0.15, 0.15);
		glTranslatef(-0.1, 0, 4.2);

			// varach plane 
			glPushMatrix();
				glTranslatef(x_translate_plane, 0.0, -6.4);

				glTranslatef(-0.356, 1.5, 0.0);
				glRotatef(-c_angle, 0, 0, 1);
				glTranslatef(-1.51 , 0.0, 0.0);
				glRotatef(-90, 0, 0, 1); // saral kel plane
					Start_Plane(1);
			glPopMatrix();
	
			// Khalach Plane
			glPushMatrix();
				glTranslatef(x_translate_plane, 0.0, -6.4);
		
				glTranslatef(-0.356, -1.5, 0.0);
				glRotatef(-c_angle, 0, 0, -1);
				glTranslatef(-1.46 , 0.0, 0.0);
				glRotatef(90, 0, 0, 1); // saral kel plane
					Start_Plane(3);
			glPopMatrix();

			// Middle plane 
			glPushMatrix();
				glTranslatef(translate_middle, -0.03, -6.4);
					Start_Plane(2);
			glPopMatrix();
	glPopMatrix();


}

void dhurrr3()
{
	glPushMatrix();
		glTranslatef(-0.1, 0.0, 0.0);
		glScalef(1.42, 0.6, 1.0);
		glEnable(GL_BLEND); 

			glBegin(GL_POLYGON); 
			    glColor3f(1, 1, 1);           // white 
				glVertex3f(-0.2, 0.00, 0.0);

				glColor3f(1, 0.4, 0.12);      // bhagava
				glVertex3f(-0.2, 0.40, 0.0);

				glColor4f(1, 0.4, 0.12, 0.5); // blend bhagava 
				glVertex3f(-0.3,  0.40, 0.0);
				
				glColor4f(1, 1, 1, 0.5);       // blend white
				glVertex3f(-0.3,  0.00, 0.0);
				//------------------
				glVertex3f(-0.2,  0.00, 0.0);
				glVertex3f(-0.3,  0.00, 0.0);

				glColor4f(0.02, 0.42, 0.22, 0.5); // blend green
				glVertex3f(-0.3, -0.40, 0.1);
				
				glColor3f(0.02, 0.42, 0.22); // green
				glVertex3f(-0.2,-0.40, 0.0);
			glEnd();
			glDisable(GL_BLEND);
	glPopMatrix();

}
void dhurrr()
{
	glPushMatrix();
		glEnable(GL_BLEND);
			glScalef(1.42, 0.6, 1.0);
			glBegin(GL_POLYGON); 
				glVertex3f(-0.3, -0.10, 0.0);
				glVertex3f(-0.3, 0.10, 0.0);

				glColor4f(0, 0, 0, 0.0);
				glVertex3f(-0.5, 0.40, 0.0);
				glVertex3f(-0.5,-0.40, 0.0);
			glEnd();
		glDisable(GL_BLEND);
	glPopMatrix();

}

void planes()
{
	// Function declarations 
	void Misail();
	void Logo();
	void IAF();

	glPushMatrix();
	glColor3f(0.25, 0.54, 0.66);
	
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

		//glColor3f(1,1,1);

		glBindTexture(GL_TEXTURE_2D, Texture_Jet);
		// wings 2
		glBegin(GL_QUADS);
			glColor3f(0.36, 0.54, 0.66);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(-0.1, 0.6, 0.0); // RT
			
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-0.4, 0.6, 0.0); // LT
				
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-0.4, 0.0, 0.0); // LB

				glTexCoord2f(1.0, 0.0);
				glVertex3f( 0.7, 0.0, 0.0); // RB
		glEnd();

		glBegin(GL_QUADS);
			//glColor3f(0.36, 0.54, 0.66);
				glTexCoord2f(1.0, 1.0);
				glVertex3f( 0.7, 0.0, 0.0); // RB
					
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-0.4,0.0, 0.0); // LT
				
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-0.4,-0.6, 0.0); // LB
				
				glTexCoord2f(1.0, 0.0);
				glVertex3f(-0.1,-0.6, 0.0); // RB
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);



		// madhala polygon
		glColor3f(0.25, 0.54, 0.66);

		Misail();
		glColor3f(0,0.1,0.1);
		
		

		// misails
		glPushMatrix();
			glTranslatef(-0.2, 0.6, 0.0);
			glScalef(0.4, 0.2, 0.2);
				Misail();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-0.2, -0.6, 0.0);
			glScalef(0.4, 0.2, 0.2);
				Misail();
		glPopMatrix();

		// logos 
		glPushMatrix();
			Logo();
			glTranslatef(0.0, -0.8, 0.0);
				Logo();
		glPopMatrix();
		
		// Flag 
		glPushMatrix();
			glTranslatef(-0.25, -0.22, 0.06);
			glScalef(0.5, 0.5, 0.5);
				flag_Quad();
				
			glTranslatef(0.60, 0.0, 0.0);			
				flag_Quad();

				IAF();
		glPopMatrix();

		glColor3f(0.25, 0.54, 0.66);

	glPopMatrix();
}
void IAF()
{
	glPushMatrix();
		glTranslatef(-0.15, 0.4, 0.00001);
		glScalef(0.4, 0.4, 0.4);

		glColor3f(0, 0, 0);
		glLineWidth(2);
		glBegin(GL_LINES);
			// I
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.3, 0.0);
		
			glVertex3f(-0.03, 0.3, 0.0);
			glVertex3f( 0.03, 0.3, 0.0);
		
			glVertex3f(-0.03, 0.0, 0.0);
			glVertex3f( 0.03, 0.0, 0.0);
		
			// A
			glVertex3f(0.1, 0.0, 0.0);
			glVertex3f(0.20, 0.3, 0.0);

			glVertex3f(0.3, 0.0, 0.0);
			glVertex3f(0.20, 0.3, 0.0);

			glVertex3f(0.15, 0.15, 0.0);
			glVertex3f(0.25, 0.15, 0.0);

			// F
			glVertex3f(0.4, 0.00, 0.0);
			glVertex3f(0.4, 0.30, 0.0);

			glVertex3f(0.4, 0.15, 0.0);
			glVertex3f(0.5, 0.15, 0.0);
		
			glVertex3f(0.4, 0.30, 0.0);
			glVertex3f(0.5, 0.30, 0.0);
		glEnd();
		glLineWidth(1);
	glPopMatrix();
}
void Misail()
{
	glBindTexture(GL_TEXTURE_2D, Texture_Jet);
	glColor3f(0.25, 0.54, 0.66);

	glPushMatrix();
		glTranslatef(0.02, 0.0, 0.0);
		glScalef(2.2, 0.5, 0.3);
			gluQuadricTexture(quadric, GL_TRUE);  
			gluSphere(quadric, 0.20, 50, 50);
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);



	/*glPushMatrix();
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
		glPopMatrix();*/
}
void Logo()
{
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 0, 0);
		for (float i = 0; i < 360; i++)
		{
			x = -0.3 + (0.06 * cos(i * (3.14 / 180)));
			y = 0.4 + (0.06 * sin(i * (3.14 / 180)));

			glVertex3f(x, y,0.01);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		for (float i = 0; i < 360; i++)
		{
			x = -0.3 + (0.04 * cos(i * (3.14 / 180)));
			y = 0.4 + (0.04 * sin(i * (3.14 / 180)));

			glVertex3f(x, y, 0.01);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.02, 0.01, 0.55);
		for (float i = 0; i < 360; i++)
		{
			x = -0.3 + (0.02 * cos(i * (3.14 / 180)));
			y = 0.4 + (0.02 * sin(i * (3.14 / 180)));

			glVertex3f(x, y, 0.01);
		}
	glEnd();

}
