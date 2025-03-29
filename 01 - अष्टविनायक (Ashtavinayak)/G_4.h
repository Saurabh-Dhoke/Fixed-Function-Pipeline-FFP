
#pragma once
#include<math.h>

GLfloat G4_Angle = 0.0;
 
// Function Definations
void Start_G_4()
{
	fogColor[0] = 1.0;
	fogColor[1] = 0.5;
	fogColor[2] = 0.0;
	fogColor[3] = 1.0;

	glFogfv(GL_FOG_COLOR, fogColor); // Fog color 
	glFogf(GL_FOG_DENSITY, 0.006f);

	// Function Declarations 
	void G4_Temple();
	void Environment_G4();
	void Gate_7();
	void Grill();
	void Shead_G4(); 
	void Grass_Trees_G4();
	
	// variable declarations 
	static float angleR = 0.0;

	// Code
	
	if (Map4_Flag == TRUE)
	{
		Rajangav_41();
	}
	else if (G4_Flag == TRUE)
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

			static BOOL Rotate_Flag = TRUE;
						
			static float cam_x = 0.0;
			static float cam_y = 3.30;
			static float cam_z = 1.75;
			static float cam_x1 = 0.0;
			static float cam_y1 = 0.0;

			//glRotatef(90, 0, 1, 0);
			glRotatef(angleR, 0, 1, 0);
			glTranslatef(0, -1.45, -6.85);
			
			//---------------------------------------------------			
			// 1
			//  X = 0.0  , y =  3.25, z =  1.75 , x1 = 0.0, y1 = 0.0
			//             y =  0.50, z = -16.5 			
			if (Flag_1 == TRUE)
				{
					if (cam_y > 0.50)
						cam_y = cam_y - 0.008;

					if (cam_z > -16.5)
						cam_z = cam_z - 0.060; 

					else
					{
						Flag_1 = FALSE;
						Flag_2 = TRUE;
					}
				}
				
			//--------------------------------------------------------
			// 2
			// x =0,   y =  0.50,  z = -16.5 , x1 = 0.0, y1 = 0.0
			//         y = -0.25,  z = 8.0			
			if (Flag_2 == TRUE)
			{
				if (cam_y > -0.25)
					cam_y = cam_y - 0.004;

				if(cam_z < -5.0)
					cam_z = cam_z + 0.040;

				else if (cam_z < 3.0)
					cam_z = cam_z + 0.028;

				else if(cam_z < 8.0)
					cam_z = cam_z + 0.015;

				else
				{
					Flag_2 = FALSE;
					Flag_3 = TRUE;
				}
			}
		
			//--------------------------------------------------------
			// 3
			// x =0,    y = -0.25,  z = 8.0	,  x1 = 0.0, y1 = 0.0
			// x =0,   y =  -0.75,  z = 4.25 , x1 = 0.0, y1 = 0.0
			
			if (Flag_3 == TRUE)
			{
				if (cam_z > 4.25)
					cam_z = cam_z - 0.010;

				else
				{
					Flag_3 = FALSE;
					Flag_4 = TRUE;

					// Assigning Values of next camara movments 
					cam_x = 0.00;
					cam_y = 0.15;
					cam_z = 5.40;

					cam_x1 = 0.0;
					cam_y1 = 0.0;

					angleR = -131.0;
				}
			}
		
			//--------------------------------------------------------
			// 4
			// x =0,    y = 0.10,  z = 5.4	,x1 = 0.0, y1 = 0.0, angleR = -131.0
			//                                                   angleR = 133.0
			//          y = 6.60
			
			if (Flag_4 == TRUE )
			{
				if (Rotate_Flag == TRUE)
				{
					if (angleR < 133.0)
						angleR = angleR + 0.30;
					else
						Rotate_Flag = FALSE;
				}
				else
				{
					Flag_4 = FALSE;
					Scene_Count = 5;
				}

			/*	else
				{
					if (cam_y < 6.6) 
						cam_y = cam_y + 0.002; 
					else
					{
						Flag_4 = FALSE;
						Scene_Count = 5;
					}

					if (angleR > 0.0)
						angleR = angleR - 0.1;
					else
						angleR = 360.0;					
				}*/
			
				glDisable(GL_FOG);

			}			
			
			gluLookAt(cam_x, cam_y, cam_z, cam_x1, cam_y1, 100, 0, 1, 0);


			//gluLookAt(2.0 * tx, 2 * ty, 2 * tz, 0.0, 0.0, 100, 0, 1, 0);


	//----------------------------------------------------------------

			// Function Calls
			
			glColor3f(1,1,1);


			Environment_G4();


			
			G4_Temple();

			// Grass
			Grass_Trees_G4();
		glPopMatrix();
	}
	
}

