
#pragma once
#include<math.h>

GLfloat Color_Arr[3];


// Function Definations
void Start_Objects()
{	
	// Function Declarations 
	void G1_Temple();
	void Environment_G1();
	void Load_Har(GLuint texture);
	void Load_PNG(GLuint texture, GLfloat Color_Arr[]);

	void Chair1();
	void WoodenChair(GLuint );
	void Marbal_Chair(GLuint texture);
	
	void Danpeti1();
	void Danpeti2();

	// Code

	glPushMatrix();
		
			glTranslatef(0,-1.45, -6.85);

	
			gluLookAt(tx, ty, tz, 0, 0, 100, 0, 1, 0);

			// Har 
			glPushMatrix();
				//glTranslatef(0.04, 1.4, 1.9);
				
				//Chair1();
				
				//1				
				//Marbal_Chair(G1_Wood);

				//2
				//WoodenChair(G1_Wood); 

				//3
				/*glScalef(0.9, 0.9, 0.7);
					Marbal_Chair(G1_FDesign);*/

				//4
				/*	glScalef(4.0, 0.9, 0.7);
					Marbal_Chair(G1_FDesign);*/
			
				//5
			/*	glScalef(4.0, 0.9, 0.7);
					WoodenChair(G1_Wood);*/

				//6
				/*glScalef(4.0, 0.9, 0.7);
					WoodenChair(G4_Tile);
				*/
			/*
			glColor3f( 0.4, 0.4, 0.4);
			glColor3f( 0.5, 0.5, 0.5);
			glColor3f( 0.7, 0.7, 0.7);
			glColor3f( 0.9, 0.9, 0.9);*/




			//Danpeti1();
			//Danpeti2();
				
		glPopMatrix();

			//// Ghanta 
			//glPushMatrix();
			//Color_Arr[0] = 0.5;//  color
			//Color_Arr[1] = 0.5;
			//Color_Arr[2] = 0.5;
			//
			//	glTranslatef(0.0, 1.44, 0.0);
			//	glScalef(0.1, 0.33, 1.0);
			//		Load_PNG(Ghanta, Color_Arr);

			//glPopMatrix();

			
		

	glPopMatrix();
}


void Load_PNG(GLuint texture, GLfloat Color_Arr[])
{
	glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, texture);

				glDisable(GL_DEPTH);
				glEnable(GL_BLEND);

					glColor4f(1.0, 1.0,1.0, 0.5);   // For Transperancy 
					glColor3fv(Color_Arr);       


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
				glBindTexture(GL_TEXTURE_2D, 0);

		glPopMatrix();
}
void Load_Har(GLuint texture)
{
	glPushMatrix();
		Color_Arr[0] = 1;//  color
		Color_Arr[1] = 1;
		Color_Arr[2] = 1;

				Load_PNG(texture, Color_Arr);
	glPopMatrix();
}


