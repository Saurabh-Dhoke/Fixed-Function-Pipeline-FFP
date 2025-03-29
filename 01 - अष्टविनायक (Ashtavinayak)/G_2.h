
#pragma once
#include<math.h>

// Function Definations
void Start_G_2()
{
	fogColor[0] = 0.5;
	fogColor[1] = 0.5;
	fogColor[2] = 0.5;
	fogColor[3] = 1.0;

	glFogfv(GL_FOG_COLOR, fogColor); // Fog color 
	glFogf(GL_FOG_DENSITY, 0.3f);
	glClearColor(0.75, 0.75, 0.75, 1.0f);


	static float Angle = 0;

	// Flags
	static BOOL Flag_1 = TRUE; 
	static BOOL Flag_2 = FALSE;
	static BOOL Flag_3 = FALSE;
	static BOOL Flag_4 = FALSE;
	static BOOL Flag_5 = FALSE;

	static float cam_x = 0.90;
	static float cam_y = 0.20;
	static float cam_z = -2.35; 

	
	// Function Declarations 
	void G2_Temple();

	// Code

	if (Map2_Flag == TRUE)
	{
		Theur_21();
	}
	else if (G2_Flag == TRUE)
	{
		glPushMatrix();
			glEnable(GL_FOG);
	
			glTranslatef(0,-1.45, -6.85);

		//------------------------
		// Camera Animation
	
		//---------------------------------------
		// 1 tirapa maghun pudh 
		//  X = 0.9  , y = 0.2 , z = -2.350
		//  X = -1.5  , y = 0.2, z = 3.150 
	
			/*static float cam_x = 0.90;
			static float cam_y = 0.20;
			static float cam_z = -2.35;*/

			if (Flag_1 == TRUE)
			{
				if (cam_x > -1.5)
					cam_x = cam_x - 0.005;

				if (cam_z < 3.15)
					cam_z = cam_z + 0.01; 
				else
				{
					Flag_1 = FALSE;
					Flag_2 = TRUE;
			    
					// Assigning Values of next camara movments 
					cam_x = -1.5;
					cam_y = 0.2;
					cam_z = 3.15;
				}
			}
				

		//  X = -1.5  , y = 0.2, z = 3.150 
		//  X = 0.0  , y = -0.15 , z = 9.25

			// gate var aat ganpati kad 
			if (Flag_2 == TRUE)
			{

				if (cam_x < 0.0)
					cam_x = cam_x + 0.005;

				if (cam_y > -0.15)
					cam_y = cam_y - 0.002;
			
				if (cam_z < 7.85)
					cam_z = cam_z + 0.01;
				else
				{
					Flag_2 = FALSE;
					Flag_3 = TRUE;
				}
			}

		// Khalun Var ganpati var 
			if (Flag_3 == TRUE)
			{
			   if(cam_y < 0.50 ) 
					cam_y = cam_y + 0.003;
			   else
			   {
				   Flag_3 = FALSE;
				   Flag_4 = TRUE;
			   }
			}

		// Vartun Khali
			if (Flag_4 == TRUE)
			{
				if (cam_y > 0.0)
					cam_y = cam_y - 0.003;
				else
				{
					Flag_4 = FALSE;
					Flag_5 = TRUE;

					// Assigning Values of next camara movments 
					cam_x = 0.0;
					cam_y = -0.15;
					cam_z = 9.25;
				}
			}
		//----------------------------------------
		// (2) Aaatun Baher 
		//  X = 0.0  , y = -0.15 , z = 9.25
		//  X = -0.8  , y = -1.0, z = -1.2 

			if (Flag_5 == TRUE)
			{
				if (cam_y > -1.0)
					cam_y = cam_y - 0.002;

				if (cam_z >= -1.2)
					cam_z = cam_z - 0.0155;
				else
				{
					Flag_5 = FALSE;
					Scene_Count = 3;
				}
			}


			// Fog Disable when camera on ganpati
			if (cam_z >= 7.4)
				glDisable(GL_FOG);
			else
				glEnable(GL_FOG);

			//-----------------------

			//glDisable(GL_FOG);

			//gluLookAt(tx, ty, tz, 0, 0, 100, 0, 1, 0);
			gluLookAt(cam_x, cam_y, cam_z, 0, 0, 100, 0, 1, 0);

			G2_Temple();

			// Har 
			glPushMatrix();
				glTranslatef(0.04, 1.4, 1.89);
				glScalef(0.6, 0.5, 1.0);
					Load_Har(Har5);
			glPopMatrix();

			// Ghanta 
			glPushMatrix();
				Color_Arr[0] = 0.5;//  color
				Color_Arr[1] = 0.5;
				Color_Arr[2] = 0.5;

				glTranslatef(0.0, 2.12, 0.0);
				glScalef(0.11 ,0.79, 1.0);
					//Load_Har(Ghanta2);
					Load_PNG(Ghanta2, Color_Arr);

			glPopMatrix();

			//Rangoli
			glPushMatrix();
				Color_Arr[0] = 1;//  color
				Color_Arr[1] = 1;
				Color_Arr[2] = 1;
			
					glTranslatef(0,-0.76, -1.1);
					glRotatef(90, 1, 0, 0);
						Load_PNG(Rangoli6, Color_Arr);
			glPopMatrix();


			// Bench an danpeti 
			glPushMatrix();
				// Right danpeti 
				glPushMatrix();
					glTranslatef(-0.7,0.45, 0.6);
					glScalef(0.3,0.6, 0.4);
						glColor3f(0.4, 0.4, 0.4);
						Danpeti1();
				glPopMatrix();
				
				//left danpeti 
				glPushMatrix();
					glTranslatef(0.7,0.45, 0.6);
					glScalef(0.3,0.6, 0.4);
						glColor3f(0.4, 0.4, 0.4);
						Danpeti1();
				glPopMatrix();

				//left Bench 
				glPushMatrix();
					glColor3f(1, 1, 1);
					glTranslatef(3.1,-0.4,-5.0);
					glRotatef(90, 0, 1, 0);
					glScalef(3.2, 0.9,0.7);
						Marbal_Chair(G1_FDesign);
				glPopMatrix();

				// right bench 
				glPushMatrix();
					glColor3f(1, 1, 1);
					glTranslatef(-3.1,-0.4,-6.2);
					glRotatef(-90, 0, 1, 0);
					glScalef(3.2, 0.9,0.7);
						Marbal_Chair(G1_FDesign);
				glPopMatrix();
			glPopMatrix();

		glPopMatrix();
	}

	glDisable(GL_FOG);


}

