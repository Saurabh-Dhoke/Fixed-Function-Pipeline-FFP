
#pragma once
#include<math.h>

BOOL Map1_Flag = TRUE;
BOOL G1_Flag = FALSE; 

BOOL Map2_Flag = TRUE;
BOOL G2_Flag = FALSE;

BOOL Map3_Flag = TRUE;
BOOL G3_Flag = FALSE;

BOOL Map4_Flag = TRUE;
BOOL G4_Flag = FALSE;

BOOL Map5_Flag = TRUE;
BOOL G5_Flag = FALSE;

BOOL Map6_Flag = TRUE;
BOOL G6_Flag = FALSE;

BOOL Map7_Flag = TRUE;
BOOL G7_Flag = FALSE;

BOOL Map8_Flag = TRUE;
BOOL G8_Flag = FALSE;

BOOL Map9_Flag = TRUE;
BOOL G9_Flag = FALSE;


GLfloat Blend_M1 = 0.0f;
GLfloat Blend_M2 = 0.0f;
GLfloat Blend_M3 = 0.0f;
GLfloat Blend_M4 = 0.0f;
GLfloat Blend_M5 = 0.0f;
GLfloat Blend_M6 = 0.0f;
GLfloat Blend_M7 = 0.0f;
GLfloat Blend_M8 = 0.0f;
GLfloat Blend_M9 = 0.0f;


// Function declarations
void Start_Map_texture()
{
	// Function Declarations 
	void Morgav_11();
	void Theur_21();
	void Sidhivinayak_31();
	void Rajangav_41();
	void Ozar_51();
	void Lenyandri_61();
	void Mahad_71();
	void Pali_81();

}

void Morgav_11()
{
	// Local Variable Dclarations 
	static float x = 0.0;
	static float y = 0.0;
	static float z = -2.0;

	static float inc_x = 0.002;
	static float inc_y = 0.002;
	static float inc_z = 0.003;


	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// Animation 
	if (x <= 0.175)
		x = x + inc_x;

	if (y <= 0.085)
		y = y + inc_y;

	if (z <= -1.05)
		z = z + inc_z;
	else 					// Scene Transition 
	{
		Map1_Flag = FALSE;
		G1_Flag   = TRUE;

	}

	

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// Code

	gluLookAt(x, y, z, 0, 0, 100, 0, 1, 0);

	// blending 
	if (Blend_M1 < 1.0)
		Blend_M1 = Blend_M1 + 0.005;

	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, Blend_M1);

	glBindTexture(GL_TEXTURE_2D, M_1);
	// Front Face 
	glBegin(GL_QUADS); 
		glTexCoord2f(0.0, 0.0);
		glVertex3f(1.5, 1.0, 0.0);       // RT

		glTexCoord2f(1.0, 0.0);
		glVertex3f(-1.5, 1.0, 0.0);       // LT

		glTexCoord2f(1.0, 1.0);
		glVertex3f(-1.5, -1.0, 0.0);       // LB

		glTexCoord2f(0.0, 1.0);
		glVertex3f(1.5, -1.0, 0.0);      // RB
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);

}

void Theur_21()
{
	// Local Variable Dclarations 
	static float x_value = 0.0, y_value = 0.0;
	static float Radius = 0.3;

	static float Counter = 0.0;
	static float inc_i = 0.0;

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// Animation
	if (Counter >= 1.0)
		if (inc_i < 130)
			inc_i = inc_i + 1.0;

	if (Counter < 1.0)
		Counter = Counter + 0.4;
	else
		Counter = 0.0;

	// Scene Transition 
	if(inc_i >= 130)
	{
		Map2_Flag = FALSE;
		G2_Flag   = TRUE;
	}

	
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// Code
	gluLookAt(0.0, 0.0, -1.9, 0, 0, 100, 0, 1, 0);

	// Blending
	if (Blend_M2 < 1.0)
		Blend_M2 = Blend_M2 + 0.005;

	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, Blend_M2);

	glPushMatrix();
		//glColor3f(1.0, 1.0, 1.0);
		glLineWidth(4.0);

		glTranslatef(-0.03, 0.015, -1.05);
		glRotatef(250,0 , 1, 1);

		glBegin(GL_LINES);
		for (float i = inc_i; i > 0; i = i - 2)
			{
				x_value = 0.0 + (Radius * cos(i * (3.14 / 180)));
				y_value = 0.0 + (Radius * sin(i * (3.14 / 180)));

				glVertex2f(x_value, y_value);
			}
		glEnd();

		glLineWidth(1.0);
	glPopMatrix();


	glBindTexture(GL_TEXTURE_2D, M_2);
		// Front Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.5, 1.0, 0.0);       // RT

			glTexCoord2f(1.0, 0.0);
			glVertex3f(-1.5, 1.0, 0.0);       // LT

			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.5, -1.0, 0.0);       // LB

			glTexCoord2f(0.0, 1.0);
			glVertex3f(1.5, -1.0, 0.0);      // RB
		glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);

}

