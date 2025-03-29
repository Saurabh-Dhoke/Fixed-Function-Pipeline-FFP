
#pragma once
#include<math.h>

GLfloat G3_Angle = 0.0;


// Function Definations
void Start_G_3()
{
	fogColor[0] = 0.5;
	fogColor[1] = 0.5;
	fogColor[2] = 0.5;
	fogColor[3] = 1.0;

	glFogfv(GL_FOG_COLOR, fogColor); // Fog color 
	glFogf(GL_FOG_DENSITY, 0.012f);


	static float Angle = 0;

	// Function Declarations 
	void G3_Temple();
	void Environment_G3();
	void Stairs_G3();


	// Code
	if (Map3_Flag == TRUE)
	{
		Sidhivinayak_31(); 
	}
	else if (G3_Flag == TRUE)
	{
		glPushMatrix();
			glEnable(GL_FOG);

			glTranslatef(0,-1.45, -6.85);
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
			static float cam_y = 14.0;
			static float cam_z = -32.5;
			static float cam_x1 = 0.0;
			static float cam_y1 = 0.0;

			// Code

			glTranslatef(0,-1.45, -6.85);

			//---------------------------------------------------			
			// 1
			//  X = 0.0  , y =  14.0, z = -32.50 , x1 = 0, y1 = 0.0
			//             y = -1.50, z =  13.0  ,         y1 = 0.0
			if (Flag_1 == TRUE)
				{
					if (cam_y > -1.5)
						cam_y = cam_y - 0.06;

					if (cam_z < 4.0)
						cam_z = cam_z + 0.12; 
					else if(cam_z < 13)
						cam_z = cam_z + 0.035;

					else
					{
						Flag_1 = FALSE;
						Flag_2 = TRUE;
					    
						// Assigning Values of next camara movments 
						cam_x = 7.0;
						cam_y = -0.55;
						cam_z = 5.5;

						cam_x1 = 174.0;
						cam_y1 = 3.0;
					}
				}
				
			//--------------------------------------------------------
			// 2
			//  X = 0.7  , y = -0.1 , z = 0.550 , x1 = 174, y1 = 0.3
			//                                    x1 = 59
			if (Flag_2 == TRUE)
				{
					if (cam_x1 > 100.0)
						cam_x1 = cam_x1 - 0.18;
					else
					{
						Flag_2 = FALSE;
						Flag_4 = TRUE;
					    
						// Assigning Values of next camara movments 
						/*cam_x = 0.0;
						cam_y = 0.0;
						cam_z = 0.0;
					 
						cam_x1 = -31.0;
						cam_y1 =   0.0;*/

						cam_x = 0.0;
						cam_y = -0.10;
						cam_z = 10.6;

						cam_x1 = 0.0;
						cam_y1 = 0.0;
					}
				}

			////----------------------------------------------
			//// 3
			////  X = 0.0  , y = 0 , z = 0.0 , x1 = -31.0, y1 = 0.0
			////                               x1 = 180.0
			//if (Flag_3 == TRUE)
			//{
			//	if (cam_x1 < 70.0)
			//		cam_x1 = cam_x1 + 0.08;
			//	else
			//	{
			//		Flag_3 = FALSE;
			//		Flag_4 = TRUE;

			//		// Assigning Values of next camara movments 
			//		cam_x = 0.0;
			//		cam_y =-0.10;
			//		cam_z = 10.6;

			//		cam_x1 = 0.0;
			//		cam_y1 = 0.0;
			//	}
			//}

			////----------------------------------------------
			// 4
			//  X = 0.0  , y = -0.35 , z = 10.6 , x1 = 0.0, y1 = 0.0
			//           , y = -2.3  , z = 0.8 
			if (Flag_4 == TRUE)
			{
				if (cam_y > -2.3)
					cam_y = cam_y - 0.0015;
				if (cam_z > 1.5)
					cam_z = cam_z - 0.0101;
				else
				{
					Flag_4 = FALSE;
					Scene_Count = 4;
				}
			}

	//----------------------------------------------------------
			gluLookAt(cam_x, cam_y, cam_z, cam_x1, cam_y1, 100, 0, 1, 0);
			tz = cam_z;  // for Gate open and close

			//gluLookAt(tx*10, ty, tz,0,0, 100, 0, 1, 0);
	//----------------------------------------------------------

			//glEnable(GL_FOG);
			// Function Calls
			G3_Temple();

			// Pooja 
			glPushMatrix();

				glTranslatef(0.6, 0.55, 3.5);
				glScalef(0.5, 0.3, 1.0);
					Load_Har(Pooja2);
			glPopMatrix();

			// Har 
			glPushMatrix();
				glTranslatef(0.04, 1.6, 1.89);
				glScalef(0.6, 0.5, 1.0);
					Load_Har(Har7);
			glPopMatrix();

			// Ghanta 
			glPushMatrix();
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
						Load_PNG(Rangoli3, Color_Arr);
			glPopMatrix();

			// Environment 
			Environment_G3();

			//glDisable(GL_FOG);
		glPopMatrix();
	}
}

