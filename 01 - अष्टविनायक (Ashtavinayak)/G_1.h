
#pragma once
#include<math.h>

GLfloat Color_Arr[3];


// Function Definations
void Start_G_1()
{
	glFogf(GL_FOG_DENSITY, 0.4f);
	glEnable(GL_FOG);


	static float Angle = 0;

	static float cam_x = 0;
	static float cam_y = -1.85;
	static float cam_z = 1.10;
	
	// Function Declarations 
	void G1_Temple();
	void Environment_G1();
//	void Load_Har(GLuint texture);
	//void Load_PNG(GLuint texture, GLfloat Color_Arr[]);

	// Code

	glPushMatrix();
		
		if (Map1_Flag == TRUE)
		{
			glDisable(GL_FOG);
			Morgav_11();
		}
		else if (G1_Flag == TRUE)
		{
			glEnable(GL_FOG);

			glTranslatef(0,-1.45, -6.85);

		//------------------------------------------------------------
			// x = 0, y = -1.850, z = 1.100  start
			// x = 0, y = -0.250, z = 2.750   gate 
			// x = 0, y = -0.350, z = 7.600   end

			if (cam_y < -0.350)
				cam_y = cam_y + 0.0025;
			/*else if(cam_y > -0.350)
				cam_y = cam_y - 0.01;*/

			if (cam_z < 2.750)
				cam_z = cam_z + 0.004;
			else if(cam_z <= 8.70)
				cam_z = cam_z + 0.0085;

			// Fog Disable when camera on ganpati
			if (cam_z >= 6.85)
				glDisable(GL_FOG);

			if (cam_z >= 8.69)
			{
				Scene_Count = 2;
			}
  
			gluLookAt(cam_x, cam_y,  cam_z, 0, 0, 100, 0, 1, 0);
			//gluLookAt(tx, ty, tz, 0, 0, 100, 0, 1, 0);
		//------------------------------------------------------------

			// Temple
			G1_Temple();

			// Har 
			glPushMatrix();
				glTranslatef(0.04, 1.4, 1.9);
				glScalef(0.6, 0.5, 1.0);
					Load_Har(Har2);
			glPopMatrix();

			// Ghanta 
			glPushMatrix();
			Color_Arr[0] = 0.5;//  color
			Color_Arr[1] = 0.5;
			Color_Arr[2] = 0.5;
			
				glTranslatef(0.0, 1.44, 0.0);
				glScalef(0.1, 0.33, 1.0);
					Load_PNG(Ghanta, Color_Arr);

			glPopMatrix();

			//Rangoli
			glPushMatrix();
				Color_Arr[0] = 0.5;//  color
				Color_Arr[1] = 0.5;
				Color_Arr[2] = 0.5;
					
					glTranslatef(0,-0.59, -1.1);
					glRotatef(90, 1, 0, 0);
						Load_PNG(G8_Rangoli1, Color_Arr);
			glPopMatrix();

			glDisable(GL_FOG);

		}

	glPopMatrix();
}
//
//
//void Load_PNG(GLuint texture, GLfloat Color_Arr[])
//{
//	glPushMatrix();
//				glBindTexture(GL_TEXTURE_2D, texture);
//
//				glDisable(GL_DEPTH);
//				glEnable(GL_BLEND);
//
//					glColor4f(1.0, 1.0,1.0, 0.5);   // For Transperancy 
//					glColor3fv(Color_Arr);       
//
//
//					// Front Face 
//					glBegin(GL_QUADS); 
//						glTexCoord2f(0.0, 0.0);
//						glVertex3f(-1.0,  1.0, -1.0);    // right top
//
//						glTexCoord2f(1.0, 0.0);
//						glVertex3f( 1.0,  1.0, -1.0);    // left top	 
//
//						glTexCoord2f(1.0, 1.0);
//						glVertex3f( 1.0, -1.0, -1.0);    // left bottom
//
//						glTexCoord2f(0.0, 1.0);
//						glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
//					glEnd(); 
//
//				glDisable(GL_BLEND);
//				glEnable(GL_DEPTH);
//				glBindTexture(GL_TEXTURE_2D, 0);
//
//		glPopMatrix();
//}
//
//void Load_Har(GLuint texture)
//{
//	glPushMatrix();
//		Color_Arr[0] = 1;//  color
//		Color_Arr[1] = 1;
//		Color_Arr[2] = 1;
//
//				Load_PNG(texture, Color_Arr);
//	glPopMatrix();
//}


