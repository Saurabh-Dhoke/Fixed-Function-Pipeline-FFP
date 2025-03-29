
#pragma once
#include<math.h>

GLfloat Color_Blend = 0.0;

GLint Flag_Count = 0;

// Function Definations
void Start_Outro()
{
	// Function declartion 
	void Start_Credits();
	void Start_M9();

	glClearColor(0.5, 0.5, 0.5, 1.0f);

	// Code
	glPushMatrix();
		if(Map9_Flag)
			AanadAshram_91();
		else
			Start_Credits();
	glPopMatrix();

}

void Start_Credits()
{
	// Code
	glPushMatrix();
		
		glEnable(GL_BLEND);
			gluLookAt(0.0, 0.0, -3.0, 0.0, 0.0, 100, 0, 1, 0);
			glScalef(1.5, 1.0 ,1.0);
			glRotatef(90, 1, 0, 0);
		
				glColor4f(1.0, 1.0, 1.0, Color_Blend);
				
				if (Flag_Count == 0)
					Flat_Tex_Quad(O0);
				else if (Flag_Count == 1)
					Flat_Tex_Quad(O1);
				else if (Flag_Count == 2)
					Flat_Tex_Quad(O2);
				else if (Flag_Count == 3)
					Flat_Tex_Quad(O3);
				else if (Flag_Count == 4)
					Flat_Tex_Quad(O4);
				else if (Flag_Count == 5)
					Flat_Tex_Quad(O5);
				else if (Flag_Count == 6)
					Flat_Tex_Quad(O6);
				else if (Flag_Count == 7)
					Flat_Tex_Quad(O7);
				else if (Flag_Count == 8)
					Flat_Tex_Quad(O8);
				else if (Flag_Count == 9)
					Flat_Tex_Quad(O9);
				else if (Flag_Count == 10)
					Flat_Tex_Quad(O10);
				

		glDisable(GL_BLEND); 

	glPopMatrix();

	// Blending Animation 
		if (Color_Blend < 1.0 && Flag_Color_Blend == TRUE)
		{
			Color_Blend = Color_Blend + 0.004;
		}
		else
		{
			Flag_Color_Blend = FALSE;

			// color kami hot jato 
			if (Flag_Color_Blend == FALSE && Color_Blend > 0.0)
			{
				Color_Blend = Color_Blend - 0.025;
			}
			else
			{
				Color_Blend = 0.0f; 
				Flag_Color_Blend = TRUE;
				Flag_Count = Flag_Count + 1;				
			}
		}
}


