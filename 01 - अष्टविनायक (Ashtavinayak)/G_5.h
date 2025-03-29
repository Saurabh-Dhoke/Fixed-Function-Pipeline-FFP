
#pragma once
#include<math.h>

GLfloat G5_Angle = 0.0;

 
// Function Definations
void Start_G_5()
{
	fogColor[0] = 1.0;
	fogColor[1] = 0.5;
	fogColor[2] = 0.0;
	fogColor[3] = 1.0;

	glFogfv(GL_FOG_COLOR, fogColor); // Fog color 
	glFogf(GL_FOG_DENSITY, 0.006f);

	// Function Declarations 
	void G5_Temple();
	void Environment_G5();
	void SabhaMandap_G5();
	void Grass_Trees_G5();
	

	// Code

	
	if (Map5_Flag == TRUE)
	{
		Ozar_51();
	}
	else if (G5_Flag == TRUE)
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
			static float cam_y = 9.5;
			static float cam_z = -41.5;
			static float cam_x1 = 0.0;
			static float cam_y1 = 0.0;

			// Code

			glTranslatef(0,-1.45, -6.85);

			//---------------------------------------------------			
			// 1
			//  X = 0.0  , y =  10.0, z = -45.5 , x1 = 0, y1 = 0.0
			//             y =  0.25, z =  6.0  ,  
			if (Flag_1 == TRUE)
				{
					if (cam_y > 0.25)
						cam_y = cam_y - 0.028;

					if (cam_z < -3.0)
						cam_z = cam_z + 0.10; 
					
					else if(cam_z < 6.0)
						cam_z = cam_z + 0.020;

					else
					{
						Flag_1 = FALSE;
						Flag_2 = TRUE;
					    
						// Assigning Values of next camara movments 
						cam_x = 2.5;
						cam_y = 0.0;
						cam_z = 3.75;

						cam_x1 = -80.0;
						cam_y1 = 0.0;

						/*cam_x = 2.5;
						cam_y = 3.25;
						cam_z = 3.75;

						cam_x1 = 160.0;
						cam_y1 = -57.5;*/
					}
				}
				
			//--------------------------------------------------------
			// 2
			//  X = 2.5  , y = 0.0 , z = 3.75 , x1 = 64.5, y1 = 0.0
			//                                  x1 = -180


			if (Flag_2 == TRUE)
				{
					if (cam_x1 <  0.0)
						cam_x1 = cam_x1 + 0.36;
					
					else if (cam_x1 < 64.5)
						cam_x1 = cam_x1 + 0.225;

					else
					{
						Flag_2 = FALSE;
						Flag_5 = TRUE;
					    
						// Assigning Values of next camara movments 
						/*cam_x = 2.5;
						cam_y = 3.25;
						cam_z = 3.75;

						cam_x1 = 160.0;
						cam_y1 = -57.5;*/

						/*cam_x = 2.5;
						cam_y = 2.25;
						cam_z = 3.75;

						cam_x1 = 195.0;
						cam_y1 =  54.0;*/
						
						cam_x = 0.0;
						cam_y = 0.0;
						cam_z = 5.5;

						cam_x1 = 0.0;
						cam_y1 = 0.0;
					}
				}

			////-----------------------------------------------------
			//// 3
			////  X = 2.5  , y = 3.25 , z = 3.75 , x1 = 160.00, y1 = -57.5
			////                                   x1 = 186.0,  y1 = 54.0
			//
			//if (Flag_3 == TRUE)
			//	{
			//		if (cam_x1 < 186.0)
			//			cam_x1 = cam_x1 + 0.032;

			//		if (cam_y1 < 54.0)
			//			cam_y1 = cam_y1 + 0.19;

			//		else
			//		{
			//			Flag_3 = FALSE;
			//			Flag_5 = TRUE;
			//		    
			//			//// Assigning Values of next camara movments 
			//			//cam_x = 2.5;
			//			//cam_y = 3.25;
			//			//cam_z = 3.75;

			//			//cam_x1 = 186.0;
			//			//cam_y1 =  54.0;

			//			
			//		}
			//	}



			//-----------------------------------------------------
			// 4
			//  X = 2.5  , y = 3.25 , z = 3.75 , x1 = 186.0, y1 = 54.0
			//                                   x1 = -42.5
			//if (Flag_4 == TRUE)
			//	{
			//	if (cam_x1 > -42.0)
			//		cam_x1 = cam_x1 - 0.10;

			//		else
			//		{
			//			Flag_4 = FALSE;
			//			//Flag_5 = TRUE;
			//		    
			//			//Scene_Count = 6;

			//			// Assigning Values of next camara movments 
			//			/*cam_x = 0.0;
			//			cam_y = 0.0;
			//			cam_z = 5.5;

			//			cam_x1 = 0.0;
			//			cam_y1 = 0.0;*/
			//		}
			//	}

			////-----------------------------------------------------
			// 5
			//  X = 0.0  , y =  0.00 ,  z =  5.50 , x1 = 0.0, y1 = 0.0
			//             y = -0.75,   z = -4.75      
			if (Flag_5 == TRUE)
			{
				if (cam_y > -0.10)
					cam_y = cam_y - 0.0005;
				
				if (cam_z > -4.75)
					cam_z = cam_z - 0.013;
			
				else
				{
					Flag_5 = FALSE;
					Scene_Count = 6;
				}
			}

			//-----------------------------------------------------
			/*
			cam_x = 2.5;
			cam_y = 2.25;
			cam_z = 3.75;

			cam_x1 = 195.0;
			cam_y1 = 54.0;*/

			gluLookAt(cam_x, cam_y, cam_z, cam_x1, cam_y1, 100, 0, 1, 0);

			//gluLookAt(5*tx + 2.5, 5*ty + 2.25, 5*tz + 3.75,0.0, 0.0, 100, 0, 1, 0);
			
	//-----------------------------------------------------

			// Function Calls
				glColor3f(1,1,1);

				G5_Temple();
				Environment_G5();
				SabhaMandap_G5();

			// Flag 
			glPushMatrix();
				
				glTranslatef(-0.7 + sx, 6.5+ sy, 12.7 + sz);
				glScalef(-0.8 , 0.5 , 2.0);

				Flag_Wave();
			glPopMatrix();

		glPopMatrix();
		glDisable(GL_FOG);

	}
}