void Doar_Khamb(GLuint texture)
{
	// Code
	
	glPushMatrix();		
		glTranslatef(1.5,-0.55, 0.8);
		glScalef(0.05, 1.2, 0.05);

		glBindTexture(GL_TEXTURE_2D, texture);


		// 3D Cube
		// Front Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.0, 1.0, 1.0);     // right top
	
			glTexCoord2f(1.0, 0.0);
			glVertex3f(-1.0, 1.0, 1.0);    // left top	
		
			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.0, -1.0 , 1.0);  // left bottom
		
			glTexCoord2f(0.0, 1.0);
			glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
		glEnd();

		// Right Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.0,  1.0, -1.0);    // right top

			glTexCoord2f(1.0, 0.0);
			glVertex3f(1.0,  1.0,  1.0);    // left top	 

			glTexCoord2f(1.0, 1.0);
			glVertex3f(1.0, -1.0 , 1.0);    // left bottom

			glTexCoord2f(0.0, 1.0);
			glVertex3f(1.0, -1.0 , -1.0);   // right bottom
		glEnd();

		// Back Face 
		glBegin(GL_QUADS); 
		glTexCoord2f(0.0, 0.0);
			glVertex3f(-1.0,  1.0, -1.0);    // right top

			glTexCoord2f(1.0, 0.0);
			glVertex3f( 1.0,  1.0, -1.0);    // left top	 

			glTexCoord2f(1.0, 1.0);
			glVertex3f( 1.0, -1.0, -1.0);    // left bottom

			glTexCoord2f(0.0, 1.0);
			glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
		glEnd(); 

		// Left Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(-1.0,  1.0, 1.0);    // right top

			glTexCoord2f(1.0, 0.0);
			glVertex3f(-1.0,  1.0, -1.0);    // left top	 

			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.0, -1.0, -1.0);    // left bottom

			glTexCoord2f(0.0, 1.0);
			glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
		glEnd(); 

		// Top Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f( 1.0,  1.0, -1.0);    // right top

			glTexCoord2f(1.0, 0.0);
			glVertex3f(-1.0,  1.0, -1.0);    // left top	

			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.0,  1.0,  1.0);    // left bottom

			glTexCoord2f(0.0, 1.0);
			glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
		glEnd(); 

		// Bottom Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f( 1.0, -1.0, -1.0);    // right top

			glTexCoord2f(1.0, 0.0);
			glVertex3f(-1.0, -1.0, -1.0);    // left top	

			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.0, -1.0,  1.0);    // left bottom

			glTexCoord2f(0.0, 1.0);
			glVertex3f( 1.0, -1.0 , 1.0);   // right bottom
		glEnd(); 

	glBindTexture(GL_TEXTURE_2D, 0);


			
	glPopMatrix();

}

void Doar(GLuint texture)
{
	// Doar
		glPushMatrix();
			glTranslatef(-0.7, -0.2, 0.2);
			glScalef(1.2, 0.5, 0.8);
			glRotatef(90, 0, 1, 0);
				Doar_Khamb(texture);

			glTranslatef(0.0, 0.0, -0.4);
				Doar_Khamb(texture);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-0.12, -1.25, -1.65);
			glScalef(0.25, 0.9, 0.8);
			glRotatef(90, 0, 0, 1);
				Doar_Khamb(texture);

			glTranslatef(-1.05, 0 , 0);
				Doar_Khamb(texture);
		glPopMatrix();
}
void Doar_2(GLuint texture)
{
	// Doar
		glPushMatrix();
			glTranslatef(-0.7, -0.2, 0.2);
			glScalef(1.2, 0.5, 0.8);
			glRotatef(90, 0, 1, 0);
				Doar_Khamb(texture);

			glTranslatef(0.0, 0.0, -0.4);
				Doar_Khamb(texture);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-0.12, -1.25, -1.7);
			glScalef(0.25, 0.9, 0.8);
			glRotatef(90, 0, 0, 1);
				Doar_Khamb(texture);

			glTranslatef(-1.2, 0 , 0);
				Doar_Khamb(texture);
		glPopMatrix();
}

