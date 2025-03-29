
#pragma once

#include<gl/GL.h>
#include<GL/glu.h>   


#include"Plane.h"   



GLfloat BTX = -3.0;
GLfloat HAX = -4.5;
GLfloat HAY =  3.0;
GLfloat ARX = -4.7;
GLfloat ARY = -3.2;

//
//GLfloat BX = 0.0;
//GLfloat HX = 0.0;
//GLfloat HY =  0;
//GLfloat A1X = 0;
//GLfloat A1Y = 0;
//GLfloat RX = 0;
//GLfloat RY = 0.0;
//GLfloat A2X =  0;
//GLfloat A2Y = 0;
//GLfloat TX = 0;

// to start animiation of letters 
GLboolean flag_B  = TRUE;
GLboolean flag_H  = FALSE;
GLboolean flag_A = FALSE;

// to start animation of jets 
GLboolean Run_jets_flag = FALSE;

// for movements of jets 
GLfloat c_angle = 360.0;
GLfloat x_translate_plane = 0.0;
GLfloat translate_decreses = 0.0;

GLfloat translate_middle = -4.93;


// for middle flags 
GLboolean flag_1 = FALSE;  
GLboolean flag_2 = FALSE; 
GLboolean flag_3 = FALSE;
GLboolean flag_4 = FALSE;
GLboolean flag_5 = FALSE;
GLboolean flag_6 = FALSE;




void Animation()
{
	// For flags  show after jet pass
	if (translate_middle >= -1.7)
		flag_1 = TRUE;
    if (translate_middle >= -1.02)
		flag_2 = TRUE;
	if (translate_middle >= -0.34)
		flag_3 = TRUE;
	if (translate_middle >= 0.35)
		flag_4 = TRUE;
	if (translate_middle >= 1.02)
		flag_5 = TRUE;
	if (translate_middle >= 1.645)
		flag_6 = TRUE;

	if (Run_jets_flag == TRUE)
	{
		// Plane animation middle 
		if (translate_middle < 5.0)
			translate_middle = translate_middle + 0.00135;


		// plane animation  upper and lower 
		if (c_angle > 270.0)                 // come from left side
			c_angle = c_angle - 0.04;
		else if (x_translate_plane < 3.55)  // go strate
			x_translate_plane = x_translate_plane + 0.00135;
		else if (c_angle > 180)             // go back to right side
			c_angle = c_angle - 0.04;

	}
	

	// B T
	if (flag_B)
	{
		if (BTX <= 0.0)
			BTX = BTX + 0.0025;
		else
		{
			flag_B = FALSE;
			flag_H = TRUE;
		}
	}

	// H A
	else if (flag_H)
	{
		if (HAX <= 0.0)
			HAX = HAX + 0.0045;

		if (HAY >= 0.0)
			HAY = HAY - 0.003;
		else
		{
			flag_H = FALSE;
			flag_A = TRUE;
		}
	}

	// A R
	else if (flag_A)
	{
		if (ARX <= 0.0)
			ARX = ARX + 0.0044;

		if (ARY <= 0.0)
			ARY = ARY + 0.003;
		else
		{
			flag_A = FALSE;
		}
	}

	if (ARY >= 0.0)
		Run_jets_flag = TRUE;
	
	
}

void Start_Bharat()
{
	// Function declarations 
	void B();
	void H();
	void A1();
	void R();
	void A2();
	void T();

	void plane_anim();

	//Start_Plane();

	// Code
	glPushMatrix();
		glTranslatef(0.0, 0.0, -6.5);

		Animation();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
			glTranslatef(BTX, 0, 0);
				B();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(HAX, HAY, 0);
				H();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(ARX, ARY, 0);
				A1();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-ARX, -ARY, 0);
				R();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-HAX, -HAY, 0);
				A2();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-BTX, 0, 0);
				T();
		glPopMatrix();
	glPopMatrix();


	glPushMatrix();
		plane_anim();
	glPopMatrix();

}


void flag_Quad()
{		
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.35, 0.525);
					glVertex2f( 0.15, 0.525);
					glVertex2f( 0.15, 0.471);
					glVertex2f( 0.35, 0.471);

				glColor3f(1.0, 1.0, 1.0);        // white
					glVertex2f( 0.35, 0.471);
					glVertex2f(0.15, 0.471);
					glVertex2f(0.15, 0.418);
					glVertex2f( 0.35, 0.418);

				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f( 0.35, 0.418);
					glVertex2f(0.15, 0.418);
					glVertex2f(0.15, 0.365);
					glVertex2f( 0.35, 0.365);
			glEnd();
}

