
#pragma once
#include<math.h>

GLfloat Z_8 = 0.0f;
GLfloat G8_Angle = 0.0f;

// Function Definations
void Start_G_8()
{
	fogColor[0] = 0.3;
	fogColor[1] = 0.3;
	fogColor[2] = 0.31;
	fogColor[3] = 1.0;

	glFogfv(GL_FOG_COLOR, fogColor); // Fog color 
	glFogf(GL_FOG_DENSITY, 0.050f);

	// Function Declarations 
	void G8_Temple();
	void Environment_G8();
	void SabhaMandap_G8();
	void Gate_G8();

	// Code

	if (Map8_Flag == TRUE)
	{
		Pali_81();
	}
	else if (G8_Flag == TRUE)
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
						
			static float cam_x = 0.0;
			static float cam_y = 6.5;
			static float cam_z = -31.75;
			static float cam_x1 = 0.0;
			static float cam_y1 = 0.0;

			// Code

			glTranslatef(0,-1.45, -6.85);

			//---------------------------------------------------			
			// 1
			//  X = 0.0  , y = 6.5 ,  z = -31.75 , x1 = 0, y1 = 0.0
			//             y = -0.25, z =   6.25  ,  
			if (Flag_1 == TRUE)
				{
					if (cam_y > -0.25)
						cam_y = cam_y - 0.028;

					if (cam_z < 0.0)
						cam_z = cam_z + 0.12; 
					
					else if(cam_z < 6.25)
						cam_z = cam_z + 0.04;

					else
					{
						Flag_1 = FALSE;
						Flag_2 = TRUE;
					    
						// Assigning Values of next camara movments 
						cam_x = 0.5;
						cam_y = 1.45;
						cam_z = -4.0;

						cam_x1 = -155.0;
						cam_y1 = -0.5;
					}
				}
				
			//--------------------------------------------------------
			// 2
			//  X = 0.5  , y = 1.25 , z = -5.0 , x1 = -155, y1 = -0.5
			//                                  x1 = 72.5


			if (Flag_2 == TRUE)
				{
					if (cam_x1 <  72.5)
						cam_x1 = cam_x1 + 0.4;

					else
					{
						Flag_2 = FALSE;
						Flag_3 = TRUE;
					    
						// Assigning Values of next camara movments 
						cam_x = 2.5;
						cam_y = 3.25;
						cam_z = 3.75;

						cam_x1 = 160.0;
						cam_y1 = -57.5;
					}
				}

			////-----------------------------------------------------
			// 3
			//  X = 2.5  , y = 3.25 , z = 3.75 , x1 = 160.00, y1 = -57.5
			//                                   x1 = 186.0,  y1 = 54.0
			
			if (Flag_3 == TRUE)
				{
					if (cam_x1 < 186.0)
						cam_x1 = cam_x1 + 0.028;

					if (cam_y1 < 54.0)
						cam_y1 = cam_y1 + 0.27;

					else
					{
						Flag_3 = FALSE;
						Flag_4 = TRUE;
					    
						// Assigning Values of next camara movments 
						cam_x = 0.0;
						cam_y = 0.0;
						cam_z = 5.5;

						cam_x1 = 0.0;
						cam_y1 = 0.0;
					}
				}

			////-----------------------------------------------------
			// 4
			//  X = 0.0  , y =  0.00 ,  z =  5.50 , x1 = 0.0, y1 = 0.0
			//             y = -0.75,   z = -10.75      
			if (Flag_4 == TRUE)
			{
				if (cam_y > -0.75)
					cam_y = cam_y - 0.003;
				
				if (cam_z > -10.75)
					cam_z = cam_z - 0.015;
			
				else
				{
					Flag_4 = FALSE;
					Scene_Count = 9;
				}
			}

			//-----------------------------------------------------
			Z_8 = cam_z;
			gluLookAt(cam_x, cam_y, cam_z, cam_x1, cam_y1, 100, 0, 1, 0);

			//gluLookAt(5*tx, 5*ty, 5*tz, 5*sx, 5*sy, 100, 0, 1, 0);
			//gluLookAt(5*tx, 5*ty, 5*tz, 0, 0, 100, 0, 1, 0);
			
	//-----------------------------------------------------

			// Function Calls
			glColor3f(1,1,1);
			Environment_G8();
			G8_Temple();
			SabhaMandap_G8();

			//// Flag 
			//glPushMatrix();
			//	
			//	glTranslatef(-0.7 + sx, 6.5+ sy, 12.7 + sz);
			//	glScalef(-0.8 , 0.5 , 2.0);

			//	Flag_Wave();
			//glPopMatrix();



			// Gate 
			glPushMatrix();
				glTranslatef(0.0, 0.0, -3.65);
				glScalef(1.23,1.15, 1.0);
					Gate_G8();
			glPopMatrix();

		glPopMatrix();
		glDisable(GL_FOG);

	}
}