void Compound_G4()
{
	glPushMatrix();			
			// Left Wall
			glPushMatrix();
				glTranslatef(5.5, 1.5,-6.3);
				glScalef(0.1, 1.5, 11.3);
					Base_G1(G4_Stone2);
			glPopMatrix();

			// Right Wall
			glPushMatrix();
				glTranslatef(-5.5, 1.5, -6.3);
				glScalef(0.1, 1.5, 11.3);
					Base_G1(G4_Stone2);
			glPopMatrix();


			// Back Wall
			glPushMatrix();
				glTranslatef(0.0,1.5,4.8);
				glRotatef(90, 0, 1, 0);
				glScalef(0.1, 1.5, 5.6);
					Base_G1(G4_Stone2);
			glPopMatrix();

			// Front Wall
			// Left 
			glTranslatef(0,0.0, -10.3);

			glPushMatrix();
				glTranslatef(3.0, 1.5, -7.2);
				glRotatef(90, 0, 1, 0);
				glScalef(0.1, 1.5, 2.58);
					Base_G1(G4_Stone1);
			glPopMatrix();
			// Right
			glPushMatrix();
				glTranslatef(-3.1, 1.5, -7.2);
				glRotatef(90, 0, 1, 0);
				glScalef(0.1, 1.5, 2.65);
					Base_G1(G4_Stone1);
			glPopMatrix();


	glPopMatrix();
}
void Grass_Trees_G4()
{
	glPushMatrix();
		Color_Arr[0] = 0.5;//  color
		Color_Arr[1] = 0.5;
		Color_Arr[2] = 0.5;

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
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-32.6, 2.6, 18.4);
			glScalef(3.1, 2.8, 1.0);

			for (int i = 0; i < 5; i++)
			{	
				glRotatef(10, 0, 1, 0);
				glTranslatef(5.5, 0.0, 0.0);
				Load_PNG(Tree2, Color_Arr);
			}
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-54.8, 2.8, 9.8);
			glScalef(3.1, 4.1, 1.0);

			for (int i = 0; i < 5; i++)
			{	
				glRotatef(10, 0, 1, 0);
				glTranslatef(7.5, 0.0, 0.0);
				Load_PNG(Tree3, Color_Arr);
			}
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-53.7, 3.7, -13.7);
			glScalef(3.1, 4.1, 1.0);

			for (int i = 0; i < 5; i++)
			{	
				glRotatef(10, 0, 1, 0);
				glTranslatef(7.5, 0.0, 0.0);
				Load_PNG(Tree3, Color_Arr);
			}
		glPopMatrix();

		
	glPopMatrix();


}

void Environment_G4()
{
	
	// Code
	glPushMatrix();
		
		//glTranslatef(sx, sy, sz);

		glPushMatrix();
			glRotatef(-177.302, 1, 0,0);
			glRotatef( 309.110, 0, 1,0);
			glRotatef( 2.600,   0, 0,1);
				glColor3f(0.7, 0.7, 0.7);
			    Sky(G4_Sky);
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
			glTranslatef(0.1,-0.1,-7.0);
			glScalef(0.65, 1.7, 1.2);
				Flat_Ground(Tile1);				
		glPopMatrix();


		// Bench an danpeti 
			glPushMatrix();
				// Right danpeti 
				glPushMatrix();
					glTranslatef(1.6, 0.8, -0.6);
					glScalef(0.3,0.6, 0.4);
						glColor3f(0.6, 0.6, 0.6);
						Danpeti1();
				glPopMatrix();
				
				//left danpeti 
				glPushMatrix();
					glTranslatef(-1.6, 0.8, -0.6);
					glScalef(0.3,0.6, 0.4);
						glColor3f(0.6, 0.6, 0.6);
						Danpeti1();
				glPopMatrix();

				//left Bench 
				glPushMatrix();
					glColor3f(1, 1, 1);

					glTranslatef(7.3, -0.3, -3.0);
					glRotatef(90, 0, 1, 0);
					glScalef(3.2, 0.9,0.7);
						WoodenChair(G1_Wood);

					glTranslatef(1.3, 0, 0);
						WoodenChair(G1_Wood);

					glTranslatef(1.3, 0, 0);
						WoodenChair(G1_Wood);

					glTranslatef(1.3, 0, 0);
						WoodenChair(G1_Wood);
				glPopMatrix();

				// right bench 
				glPushMatrix();
					glColor3f(1, 1, 1);
					glTranslatef(-7.5, -0.3, -3.3);
					glRotatef(-90, 0, 1, 0);
					glScalef(3.2, 0.9,0.7);
						WoodenChair(G1_Wood);
					
					glTranslatef(-1.3, 0, 0);
						WoodenChair(G1_Wood);
						
					glTranslatef(-1.3, 0, 0);
						WoodenChair(G1_Wood);

					glTranslatef(-1.3, 0, 0);
						WoodenChair(G1_Wood);
				glPopMatrix();
			glPopMatrix();

			

	glPopMatrix();

}