void plane_anim()
{

	// function declarations 
	
	// Code
	// varach plane 
	glPushMatrix();
		glTranslatef(x_translate_plane, 0.0, -6.4);

		glTranslatef(-1.9, 3.10, 0.0);
		glRotatef(-c_angle, 0, 0, 1);
		glTranslatef(-3.1 , 0.0, 0.0);
		glRotatef(-90, 0, 0, 1); // saral kel plane
			Start_Plane(1);
	glPopMatrix();
	
	// Khalach Plane
	glPushMatrix();
		glTranslatef(x_translate_plane, 0.0, -6.4);
		
		glTranslatef(-1.9, -3.21, 0.0);
		glRotatef(-c_angle, 0, 0, -1);
		glTranslatef(-3.1 , 0.0, 0.0);
		glRotatef(90, 0, 0, 1); // saral kel plane
			Start_Plane(3);
	glPopMatrix();

	// Middle plane 
	glPushMatrix();
		glTranslatef(translate_middle, -0.06, -6.4);
			Start_Plane(2);
	glPopMatrix();



}

void B()
{
	glPushMatrix();
		glTranslatef(-2.0, -0.5, 0.0);
			// phila vertical quad
			glBegin(GL_QUADS);
				glVertex2f(  0.15, 0.9); 
				glVertex2f( -0.10, 0.9); 
				glVertex2f( -0.10, 0.0); 
				glVertex2f(  0.15, 0.0);  
			glEnd();

			// last cha vertical quad
			glBegin(GL_QUADS);
				glVertex2f( 0.45, 0.9);
				glVertex2f( 0.35, 0.9);
				glVertex2f(0.35, 0.0);
				glVertex2f(0.45, 0.0);
			glEnd();

			// 1st horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.90);
				glVertex2f( 0.15, 0.90);
				glVertex2f( 0.15, 0.75);
				glVertex2f( 0.35, 0.75);
			glEnd();

			// 2nd horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.525);
				glVertex2f( 0.15, 0.525);
				glVertex2f( 0.15, 0.365);
				glVertex2f( 0.35, 0.365);
			glEnd();

			if(flag_1)
				flag_Quad();

			// 3rd horizontal
			glColor3f(0.5, 0.5, 0.5);
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.15);
				glVertex2f( 0.15, 0.15);
				glVertex2f( 0.15, 0.00);
				glVertex2f( 0.35, 0.00);
			glEnd();
	glPopMatrix();
}
void H()
{
	glPushMatrix();
		glTranslatef(-1.3, -0.5, 0.0);
			// phila vertical quad
			glBegin(GL_QUADS);
				glVertex2f(  0.15, 0.9); 
				glVertex2f( -0.10, 0.9); 
				glVertex2f( -0.10, 0.0); 
				glVertex2f(  0.15, 0.0);  
			glEnd();

			// last cha vertical quad
			glBegin(GL_QUADS);
				glVertex2f( 0.45, 0.9);
				glVertex2f( 0.35, 0.9);
				glVertex2f(0.35, 0.0);
				glVertex2f(0.45, 0.0);
			glEnd();

			// 2nd horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.525);
				glVertex2f( 0.15, 0.525);
				glVertex2f( 0.15, 0.365);
				glVertex2f( 0.35, 0.365);
			glEnd();

			if(flag_2)
				flag_Quad();

			glColor3f(0.5, 0.5, 0.5);
	glPopMatrix();
}
void A1()
{
	glPushMatrix();
		glTranslatef(-0.6, -0.5, 0.0);
			// phila vertical quad
			glBegin(GL_QUADS);
				glVertex2f(  0.15, 0.9); 
				glVertex2f( -0.10, 0.9); 
				glVertex2f( -0.10, 0.0); 
				glVertex2f(  0.15, 0.0);  
			glEnd();

			// last cha vertical quad
			glBegin(GL_QUADS);
				glVertex2f( 0.45, 0.9);
				glVertex2f( 0.35, 0.9);
				glVertex2f(0.35, 0.0);
				glVertex2f(0.45, 0.0);
			glEnd();

			// 1st horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.90);
				glVertex2f( 0.15, 0.90);
				glVertex2f( 0.15, 0.75);
				glVertex2f( 0.35, 0.75);
			glEnd();

			// 2nd horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.525);
				glVertex2f( 0.15, 0.525);
				glVertex2f( 0.15, 0.365);
				glVertex2f( 0.35, 0.365);
			glEnd();

			if (flag_3)
				flag_Quad();

			glColor3f(0.5, 0.5, 0.5);

	glPopMatrix();
}
void R()
{
	glPushMatrix();
		glTranslatef(0.1, -0.5, 0.0);		
			// phila vertical quad
			glBegin(GL_QUADS);
				glVertex2f(  0.15, 0.9); 
				glVertex2f( -0.10, 0.9); 
				glVertex2f( -0.10, 0.0); 
				glVertex2f(  0.15, 0.0);  
			glEnd();

			// last cha vertical quad
			glBegin(GL_QUADS);
				glVertex2f( 0.45, 0.9);
				glVertex2f( 0.35, 0.9);
				glVertex2f( 0.35, 0.365);
				glVertex2f( 0.45, 0.365);
			glEnd();

			// 1st horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.90);
				glVertex2f( 0.15, 0.90);
				glVertex2f( 0.15, 0.75);
				glVertex2f( 0.35, 0.75);
			glEnd();

			// 2nd horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.525);
				glVertex2f( 0.15, 0.525);
				glVertex2f( 0.15, 0.365);
				glVertex2f( 0.35, 0.365);
			glEnd();

			glPushMatrix();
				// Tirapi line 
				glTranslatef(0.35, -0.03, 0.0);
				glRotatef(45, 0, 0, 1);
					glBegin(GL_QUADS);
						glVertex2f(0.15, 0.44);
						glVertex2f(0.05, 0.44);
						glVertex2f(0.05, 0.0);
						glVertex2f(0.15, 0.0);
					glEnd();
			glPopMatrix();
	
			if (flag_4 )
				flag_Quad();

			glColor3f(0.5, 0.5, 0.5);

	glPopMatrix();
}
void A2()
{
	glPushMatrix();
		glTranslatef(1.4, 0.0, 0.0 );
			glTranslatef(-0.6, -0.5, 0.0);
			// phila vertical quad
			glBegin(GL_QUADS);
				glVertex2f(  0.15, 0.9); 
				glVertex2f( -0.10, 0.9); 
				glVertex2f( -0.10, 0.0); 
				glVertex2f(  0.15, 0.0);  
			glEnd();

			// last cha vertical quad
			glBegin(GL_QUADS);
				glVertex2f( 0.45, 0.9);
				glVertex2f( 0.35, 0.9);
				glVertex2f(0.35, 0.0);
				glVertex2f(0.45, 0.0);
			glEnd();

			// 1st horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.90);
				glVertex2f( 0.15, 0.90);
				glVertex2f( 0.15, 0.75);
				glVertex2f( 0.35, 0.75);
			glEnd();

			// 2nd horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.35, 0.525);
				glVertex2f( 0.15, 0.525);
				glVertex2f( 0.15, 0.365);
				glVertex2f( 0.35, 0.365);
			glEnd();


			if (flag_5 )
				flag_Quad();

			glColor3f(0.5, 0.5, 0.5);

	glPopMatrix();
}
void T()
{
	glPushMatrix();
		glTranslatef(1.25, -0.5, 0.0);
			// 1st horizontal
			glBegin(GL_QUADS);
				glVertex2f( 0.70, 0.90);
				glVertex2f( 0.15, 0.90);
				glVertex2f( 0.15, 0.75);
				glVertex2f( 0.70, 0.75);
			glEnd();

			glTranslatef(-0.05, 0.0, 0.0);
				// last cha vertical quad
				glBegin(GL_QUADS);
					glVertex2f( 0.60, 0.9);
					glVertex2f( 0.35, 0.9);
					glVertex2f( 0.35, 0.0);
					glVertex2f( 0.60, 0.0);
				glEnd();

			
			glTranslatef(0.16, 0.0, 0.0);
				glScalef(1.25, 1.0, 1.0);
					if (flag_6)
						flag_Quad();

				glColor3f(0.5, 0.5, 0.5);
	glPopMatrix();
}