void Gate_G8()
{
	//---------------------------------------
	// Gate Animation 
	if (Z_8 > -8.0 && G8_Angle < 80.0)
	{
		G8_Angle = G8_Angle + 1.0;
	}
	else if (Z_8 <= -8.0 && G8_Angle > 0.0)
	{
		G8_Angle = G8_Angle - 0.5;

	}
	//---------------------------------------

	//Gate
			glPushMatrix();
				glDisable(GL_DEPTH);
				glEnable(GL_BLEND);
					glColor4f(1.0, 1.0, 1.0, 0.5);   // For Transperancy 
					glColor3f(0, 0, 0); 

					// Left Side
					glPushMatrix();
						glTranslatef(0.725, 0.8, -7.12);
						glScalef(0.355,0.7, 1.0);
						
						glRotatef(G8_Angle, 0, 1, 0);
						glTranslatef(-1.0, 0.0, 1.0);
							Front_Tex_Quad(G3_Gate1);
					glPopMatrix();

					// Right Side 
					glPushMatrix();

						glTranslatef(-0.70, 0.8, -7.12);
						glScalef(0.355,0.7, 1.0);
						
						glRotatef(-G8_Angle, 0, 1, 0);
						glTranslatef(1.0, 0.0, 1.0);
							Front_Tex_Quad(G3_Gate2);
					glPopMatrix();

				glDisable(GL_BLEND);
				glEnable(GL_DEPTH);
			glPopMatrix();
}