void Cube_Obj(GLuint texture)
{
	// Code
	
	glPushMatrix();		

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
void Legs_t(GLuint texture)
{
	glPushMatrix();
		glTranslatef(0.0, 0.09,-0.1);

		glScalef(0.025, 0.2 , 0.025);
			Cube_Obj(texture);
				
		glTranslatef(14.1, 0.0, 0.0);
			Cube_Obj(texture);

		glTranslatef(0.0, 0.0, 13.0);
			Cube_Obj(texture);

		glTranslatef(-14.1 , 0.0, 0.0);
			Cube_Obj(texture);
	glPopMatrix();
}

void Cube_plane()
{
	// Code
	
	glPushMatrix();		

		// 3D Cube
	    glColor3f(0.4, 0.4, 0.4);
		// Front Face 
		glBegin(GL_QUADS); 
			glVertex3f(1.0, 1.0, 1.0);     // right top
			glVertex3f(-1.0, 1.0, 1.0);    // left top	 
			glVertex3f(-1.0, -1.0 , 1.0);  // left bottom 
			glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
		glEnd();

		glColor3f(0.5, 0.5, 0.5);
		// Right Face 
		glBegin(GL_QUADS);  
			glVertex3f(1.0,  1.0, -1.0);    // right top
			glVertex3f(1.0,  1.0,  1.0);    // left top	 
			glVertex3f(1.0, -1.0 , 1.0);    // left bottom
			glVertex3f(1.0, -1.0 , -1.0);   // right bottom
		glEnd();

		glColor3f(0.5, 0.5, 0.5);
		// Left Face 
		glBegin(GL_QUADS); 
 			glVertex3f(-1.0,  1.0, 1.0);    // right top
			glVertex3f(-1.0,  1.0, -1.0);    // left top	 
			glVertex3f(-1.0, -1.0, -1.0);    // left bottom
			glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
		glEnd(); 

		glColor3f(0.4, 0.4, 0.4);
		// Back Face 
		glBegin(GL_QUADS); 
			glVertex3f(-1.0,  1.0, -1.0);    // right top
			glVertex3f( 1.0,  1.0, -1.0);    // left top	 
			glVertex3f( 1.0, -1.0, -1.0);    // left bottom
			glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
		glEnd(); 

		glColor3f(0.4, 0.4, 0.4);
		// Top Face 
		glBegin(GL_QUADS); 
 			glVertex3f( 1.0,  1.0, -1.0);    // right top
			glVertex3f(-1.0,  1.0, -1.0);    // left top	
			glVertex3f(-1.0,  1.0,  1.0);    // left bottom
			glVertex3f( 1.0,  1.0 , 1.0);   // right bottom
		glEnd(); 

		glColor3f(0.4, 0.4, 0.4);
		// Bottom Face 
		glBegin(GL_QUADS); 
 			glVertex3f( 1.0, -1.0, -1.0);    // right top
			glVertex3f(-1.0, -1.0, -1.0);    // left top	
			glVertex3f(-1.0, -1.0,  1.0);    // left bottom
			glVertex3f( 1.0, -1.0 , 1.0);   // right bottom
		glEnd(); 
		
		glColor3f(0.4, 0.4, 0.4);

	glPopMatrix();

}
void Legs()
{
	glPushMatrix();
	glTranslatef(0.0, 0.1, 0.0);

		glScalef(0.025, 0.2 , 0.025);
			Cube_plane();
				
		glTranslatef(14.1, 0.0, 0.0);
			Cube_plane();

		glTranslatef(0.0, 0.0, 13.0);
			Cube_plane();

		glTranslatef(-14.1 , 0.0, 0.0);
			Cube_plane();
	glPopMatrix();
}

// Bench 1
void Chair1()
{
	glPushMatrix();		
		glTranslatef(0.0, 0.5, -3.0);
		
		// Legs
		Legs();

		// Top Cube 
		glPushMatrix();			
			glTranslatef(0.18, 0.28, 0.11);
			glScalef(0.25, 0.03 ,0.28);
				Cube_plane();
		glPopMatrix();
		
		// Back Cube 
		glPushMatrix();			 
			glTranslatef(0.18, 0.52, 0.45);
			glRotatef(110, 1, 0, 0);
			glScalef(0.25, 0.03 ,0.28);

			glColor3f(0.4, 0.4, 0.4);

				Cube_plane();
		glPopMatrix();

		


	glPopMatrix();
}

void WoodenChair(GLuint Texture)
{
	glPushMatrix();		
		glTranslatef(0.0, 0.5, -3.0);
		
			glColor3f(0.6, 0.6, 0.6);
			// Legs
			Legs_t(Texture);

			glColor3f(0.7, 0.7, 0.7);
			// Top Cube 
			glPushMatrix();			
				glTranslatef(0.18, 0.28, 0.11);
				glScalef(0.25, 0.03 ,0.28);
				Cube_Obj(Texture);
			glPopMatrix();

			glColor3f(0.6, 0.6, 0.6);
			// Back Cube 
			glPushMatrix();			 
				glTranslatef(0.18, 0.52, 0.45);
				glRotatef(110, 1, 0, 0);
				glScalef(0.25, 0.03 ,0.28);
					Cube_Obj(Texture);
			glPopMatrix();

	glPopMatrix();
}
void Marbal_Chair(GLuint texture )
{
	glPushMatrix();		
		glTranslatef(0.0, 0.5, -3.0);
			glColor3f(0.7, 0.7, 0.7);

			// Top Cube 
			glPushMatrix();			
				glTranslatef(0.18, 0.28, 0.11);
				glScalef(0.25, 0.03 ,0.28);
					Cube_Obj(texture);
			glPopMatrix();
			
			// Back Cube 
			glPushMatrix();			 
				glTranslatef(0.18, 0.52, 0.45);
				glRotatef(110, 1, 0, 0);
				glScalef(0.25, 0.03 ,0.28);

				glColor3f(0.5, 0.5, 0.5);
					Cube_Obj(texture);
			glPopMatrix();

			// Ubha Cube 
			glPushMatrix();			
				glTranslatef(0.18, 0.08, 0.31);
				glRotatef(90, 1, 0, 0);
				glRotatef(90, 0, 1, 0);
				glScalef(0.18, 0.03 ,0.25);
					Cube_Obj(texture);
				
				glTranslatef(-0.05 , -15.0, 0.0);
					Cube_Obj(texture);
			glPopMatrix();
	glPopMatrix();
}

void Marbal_Chair2(GLuint texture )
{
	glPushMatrix();		
		glTranslatef(0.0, 0.5, -3.0);

			// Top Cube 
			glPushMatrix();			
				glTranslatef(0.18, 0.28, 0.11);
				glScalef(0.25, 0.03 ,0.28);
					Cube_Obj(texture);
			glPopMatrix();
			
			// Back Cube 
			glPushMatrix();			 
				glTranslatef(0.18, 0.52, 0.45);
				glRotatef(110, 1, 0, 0);
				glScalef(0.25, 0.03 ,0.28);
					Cube_Obj(texture);
			glPopMatrix();

			// Ubha Cube 
			glPushMatrix();			
				glTranslatef(0.18, 0.08, 0.31);
				glRotatef(90, 1, 0, 0);
				glRotatef(90, 0, 1, 0);
				glScalef(0.18, 0.03 ,0.25);
					Cube_Obj(texture);
				
				glTranslatef(-0.05 , -15.0, 0.0);
					Cube_Obj(texture);
			glPopMatrix();
	glPopMatrix();
}

void Cube_Obj1(GLuint texture)
{
	// Code
	
	glPushMatrix();		

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

	glBindTexture(GL_TEXTURE_2D, 0);


			
	glPopMatrix();

}

// Cone
void Cube_Obj2(GLuint texture)
{
	// Code
	
	glPushMatrix();		

		glBindTexture(GL_TEXTURE_2D, texture);


		// 3D Cube
		// Front Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.5, 1.0, 0.1);     // right top
	
			glTexCoord2f(1.0, 0.0);
			glVertex3f(-0.5, 1.0, 0.1);    // left top	
		
			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.0, -1.0 , 1.0);  // left bottom
		
			glTexCoord2f(0.0, 1.0);
			glVertex3f( 1.0, -1.0 , 1.0);  // right bottom
		glEnd();

		// Right Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.5,  1.0, -0.1);    // right top

			glTexCoord2f(1.0, 0.0);
			glVertex3f(0.5,  1.0,  0.1);    // left top	 

			glTexCoord2f(1.0, 1.0);
			glVertex3f(1.0, -1.0 , 1.0);    // left bottom

			glTexCoord2f(0.0, 1.0);
			glVertex3f(1.0, -1.0 , -1.0);   // right bottom
		glEnd();

		// Back Face 
		glBegin(GL_QUADS); 
		glTexCoord2f(0.0, 0.0);
			glVertex3f(-0.5,  1.0, -0.1);    // right top

			glTexCoord2f(1.0, 0.0);
			glVertex3f( 0.5,  1.0, -0.1);    // left top	 

			glTexCoord2f(1.0, 1.0);
			glVertex3f( 1.0, -1.0, -1.0);    // left bottom

			glTexCoord2f(0.0, 1.0);
			glVertex3f(-1.0, -1.0 , -1.0);   // right bottom
		glEnd(); 

		// Left Face 
		glBegin(GL_QUADS); 
			glTexCoord2f(0.0, 0.0);
			glVertex3f(-0.5,  1.0, 0.1);    // right top

			glTexCoord2f(1.0, 0.0);
			glVertex3f(-0.5,  1.0, -0.1);    // left top	 

			glTexCoord2f(1.0, 1.0);
			glVertex3f(-1.0, -1.0, -1.0);    // left bottom

			glTexCoord2f(0.0, 1.0);
			glVertex3f(-1.0, -1.0 , 1.0);   // right bottom
		glEnd(); 

	glBindTexture(GL_TEXTURE_2D, 0);


			
	glPopMatrix();

}