void G2_Temple()
{
	// Function Declarations 
	void Shed_G2();
	void Shed_Base_G2(GLuint); 
	void Mandir_G2();
	void Temple_Base_G2();

	// Code


	//glTranslatef(tx, ty, tz);
	//glScalef(sx, sy, sz);

	
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		// Payarya middle 
		glTranslatef(0.0, -0.10, -3.95);
		glScalef(0.76,0.05,0.2);
			for (int i = 0; i < 3; i++)
			{
				glColor3f(1,1,1);
				glTranslatef(0.0, 2.0, 1.1);
				Stairs_G1(G1_Stone);
			}
	glPopMatrix();
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	glPushMatrix();
		
		glColor3f(1,1,1);
			/*glTranslatef(tx, ty, tz);
			glScalef(sx,sy,sz);*/
					
		// Base 
		glPushMatrix();
			glTranslatef(0.0, 0.0, 0.0);
			glScalef(2.0, 0.2, 3.0);
				Temple_Base_G2();
		glPopMatrix();


		// SIde Kathade
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(1.9,0.7, -1.0);
			glScalef(0.1, 1.0, 2.0);
					Base_G1(G2_Brick_3);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.9, 0.7, -1.0);
			glScalef(0.1, 1.0, 2.0);
					Base_G1(G2_Brick_3);
		glPopMatrix();


		// Front kathade
		glPushMatrix();
			glTranslatef(1.3, -0.2, -2.9);
			glScalef(0.5, 0.7, 0.1);
					Base_G1(G2_Brick_3);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.3, -0.2, -2.9);
			glScalef(0.5, 0.7, 0.1);
					Base_G1(G2_Brick_3);
		glPopMatrix();

		// Side Bar 
		glPushMatrix();
			// Left 
			glPushMatrix();
				glColor3f(0.5, 0.5, 0.5);
				// 1
				glTranslatef(0.9, 1.4, -2.9);
				glScalef(0.15, 1.8, 0.15);
						Base_G1(G1_Stairs);
				//2
				glTranslatef(6.9,0.0, 0.0);
						Base_G1(G1_Stairs);
				// 3
				glTranslatef(-0.4,0.0, 12.60);
						Base_G1(G1_Stairs);
				//4
				glTranslatef(-0.3,0.0, 12.60);
						Base_G1(G1_Stairs);
			glPopMatrix();

			// Right side
			glPushMatrix();
				// 1
				glTranslatef(-0.9, 1.4, -2.9);
				glScalef(0.15, 1.8, 0.15);
						Base_G1(G1_Stairs);
				//2
				glTranslatef(-6.9,0.0, 0.0);
						Base_G1(G1_Stairs);
				// 3
				glTranslatef(0.4,0.0, 12.60);
						Base_G1(G1_Stairs);
				//4
				glTranslatef(0.3,0.0, 12.60);
						Base_G1(G1_Stairs);
			glPopMatrix();
		glPopMatrix();

		// Slap 
		glPushMatrix();
			glColor3f(0.38, 0.17, 0.14);
			glTranslatef(0.0, 2.8, -1.0);
			glScalef(2.2, 0.4, 2.2);
					Base_G1(G1_Wood);
		glPopMatrix();

		// Mandir
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(0.0, 1.69, 2.0);
			glScalef(2.0,1.5, 1.0);
					Mandir_G2();
		glPopMatrix();
	glPopMatrix();

	// Shead
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(0.0,0.3,-0.7);
					Shed_G2();

					glColor3f(1, 1, 1);
					Shed_Base_G2(G2_Soil);
		glPopMatrix();




}