void Ghumat_Cube_G3(GLuint texture)
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture);
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

			
			glColor3f(0.2, 0.2, 0.2); 
			// Top face pattya 
			// Front  
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0,  1.0,  -0.8);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0,  1.0 , -0.8);   // right bottom
			glEnd(); 

			// Back  
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, 0.8);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, 0.8);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 

			// Left  
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( -0.8,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.0);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( -0.8,  1.0 , 1.0);   // right bottom
			glEnd(); 

				// Right 
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(0.8,  1.0, -1.0);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(0.8,  1.0,  1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
			glEnd(); 


			glColor3f(0.5, 0.5 , 0.5);

		glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
			

}
void Pyramid_G3(GLuint texture)
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
void Ghumat_G3(GLuint texture)
{

	glPushMatrix();

		glTranslatef(0, -0.80, 0);
		glScalef(1.0, 0.10, 1.0);
		glColor3f(0.5, 0.5, 0.5);
		
		for (int i = 0; i < 7; i++)
		{
			Ghumat_Cube_G3(texture);


			glTranslatef(0, 1.7 , 0);
			glScalef(0.80, 0.80, 0.80);
		}

		glTranslatef(0, 2.1, 0);
		glScalef(1.0, 3.0, 1.0);

			Pyramid_G3(texture);
	glPopMatrix();
}