void Tree_G5(GLuint texture)
{
	glPushMatrix();
		Color_Arr[0] = 0.5;//  color
		Color_Arr[1] = 0.5;
		Color_Arr[2] = 0.5;

		glTranslatef(-22.4, 0.0, 0.0);	

		// Tree1 
		glPushMatrix();			
			glTranslatef(-17.6, 2.6, 12.5);
			glScalef(3.1, 2.8, 1.0);
				Load_PNG(texture, Color_Arr);
		glPopMatrix();

		glPushMatrix();	
			glTranslatef(-14.45, 2.7, 11.5);
			glScalef(3.1, 2.8, 1.0);
			glRotatef(90, 0, 1, 0);
				Load_PNG(texture, Color_Arr);
		glPopMatrix();

	glPopMatrix();
}

void Grass_Trees_G5()
{
	glPushMatrix();
		Color_Arr[0] = 0.5;//  color
		Color_Arr[1] = 0.5;
		Color_Arr[2] = 0.5;

		// Tree Back
		glPushMatrix();
			for (int i = 0; i < 5; i++)
			{
				Tree_G5(Tree5);
				glTranslatef(17.0, 0.0, 6.3);
			}
		glPopMatrix();

		

		// Treeleft
		glPushMatrix();
			glTranslatef(1.2, -0.2, -21.4);

			for (int i = 0; i < 5; i++)
			{
				Tree_G5(Tree7);
				glTranslatef(10.0, 0.0, 6.3);
			}

			glTranslatef(-3.0, 0.0, 0.0);
			glRotatef(50, 0, 1, 0 );
			for (int i = 0; i < 5; i++)
			{
				Tree_G5(Tree7);
				glTranslatef(10.0, 0.0, -6.3);
			}
		glPopMatrix();

		
		// Tree Front 
		glPushMatrix();
			glTranslatef(-2.2, 0.2, -39.6);
			for (int i = 0; i < 5; i++)
			{
				Tree_G5(Tree2);
				glTranslatef(17.0, 0.0, 6.3);
			}
		glPopMatrix();

		
	glPopMatrix();


}