void G1_Temple()
{
	// Function Declarations 
	void Stairs_G1(GLuint);
	void Base_G1(GLuint);
	void Mandir_G1();
	void Temple_Base_G1();

	// Code


	//glTranslatef(tx, ty, tz);
	//glScalef(sx, sy, sz);

	
	glColor3f(0.5, 0.5, 0.5);

	glPushMatrix();
		glTranslatef(0.0, -0.75, -5.4);
		glScalef(0.76,0.05,0.2);
		
			for (int i = 0; i < 11; i++)
			{
				glColor3f(1,1,1);
				glTranslatef(0.0, 2.0, 1.0);
					Stairs_G1(G1_Stairs);
			}
	glPopMatrix();

	glPushMatrix();
		
		glColor3f(1,1,1);
			/*glTranslatef(tx, ty, tz);
			glScalef(sx,sy,sz);*/

			
		// Base 
		glPushMatrix();
			//glColor3f(0.25, 0.25, 0.25);
			glTranslatef(0.0, 0.0, 0.0);
			glScalef(2.0, 0.4, 3.0);
				Temple_Base_G1();
		glPopMatrix();

		// SIde Kathade
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(1.9,0.7, -1.0);
			glScalef(0.1, 0.3, 2.0);
					Base_G1(G1_Stone);
		glPopMatrix();
		glPushMatrix();
			//glColor3f(1, 1, 0);
			glTranslatef(-1.9, 0.7, -1.0);
			glScalef(0.1, 0.3, 2.0);
					Base_G1(G1_Stone);
		glPopMatrix();

		// Front kathade
		glPushMatrix();
			//glColor3f(0, 1, 1);
			glTranslatef(1.3, 0.7, -2.9);
			glScalef(0.5, 0.3, 0.1);
					Base_G1(G1_Stone);
		glPopMatrix();
		glPushMatrix();
			//glColor3f(0, 1, 1);
			glTranslatef(-1.3, 0.7, -2.9);
			glScalef(0.5, 0.3, 0.1);
					Base_G1(G1_Stone);
		glPopMatrix();

		// Side Bar 
		glPushMatrix();
			// Left 
			glPushMatrix();
				glColor3f(0.5, 0.5, 0.5);
				glTranslatef(0.9, 1.8, -2.9);
				glScalef(0.05, 0.8, 0.05);
						Base_G1(G1_Stairs);
				
				glTranslatef(19.9,0.0, 0.0);
						Base_G1(G1_Stairs);

				glTranslatef(0.0,0.0, 36.40);
				glScalef(1.0, 1.38, 1.0);

						Base_G1(G1_Stairs);
			glPopMatrix();

			// Right
			glPushMatrix();
				glColor3f(0.5, 0.5, 0.5);
				glTranslatef(-0.9, 1.8, -2.9);
				glScalef(0.05, 0.8, 0.05);
						Base_G1(G1_Stairs);
				
				glTranslatef(-19.9,0.0, 0.0);
						Base_G1(G1_Stairs);

				glTranslatef(0.0,0.0, 36.40);
				glScalef(1.0, 1.38, 1.0);

						Base_G1(G1_Stairs);
			glPopMatrix();
		glPopMatrix();

		// Slap 
		glPushMatrix();
		glColor3f(0.25, 0.25, 0.25);
		glTranslatef(0.0, 2.6, -1.0);
			glScalef(2.0, 0.3, 2.0);
					Base_G1(G1_Wood);
		glPopMatrix();

		// Mandir
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(0.0, 1.7, 2.0);
			glScalef(2.0,1.5, 1.0);
					Mandir_G1(G1_Stairs);
		glPopMatrix();
	glPopMatrix();

}

