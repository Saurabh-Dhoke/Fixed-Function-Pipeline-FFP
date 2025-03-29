
#pragma once
#include<math.h>

GLfloat G7_Angle;


// Function Definations
void Start_G_7()
{
	fogColor[0] = 0.5;
	fogColor[1] = 0.5;
	fogColor[2] = 0.5;
	fogColor[3] = 1.0;

	glFogfv(GL_FOG_COLOR, fogColor); // Fog color 
	glFogf(GL_FOG_DENSITY, 0.010f);


	// Function Declarations 
	void G7_Temple();
	void Environment_G7();
	void Grill();

	// Code

	if (Map7_Flag == TRUE)
	{
		Mahad_71();
	}
	else if (G7_Flag == TRUE)
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
			static float cam_y = 1.1;
			static float cam_z = 3.6;
			static float cam_x1 = 0.0;
			static float cam_y1 = 0.0;

			// Code

			glTranslatef(0,-1.45, -6.85);

			//---------------------------------------------------			
			// 1
			//  X = 0.0  , y =  1.1 , z = 3.6 , x1 = 0 , y1 = 0
			//             y =  0.2,  z = -3.05  ,  
			if (Flag_1 == TRUE)
				{
					if (cam_y > 0.2)
						cam_y = cam_y - 0.002;

					if (cam_z > -3.05)
						cam_z = cam_z - 0.014; 
					
					else
					{
						Flag_1 = FALSE;
						Flag_2 = TRUE;
					}
				}
				
			//--------------------------------------------------------
			// 2
			//  X = 2.5  , y =  0.20 ,  z = -3.05 , x1 = 0, y1 = 0
			//             y = -0.25, z =  9.45                    
			if (Flag_2 == TRUE)
				{
					if (cam_y > -0.25)
						cam_y = cam_y - 0.003;

					if (cam_z < 9.40)
						cam_z = cam_z + 0.024; 
					
					else
					{
						Flag_2 = FALSE;
						Flag_3 = TRUE;
					    
						// Assigning Values of next camara movments 
						cam_x = 0.0;
						cam_y = 0.9;
						cam_z = -1.9;

						cam_x1 = -150.0;
						cam_y1 =  3.5;
					}
				}

			//--------------------------------------------------------
			// 3
			//  X = 0.0  , y =  -0.3 ,  z = -1.4 , x1 = -160.0 , y1 = 0
			//                                     x1 =  30.4             
			if (Flag_3 == TRUE)
				{
					if (cam_x1 < 150)
						cam_x1 = cam_x1 + 0.34;
					
					else
					{
						Flag_3 = FALSE;
						Scene_Count = 8;
					}
				}

	//----------------------------------------------------------------------------
			gluLookAt(cam_x, cam_y, cam_z, cam_x1, cam_y1, 100, 0, 1, 0);

			//gluLookAt(1*tx, 1*ty, 1*tz, 0,0, 100, 0, 1, 0);
	//----------------------------------------------------------------------------
	
			// Function Calls
			Environment_G7();

			glColor3f(1,1,1);
			G7_Temple();
	
		glPopMatrix();
		glDisable(GL_FOG);

	}
	
	

}