void Environment_G5()
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

		// Main Ground 
		glPushMatrix();
			glTranslatef(0.0,-0.1, -0.4);
			glScalef(5.0, 1.0, 5.0);
				Flat_Ground(G7_Grass2);				
		glPopMatrix();
		
		// Tiles
		glPushMatrix();
			glColor3f(0.7, 0.7, 0.7);
			glTranslatef(0.1,-0.1,-0.2);
			glScalef(0.65, 1.7, 1.2);
				Flat_Ground(Tile2);				
		glPopMatrix();

		// Bench an danpeti 
		glPushMatrix();
			// Right danpeti 
			glPushMatrix();
				glTranslatef(1.1, 0.9, 0.6);
				glScalef(0.3,0.6, 0.4);
					glColor3f(0.6, 0.6, 0.6);
					Danpeti2();
			glPopMatrix();
				
			//left danpeti 
			glPushMatrix();
				glTranslatef(-1.1, 0.9, 0.6);
				glScalef(0.3,0.6, 0.4);
					glColor3f(0.6, 0.6, 0.6);
					Danpeti2();
			glPopMatrix();

			//left Bench 
			glPushMatrix();
				glColor3f(0.5, 0.5, 0.5);
				glTranslatef(7.1, -0.3, 5.4);
				glRotatef(90, 0, 1, 0);
				glScalef(3.2, 0.9,0.7);
					for (int i = 0; i < 5; i++)
					{
						glTranslatef(0.9, 0, 0);
							Marbal_Chair(G1_FDesign);
					}					
			glPopMatrix();

			// right bench 
			glPushMatrix();
				glColor3f(0.5, 0.5, 0.5);
				glTranslatef(-7.3, -0.3, 4.0);
				glRotatef(-90, 0, 1, 0);
				glScalef(3.2, 0.9,0.7);
					for (int i = 0; i < 5; i++)
					{
						glTranslatef(-0.9, 0, 0);
							Marbal_Chair(G1_FDesign);
					}
			glPopMatrix();


			// Trees 
			Grass_Trees_G5();
		glPopMatrix();
	glPopMatrix();

}
void G5_Temple()
{
	// Function Declarations 
	void Mandir_G5();

	// Code
	// Payarya  
	glPushMatrix();
		glColor3f(0.1, 0.5, 0.5);

		// Mandir 
		glTranslatef(0.0, 0.46, 0);
		glScalef(0.76,0.05,0.2);
			for (int i = 0; i < 4; i++)
			{
				glColor3f(1,1,1);
				glTranslatef(0.0, 2.0, 1.1);
					Stairs_G1(G1_Wood);
			}
	glPopMatrix();

	// Temple
	glPushMatrix();
		glColor3f(1,1,1);

		// Mandir
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(0.0, 2.1, 2.0);
			glScalef(2.0,1.5, 1.0);
					Mandir_G5();
		glPopMatrix();

	glPopMatrix();

}

void base_G5()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, G1_Wood);
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

void Cylinder_G5(GLuint texture)
{
	//gluCylinder(quadric, baseRadius, topRadius, Height, Slices, Stacks);

	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		
		gluQuadricTexture(quadric2, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
				gluCylinder(quadric2, 0.15 , 0.15 ,2.5, 30, 30);
		glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();
}
void Khamb_G5()
{
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
		// Left side 
		glPushMatrix();
			glTranslatef(2.1 , 2.9, -4.2);
				Cylinder_G5(G5_Brick2);
		glPopMatrix();

		// Right side 
		glPushMatrix();
			glTranslatef(-2.1, 2.9, -4.2);
				Cylinder_G5(G5_Brick2);
		glPopMatrix();

		// middle Left
		glPushMatrix();
			glTranslatef(0.9, 2.9, -4.2);
				Cylinder_G5(G5_Brick2);
		glPopMatrix();
		
		// Middle Right 
		glPushMatrix();
			glTranslatef(-0.9, 2.9, -4.2);
				Cylinder_G5(G5_Brick2);
		glPopMatrix();


	glPopMatrix();
}

void Frond_View()
{
	glPushMatrix();
		// Khamb 
		Khamb_G5();

		// Front kathade
		glPushMatrix();			
		glColor3f(0.5, 0.5, 0.5);
			glTranslatef(1.5, 0.7, -4.2);
			glScalef(0.5, 0.3, 0.1);
					Base_G1(G5_Brick);

			glTranslatef(0.0, 6.3, 0.0);
			glRotatef(180, 1, 0, 0); // ulta karun ghetla 
					Base_G1(G5_Brick);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.5, 0.7, -4.2);
			glScalef(0.5, 0.3, 0.1);
					Base_G1(G5_Brick);

			glTranslatef(0.0 , 6.3, 0.0);
			glRotatef(180, 1 , 0, 0); // ulta karun ghetla 
					Base_G1(G5_Brick);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0, 2.6, -4.2);
			glRotatef(180, 1, 0, 0); // ulta karun ghetla 
			glScalef(0.79 , 0.3, 0.1);
					Base_G1(G5_Brick);
		glPopMatrix();

		//Design
		glPushMatrix();
			Color_Arr[0] = 0.0; // Black color
			Color_Arr[1] = 0.0;
			Color_Arr[2] = 0.0;

			// Middle
			glTranslatef(0.0, 1.82, -3.3);
			glScalef(0.86, 0.62, 1.0);
				Load_PNG(G5_Design1, Color_Arr);
			
			//Left 
			glTranslatef(1.75, -0.17 , 0.0);
			glScalef(0.66, 1.26, 1.0);
				Load_PNG(G5_Design2, Color_Arr);
			// Right
			glTranslatef(-5.30, 0.0 , 0.0);
				Load_PNG(G5_Design2, Color_Arr);
				glColor3f(1.0, 1.0, 1.0);
		glPopMatrix();
	
		// Payarya
		glPushMatrix();
			glColor3f(0.1, 0.5, 0.5);
			glTranslatef(0.0, 0.1, -5.4);
			glScalef(0.76,0.05,0.2);
				for (int i = 0; i < 3; i++)
				{
					glColor3f(1,1,1);
					glTranslatef(0.0, 2.0, 1.1);
						Stairs_G1(G1_Wood);
				}
		
		glPopMatrix();
	glPopMatrix();
}