void Grass_Trees_G8()
{
	glPushMatrix();
		Color_Arr[0] = sx;//  color
		Color_Arr[1] = sx;
		Color_Arr[2] = sx;

		// Tree Back
		

		glPushMatrix();
			glTranslatef(-2.5, 0.0, 4.5);
				for (int i = 0; i < 6; i++)
				{
					Tree_G7(Tree7);
					glTranslatef(10.0, 0.0, 6.3);
				}
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-3.0 , 0.0, -14.8);
			glRotatef(-12, 0, 1, 0);
				for (int i = 0; i < 6; i++)
				{
					Tree_G7(Tree4);
					glTranslatef(7.0, 0.0, 6.3);
				}
		glPopMatrix();

		

		glPushMatrix();
			glTranslatef(40.3 , 0.0, 27.2);
				for (int i = 0; i < 6; i++)
				{
					Tree_G7(Tree4);
					glTranslatef(7.0, 0.0, -3.3);
				}
		glPopMatrix();

		glPushMatrix();
			glRotatef(10, 0, 1, 0);
			glTranslatef(33.0 , 0.0, 22.2);
				for (int i = 0; i < 6; i++)
				{
					Tree_G7(Tree7);
					glTranslatef(10.0, 0.0, -6.3);
				}
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-3.7 , 0.0, -23.9);
			glRotatef(113.0 , 0, 1, 0);
				for (int i = 0; i < 6; i++)
				{
					Tree_G7(Tree4);
					glTranslatef(7.0, 0.0, 6.3);
				}
		glPopMatrix();

		// Flowers
		glPushMatrix();
			glTranslatef(-16.6, 0.1, -20.4);
			glScalef(0.3, 0.25, 1.0);
				for (int i = 0; i < 7; i++)
				{
					Tree_G7(Flower4);
					glTranslatef(7.0, 0.0, 4.5);
				}

			glTranslatef(-20.10, 0.1, -23.0);
				for (int i = 0; i < 7 ; i++)
				{
					Tree_G7(Flower4);
					glTranslatef(7.0, 0.0, 4.5);
				}
		glPopMatrix();

		glPushMatrix();
			glTranslatef(26.5, 0.1, 4.9);
			glScalef(0.3, 0.25, 1.0);
				for (int i = 0; i < 6; i++)
				{
					Tree_G7(Flower4);
					glTranslatef(7.0, 0.0, -4.5);
				}
				
				glTranslatef(-45.2, 0.0, 14.4);
				for (int i = 0; i < 6; i++)
				{
					Tree_G7(Flower4);
					glTranslatef(7.0, 0.0, -4.5);
				}
		glPopMatrix();

		// Front che flowers
		glPushMatrix();
			glTranslatef(2.6, -0.3, -23.2);
			glScalef(0.3, 0.25, 1.0);
				for (int i = 0; i < 4; i++)
				{
					Tree_G7(Flower5);
					glTranslatef(7.0, 0.0, 0.0);
				}
				
			glTranslatef(12.5, 0.0, 0.0);
				for (int i = 0; i < 4; i++)
				{
					Tree_G7(Flower5);
					glTranslatef(7.0, 0.0, 0.0);
				}
		glPopMatrix();

		glPushMatrix();
			// Back che 2 
			glTranslatef(32.7, -0.2, 4.5);
				for (int i = 0; i < 2; i++)
				{
					Tree_G7(Tree7);
					glTranslatef(15.0, 0.0, 0.0);
				}
			
			// front che 2 
			glTranslatef(-30.0 + sx, 0.0, sz + -34.700);
				for (int i = 0; i < 2; i++)
				{
					Tree_G7(Tree7);
					glTranslatef(15.0, 0.0, 0.0);
				}
		glPopMatrix();
		
	glPopMatrix();


}


void Environment_G8()
{
	
	// Code
	glPushMatrix();

		// Sky
		glPushMatrix();
			glRotatef(-177.302, 1, 0,0);
			glRotatef( 309.110, 0, 1,0);
			glRotatef( 2.600,   0, 0,1);
			      Sky(G4_Sky);

		glPopMatrix();

		glColor3f(0.2, 0.2, 0.2);

		// Main Ground 
			glPushMatrix();
				glTranslatef(0.0,-0.1, -0.4);
				glScalef(5.0, 2.0, 5.0);
					Flat_Ground(G7_Grass2);				
			glPopMatrix();
	
		// Compound 
			glPushMatrix();
				glTranslatef(0.0,-1.5, 3.2);
				glScalef(2.0 ,1.1, 0.8);
					Compound_G4();
			glPopMatrix();

		// Tiles
		glColor3f(0.5, 0.5, 0.5);
		glPushMatrix();
			glTranslatef(0.1,-0.06,-1.95);
			glScalef( 1.1, 1.7,  0.89);
				Flat_Ground(Tile3);				
		glPopMatrix();

		// Bench 
		glPushMatrix();

			//left Bench 
			glPushMatrix();
				glColor3f(0.3, 0.3, 0.3);
				glTranslatef(11.1, -0.3, 8.9);
				glRotatef(90, 0, 1, 0);
				glScalef(3.2, 0.9,0.7);
					for (int i = 0; i < 5; i++)
					{
						glTranslatef(0.9, 0, 0);
							Marbal_Chair2(G1_FDesign);
					}					
			glPopMatrix();

			// right bench 
			glPushMatrix();
				glColor3f(0.3, 0.3, 0.3);
				glTranslatef(-11.3, -0.3, 7.5);
				glRotatef(-90, 0, 1, 0);
				glScalef(3.2, 0.9,0.7);
					for (int i = 0; i < 5; i++)
					{
						glTranslatef(-0.9, 0, 0);
							Marbal_Chair2(G1_FDesign);
					}
			glPopMatrix();
		glPopMatrix();

		// Treees 
		Grass_Trees_G8();
		
	glPopMatrix();

}
void G8_Temple()
{
	// Function Declarations 
	void Mandir_G8();
	void Stairs_G8(GLuint texture);

	// Code
	// Payarya  
	glPushMatrix();
		glColor3f(0.1, 0.5, 0.5);

		// Mandir 
		glTranslatef(0.0, 0.50, 0);
		glScalef(0.76,0.05,0.2);
			for (int i = 0; i < 4; i++)
			{
				glColor3f(1,1,1);
				glTranslatef(0.0,1.44, 1.1);
					Stairs_G8(G1_Wood);
			}
	glPopMatrix();

	// Temple
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(0.0, 2.1, 2.0);
		glScalef(2.0,1.5, 1.0);
			Mandir_G8();
	glPopMatrix();

}