void Tree_G7(GLuint texture)
{
	glPushMatrix();
		Color_Arr[0] = 0.35;//  color
		Color_Arr[1] = 0.35;
		Color_Arr[2] = 0.35;

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
void Grass_Trees_G6()
{
	glPushMatrix();
		Color_Arr[0] = sx;//  color
		Color_Arr[1] = sx;
		Color_Arr[2] = sx;

		// Tree Back
		glPushMatrix();
			for (int i = 0; i < 5; i++)
			{
				Tree_G7(Tree7);
				glTranslatef(17.0, 0.0, 6.3);
			}
		glPopMatrix();

		

		// Treeleft
		glPushMatrix();
			glTranslatef(1.2, -0.2, -21.4);

			for (int i = 0; i < 5; i++)
			{
				Tree_G7(Tree2);
				glTranslatef(10.0, 0.0, 6.3);
			}

			glTranslatef(-17.6, 0.0, -18.4);
			glRotatef(50, 0, 1, 0 );
			for (int i = 0; i < 5; i++)
			{
				Tree_G7(Tree2);
				glTranslatef(10.0, 0.0, -6.3);
			}
		glPopMatrix();

		
		// Grass
		glPushMatrix();
			glTranslatef(-6.9, 0.1, -23.2);
			glScalef(0.3, 0.25, 1.0);
				for (int i = 0; i < 5; i++)
				{
					Tree_G7(Grass7);
					glTranslatef(7.0, 0.0, 4.5);
				}

			glTranslatef(-20.10, 0.1, -23.0);
				for (int i = 0; i < 5; i++)
				{
					Tree_G7(Grass7);
					glTranslatef(7.0, 0.0, 4.5);
				}
		glPopMatrix();

		glPushMatrix();
			glTranslatef(21.8, 0.1, 8.7);
			glScalef(0.3, 0.25, 1.0);
				for (int i = 0; i < 5; i++)
				{
					Tree_G7(Grass7);
					glTranslatef(7.0, 0.0, -4.5);
				}
				
				glTranslatef(-45.2, 0.0, 14.4);
				for (int i = 0; i < 5; i++)
				{
					Tree_G7(Grass7);
					glTranslatef(7.0, 0.0, -4.5);
				}
		glPopMatrix();

		
	glPopMatrix();


}

void Environment_G7()
{
	
	// Code
	glPushMatrix();
		
		glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			glRotatef(-177.302, 1, 0,0);
			glRotatef( 309.110, 0, 1,0);
			glRotatef( 2.600,   0, 0,1);
			      Sky(G7_Sky);
		glPopMatrix();

		// Main Ground 
		glPushMatrix();			
			glTranslatef(0.0,-0.1, -0.4);
			glScalef(5.0 ,2.0, 5.0 );
				glColor3f(0.5, 0.5, 0.5);
				Flat_Ground(G7_Grass2);
				
			// Tiles 
			glTranslatef(0.6,-0.05,0.0);
			glScalef(0.06, 1.53,  -0.115); 
				glColor3f(0.7, 0.7, 0.7);
				Flat_Ground(G2_Soil);

			glTranslatef(-19.80, 0.0, 0.0);
				Flat_Ground(G2_Soil);
		glPopMatrix();

		// Bench an danpeti 
		glPushMatrix();
			// Right danpeti 
			glPushMatrix();
				glTranslatef(1.0, 0.7, 0.6);
				glScalef(0.3,0.6, 0.4);
					glColor3f(0.6, 0.6, 0.6);
					Danpeti1();
			glPopMatrix();
				
			//left danpeti 
			glPushMatrix();
				glTranslatef(-1.0, 0.7, 0.6);
				glScalef(0.3,0.6, 0.4);
					glColor3f(0.6, 0.6, 0.6);
					Danpeti1();
			glPopMatrix();
		
		glPopMatrix();

		//  Tress
		Grass_Trees_G6();
	glPopMatrix();

}

void Grill()
{

	
	// Code
	// Grill Window
	glPushMatrix();
		Color_Arr[0] = 1.0;
		Color_Arr[1] = 1.0;
		Color_Arr[2] = 1.0;
		
		
		// Left Side 
		
		// Left Side 1 
		glPushMatrix();		
			glTranslatef(3.6, 2.0, -1.95);
			glRotatef(90, 0, 1, 0);
			glScalef(0.8, 0.8, 0.7);
				Load_PNG(G7_Grill_1, Color_Arr);
		glPopMatrix();

		// Left Side 2
		glPushMatrix();		
			glTranslatef(3.6, 2.0, -0.05);
			glRotatef(90, 0, 1, 0);
			glScalef(0.8, 0.8, 0.7);
				Load_PNG(G7_Grill_1, Color_Arr);
		glPopMatrix();

		// Front 
		glPushMatrix();
			glTranslatef(1.95, 2.0, -1.9);
			glScalef(0.9, 0.8, 1.0);
				Load_PNG(G7_Grill_1, Color_Arr);
		glPopMatrix();


		glColor3f(1, 1, 1);

		// Right Side
			
		// Right Side 1 
		glPushMatrix();		
			glTranslatef(-2.2, 2.0, -1.95);
			glRotatef(90, 0, 1, 0);
			glScalef(0.8, 0.8, 0.7);
				Load_PNG(G7_Grill_1, Color_Arr);
		glPopMatrix();

		// Right Side 2
		glPushMatrix();		
			glTranslatef(-2.2, 2.0, -0.05);
			glRotatef(90, 0, 1, 0);
			glScalef(0.8, 0.8, 0.7);
				Load_PNG(G7_Grill_1, Color_Arr);
		glPopMatrix();

		//  Front 
		glPushMatrix();
			glTranslatef(-1.95, 2.0, -1.9);
			glScalef(0.9, 0.8, 1.0);
				Load_PNG(G7_Grill_1, Color_Arr);
		glPopMatrix();


	glPopMatrix();
}
void G7_Temple()
{

	// Function Declarations 
	void Mandir_G7();
	void Temple_Base_G7();
	void Kaul_Roof_G7();
	

	// Code

	glPushMatrix();
		glColor3f(0.1, 0.5, 0.5);
		// Payarya  
		glTranslatef(0.0, 0.05, -3.85);
		glScalef(0.76,0.05,0.2);
			for (int i = 0; i < 3; i++)
			{
				glColor3f(1,1,1);
				glTranslatef(0.0, 2.0, 1.1);
					Stairs_G1(G1_Wood);
			}
	glPopMatrix();

	glPushMatrix();
		glColor3f(1,1,1);
	
		// Base 
		glPushMatrix();

			glTranslatef(0.0, 0.0, 0.5);
			glScalef(3.0, 0.4, 3.5);
				Temple_Base_G7();
		glPopMatrix();


		// SIde Kathade
		glPushMatrix();
			glColor3f(0.7, 0.7, 0.7);
			glTranslatef(2.9, 0.61, -1.01);
			glScalef(0.1, 0.53, 2.0);
					Base_G1(G2_Brick_3);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-2.9, 0.61, -1.01);
			glScalef(0.1, 0.53, 2.0);
					Base_G1(G2_Brick_3);
		glPopMatrix();

		// Front kathade
		glPushMatrix();
			glTranslatef(1.8, 0.61, -2.91);
			glScalef(1.0, 0.53,  0.1);
					Base_G1(G2_Brick_3);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-1.8,  0.61 , -2.91);
			glScalef(1.0, 0.53, 0.1);
				Base_G1(G2_Brick_3);
		glPopMatrix();

		// Side Bar 
		glPushMatrix();
			// Left 
			glPushMatrix();

				glColor3f(0.7, 0.7, 0.7);
				// 1
				glTranslatef(0.9,1.45, -2.9);
				glScalef(0.15, 1.8, 0.15);
						Base_G1(G2_Brick_1);
				//2						
				glTranslatef(13.3,-0.14, 0.0);
						Base_G1(G2_Brick_1);
				// 3
				glTranslatef(-0.4,0.0, 12.60);
						Base_G1(G2_Brick_1);
				//4
				glTranslatef(-0.3,0.0, 12.60);
						Base_G1(G2_Brick_1);
			glPopMatrix();

			// Right side
			glPushMatrix();
				// 1
				glTranslatef(-0.9, 1.4, -2.9);
				glScalef(0.15, 1.8, 0.15);
						Base_G1(G2_Brick_1);
				//2
				glTranslatef(-13.3,-0.14, 0.0);
						Base_G1(G2_Brick_1);
				// 3
				glTranslatef(0.4,0.0, 12.60);
						Base_G1(G2_Brick_1);
				//4
				glTranslatef(0.3,0.0, 12.60);
						Base_G1(G2_Brick_1);
			glPopMatrix();
		glPopMatrix();

		// Slap 
		glPushMatrix();
			glColor3f(0.5, 0.5, 0.5);
			glTranslatef(0.0, 3.5, -1.4);
			glScalef(3.5, 0.7, 2.5);
				Kaul_Roof_G7();
		glPopMatrix();

		// Name
		glPushMatrix();
			
			Color_Arr[0] = 1.0; // white color
			Color_Arr[1] = 1.0;
			Color_Arr[2] = 1.0;

			glColor3f(1.0, 0.5, 0.0); // Bhagava color 

			glTranslatef(0.0, 2.75, -2.1);
			glScalef(1.1, 0.5, 1.0);
				Front_Tex_Quad(G1_Wood);

			glTranslatef(0.0, -0.3, -0.05);
			glScalef(0.8, 0.5, 1.0);
				Load_PNG(G7_Name, Color_Arr);

				glColor3f(1.0, 1.0, 1.0);
		glPopMatrix();


		// Mandir
		glPushMatrix();
			glColor3f(0.5, 0.5, 0.5);
			glTranslatef(0.0, 1.6, 2.0);
			glScalef(2.0,1.5, 1.0);
					Mandir_G7(G1_Stairs);
		glPopMatrix();


		// Har 
		glPushMatrix();
			glTranslatef(0.04, 1.61, 1.89);
			glScalef(0.6,0.23, 1.0);
			glColor3f(0.7, 0.7, 0.7);
				Load_Har(Har6);
		glPopMatrix();

		// Ghanta 
		glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			glTranslatef(0.05, 2.12, 1.5);
			glScalef(0.11 ,0.79, 1.0);
				Load_Har(Ghanta2);
		glPopMatrix();

		//Rangoli
		glPushMatrix();
			Color_Arr[0] = 1;//  color
			Color_Arr[1] = 1;
			Color_Arr[2] = 1;
			
				glTranslatef(0,-0.56, -1.1);
				glRotatef(90, 1, 0, 0);
					Load_PNG(Rangoli5, Color_Arr);
		glPopMatrix();


		//Mandir Grill 
		Grill();
		glColor3f(1, 1, 1);

	glPopMatrix();

}

