
#pragma once
//--------------------------
// for wave 
#include<math.h>

float points[45][45][3];                    // The Array For The Points On The Grid Of Our "Wave"
int wiggle_count = 0;                       // Counter Used To Control How Fast Flag Waves
GLfloat hold;                           // Temporarily Holds A Floating Point Value

GLfloat xrot = 0.0f;
GLfloat yrot = 0.0f;
GLfloat zrot = 0.0f;

//-------------------------

void Call_in_initialize()
{
	// Loop Through The X Plane
	for (int x = 0; x < 45; x++)
	{
		// Loop Through The Y Plane
		for (int y = 0; y < 45; y++)
		{
			// Apply The Wave To Our Mesh
			points[x][y][0] = ((x / 5.0f) - 4.5f);
			points[x][y][1] = ((y / 5.0f) - 4.5f);
			points[x][y][2] = (sin((((x / 5.0f) * 40.0f) / 360.0f) * 3.141592654 * 2.0f));
		}
	}
	//------------------------
}

void Flag_Wave()
{
	//--------------------------------------------------------------------
	// Variable declarations 
	int x, y;                       // Loop Variables
	float float_x, float_y, float_xb, float_yb;     // Used To Break The Flag Into Tiny Quads

	// Code

	glPushMatrix();
		glDisable(GL_DEPTH);
		glEnable(GL_BLEND);

		glColor4f(1.0, 0.5, 0.0, 0.5);

		glTranslatef(0.0f , 0.7f , -5.2f);
		glScalef(0.2, 0.2, 0.2);
		glBindTexture(GL_TEXTURE_2D, Flag);       // Select Our Texture

		glBegin(GL_QUADS);                  // Start Drawing Our Quads
		for (x = 0; x < 44; x++)                // Loop Through The X Plane (44 Points)
		{
			for (y = 0; y < 44; y++)            // Loop Through The Y Plane (44 Points)
			{
				float_x = (x) / 44.0f;       // Create A Floating Point X Value
				float_y = (y) / 44.0f;       // Create A Floating Point Y Value
				float_xb = (x + 1) / 44.0f;        // Create A Floating Point Y Value+0.0227f
				float_yb = (y + 1) / 44.0f;        // Create A Floating Point Y Value+0.0227f
		
				glTexCoord2f(float_x, float_y);    // First Texture Coordinate (Bottom Left)
				glVertex3f(points[x][y][0], points[x][y][1], points[x][y][2]);

				glTexCoord2f(float_x, float_yb);  // Second Texture Coordinate (Top Left)
				glVertex3f(points[x][y + 1][0], points[x][y + 1][1], points[x][y + 1][2]);

				glTexCoord2f(float_xb, float_yb); // Third Texture Coordinate (Top Right)
				glVertex3f(points[x + 1][y + 1][0], points[x + 1][y + 1][1],  points[x +1][y + 1][2]);

				glTexCoord2f(float_xb, float_y);  // Fourth Texture Coordinate (Bottom Right)
				glVertex3f(points[x + 1][y][0], points[x + 1][y][1], points[x + 1][y][2]);
			}
		}
		glEnd();                        // Done Drawing Our Quads

		if (wiggle_count == 5)                 // Used To Slow Down The Wave (Every 2nd Frame Only)
		{
			for (y = 0; y < 45; y++)            // Loop Through The Y Plane
			{
				hold = points[0][y][2];           // Store Current Value One Left Side Of Wave
				for (x = 0; x < 44; x++)     // Loop Through The X Plane
				{
					// Current Wave Value Equals Value To The Right
					points[x][y][2] = points[x + 1][y][2];
				}
				points[44][y][2] = hold;          // Last Value Becomes The Far Left Stored Value
			}
			wiggle_count = 0;               // Set Counter Back To Zero
		}
		wiggle_count++;                     // Increase The Counter

		glBindTexture(GL_TEXTURE_2D, 0);
	
		glDisable(GL_BLEND); 
		glEnable(GL_DEPTH); 

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.90, 0.0, -5.3);
	glScalef(0.03, 1.5, 0.05);

				// Front Face 
			glColor3f(0.25, 0.25, 0.25);
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