void Stairs_G8(GLuint texture)
{
	// Code
	
	glBindTexture(GL_TEXTURE_2D, texture);

	glPushMatrix();
			// Right Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0,  1.0, -1.0);    // right top

				glTexCoord2f(0.5, 0.0);
				glVertex3f(1.0,  1.0,  1.0);    // left top	 

				glTexCoord2f(0.5, 0.5);
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom

				glTexCoord2f(0.0, 0.5);
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();


			glColor3f(0.35,0.35,0.35);
			// Front Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // right top

				glTexCoord2f(0.5, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(0.5, 0.5);
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0,0.5);
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			glEnd(); 

			glColor3f(0.5, 0.5, 0.5);
			// Left Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, 1.0);    // right top

				glTexCoord2f(0.5, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(0.5, 0.5);
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 0.5);
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

			// Top Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(0.5, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(0.5, 0.5);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 0.5);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 

	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);

}

void base_G8()
{
	glPushMatrix();
		glColor3f(0.4, 0.4, 0.4);
		glBindTexture(GL_TEXTURE_2D, G8_Patti_Design);
			// Front Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.5);
				glVertex3f(-1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // left top	 

				glTexCoord2f(1.0, 0.5);
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
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

		glBindTexture(GL_TEXTURE_2D, 0);
		
		glBindTexture(GL_TEXTURE_2D, G1_FDesign);
			// Top Face 
			glColor3f(0.4, 0.4, 0.4);
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(8.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(8.0, 8.0);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 8.0);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 
		glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();
}

void Khamb_G8()
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

void Grill_G8()
{
	glPushMatrix();
		Color_Arr[0] = 0;//  color
		Color_Arr[1] = 0;
		Color_Arr[2] = 0;
			
			
			glTranslatef(0.0,0.82, -3.3);
			glScalef(2.18,0.32, 1.0);
				Load_PNG(G4_FGrill, Color_Arr);
	glPopMatrix();
}

void Rangoli_G8()
{
	glPushMatrix();
		Color_Arr[0] = 1;//  color
		Color_Arr[1] = 1;
		Color_Arr[2] = 1;

			glTranslatef(0,-0.48, -1.5);
			glRotatef(90, 1, 0, 0);
				Load_PNG(G8_Rangoli1, Color_Arr);
	glPopMatrix();
}

void Frond_View_G8()
{
	// Khamb 
	glPushMatrix();

		//glTranslatef(0.0, -2.0, 0.0);
			Khamb_G8();

	glPopMatrix();

	glPushMatrix();
		//Design
		glPushMatrix();
			Color_Arr[0] = 0.5; // White color
			Color_Arr[1] = 0.5;
			Color_Arr[2] = 0.5;

			// Middle
			glTranslatef(0.0, 2.02, -3.3);
			glScalef(0.80, 0.6, 1.0);
				Load_PNG(G8_Design, Color_Arr);
			
			//Left 
			glTranslatef(1.9, 0.0, 0.0);
				Load_PNG(G8_Design, Color_Arr);

			// Right
			glTranslatef(-3.8, 0.0, 0.0);
				Load_PNG(G8_Design, Color_Arr);
				glColor3f(1.0, 1.0, 1.0);
		glPopMatrix();
		
		// Grill
		Grill_G8();

		// Payarya
		glPushMatrix();
			glColor3f(0.5, 0.5, 0.5);
			glTranslatef(0.0, 0.06, -5.34);
			glScalef(0.76,0.05,0.2);
				for (int i = 0; i < 3; i++)
				{
					//glColor3f(1,1,1);
					glTranslatef(0.0, 2.0, 1.1);
						Stairs_G8(G8_Patti_Design);
				}
		
		glPopMatrix();
	glPopMatrix();
}

void Slap_G8()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, G8_Patti_Design);
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
				glVertex3f(1.0,  1.0, -1.0);    // left top	 

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
		
		glBindTexture(GL_TEXTURE_2D, 0);
		
		glBindTexture(GL_TEXTURE_2D, G8_Slap_Design);
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

		glBindTexture(GL_TEXTURE_2D, G8_Slap_Design);
			// Bottom Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0, -1.0, -1.0);    // right top
				
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