void Slap_G5()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, G4_Golden_design1);
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
		
		glBindTexture(GL_TEXTURE_2D, G1_Wood);
			// Top Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(2.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(2.0, 2.0);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 
		glBindTexture(GL_TEXTURE_2D, 0);

		glBindTexture(GL_TEXTURE_2D, G5_Design3);
			// Bottom Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0, -1.0, -1.0);    // right top
				
				glTexCoord2f(3.0, 0.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left top	

				glTexCoord2f(3.0, 3.0);
				glVertex3f(-1.0, -1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 3.0);
				glVertex3f( 1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 
		glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

void SabhaMandap_G5()
{
	// Code
	
	glPushMatrix();
		// Base 
		glPushMatrix();
			glTranslatef(0.0, 0.31,0.3);
			glScalef(2.5, 0.2,3.9);
				base_G5();
		glPopMatrix();
		
		// slap 
		glPushMatrix();
			glTranslatef(0.0, 3.0, -1.3);
			glScalef(2.7, 0.125,2.4);
					Slap_G5();
		glPopMatrix();
			
		// Har 
		glPushMatrix();

			glTranslatef(0.04, 2.08, 1.94);
			glScalef(0.6, 0.5, 1.0);
				Load_Har(Har7);
		glPopMatrix();

		// Ghanta 
		glPushMatrix();
			glTranslatef(0.00, 2.47, 1.29);
			glScalef(0.1 ,0.42, 1.0);
				Load_Har(Ghanta);

		glPopMatrix();

		//Rangoli
		glPushMatrix();
			Color_Arr[0] = 1;//  color
			Color_Arr[1] = 1;
			Color_Arr[2] = 1;
				glTranslatef(0,-0.46, -1.5);
				glRotatef(90, 1, 0, 0);
					Load_PNG(Rangoli1, Color_Arr);
		glPopMatrix();



		// All Side Design And Walls
		glPushMatrix();
			glTranslatef(0,0,0.9);
				glPushMatrix();
				glTranslatef(2.1, 0.0, -2.1);
					glRotatef(90, 0, 1 , 0);
						Frond_View();
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-2.1, 0.0, -2.1);
					glRotatef(-90, 0, 1 , 0);
						Frond_View();
				glPopMatrix();

				glPushMatrix();
					Frond_View();
				glPopMatrix();
		glPopMatrix();
		
		// Ganapati NAme  
			glPushMatrix();
				Color_Arr[0] = 1.0; //  color
				Color_Arr[1] = 0.5;
				Color_Arr[2] = 0.0;

				glTranslatef(0.0, 2.6, -2.5);
				glScalef(0.75,0.15, 1.0);
					Load_PNG(G5_Name, Color_Arr);
			glPopMatrix();

	glPopMatrix();
}

void Mandir_G5()
{
	// Code 

	glPushMatrix();	
		glTranslatef(0.0, 2.80, -0.01);
		glScalef(1.0, 2.4 , 1.0);
			Ghumat_G4_1(G5_Stone);
	glPopMatrix();

	glPushMatrix();
		glScalef(1.0 ,1.3 ,1.0);
		glBindTexture(GL_TEXTURE_2D, G5_Stone1);
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

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0,  0.5,  1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();
			
			// Left Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  0.5, 1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  0.5, -1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
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
			glBindTexture(GL_TEXTURE_2D, 0); // Unbined texture 
	glPopMatrix();	


	// Ganpati
	glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(0.0,-0.1, 1.7);
		glScalef(0.65, 0.7, 1.0);
			Front_Tex_Quad(G5_Ganpati);
	glPopMatrix();

	// Baherchi Gold Design 
	glPushMatrix();
		Color_Arr[0] = 1.0; //  color
		Color_Arr[1] = 1.0;
		Color_Arr[2] = 1.0;
		
		glTranslatef(0.0, -0.31, 0.0);
		glScalef(1.0, 1.0, 1.0);
			Load_PNG(G5_Gold, Color_Arr);
	glPopMatrix();
	
	// Doar 
	glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		glTranslatef(0, 0.05, 0);
			Doar(G2_Brick_1);

		glColor3f(1,1,1);
	glPopMatrix();

		
}