void Temple_Base_G7()
{
	// Code

	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, G1_Stairs);

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
		
		glBindTexture(GL_TEXTURE_2D, G1_Wood);
			// Top Face 
			glColor3f(0.4, 0.4, 0.4);
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
void Kaul_Roof_G7()
{
			glBindTexture(GL_TEXTURE_2D, G2_Roof);
			// 3D Pyramid
			// Front Face 
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0.5, 2.0);
				glVertex3f( 0.0,  1.0, 0.0);  // top
		
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 1.0);  // left bottom
		
				glTexCoord2f(2.0, 0.0);
				glVertex3f( 1.0, -1.0, 1.0);  // right bottom
			glEnd();

			// Right Face 
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0.5, 2.0);
				glVertex3f( 0.0,  1.0, 0.0);  // apex
		
				glTexCoord2f(2.0, 0.0);
				glVertex3f( 1.0, -1.0, 1.0);  // left bottom
		
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0, -1.0, -1.0);  // right bottom
			glEnd();

			// Front Face 
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0.5, 2.0);
				glVertex3f( 0.0,  1.0, 0.0);  // apex
	
				glTexCoord2f(2.0, 0.0);
				glVertex3f( 1.0, -1.0, -1.0);  // left bottom

				glTexCoord2f(0.0, 0.0);
				glVertex3f( -1.0, -1.0, -1.0);  // right bottom
			glEnd();

			// Left Face 
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0.5, 2.0);
				glVertex3f(  0.0,  1.0,  0.0);  // apex

				glTexCoord2f(0.0, 0.0);
				glVertex3f( -1.0, -1.0, -1.0);  // left bottom

				glTexCoord2f(2.0, 0.0);
				glVertex3f( -1.0, -1.0,  1.0);  // right bottom
			glEnd();


			glBindTexture(GL_TEXTURE_2D, 0);

			//--------------------------------------------------------------------
}