void Sidhivinayak_31()
{
	// Local Variable Dclarations 
	static float x_value = 0.0, y_value = 0.0;

	static float Counter = 0.0;
	static float inc_i = 0.0;

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// Animation
	if (Counter >= 1.0)
		if (inc_i < 180)
			inc_i = inc_i + 1.0;

	if (Counter < 1.0)
		Counter = Counter + 0.4;
	else
		Counter = 0.0;

	// Scene Transition 
	if (inc_i >= 180)
	{
		Map3_Flag = FALSE;
		G3_Flag = TRUE;
	}
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// Code
	gluLookAt(0.0, 0.0, -1.9, 0, 0, 100, 0, 1, 0);

	// Blending
	if (Blend_M3 < 1.0)
		Blend_M3 = Blend_M3 + 0.005;

	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, Blend_M3);

	glPushMatrix();
		//glColor3f(1.0, 1.0, 1.0);
		glLineWidth(4.0);

		glTranslatef(-0.055, -0.025, -0.15);

		//glTranslatef(tx, ty, tz);

		glRotatef(15,1 , 1, 1);

		glBegin(GL_LINES);
		for (float i = inc_i; i > 0; i = i - 2)
			{
				x_value = 0.0 + (0.74 * cos(i * (3.14 / 180)));
				y_value = 0.0 + (0.2 * sin(i * (3.14 / 180)));

				glVertex2f(x_value, y_value);
			}
		glEnd();

		glLineWidth(1.0);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, M_3);
		// Front Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.5, 1.0, 0.0);       // RT

			glTexCoord2f(1.0, 0.0);
			glVertex3f(-1.5, 1.0, 0.0);       // LT

			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.5, -1.0, 0.0);       // LB

			glTexCoord2f(0.0, 1.0);
			glVertex3f(1.5, -1.0, 0.0);      // RB
		glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
}

void Rajangav_41()
{
	// Local Variable Dclarations 
	static float x_value = 0.0, y_value = 0.0;
	static float Radius = 0.3;

	static float Counter = 0.0;
	static float inc_i = 0.0;

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// Animation
	if (Counter >= 1.0)
		if (inc_i < 130)
			inc_i = inc_i + 1.0;
		

	if (Counter < 1.0)
		Counter = Counter + 0.4;
	else
		Counter = 0.0;

	// Scene Transition 
	if (inc_i >= 130)
	{
		Map4_Flag = FALSE;
		G4_Flag = TRUE;
	}
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// Code
	gluLookAt(0.0, 0.0, -1.9, 0, 0, 100, 0, 1, 0);

	// Blending
	if (Blend_M4 < 1.0)
		Blend_M4 = Blend_M4 + 0.005;

	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, Blend_M4);

	glPushMatrix();
		//glColor3f(1.0, 1.0, 1.0);
		glLineWidth(4.0);

		glTranslatef(-0.050, 0.024, -0.90);
		
		glRotatef(250,0 , 1, 1);
		glRotatef(330,0 , 0, 1);

		glBegin(GL_LINES);
			for (float i = inc_i; i > 0; i = i - 2)
			{
				x_value = 0.0 + (0.35 * cos(i * (3.14 / 180)));
				y_value = 0.0 + (Radius * sin(i * (3.14 / 180)));

				glVertex2f(x_value, y_value);
			}
		glEnd();

		glLineWidth(1.0);
	glPopMatrix();


	glBindTexture(GL_TEXTURE_2D, M_4);
	// Front Face 
	glBegin(GL_QUADS); 
		glTexCoord2f(0.0, 0.0);
		glVertex3f(1.5, 1.0, 0.0);       // RT

		glTexCoord2f(1.0, 0.0);
		glVertex3f(-1.5, 1.0, 0.0);       // LT

		glTexCoord2f(1.0, 1.0);
		glVertex3f(-1.5, -1.0, 0.0);       // LB

		glTexCoord2f(0.0, 1.0);
		glVertex3f(1.5, -1.0, 0.0);      // RB
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
}

