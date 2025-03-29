
#pragma once
#include<math.h>

GLfloat Color_Blend1 = 0.0;
GLfloat Color_Blend2 = 0.0;

BOOL L_Flag = FALSE;

// Function Definations
void Start_Intro()
{
	// Code
	glPushMatrix();
		
		glEnable(GL_BLEND);
		
			gluLookAt(0.0, 0.0, -3.0, 0.0, 0.0, 100, 0, 1, 0);
			glScalef(1.5, 1.0 ,1.0);
			glRotatef(90, 1, 0, 0);
		
				glColor4f(1.0, 1.0, 1.0, Color_Blend1);
				Flat_Tex_Quad(I_1);
	
				glColor4f(1.0, 1.0, 1.0, Color_Blend2);
				Flat_Tex_Quad(I_2);

		glDisable(GL_BLEND); 

	glPopMatrix();

	if (I_Flag = TRUE)
	{
		// Blending Animation 
		if (Color_Blend1 < 1.0 && Flag_Color_Blend1 == TRUE)
		{
			Color_Blend1 = Color_Blend1 + 0.003;
		}
		else
		{
			Flag_Color_Blend1 = FALSE;

			// color kami hot jato 
			if (Flag_Color_Blend1 == FALSE && Color_Blend1 > 0.0)
			{
				Color_Blend1 = Color_Blend1 - 0.008;
			}
			else
			{
				Flag_Color_Blend2 = TRUE;
				I_Flag = FALSE;
			}
		}
	}
		


	if (I_Flag == FALSE)
	{

		// Blending Animation  image 2
		if (L_Flag == FALSE && Color_Blend2 < 1.0 && Flag_Color_Blend2 == TRUE)
		{
			Color_Blend2 = Color_Blend2 + 0.003;
		}
		else 
		{
			Flag_Color_Blend2 = FALSE;
			L_Flag = TRUE;

			// color kami hot jato 
			if (Flag_Color_Blend2 == FALSE && Color_Blend2 > 0.0)
			{
				Color_Blend2 = Color_Blend2 - 0.008;
			}
			else
			{
				Scene_Count = 1;
			}
		}

		
	}

}