void Danpeti1()
{
	glPushMatrix();
		glScalef(0.75, 0.60, 0.5);
			Cube_Obj1(Steel2);
	
		glTranslatef(0.0, 1.3, 0.0);
		glScalef(1.0,0.3, 1.0);
			Cube_Obj2(Steel1);		
	glPopMatrix();

}
void Danpeti2()
{
	glPushMatrix();
		glScalef(0.75, 0.60, 0.5);
			Cube_Obj1(Steel2);
	
		glTranslatef(0.0, 0.5,0.0);
		glRotatef(180,1,0,0);
		glScalef(1.0, 0.5, 1.0);
			Cube_Obj2(Steel1);
		
		
	glPopMatrix();

}


//void DoAbcar(GLuint texture)
//{
//	// Doar
//		glPushMatrix();
//			glTranslatef(-0.7, -0.2, 0.2);
//			glScalef(1.2, 0.5, 0.8);
//			glRotatef(90, 0, 1, 0);
//				Doar_Khamb(texture);
//
//			glTranslatef(0.0, 0.0, -0.4);
//				Doar_Khamb(texture);
//		glPopMatrix();
//
//		glPushMatrix();
//			glTranslatef(-0.12, -1.25, -1.65);
//			glScalef(0.25, 0.9, 0.8);
//			glRotatef(90, 0, 0, 1);
//				Doar_Khamb(texture);
//
//			glTranslatef(-1.05, 0 , 0);
//				Doar_Khamb(texture);
//		glPopMatrix();
//}