void Pyramid(GLuint texture)
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture);
			// 3D Pyramid
			// Front Face 
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0.5, 2.0);
				glVertex3f( 0.0,  1.0, 0.0);  // top
		
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 1.0);  // left bottom
		
				glTexCoord2f(2.0, 0.0);
				glVertex3f( 1.0, -1.0, 1.0);  // right bottom
			glEnd();

			// Right Face 
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0.5, 2.0);
				glVertex3f( 0.0,  1.0, 0.0);  // apex
		
				glTexCoord2f(2.0, 0.0);
				glVertex3f( 1.0, -1.0, 1.0);  // left bottom
		
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0, -1.0, -1.0);  // right bottom
			glEnd();

			// Front Face 
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0.5, 2.0);
				glVertex3f( 0.0,  1.0, 0.0);  // apex
	
				glTexCoord2f(2.0, 0.0);
				glVertex3f( 1.0, -1.0, -1.0);  // left bottom

				glTexCoord2f(0.0, 0.0);
				glVertex3f( -1.0, -1.0, -1.0);  // right bottom
			glEnd();

			// Left Face 
			glBegin(GL_TRIANGLES);
				glTexCoord2f(0.5, 2.0);
				glVertex3f(  0.0,  1.0,  0.0);  // apex

				glTexCoord2f(0.0, 0.0);
				glVertex3f( -1.0, -1.0, -1.0);  // left bottom

				glTexCoord2f(2.0, 0.0);
				glVertex3f( -1.0, -1.0,  1.0);  // right bottom
			glEnd();
			glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
			

}
void Cube(GLuint texture)
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture);
			// Front Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(0.1, 1.0, 0.1);     // right top
	
				glTexCoord2f(1.0, 0.0);
				glVertex3f(-0.1, 1.0, 0.1);    // left top	
		
				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);  // left bottom
		
				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
			glEnd();

			// Right Face 
			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.1,  1.0, -0.1);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(0.1,  1.0,  0.1);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0 , 1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.0, -1.0 , -1.0);   // right bottom
			glEnd();

			// Back Face 
			glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
				glVertex3f(-0.1,  1.0, -0.1);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(0.1,  1.0, -0.1);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f( 1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
			glEnd(); 

			// Left Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-0.1,  1.0, 0.1);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-0.1,  1.0, -0.1);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 

			//// Top Face 
			//glBegin(GL_QUADS); 
			//	glTexCoord2f(0.0, 0.0);
			//	glVertex3f( 1.0,  1.0, -1.0);    // right top

			//	glTexCoord2f(1.0, 0.0);
			//	glVertex3f(-1.0,  1.0, -1.0);    // left top	

			//	glTexCoord2f(1.0, 1.0);
			//	glVertex3f(-1.0,  1.0,  1.0);    // left bottom

			//	glTexCoord2f(0.0, 1.0);
			//	glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			//glEnd(); 

			// Bottom Face 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(0.1, -1.0, -0.1);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-0.1, -1.0, -0.1);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 
		glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
			

}