void SabhaMandap_G8()
{
	// Code
	
	glPushMatrix();
		
		// Base 
		glPushMatrix();
			glTranslatef(0.0, 0.31,0.3);
			glScalef(2.5, 0.2,3.9);
				base_G8();
		glPopMatrix();
		
		// slap 
		glPushMatrix();
			glTranslatef(0.0, 2.7, -1.3);
			glScalef(2.7, 0.125,2.4);
					Slap_G8();
		glPopMatrix();

		// Har 
		glPushMatrix();
			glTranslatef(0.03, 1.93, 1.89);
			glScalef(0.6 , 0.58, 1.0);
				Load_Har(Har2);
		glPopMatrix();

		// Ghanta 
		glPushMatrix();
			glTranslatef(0.03, 2.26, 1.05);
			glScalef(0.11, 0.32, 1.0);
				Load_Har(Ghanta);
		glPopMatrix();

		//Rangoli
		glPushMatrix();
			Color_Arr[0] = 1;//  color
			Color_Arr[1] = 1;
			Color_Arr[2] = 1;

				glTranslatef(0,-0.48, -1.81);
				glRotatef(90, 1, 0, 0);
					Load_PNG(Rangoli2, Color_Arr);
		glPopMatrix();



		// All Side Design And Walls
		glPushMatrix();
			glTranslatef(0,0,0.9);
				glPushMatrix();
				glTranslatef(1.98, 0.0,-2.0);
					glRotatef(90, 0, 1 , 0);
						Frond_View_G8();
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-1.98, 0.0, -2.0);
					glRotatef(-90, 0, 1 , 0);
						Frond_View_G8();
				glPopMatrix();

				glPushMatrix();
					Frond_View_G8();
				glPopMatrix();
		glPopMatrix();
		
		// Ganapati Name  
			glPushMatrix();
				Color_Arr[0] = 0.6; //  color
				Color_Arr[1] = 0.6;
				Color_Arr[2] = 0.6;

				//(sx, sy, sz);
				glTranslatef(0.0,2.68, -2.8);
				glScalef(1.05 ,0.12, 1.0);
					Load_PNG(G8_Name, Color_Arr);
			glPopMatrix();

		
	glPopMatrix();
}