void Stairs_G1(GLuint texture)
{
	// Code
	
	glBindTexture(GL_TEXTURE_2D, texture);

	glPushMatrix();
			// Right Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0,  1.0,  1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();


			glColor3f(0.25,0.25,0.25);
			// Front Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 2.0);
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			glEnd(); 

			glColor3f(1,1,1);
			// Left Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, 1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

			// Top Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 

	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

}
void Base_G1(GLuint G1_Texture)
{
	// Code
	
	glTranslatef(0.0, 0.0, 0.01);
	glScalef(1.05, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, G1_Texture);

	glPushMatrix();

			// 3D Cube
			// Back Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);

				glVertex3f(1.0, 1.0, 1.0);     // right top
	
				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);    // left top	
		
				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);  // left bottom
		
				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
			glEnd();

			// Right Face 
			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0,  1.0,  1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();

			// Front Face 
			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			glEnd(); 

			// Left Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, 1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

			// Top Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 
			glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

}

void Base_G1_C(GLuint G1_Texture)
{
	// Code
	
	glTranslatef(0.0, 0.0, 0.01);
	glScalef(1.05, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, G1_Texture);

	glPushMatrix();

			// 3D Cube
			// Back Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);

				glVertex3f(1.0, 1.0, 1.0);     // right top
	
				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);    // left top	
		
				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);  // left bottom
		
				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
			glEnd();

			// Right Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0,  1.0,  1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();

			// Front Face 
			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			glEnd(); 

			// Left Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, 1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

			// Top Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(0.05, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(0.05, 0.05);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 0.05);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 
			glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

}

void Temple_Base_G1()
{
	// Code
	

	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, G1_Stone);

			// Front Face 
			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // right top

				glTexCoord2f(2.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(2.0, 2.0);
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 2.0);
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			glEnd(); 
		glBindTexture(GL_TEXTURE_2D, 0);

			// Right Face 
			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0,  1.0,  1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();

			// Left Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, 1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

		glBindTexture(GL_TEXTURE_2D, G1_FDesign);
			// Top Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 
		glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

}

void Mandir_G1()
{
	// Code 
	glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, G1_Bricks);

			// Back Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0, 1.0, 1.0);     // right top
	
				glTexCoord2f(2.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);    // left top	
		
				glTexCoord2f(2.0, 2.0);
				glVertex3f(-1.0, -1.0 , 1.0);  // left bottom
		
				glTexCoord2f(0.0, 2.0);
				glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
			glEnd();

			// Right Face 
			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0,  1.0,  1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();
			
			// Left Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, 1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

			// Top Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 

			// Bottom Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0, -1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

			// Front Walll
		glPushMatrix();
			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  0.1, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f( -0.2,  0.1, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f( -0.2, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			glEnd(); 

			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
				glVertex3f(0.2,  0.1, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f( 1.0,  0.1, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(0.2, -1.0 , -1.0);   // right bottom
			glEnd(); 

			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f( 1.0,  0.1, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0,  0.1 , -1.0);   // right bottom
			glEnd(); 

		glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);


		glPushMatrix();
			glColor3f(1, 1, 1);
			glBindTexture(GL_TEXTURE_2D, G1_Ganpati);

			glTranslatef(0.0, -0.5, 1.0);
			glRotatef(10, 1, 0, 0);
			glScalef(0.5, 0.6, 1.0);

				// Back Face 
				glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
					glVertex3f(-1.0,  1.0, -1.0);    // right top

					glTexCoord2f(1.0, 0.0);
					glVertex3f( 1.0,  1.0, -1.0);    // left top	 

					glTexCoord2f(1.0, 1.0);
					glVertex3f( 1.0, -1.0, -1.0);    // left bottom

					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
				glEnd(); 
			glBindTexture(GL_TEXTURE_2D, 0);	
		glPopMatrix();

		// Doar 
		glColor3f(0.5, 0.5, 0.5);
		Doar(G1_Stairs);
		
		glColor3f(1, 1, 1);
	glPopMatrix();
}
