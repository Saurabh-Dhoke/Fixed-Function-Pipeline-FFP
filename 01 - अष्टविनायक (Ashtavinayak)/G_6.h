
#pragma once
#include<math.h>

 
// Function Definations
void Start_G_6()
{
	fogColor[0] = 0.5;
	fogColor[1] = 0.5;
	fogColor[2] = 0.5;
	fogColor[3] = 1.0;

	glFogfv(GL_FOG_COLOR, fogColor); // Fog color 
	glFogf(GL_FOG_DENSITY, 0.005f);

	//glClearColor(0.0, 0.5, 0.5, 1.0f);

	

	// Code

	if (Map6_Flag == TRUE)
	{
		Lenyandri_61();
	}
	else if (G6_Flag == TRUE)
	{
		glEnable(GL_FOG);
		glPushMatrix();

		//-----------------------------------------------------------------
		//                Camera Animation
		//----------------------------------------------------------------

				// Flags
		static BOOL Flag_1 = TRUE;
		static BOOL Flag_2 = FALSE;
		static BOOL Flag_3 = FALSE;
		static BOOL Flag_4 = FALSE;
		static BOOL Flag_5 = FALSE;

		static float cam_x = 127.5;
		static float cam_y = -16.5;
		static float cam_z = 67.5;

		static float cam_x1 = 0.0;
		static float cam_y1 = 0.0;

		// Code

//	glTranslatef(0,-1.45, -6.85);

			//--------------------------------------------------------
			// 1
			//  X = 127.5.0  , y = -16.5 ,  z = 67.5 , x1 = 0, y1 = 0.0
			//  X = 6.0  ,               ,  z = -6.0 ,                              


		if (Flag_1 == TRUE)
		{
			if (cam_x > 6.0)
				cam_x = cam_x - 0.15;

			if (cam_y > 0.0)
				cam_y = cam_y + 0.15;

			if (cam_z > -6.0)
				cam_z = cam_z - 0.15;

			else
			{
				Flag_1 = FALSE;
				Flag_2 = TRUE;

				// Assigning Values of next camara movments 
				cam_x = 6.0;
				cam_y = 0.0;
				cam_z = -6.0;

			}
		}

		//---------------------------------------------------			
		// 2
		//  X = 6.0  , y = 0.0 ,  z = -6.0 , x1 = 0, y1 = 0.0
		//                      , z = 114 ,  

		if (Flag_2 == TRUE)
		{
			if (cam_z < 114.0)
				cam_z = cam_z + 0.25;

			else
			{
				Flag_2 = FALSE;
				Flag_3 = TRUE;

				// Assigning Values of next camara movments 

				cam_x = 3.0;
				cam_y = 6.0;
				cam_z = 138.0;
			}
		}

		////-----------------------------------------------------
		// 3
		//  X = 3.0  , y = 6.0 , z = 138 , x1 = 0.00, y1 = 0.0
		//                       z = 313.5

		if (Flag_3 == TRUE)
		{

			if (cam_z < 313.5)
				cam_z = cam_z + 0.1665;

			else
			{
				Flag_3 = FALSE;
				//Flag_4 = TRUE;

				// Assigning Values of next camara movments 
				Scene_Count = 7;
			}
		}



		//-----------------------------------------------------


		// Function Declarations 
		void G6_Temple();
		void Doar_png();


		// Code 
		gluLookAt(1392.0 + cam_x, -16.5 + cam_y, -1750.01 + cam_z, 1653.01, 0, 100, 0, 1, 0);
		//gluLookAt(1392.0+ 30 * tx, -16.5+ 30 * ty, -1750.01 + 30 * tz,1653.01, 0, 100, 0, 1, 0);
	
		//-----------------------------------------------------

		glPushMatrix();
			glColor3f(1, 1, 1);

			glTranslatef(71.299 * 20, 2.3 * 20, -47.40 * 20);
			glTranslatef(-31, -71.15, -489.55);

			glScalef(5.0, 5.0, 5.0);
			glRotatef(0, 0, 1, 0);
				G6_Temple();

			// sky 
			glPushMatrix();
				glTranslatef(31.0, 31.0, 5.0);
				glScalef(58.7, 37.2, 1.0);
				glRotatef(90, 1, 0, 0);
					Flat_Tex_Quad(G3_Sky);
			glPopMatrix();
		glPopMatrix();

		// terrain
		glPushMatrix();
			glTranslatef(-80, 19.0, -649.0);
			glTranslatef(-30.7 * 10, 10 * 10, 3.8 * 10);

			glTranslatef(702.22, -219.15, -888.49);

			glRotatef(0, 0, 1, 0);
			glBindTexture(GL_TEXTURE_2D, Texture_Terrain);

			for (int z = 0; z < TERRAIN_MAP_Z - 1; z++)
			{
				glBegin(GL_TRIANGLE_STRIP);
				for (int x = 0; x < TERRAIN_MAP_X - 1; x++)
				{
					glTexCoord2f(0.0, 0.0);
					glVertex3f(terrain_Height_Map[x][z][0], terrain_Height_Map[x][z][1], terrain_Height_Map[x][z][2]);

					glTexCoord2f(1.0, 0.0);
					glVertex3f(terrain_Height_Map[x + 1][z][0], terrain_Height_Map[x + 1][z][1], terrain_Height_Map[x + 1][z][2]);

					glTexCoord2f(0.0, 1.0);
					glVertex3f(terrain_Height_Map[x][z + 1][0], terrain_Height_Map[x][z + 1][1], terrain_Height_Map[x][z + 1][2]);

					glTexCoord2f(1.0, 1.0);
					//	glVertex3f(sin(var) * terrain_Height_Map[x+1][z + 1][0],  terrain_Height_Map[x+1][z + 1][1], cos(var) * terrain_Height_Map[x+1][z + 1][2]);
					glVertex3f(terrain_Height_Map[x + 1][z + 1][0], terrain_Height_Map[x + 1][z + 1][1], terrain_Height_Map[x + 1][z + 1][2]);
				}
				glEnd();
			}

			glBindTexture(GL_TEXTURE_2D, 0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1326.0, -33.0, -1626.0);
			glScalef(8.0 , 9.0, 1.0);
				Doar_png();
		glPopMatrix();

			// Payarya
		glPushMatrix();
			glColor3f(0.3, 0.3, 0.3);
			glTranslatef(1398.399 , -45.6 , -1650.7);
			glScalef(9.9, 1.6, 4.5);

		
				for (int i = 0; i < 5; i++)
				{
					//glColor3f(1,1,1);
					glTranslatef(0.0, 2.0, 1.1);
						Stairs_G1(G1_Stairs);
				}
		
		glPopMatrix();

	   glPopMatrix();
	  
	   glDisable(GL_FOG);

	}
}