void Sky(GLuint texture)
{
	glPushMatrix();
		glRotatef(44.7, 1, 0, 0);
		glRotatef(46, 1, 0, 0);
		glRotatef(177.602, 0, 1, 0);
		glRotatef(-128.699, 0, 0, 1);

		gluQuadricTexture(quadric, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
			gluSphere(quadric, 50.0f, 100, 100);
		glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();
}
void Flat_Ground(GLuint texture)
{
	glPushMatrix();
		glTranslatef(0.0, 10.1, 0.0);
		glScalef(10.0, 10.0, 10.0);
	
		glBindTexture(GL_TEXTURE_2D, texture);

			// Bottom Face 
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
	glPopMatrix();
}
void Flat_Quad()
{
	glPushMatrix();
			// Bottom Face 
			glBegin(GL_QUADS); 
				glVertex3f( 1.0, -1.0, -1.0);    // right t
				glVertex3f(-1.0, -1.0, -1.0);    // left top	
				glVertex3f(-1.0, -1.0,  1.0);    // left bottom
				glVertex3f( 1.0, -1.0 , 1.0);   // right bottom
			glEnd(); 
	glPopMatrix();
}
void Compound_G3(GLuint texture)
{
	glPushMatrix();
			
			// Left Wall
			glPushMatrix();
				glTranslatef(5.5, 0.7, -1.2);
				glScalef(0.1, 0.7, 6.0);
					Base_G1_C(texture);
			glPopMatrix();

			// Right Wall
			glPushMatrix();
				glTranslatef(-5.5, 0.7, -1.2);
				glScalef(0.1, 0.7, 6.0);
					Base_G1_C(texture);
			glPopMatrix();


			// Back Wall
			glPushMatrix();
				glTranslatef(0.0, 0.7, 4.8);
				glRotatef(90, 0, 1, 0);
				glScalef(0.1, 0.7, 5.6);
					Base_G1_C(texture);
			glPopMatrix();

			// Front Wall
			// Left 
			glPushMatrix();
				glTranslatef(3.1, 0.7, -7.2);
				glRotatef(90, 0, 1, 0);
				glScalef(0.1, 0.7, 2.4);
					Base_G1_C(texture);
			glPopMatrix();
			// Right
			glPushMatrix();
				glTranslatef(-3.2, 0.7, -7.2);
				glRotatef(90, 0, 1, 0);
				glScalef(0.1, 0.7, 2.47);
					Base_G1_C(texture);
			glPopMatrix();


	glPopMatrix();
}

void Flat_Tex_Quad(GLuint texture)
{
	glPushMatrix();	
		glBindTexture(GL_TEXTURE_2D, texture);

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
	glPopMatrix();

}
void Front_Tex_Quad(GLuint texture)
{
	glPushMatrix();	
		glBindTexture(GL_TEXTURE_2D, texture);

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
	glPopMatrix();

}

void Gate()
{
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
						
						glRotatef(G3_Angle, 0, 1, 0);
						glTranslatef(-1.0, 0.0, 1.0);
							Front_Tex_Quad(G3_Gate1);
					glPopMatrix();

					// Right Side 
					glPushMatrix();

						glTranslatef(-0.70, 0.8, -7.12);
						glScalef(0.355,0.7, 1.0);
						
						glRotatef(-G3_Angle, 0, 1, 0);
						glTranslatef(1.0, 0.0, 1.0);
							Front_Tex_Quad(G3_Gate2);
					glPopMatrix();

				glDisable(GL_BLEND);
				glEnable(GL_DEPTH);
			glPopMatrix();
}
void Grass_Trees_G3()
{
	glPushMatrix();
		Color_Arr[0] = 0.4;//  color
		Color_Arr[1] = 0.4;
		Color_Arr[2] = 0.4;

		// Tree1 
		glPushMatrix();			
			glTranslatef(-35.3, 2.6, 33.60);
			glScalef(3.1, 2.8, 1.0);

			for (int i = 0; i < 5; i++)
			{	
				glRotatef(10, 0, 1, 0);
				glTranslatef(4.7, 0.0, 0.0);
				Load_PNG(Tree5, Color_Arr);
			}

			
			for (int i = 0; i < 5; i++)
			{
				glTranslatef(2.5, 0.0, -6.9);
				Load_PNG(Tree4, Color_Arr);
			}

			for (int i = 0; i < 5; i++)
			{
				glTranslatef(4.0, 0.0,2.2);
				//glTranslatef(2.5, -0.1, -6.9);
				Load_PNG(Tree2, Color_Arr);
			}

		glPopMatrix();

		
	glPopMatrix();


}

void Environment_G3()
{
	
	// Gate Animation 
	if (tz > 4.0 && G3_Angle < 90.0)
	{
		G3_Angle = G3_Angle + 0.5;
	}
	else if (tz <= 4.0 && G3_Angle > 0.0)
	{
		G3_Angle = G3_Angle - 0.5;

	}

	// Code
	glPushMatrix();

		// Sky
		glPushMatrix();
			//glTranslatef(sx * 10, sy * 10, sz * 10);
		glColor3f(0.2, 0.2, 0.2);

				Sky(G3_Sky);
		glPopMatrix();
		
		// Main Ground 
			glPushMatrix();
				glTranslatef(0.0, -0.1,0.0 );
				glScalef(5.0, 1.0, 5.0);
					glColor3f(0.0, 0.25, 0.0);
					Flat_Ground(G3_Grass_1);
			glPopMatrix();

		   // Tiles
			glColor3f(0.7,0.7,0.7);
			glPushMatrix();
				glTranslatef(0.1,-0.1,-1.3);
				glScalef(0.55,1.7,0.6);
					Flat_Ground(G2_Soil);				
			glPopMatrix();

			glColor3f(0.5, 0.5, 0.5);
			Compound_G3(G3_Wall); 

			// Road
			glPushMatrix();
				glColor3f(0.5, 0.5 ,0.5);
				glTranslatef(0.0, 1.102, -8.8);
				glScalef(0.8,1.0, 5.0);
					Flat_Tex_Quad(G3_Tile);
				
			glPopMatrix();

			
			// Bench an danpeti 
			glPushMatrix();
				// Right danpeti 
				glPushMatrix();
					//glTranslatef(-0.7,0.45, 0.6);
					glTranslatef(1.6, 0.8, -0.6);
					glRotatef(90, 0, 1, 0);
					glScalef(0.3,0.6, 0.4);
						glColor3f(0.6, 0.6, 0.6);
						Danpeti2();
				glPopMatrix();
				
				//left danpeti 
				glPushMatrix();
					//glTranslatef(0.7,0.45, 0.6);
					glTranslatef(-1.6, 0.8, -0.6);
					glRotatef(-90, 0, 1, 0);
					glScalef(0.3,0.6, 0.4);
						glColor3f(0.6, 0.6, 0.6);
						Danpeti2();
				glPopMatrix();

				//left Bench 
				glPushMatrix();
					glColor3f(1, 1, 1);
					glTranslatef(6.2, -0.3, 0.6);
					glRotatef(90, 0, 1, 0);
					glScalef(3.2, 0.9,0.7);
						Marbal_Chair(G1_Wood);

						glTranslatef(0.9, 0, 0);
						Marbal_Chair(G1_Wood);
				glPopMatrix();

				// right bench 
				glPushMatrix();
					glColor3f(1, 1, 1);
					glTranslatef(-6.4, -0.3, -0.3);
					glRotatef(-90, 0, 1, 0);
					glScalef(3.2, 0.9,0.7);
						Marbal_Chair(G1_Wood);
					glTranslatef(-0.9, 0, 0);
						Marbal_Chair(G1_Wood);
				glPopMatrix();
			glPopMatrix();

			// Flag 
			glPushMatrix();
				glTranslatef(-0.8, 5.9, 12.7);
				glScalef(-0.8, 0.5, 2.0);

				Flag_Wave();
			glPopMatrix();

			// Gate 
			Gate();

			// Grass
			Grass_Trees_G3();

	glPopMatrix();

}

void G3_Temple()
{
	// Function Declarations 
	//void Base_G3(GLuint);
	void Mandir_G3();
	void Temple_Base_G3();

	// Code

	glPushMatrix();
		glColor3f(0.1, 0.5, 0.5);
		// Payarya middle 
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
			/*glTranslatef(tx, ty, tz);
			glScalef(sx,sy,sz);*/

			
		// Base 
		glPushMatrix();
			//glColor3f(0.25, 0.25, 0.25);

			glTranslatef(0.0, 0.0, -1.0);
			glScalef(2.0, 0.4, 2.0);
				Temple_Base_G3();
		glPopMatrix();

		// SIde Kathade
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(1.9,0.7, -1.0);
			glScalef(0.1, 0.3, 2.0);
					Base_G1(G1_Wood);
		glPopMatrix();
		glPushMatrix();
			//glColor3f(1, 1, 0);
			glTranslatef(-1.9, 0.7, -1.0);
			glScalef(0.1, 0.3, 2.0);
					Base_G1(G1_Wood);
		glPopMatrix();

		// Front kathade
		glPushMatrix();
			//glColor3f(0, 1, 1);
			glTranslatef(1.3, 0.7, -2.9);
			glScalef(0.5, 0.3, 0.1);
					Base_G1(G1_Wood);
		glPopMatrix();
		glPushMatrix();
			//glColor3f(0, 1, 1);
			glTranslatef(-1.3, 0.7, -2.9);
			glScalef(0.5, 0.3, 0.1);
					Base_G1(G1_Wood);
		glPopMatrix();

		// Side Bar 
		glPushMatrix();
			// Left 
			glPushMatrix();
				glColor3f(0.5, 0.5, 0.5);
				glTranslatef(0.9, 1.8, -2.9);
				glScalef(0.05, 0.8, 0.05);
						Base_G1(G1_Wood);
				
				glTranslatef(19.9,0.0, 0.0);
						Base_G1(G1_Wood);

				glTranslatef(0.0,0.0, 36.40);
				glScalef(1.0, 1.38, 1.0);

						Base_G1(G1_Wood);
			glPopMatrix();

			// Right
			glPushMatrix();
				glColor3f(0.5, 0.5, 0.5);
				glTranslatef(-0.9, 1.8, -2.9);
				glScalef(0.05, 0.8, 0.05);
						Base_G1(G1_Wood);
				
				glTranslatef(-19.9,0.0, 0.0);
						Base_G1(G1_Wood);

				glTranslatef(0.0,0.0, 36.40);
				glScalef(1.0, 1.38, 1.0);
						Base_G1(G1_Wood);
			glPopMatrix();
		glPopMatrix();

		// Slap 
		glPushMatrix();
		glColor3f(0.25, 0.25, 0.25);
		glTranslatef(0.0, 2.6, -1.0);
			glScalef(2.0, 0.3, 2.0);
					Base_G1(G1_Wood);
		glPopMatrix();

		// Name
		glPushMatrix();
			glTranslatef(0.0, 2.55, -1.99);
			glScalef(1.0, 0.15, 1.0);

				glBindTexture(GL_TEXTURE_2D, G3_Name);

				glDisable(GL_DEPTH);
				glEnable(GL_BLEND);

					glColor4f(1.0, 1.0,1.0, 0.5);   // For Transperancy 
					glColor3f(1,0.5,0);         // Bhagava Color

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

				glDisable(GL_BLEND);
				glEnable(GL_DEPTH);
		glPopMatrix();

		// Mandir
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(0.0, 1.6, 2.0);
			glScalef(2.0,1.5, 1.0);
					Mandir_G3(G1_Stairs);
		glPopMatrix();
	glPopMatrix();

}
void Temple_Base_G3()
{
	// Code
	

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

		
			// Top Face 
			glColor3f(0.4, 0.4, 0.4);

			glTranslatef(0.0, 0.0, 0.50);

			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f( 1.0,  1.0, -1.5);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, -1.5);    // left top	

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0,  1.0,  1.5);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f( 1.0,  1.0 , 1.5);   // right bottom
			glEnd(); 
		glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

}
void Mandir_G3()
{
	// Code 
	
	glPushMatrix();	
		glTranslatef(0.0, 2.5, 0.0);
		glScalef(0.8 , 1.7, 0.8);
			Ghumat_G3(G3_Stone2);
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
				glTranslatef(0.0, -0.4, 1.7);
				glRotatef(10, 1, 0, 0);
				glScalef(0.5, 0.6, 1.0);
			
				glBindTexture(GL_TEXTURE_2D, G3_Ganpati);

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
		glColor3f(0.5, 0.5, 0.5);
		glTranslatef(0, 0.05, 0);
			Doar(G1_Wood);

		glColor3f(1,1,1);
	glPopMatrix();

}