void Shed_Base_G2(GLuint texture)
{
	glPushMatrix();
			glTranslatef(0.0, 1.2, -4.5);
			glTranslatef(0.0, -3.55, 0.20);
			glScalef(2.0, 2.0, 2.0);

				glBindTexture(GL_TEXTURE_2D, texture); 
					// Tiles 
					glBegin(GL_QUADS); 
						glTexCoord2f(0.0, 0.0);
						glVertex3f( 1.0,  1.0, -1.0);    // right top

						glTexCoord2f(2.0, 0.0);
						glVertex3f(-1.0,  1.0, -1.0);    // left top	

						glTexCoord2f(2.0, 2.0);
						glVertex3f(-1.0,  1.0,  1.0);    // left bottom

						glTexCoord2f(0.0, 2.0);
						glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
					glEnd(); 
				glBindTexture(GL_TEXTURE_2D, 0);

		glPopMatrix();

}
void Shed_Khamb( )
{
	// Code
	
	glPushMatrix();
		glColor3f(0.1, 0.0, 0.0);
		
		glTranslatef(1.5,-0.55, 0.8);
		glScalef(0.05, 1.2, 0.05);

			// 3D Cube
			// Front Face 
			glBegin(GL_QUADS); 
				glVertex3f(1.0, 1.0, 1.0);     // right top
				glVertex3f(-1.0, 1.0, 1.0);    // left top	 
				glVertex3f(-1.0, -1.0 , 1.0);  // left bottom
				glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
			glEnd();

			// Right Face 
			glBegin(GL_QUADS); 
				glVertex3f(1.0,  1.0, -1.0);    // right top
				glVertex3f(1.0,  1.0,  1.0);    // left top	 
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();

			// Back Face 
			glBegin(GL_QUADS); 
				glVertex3f(-1.0,  1.0, -1.0);    // right top
				glVertex3f( 1.0,  1.0, -1.0);    // left top	 
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			glEnd(); 

			// Left Face 
			glBegin(GL_QUADS); 
				glVertex3f(-1.0,  1.0, 1.0);    // right top
				glVertex3f(-1.0,  1.0, -1.0);    // left top	 
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

			// Top Face 
			glBegin(GL_QUADS); 
				glVertex3f( 1.0,  1.0, -1.0);    // right top
				glVertex3f(-1.0,  1.0, -1.0);    // left top	 
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 

			// Bottom Face 
			glBegin(GL_QUADS); 
				glVertex3f( 1.0, -1.0, -1.0);    // right top
				glVertex3f(-1.0, -1.0, -1.0);    // left top	 
				glVertex3f(-1.0, -1.0,  1.0);    // left bottom
				glVertex3f( 1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 
			
	glPopMatrix();

}
void Shed_G2()
{
	// Code
	glPushMatrix();
		glTranslatef(0.0, 1.2, -4.5);
		
		glBindTexture(GL_TEXTURE_2D, G2_Roof);
		glPushMatrix();
			// Right Face 
			glTranslatef(0.48, 0.0, 0.0);
			glRotatef(65, 0, 0, 1);
					glBegin(GL_QUADS); 
						glTexCoord2f(0.0, 0.0);
						glVertex3f(1.0,  1.0, -2.0);    // right top

						glTexCoord2f(2.0, 0.0);
						glVertex3f(1.0,  1.0,  2.0);    // left top	 

						glTexCoord2f(2.0, 2.0);
						glVertex3f(1.0, -1.0 , 2.0);    // left bottom

						glTexCoord2f(0.0, 2.0);
						glVertex3f(1.0, -1.0 , -2.0);   // right bottom
					glEnd();
		glPopMatrix();

		glPushMatrix();
			// Left Face 
			glTranslatef(-0.48, 0.0, 0.0);
			glRotatef(-65, 0, 0, 1);

				glBegin(GL_QUADS); 
					glTexCoord2f(0.0, 0.0);
					glVertex3f(-1.0,  1.0, 2.0);    // right top

					glTexCoord2f(2.0, 0.0);
					glVertex3f(-1.0,  1.0, -2.0);    // left top	 

					glTexCoord2f(2.0, 2.0);
					glVertex3f(-1.0, -1.0, -2.0);    // left bottom

					glTexCoord2f(0.0, 2.0);
					glVertex3f(-1.0, -1.0 , 2.0);   // right bottom
				glEnd(); 
		glPopMatrix();
		glBindTexture(GL_TEXTURE_2D, 0);

		
		glPushMatrix();
				Shed_Khamb();

			glTranslatef(0.0, 0.0, -2.0);
				Shed_Khamb();
			
			glTranslatef(-3.0,0.0, 0.0);
				Shed_Khamb();
			
			glTranslatef(0.0, 0.0, 2.0);
				Shed_Khamb();

		glPopMatrix();
	glPopMatrix();

}

void Temple_Base_G2()
{
	// Code
	
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, G2_Brick_3);

			//// Front Face 
			//glBegin(GL_QUADS); 
			//glTexCoord2f(0.0, 0.5);
			//	glVertex3f(-1.0,  1.0, -1.0);    // right top

			//	glTexCoord2f(1.0, 0.0);
			//	glVertex3f( 1.0,  1.0, -1.0);    // left top	 

			//	glTexCoord2f(1.0, 0.5);
			//	glVertex3f( 1.0, -1.0, -1.0);    // left bottom

			//	glTexCoord2f(0.0, 1.0);
			//	glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			//glEnd(); 

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

		glBindTexture(GL_TEXTURE_2D, 0);

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
void Mandir_G2()
{
	// Code 
	

	glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, G2_Brick_2);

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
			glBindTexture(GL_TEXTURE_2D, G2_Ganpati);

			glTranslatef(0.0, -0.1, 1.7);
			glScalef(0.9, 0.9, 1.0);

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

		Doar_2(G2_Brick_2);
	glPopMatrix();

}