void Ozar_51()
{
	// Local Variable Dclarations 
	static float x_value = 0.0, y_value = 0.0;
	static float Radius = 0.3;

	static float Counter = 0.0;
	static float inc_i = 0.0;

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// Animation
	if (Counter >= 1.0)
		if (inc_i < 130)
			inc_i = inc_i + 1.0;
		

	if (Counter < 1.0)
		Counter = Counter + 0.4;
	else
		Counter = 0.0;

	// Scene Transition 
	if (inc_i >= 130)
	{
		Map5_Flag = FALSE;
		G5_Flag = TRUE;
	}
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// Code
	gluLookAt(0.0, 0.0, -1.9, 0, 0, 100, 0, 1, 0);

	// Blending
	if (Blend_M5 < 1.0)
		Blend_M5 = Blend_M5 + 0.005;

	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, Blend_M5);

	glPushMatrix();
		//glColor3f(1.0, 1.0, 1.0);
		glLineWidth(4.0);

		glTranslatef(0.06, 0.004, -0.94);
		
		glRotatef(250,0 , 1, 1);
		glRotatef(-329.5,1 , 0, 0);
		glRotatef(-3.5,0 , 1, 0);

		glBegin(GL_LINES);
			for (float i = inc_i; i > 0; i = i - 2)
			{
				x_value = 0.0 + (0.20 * cos(i * (3.14 / 180)));
				y_value = 0.0 + (Radius * sin(i * (3.14 / 180)));

				glVertex2f(x_value, y_value);
			}
		glEnd();

		glLineWidth(1.0);
	glPopMatrix();


	glBindTexture(GL_TEXTURE_2D, M_5);
	glBegin(GL_QUADS); 
		glTexCoord2f(0.0, 0.0);
		glVertex3f(1.5, 1.0, 0.0);       // RT

		glTexCoord2f(1.0, 0.0);
		glVertex3f(-1.5, 1.0, 0.0);       // LT

		glTexCoord2f(1.0, 1.0);
		glVertex3f(-1.5, -1.0, 0.0);       // LB

		glTexCoord2f(0.0, 1.0);
		glVertex3f(1.5, -1.0, 0.0);      // RB
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
}

void Lenyandri_61()
{
	// Local Variable Dclarations 
	static float x_value = 0.0, y_value = 0.0;
	static float Radius = 0.3;

	static float Counter = 0.0;
	static float inc_i = 0.0;

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// Animation
	if (Counter >= 1.0)
		if (inc_i < 148)
			inc_i = inc_i + 1.0;
		

	if (Counter < 1.0)
		Counter = Counter + 0.4;
	else
		Counter = 0.0;

	// Scene Transition 
	if (inc_i >= 148)
	{
		Map6_Flag = FALSE;
		G6_Flag = TRUE;
	}
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// Code
	gluLookAt(0.0, 0.0, -1.9, 0, 0, 100, 0, 1, 0);

	// Blending
	if (Blend_M6 < 1.0)
		Blend_M6 = Blend_M6 + 0.005;

	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, Blend_M6);

	glPushMatrix();
		//glColor3f(1.0, 1.0, 1.0);
		glLineWidth(4.0);

		glTranslatef(0.305, 0.085, -1.10 );
		glRotatef(42.5,1 , 0, 0);
		glRotatef(-140,0 , 1, 0);

		glBegin(GL_LINES);
			for (float i = inc_i; i > 0; i = i - 2)
			{
				x_value = 0.0 + (0.20 * cos(i * (3.14 / 180)));
				y_value = 0.0 + (Radius * sin(i * (3.14 / 180)));

				glVertex2f(x_value, y_value);
			}
		glEnd();

		glLineWidth(1.0);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, M_6);
	glBegin(GL_QUADS); 
		glTexCoord2f(0.0, 0.0);
		glVertex3f(1.5, 1.0, 0.0);       // RT

		glTexCoord2f(1.0, 0.0);
		glVertex3f(-1.5, 1.0, 0.0);       // LT

		glTexCoord2f(1.0, 1.0);
		glVertex3f(-1.5, -1.0, 0.0);       // LB

		glTexCoord2f(0.0, 1.0);
		glVertex3f(1.5, -1.0, 0.0);      // RB
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
}

void Mahad_71()
{
	// Local Variable Dclarations 
	static float x_value = 0.0, y_value = 0.0;
	static float Radius = 0.3;

	static float Counter = 0.0;
	static float inc_i = 5.0;

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// Animation
	if (Counter >= 1.0)
		if (inc_i < 115)
			inc_i = inc_i + 1.0;
		

	if (Counter < 1.0)
		Counter = Counter + 0.4;
	else
		Counter = 0.0;

	// Scene Transition 
	if (inc_i >= 115)
	{
		Map7_Flag = FALSE;
		G7_Flag = TRUE;
	}
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// Code
	gluLookAt(0.0, 0.0, -1.9, 0, 0, 100, 0, 1, 0);

	// Blending
	if (Blend_M7 < 1.0)
		Blend_M7 = Blend_M7 + 0.005;

	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, Blend_M7);

	glPushMatrix();
		//glColor3f(1.0, 1.0, 1.0);
		glLineWidth(4.0);

		glTranslatef(-0.030, 0.020, -1.3);
		glRotatef(-91.5, 1, 0, 0);
		glRotatef(-137.5, 0, 1, 0);
		glRotatef(17.5, 0, 0, 1);

		glBegin(GL_LINES);
			for (float i = inc_i; i > 0; i = i - 2)
			{
				x_value = 0.0 + (0.20 * cos(i * (3.14 / 180)));
				y_value = 0.0 + (Radius * sin(i * (3.14 / 180)));

				glVertex2f(x_value, y_value);
			}
		glEnd();

		glLineWidth(1.0);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, M_7);
	glBegin(GL_QUADS); 
		glTexCoord2f(0.0, 0.0);
		glVertex3f(1.5, 1.0, 0.0);       // RT

		glTexCoord2f(1.0, 0.0);
		glVertex3f(-1.5, 1.0, 0.0);       // LT

		glTexCoord2f(1.0, 1.0);
		glVertex3f(-1.5, -1.0, 0.0);       // LB

		glTexCoord2f(0.0, 1.0);
		glVertex3f(1.5, -1.0, 0.0);      // RB
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
}