void Shree()
{
	
		// Name
		glPushMatrix();
			
			Color_Arr[0] = 1.0; // Bhagava color
			Color_Arr[1] = 0.5;
			Color_Arr[2] = 1.0;

			glScalef(0.1, 0.1, 0.1);
				Load_PNG(G4_Shree, Color_Arr);

				glColor3f(1.0, 1.0, 1.0);
		glPopMatrix();

}
void Gate_G4()
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
						
						glRotatef(G4_Angle, 0, 1, 0);
						glTranslatef(-1.0, 0.0, 1.0);
							Front_Tex_Quad(G4_Gate1);
					glPopMatrix();

					// Right Side 
					glPushMatrix();

						glTranslatef(-0.70, 0.8, -7.12);
						glScalef(0.355,0.7, 1.0);
						
						glRotatef(-G4_Angle, 0, 1, 0);
						glTranslatef(1.0, 0.0, 1.0);
							Front_Tex_Quad(G4_Gate2);
					glPopMatrix();

				glDisable(GL_BLEND);
				glEnable(GL_DEPTH);
			glPopMatrix();
}

void G4_Temple()
{



	// Function Declarations 
	void Mandir_G4_1();
	void Mandir_G4_2();
	void Shead_Base_G4();
	void Shead_G4();
	void Grill_G4();
	void Grill_Shead_G4();
	
	//---------------------------------------
	// Gate Animation 
	if (tz > -13.5 && G4_Angle < 80.0)
	{
		G4_Angle = G4_Angle + 0.5;
	}
	else if (tz <= -13.5 && G4_Angle > 0.0)
	{
		G4_Angle = G4_Angle - 0.5;

	}
	//---------------------------------------

	// Code
	
	// Payarya  
	glPushMatrix();
		glColor3f(0.1, 0.5, 0.5);
		glTranslatef(0.0, 0.05, -14.55);
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
			glTranslatef(0.0, 0.2, -9.3);
			glScalef(2.5, 0.2,4.4);
				Shead_Base_G4();
		glPopMatrix();



		// Mandir
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(0.0, 1.6, 2.0);
			glScalef(2.0,1.5, 1.0);
					Mandir_G4_1(G1_Stairs);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(0.0, 2.4, -1.86);
			glScalef(3.0,2.5, 3.0);
					Mandir_G4_2(G1_Stairs);
		glPopMatrix();

		// Shead
		Shead_G4();

		// Name
		glPushMatrix();
			
			Color_Arr[0] = 1.0; // Bhagava color
			Color_Arr[1] = 0.5;
			Color_Arr[2] = 1.0;

			glTranslatef(0.0, 4.9, -3.9);
			glScalef(2.3 , 0.6, 1.0);
				Load_PNG(G4_Name, Color_Arr);

				glColor3f(1.0, 1.0, 1.0);
		glPopMatrix();

		// Grill
		glPushMatrix();
			glTranslatef(0.1,  0.7, -1.7);
			glScalef(2.0, 0.3 , 1.8);
				Grill_G4();
		glPopMatrix();


		// Shree 
		glPushMatrix();
			glTranslatef(0.1, 2.75, -5.0);
				Shree();
		
		glPopMatrix();

		// Har 
		glPushMatrix();
			glTranslatef(0.04, 1.32, 1.94);
			glScalef(0.6, 0.5, 1.0);
				Load_Har(Har4);
		glPopMatrix();

		// bahercha Har 
		glPushMatrix();
			glTranslatef(0.06, 2.16, -4.01);
			glScalef(0.6 , 0.5, 1.0);
				Load_Har(Har5);
		glPopMatrix();

		// Ghanta 
		glPushMatrix();
			glTranslatef(0.105, 2.66, -5.5);
			glScalef(0.11 ,0.55, 1.0);
				Load_Har(Ghanta);

		glPopMatrix();

		// Baherach Grill
		glPushMatrix();
			glColor3f(0,0,0);
			glTranslatef(0.1, 0.7, -10.7);
			glScalef(2.0, 0.3, 2.8);

				Grill_Shead_G4();
			glColor3f(1,1,1);
		glPopMatrix();

		// Flag 
		glPushMatrix();
			glTranslatef(-0.7, 9.9 , 8.6);
			glScalef(-0.8, 0.5, 2.0);

				Flag_Wave();
		glPopMatrix();

	glPopMatrix();

}