void Mandir_G8()
{
	// Code 

	glPushMatrix();	
		glTranslatef(0.0, 2.809, 0.0);
		glScalef(1.0, 2.4 , 1.0);
			Ghumat_G4_1(G8_G_Design);
	glPopMatrix();

	glPushMatrix();
		glScalef(1.0 ,1.3 ,1.0);
		glBindTexture(GL_TEXTURE_2D, G8_Stone1);
			// Back Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0, 0.5, 1.0);     // right top
	
				glTexCoord2f(2.0, 0.0);
				glVertex3f(-1.0, 0.5, 1.0);    // left top	
		
				glTexCoord2f(2.0, 2.0);
				glVertex3f(-1.0, -1.0 , 1.0);  // left bottom
		
				glTexCoord2f(0.0, 2.0);
				glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
			glEnd();

			// Right Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0,  0.5, -1.0);    // right top

				glTexCoord2f(2.0, 0.0);
				glVertex3f(1.0,  0.5,  1.0);    // left top	 

				glTexCoord2f(2.0, 2.0);
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom

				glTexCoord2f(0.0, 2.0);
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();
			
			// Left Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  0.5, 1.0);    // right top

				glTexCoord2f(2.0, 0.0);
				glVertex3f(-1.0,  0.5, -1.0);    // left top	 

				glTexCoord2f(2.0, 2.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 2.0);
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

			// Front Walll
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  0.1, -1.0);    // right top

				glTexCoord2f(1.5, 0.0);
				glVertex3f( -0.2,  0.1, -1.0);    // left top	 

				glTexCoord2f(1.5, 1.5);
				glVertex3f( -0.2, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.5);
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			glEnd(); 

			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
				glVertex3f(0.2,  0.1, -1.0);    // right top

				glTexCoord2f(1.5, 0.0);
				glVertex3f( 1.0,  0.1, -1.0);    // left top	 

				glTexCoord2f(1.5, 1.5);
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.5);
				glVertex3f(0.2, -1.0 , -1.0);   // right bottom
			glEnd(); 

			glBindTexture(GL_TEXTURE_2D, 0); // Unbined texture 

			// Doar chya varacha Quad 
			glBindTexture(GL_TEXTURE_2D, G8_Stone2);
				glBegin(GL_QUADS); 
					glTexCoord2f(0.0, 0.0);
					glVertex3f(-1.0,  0.5, -1.0);    // right top

					glTexCoord2f(1.0, 0.0);
					glVertex3f( 1.0,  0.5, -1.0);    // left top	 

					glTexCoord2f(1.0, 1.0);
					glVertex3f( 1.0,  0.1, -1.0);    // left bottom

					glTexCoord2f(0.0, 1.0);
					glVertex3f(-1.0,  0.1 , -1.0);   // right bottom
				glEnd(); 
			glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	// Bottom Face Floar
	glPushMatrix();
		glTranslatef(0, 0.2, 0);
			glBindTexture(GL_TEXTURE_2D, G4_Tile);
				glBegin(GL_QUADS); 
					glTexCoord2f(0.0, 0.0);
					glVertex3f( 1.0, -1.0, -1.0);    // right top
					
					glTexCoord2f(4.0, 0.0);
					glVertex3f(-1.0, -1.0, -1.0);    // left top	

					glTexCoord2f(4.0, 4.0);
					glVertex3f(-1.0, -1.0,  1.0);    // left bottom

					glTexCoord2f(0.0, 4.0);
					glVertex3f( 1.0, -1.0 , 1.0);   // right bottom
				glEnd();
			glBindTexture(GL_TEXTURE_2D, 0);		
	glPopMatrix();	


	// Ganpati
	glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(0.0,-0.8, 1.2);
		glRotatef(35, 1, 0, 0);
		glScalef(0.65, 0.7, 1.0);
			Front_Tex_Quad(G8_Ganpati);
	glPopMatrix();

	// Doar 
	glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		glTranslatef(0, 0.05, 0);
			Doar(G2_Brick_1);

		glColor3f(1,1,1);
	glPopMatrix();

}