void Doar_png()
{
	glPushMatrix();
		Color_Arr[0] = 0.4;//  color
		Color_Arr[1] = 0.4;
		Color_Arr[2] = 0.4;

		glTranslatef(9.0, 2.79 , 0.2);
		glScalef( 2.0,  2.4, 3.3);
				Load_PNG(G6_Doar, Color_Arr);
	glPopMatrix();
}



void plane_png()
{
	glPushMatrix();
		Color_Arr[0] = 0.5;//  color
		Color_Arr[1] = 0.5;
		Color_Arr[2] = 0.5;

		glTranslatef(9.0, 2.79 , 0.2);
		glScalef( 2.0,  2.4, 3.3);
				Load_PNG(G6_Png_plane, Color_Arr);
	glPopMatrix();
}

void Pillar()
{
	glPushMatrix();
		Color_Arr[0] = 0.5;//  color
		Color_Arr[1] = 0.5;
		Color_Arr[2] = 0.5;

		glTranslatef(9.0, 2.8 , 0.2);
		glScalef(1.0, 3.6, 1.0);
				Load_PNG(G6_Pillar, Color_Arr);
	glPopMatrix();

}

void Cave()
{
	// Cave Leni 
	glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		glTranslatef(0.0, -0.7, 0.75);
		glScalef(100.0, 61.0, 15.0);
		glRotatef(90, 1, 0, 0);
			Cylinder_G5(G6_Stone);
	glPopMatrix();

	// Bottom 
	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glTranslatef(0.0, 0.15, -17.5);
		glScalef(15.6, 1, 21.0);
			Flat_Tex_Quad(G6_Stone);		
	glPopMatrix();
	
	// Back Side
	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glTranslatef(0.0, 3.4,8.7);
		glScalef(15.4, 5.1, 8.1);
		glRotatef(90, 1, 0, 0);
			Flat_Tex_Quad(G6_Stone2);		
	glPopMatrix();

	// Ganpati 
	glPushMatrix();
		Color_Arr[0] = 1.0;//  color
		Color_Arr[1] = 1.0;
		Color_Arr[2] = 1.0;

		glTranslatef(0.0, 3.3, -1.0);
		glScalef(3.8, 4.1, -1.5);
				Load_PNG(G6_Ganpati, Color_Arr);
	glPopMatrix();

	// Pillars
	// left 
	glPushMatrix();
		for(int i =0; i< 4; i++)
		{
			Pillar();
			glTranslatef(0.0, 0.0, -9.0);
		}
	glPopMatrix();

	// Right
	glPushMatrix();
		glTranslatef(-18.0 , 0.0,  0.0);

		for (int i = 0; i < 4; i++)
		{
			Pillar();
			glTranslatef(0.0, 0.0, -9.0);
		}
	glPopMatrix();

	// Madhale 2
	glPushMatrix();
		glTranslatef(0.0, 0.17, -3.2);
		glScalef(1.0, 1.25, 1.0);
			
			for (int i = 0; i < 4; i++)
			{
				glPushMatrix();
					for (int i = 0; i < 2; i++)
					{
						glTranslatef(-6.0, 0.0, 0.0);
						Pillar();

					}
				glPopMatrix();

				glTranslatef(0.0, 0.0, -7.6);
			}

			glTranslatef(-8.6, -1.1, -1.4);
			plane_png();
	glPopMatrix();

	// plane png doar 
	

}

void G6_Temple()
{
	// Code 
	glPushMatrix();

		// Cave
		Cave();


	glPopMatrix();
}

void Khamb_G9()
{
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
		// Left side 
		glPushMatrix();
			glTranslatef(2.23, 1.5, -4.3);
			glScalef(0.7, 1.0, 0.4);
				Cylinder_G5(G8_Pole_Design);
		glPopMatrix();

		// Right side 
		glPushMatrix();
			glTranslatef(-2.23, 1.5, -4.3);
			glScalef(0.7, 1.0, 0.4);

				Cylinder_G5(G8_Pole_Design);
		glPopMatrix();

		// middle Left
		glPushMatrix();
			glTranslatef(0.75, 1.5, -4.3);
			glScalef(1.1 ,1.0, 1.1);
				Cylinder_G5(G8_Pole_Design);
		glPopMatrix();
		
		// Middle Right 
		glPushMatrix();
			glTranslatef(-0.75, 1.5, -4.3);
			glScalef(1.1 ,1.0, 1.1);
				Cylinder_G5(G8_Pole_Design);
		glPopMatrix();


	glPopMatrix();
}