void Grill_G4()
{
	glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, G4_Grill);

		glDisable(GL_DEPTH);
		glEnable(GL_BLEND);

		glColor4f(1.0, 1.0, 1.0, 0.5);   // For Transperancy 
		glColor3f(0.0, 0.0, 0.0);

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

			// Front 
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
			glDisable(GL_BLEND);
			glEnable(GL_DEPTH);
		glPopMatrix();
}
void Grill_Shead_G4()
{
	glPushMatrix();


		glDisable(GL_DEPTH);
		glEnable(GL_BLEND);

		glColor4f(1.0, 1.0, 1.0, 0.5);   // For Transperancy 
		glColor3f(0.0, 0.0, 0.0);

			glBindTexture(GL_TEXTURE_2D, G4_Grill);

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
			
			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(1.0,  1.0, 1.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0,  1.0,  2.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0 , 2.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(1.0, -1.0 , 1.0);   // right bottom
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

			glBegin(GL_QUADS); 
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0,  1.0, 2.0);    // right top

				glTexCoord2f(1.0, 0.0);
				glVertex3f(-1.0,  1.0, 1.0);    // left top	 

				glTexCoord2f(1.0, 1.0);
				glVertex3f(-1.0, -1.0, 1.0);    // left bottom

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0 , 2.0);   // right bottom
			glEnd(); 

		glBindTexture(GL_TEXTURE_2D, 0);

		glBindTexture(GL_TEXTURE_2D, G4_FGrill);
			glTranslatef(0, 0, -0.3);
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

			glTranslatef(0, 0, -0.8);
			// Back Face 2
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

			// Front 
			glTranslatef(0, 0, 1.1);

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
	

			glDisable(GL_BLEND);
			glEnable(GL_DEPTH);
		glPopMatrix();
}

void Shead_Base_G4()
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
		
		glBindTexture(GL_TEXTURE_2D, G4_Tile2);
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
void Shead_G4()
{
	glPushMatrix();
		glColor3f(0.3 , 0.3 ,0.3);

		glTranslatef(0.1, 0.7, -2.4);
		glScalef(1.3, 1.0, 1.1);
			Shed_G2();
	
		glColor3f(0.3 , 0.3 ,0.3);
		glTranslatef(0.0, 0.0, -4.0);
			Shed_G2();

		glColor3f(1, 1, 1);
	glPopMatrix();
}

void Ghumat_Cube_G4(GLuint texture)
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
void Ghumat_G4_1(GLuint texture)
{

	glPushMatrix();

		glTranslatef(0, -0.80, 0);
		glScalef(1.0, 0.10, 1.0);
		glColor3f(0.5, 0.5, 0.5);
		
		for (int i = 0; i < 7; i++)
		{
			Ghumat_Cube_G4(texture);


			glTranslatef(0, 1.7 , 0);
			glScalef(0.80, 0.80, 0.80);
		}

		glTranslatef(0, 2.1, 0);
		glScalef(1.0, 3.0, 1.0);

			Pyramid(texture);
	glPopMatrix();
}
void Ghumat_G4_2()
{
	glPushMatrix();

		glTranslatef(0, -0.80, 0);
		glScalef(1.0, 0.20, 1.0);
		glColor3f(0.5, 0.5, 0.5);
			
		for (int i = 0; i < 7; i++)
		{

			Ghumat_Cube_G4(G4_Golden_design1);

			glTranslatef(0, 1.7 , 0);
			glScalef(0.80, 0.80, 0.80);


		}

		glTranslatef(0,  1.3, 0);
		glScalef(1.0, 2.5, 1.0);
			Pyramid(G4_Golden_design1);
	glPopMatrix();

	glPushMatrix();

		glTranslatef(0, -0.80, 0);
		glScalef(1.0, 0.20, 1.0);
		glColor3f(0.5, 0.5, 0.5);
			
		for (int i = 0; i < 7; i++)
		{
			Ghumat_Cube_G4(G4_Brick1);


			glTranslatef(0, 1.7 , 0);
			glScalef(0.82, 0.82, 0.82);


		}

		glTranslatef(0, 2.1, 0);
		glScalef(1.0, 3.0, 1.0);

			Pyramid(G4_Brick3);
	glPopMatrix();
}