void Ghumat_G7()
{
	glPushMatrix();
		Cube(G3_Stone);

		glTranslatef(0, 1.2, 0);
		glScalef(0.1, 0.2, 0.1);
			Pyramid(G7_Golden);
	glPopMatrix();
}
void Mandir_G7()
{
	// Code 
	glPushMatrix();	
		glTranslatef(0.0, 2.0, 0.0);
			Ghumat_G7();
	glPopMatrix();

	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, G1_Stone);
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

			glBindTexture(GL_TEXTURE_2D, 0); // Unbined texture 

			glBindTexture(GL_TEXTURE_2D, G3_Stone);
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
			glBindTexture(GL_TEXTURE_2D, 0);
		glPopMatrix();



			glPushMatrix();
				glColor3f(1, 1, 1);
				glTranslatef(0.0, -0.3, 1.7);
				glRotatef(10, 1, 0, 0);
				glScalef(0.7, 0.7, 1.0);
			
				glBindTexture(GL_TEXTURE_2D, G7_Ganpati);

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
	glPopMatrix();

	glPushMatrix();
		// Doar 
		glColor3f(0.7, 0.7, 0.7);
		glTranslatef(0, 0.05, 0);
			Doar(G2_Brick_1);

		glColor3f(1,1,1);
	glPopMatrix();

}