void Pali_81()
{
	// Local Variable Dclarations 
	static float x_value = 0.0, y_value = 0.0;
	static float Radius = 0.3;

	static float Counter = 0.0;
	static float inc_i = 5.0;

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// Animation
	if (Counter >= 1.0)
		if (inc_i < 115)
			inc_i = inc_i + 1.0;
		

	if (Counter < 1.0)
		Counter = Counter + 0.4;
	else
		Counter = 0.0;

	// Scene Transition 
	if (inc_i >= 115)
	{
		Map8_Flag = FALSE;
		G8_Flag = TRUE;
	}
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// Code
	gluLookAt(0.0, 0.0, -1.9, 0, 0, 100, 0, 1, 0);

	// Blending
	if (Blend_M8 < 1.0)
		Blend_M8 = Blend_M8 + 0.005;

	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, Blend_M8);

	glPushMatrix();
		//glColor3f(1.0, 1.0, 1.0);
		glLineWidth(4.0);

		glTranslatef(0.05, 0.030, -1.1);
		glRotatef(-83.5, 1, 0, 0);
		glRotatef(-99.5, 0, 1, 0);
		glRotatef(24.0, 0, 0, 1);

		glBegin(GL_LINES);
			for (float i = inc_i; i > 0; i = i - 2)
			{
				x_value = 0.0 + (0.20 * cos(i * (3.14 / 180)));
				y_value = 0.0 + (Radius * sin(i * (3.14 / 180)));

				glVertex2f(x_value, y_value);
			}
		glEnd();

		glLineWidth(1.0);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, M_8);
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.5, 1.0, 0.0);       // RT

			glTexCoord2f(1.0, 0.0);
			glVertex3f(-1.5, 1.0, 0.0);       // LT

			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.5, -1.0, 0.0);       // LB

			glTexCoord2f(0.0, 1.0);
			glVertex3f(1.5, -1.0, 0.0);      // RB
		glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
}

void AanadAshram_91()
{
	// Local Variable Dclarations 
	static float x_value = 0.0, y_value = 0.0;

	static float Counter = 0.0;
	static float inc_i = 0.0;

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// Animation
	if (Counter >= 1.0)
		if (inc_i < 180)
			inc_i = inc_i + 1.0;

	if (Counter < 1.0)
		Counter = Counter + 0.37;
	else
		Counter = 0.0;

	// Scene Transition 
	if (inc_i >= 180)
	{
		Map9_Flag = FALSE;
	}
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// Code
	gluLookAt(0.0, 0.0, -1.9, 0, 0, 100, 0, 1, 0);

	// Blending
	if (Blend_M9 < 1.0)
		Blend_M9 = Blend_M9 + 0.005;

	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, Blend_M9);

	glPushMatrix();
		//glColor3f(1.0, 1.0, 1.0);
		glLineWidth(4.0);

		glTranslatef(-0.085, 0.1, -0.065);

		//glTranslatef(tx, ty, tz);

		glRotatef(3.9,1 , 1, 1);

		glBegin(GL_LINES);
		for (float i = inc_i; i > 0; i = i - 2)
			{
				x_value = 0.0 + ( 0.55 * cos(i * (3.14 / 180)));
				y_value = 0.0 + ( 0.20 * sin(i * (3.14 / 180)));

				glVertex2f(x_value, y_value);
			}
		glEnd();

		glLineWidth(1.0);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, M_9);
		// Front Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.5, 1.0, 0.0);       // RT

			glTexCoord2f(1.0, 0.0);
			glVertex3f(-1.5, 1.0, 0.0);       // LT

			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.5, -1.0, 0.0);       // LB

			glTexCoord2f(0.0, 1.0);
			glVertex3f(1.5, -1.0, 0.0);      // RB
		glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
}