void Mandir_G4_1()
{
	// Code 

	glPushMatrix();	
		glTranslatef(0.0, 1.4, 0.0);
			Ghumat_G4_1(G4_Brick0);
	glPopMatrix();

	glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, G4_Brick3);
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

			// Doar chya varacha Quad 
			glBindTexture(GL_TEXTURE_2D, G4_Brick1);
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

		glPopMatrix();



			glPushMatrix();
				glColor3f(1, 1, 1);

				glTranslatef(0.0,-0.1, 1.7);
				glScalef(0.65, 0.7, 1.0);
			
				glBindTexture(GL_TEXTURE_2D, G4_Ganpati);

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
void Mandir_G4_2()
{
	// Function declarations 
	void Front_Wall();
	void G4_Photos();


	// Code 

	glPushMatrix();	
		glTranslatef(0.0, 2.0, 0.0);
			Ghumat_G4_2();
	glPopMatrix();

	glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, G4_Brick3);
			//// Back Face 
			//glBegin(GL_QUADS); 
			//	glTexCoord2f(0.0, 0.0);
			//	glVertex3f(1.0, 1.0, 1.0);     // right top
	
			//	glTexCoord2f(2.0, 0.0);
			//	glVertex3f(-1.0, 1.0, 1.0);    // left top	
		
			//	glTexCoord2f(2.0, 2.0);
			//	glVertex3f(-1.0, -1.0 , 1.0);  // left bottom
		
			//	glTexCoord2f(0.0, 2.0);
			//	glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
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
			glBindTexture(GL_TEXTURE_2D, 0); // Unbined texture 

			glPushMatrix();
				Front_Wall();

				glTranslatef(0.0, 0.0, 2.0);
					Front_Wall();
				
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0, 0.2, 0);
					glBindTexture(GL_TEXTURE_2D, G4_Tile);
					// Bottom Face Floar
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
			
	glPopMatrix();

	glPushMatrix();
		// Doar 
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0, 0.05, 0);
			Doar(G4_Tile);

		glColor3f(1,1,1);
	glPopMatrix();

	// Aaatale Photos 
	glPushMatrix();
		G4_Photos();
	glPopMatrix();

}

void G4_Photos()
{
	glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);

		glPushMatrix();
			glScalef(0.22, 0.3, 1.1);

			// 1
			glTranslatef(3.0, -0.5, 0.1);
			glRotatef(90, 1, 0, 0);
				Flat_Tex_Quad(G1);
		
			// 8
			glTranslatef(-5.8, 0.0, 0.0);
				Flat_Tex_Quad(G8);
		glPopMatrix();


		glPushMatrix();
			glTranslatef(1.2, -0.15, -0.5);
			glRotatef(90, 0, 1, 0);
			glRotatef(90, 1, 0, 0);
			glScalef( 0.26, 0.26, 0.30);
				
			// Left Side Vale Ganpati 
				glPushMatrix();
					glTranslatef(0.0, -0.2, 0.0);
						Flat_Tex_Quad(G2);
			
					glTranslatef(-2.2, 0.2, 0.0);			
						Flat_Tex_Quad(G3);
			
					glTranslatef(-2.2, 0.0, 0.0);			
						Flat_Tex_Quad(G4);
				glPopMatrix();
		
			// Right Side Vale Ganpati 
				glPushMatrix();
					glTranslatef(0.0, -7.459, 0.0);
						Flat_Tex_Quad(G5);
			
					glTranslatef(-2.2, 0.0, 0.0);			
						Flat_Tex_Quad(G6);
			
					glTranslatef(-2.2, 0.0, 0.0);			
						Flat_Tex_Quad(G7);
				glPopMatrix();





		glPopMatrix();
	glPopMatrix();

}


void Front_Wall()
{
		// Front Walll
		glBindTexture(GL_TEXTURE_2D, G4_Brick3);

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

			// Doar chya varacha Quad 
			glBindTexture(GL_TEXTURE_2D, G4_Brick2);
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


}
