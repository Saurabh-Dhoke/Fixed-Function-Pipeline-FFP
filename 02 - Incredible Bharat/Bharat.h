
#pragma once

// for middle flags 
GLboolean flag_1 = FALSE;
GLboolean flag_2 = FALSE;
GLboolean flag_3 = FALSE;
GLboolean flag_4 = FALSE;
GLboolean flag_5 = FALSE;
GLboolean flag_6 = FALSE;

void Start_Bharat()
{
	// Function declarations 
	void B();
	void H();
	void A1();
	void R();
	void A2();
	void T();

	// Code
	glPushMatrix();
		glTranslatef(0.0, 0.02, -0.4);
		glScalef(0.05, 0.05, 0.05);

		if (translate_jet >= 0.04)
		{
			B();
			H();
		}
		
		if (translate_jet >= 0.1)
		{
			A1();
			R();
		}
		
		if (translate_jet >= 0.165)
		{
			A2();
			T();
		}
	glPopMatrix();

}

void flag_Quad()
{		
			// 2nd horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.35, 0.525);
					glVertex2f( 0.15, 0.525);
					glVertex2f( 0.15, 0.471);
					glVertex2f( 0.35, 0.471);

				glColor3f(1.0, 1.0, 1.0);      // white
					glVertex2f( 0.35, 0.471);
					glVertex2f(0.15, 0.471);
					glVertex2f(0.15, 0.418);
					glVertex2f( 0.35, 0.418);

				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f( 0.35, 0.418);
					glVertex2f(0.15, 0.418);
					glVertex2f(0.15, 0.365);
					glVertex2f( 0.35, 0.365);
			glEnd();

		glPointSize(4);
		glBegin(GL_POINTS);
		glColor3f(0.02, 0.01, 0.55);
			glVertex2f(0.25, 0.4445);
		glEnd();
		glPointSize(1);

}

void B()
{
	glPushMatrix();
		glTranslatef(-2.0, -0.5, 0.0);
			
			// phila vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.15, 0.9); 
					glVertex2f( -0.10, 0.9); 
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( -0.10, 0.45);
					glVertex2f( 0.15, 0.45);
					glVertex2f(0.15, 0.45);
					glVertex2f(-0.10, 0.45);
				
				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f(-0.10, 0.0);
					glVertex2f(0.15, 0.0);
			glEnd();

			// last cha vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.45, 0.9);
					glVertex2f( 0.35, 0.9);
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( 0.35, 0.45);
					glVertex2f( 0.45, 0.45);
					glVertex2f(0.45, 0.45);
					glVertex2f(0.35, 0.45);
				
				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f(0.35, 0.0);
					glVertex2f(0.45, 0.0);
			glEnd();

			// 1st horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);
					glVertex2f( 0.35, 0.90);
					glVertex2f( 0.15, 0.90);
		
				glColor3f(1, 0.6, 0.41);
					glVertex2f( 0.15, 0.75);
					glVertex2f( 0.35, 0.75);
			glEnd();

			// 2nd horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.86, 0.77);
					glVertex2f( 0.35, 0.525);
					glVertex2f( 0.15, 0.525);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.15, 0.465);
					glVertex2f( 0.35, 0.465);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.35, 0.465);
					glVertex2f( 0.15, 0.465);

				glColor3f(0.86, 0.92, 0.89);
					glVertex2f( 0.15, 0.365);
					glVertex2f( 0.35, 0.365);
			glEnd();

			// 3rd horizontal
			glBegin(GL_QUADS);
				glColor3f(0.43, 0.63, 0.53);
					glVertex2f( 0.35, 0.15);
					glVertex2f( 0.15, 0.15);

				glColor3f(0.02, 0.42, 0.22);
					glVertex2f( 0.15, 0.00);
					glVertex2f( 0.35, 0.00);
			glEnd();

			if(flag_1 == TRUE)
				flag_Quad();
	glPopMatrix();
}

void H()
{
	glPushMatrix();
		glTranslatef(-1.3, -0.5, 0.0);
			
			// phila vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.15, 0.9); 
					glVertex2f( -0.10, 0.9); 
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( -0.10, 0.45);
					glVertex2f( 0.15, 0.45);
					glVertex2f(0.15, 0.45);
					glVertex2f(-0.10, 0.45);
				
				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f(-0.10, 0.0);
					glVertex2f(0.15, 0.0);
			glEnd();

			// last cha vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.45, 0.9);
					glVertex2f( 0.35, 0.9);
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( 0.35, 0.45);
					glVertex2f( 0.45, 0.45);
					glVertex2f(0.45, 0.45);
					glVertex2f(0.35, 0.45);
				
				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f(0.35, 0.0);
					glVertex2f(0.45, 0.0);
			glEnd();

			// 2nd horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.86, 0.77);
					glVertex2f( 0.35, 0.525);
					glVertex2f( 0.15, 0.525);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.15, 0.465);
					glVertex2f( 0.35, 0.465);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.35, 0.465);
					glVertex2f( 0.15, 0.465);

				glColor3f(0.86, 0.92, 0.89);
					glVertex2f( 0.15, 0.365);
					glVertex2f( 0.35, 0.365);
			glEnd();

			if (flag_2 == TRUE)
				flag_Quad();

	glPopMatrix();
}

void A1()
{
	glPushMatrix();
		glTranslatef(-0.6, -0.5, 0.0);
			
			// phila vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.15, 0.9); 
					glVertex2f( -0.10, 0.9); 
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( -0.10, 0.45);
					glVertex2f( 0.15, 0.45);
					glVertex2f(0.15, 0.45);
					glVertex2f(-0.10, 0.45);
				
				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f(-0.10, 0.0);
					glVertex2f(0.15, 0.0);
			glEnd();


			// last cha vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.45, 0.9);
					glVertex2f( 0.35, 0.9);
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( 0.35, 0.45);
					glVertex2f( 0.45, 0.45);
					glVertex2f(0.45, 0.45);
					glVertex2f(0.35, 0.45);
				
				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f(0.35, 0.0);
					glVertex2f(0.45, 0.0);
			glEnd();

			// 1st horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);
					glVertex2f( 0.35, 0.90);
					glVertex2f( 0.15, 0.90);
		
				glColor3f(1, 0.6, 0.41);
					glVertex2f( 0.15, 0.75);
					glVertex2f( 0.35, 0.75);
			glEnd();

			// 2nd horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.86, 0.77);
					glVertex2f( 0.35, 0.525);
					glVertex2f( 0.15, 0.525);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.15, 0.465);
					glVertex2f( 0.35, 0.465);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.35, 0.465);
					glVertex2f( 0.15, 0.465);

				glColor3f(0.86, 0.92, 0.89);
					glVertex2f( 0.15, 0.365);
					glVertex2f( 0.35, 0.365);
			glEnd();


			if (flag_3 == TRUE)
				flag_Quad();

	glPopMatrix();
}

void R()
{
	glPushMatrix();
		glTranslatef(0.1, -0.5, 0.0);
			
			glPushMatrix();
				// Tirapi line 
				glTranslatef(0.35, -0.03, 0.0);
				glRotatef(45, 0, 0, 1);

					glBegin(GL_QUADS);
						glColor3f(0.86, 0.92, 0.89);
							glVertex2f(0.15, 0.44);
							glVertex2f(0.05, 0.44);
						glColor3f(0.02, 0.42, 0.22);      // green
							glVertex2f(0.05, 0.0);
							glVertex2f(0.15, 0.0);
					glEnd();
			glPopMatrix();


		// 2nd horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.86, 0.77);
					glVertex2f( 0.45, 0.525);
					glVertex2f( 0.15, 0.525);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.15, 0.465);
					glVertex2f( 0.45, 0.465);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.45, 0.465);
					glVertex2f( 0.15, 0.465);

				glColor3f(0.86, 0.92, 0.89);
					glVertex2f( 0.15, 0.365);
					glVertex2f( 0.45, 0.365);
			glEnd();


			// phila vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.15, 0.9); 
					glVertex2f( -0.10, 0.9); 
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( -0.10, 0.45);
					glVertex2f( 0.15, 0.45);
					glVertex2f(0.15, 0.45);
					glVertex2f(-0.10, 0.45);
				
				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f(-0.10, 0.0);
					glVertex2f(0.15, 0.0);
			glEnd();



			// last cha vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.45, 0.9);
					glVertex2f( 0.35, 0.9);
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( 0.35, 0.46);
					glVertex2f( 0.45, 0.46);
			glEnd();


			// 1st horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);
					glVertex2f( 0.35, 0.90);
					glVertex2f( 0.15, 0.90);
		
				glColor3f(1, 0.6, 0.41);
					glVertex2f( 0.15, 0.75);
					glVertex2f( 0.35, 0.75);
			glEnd();


			if (flag_4 == TRUE)
				flag_Quad();

	glPopMatrix();
}

void A2()
{
	glPushMatrix();
		glTranslatef(0.8, -0.5, 0.0 );

		   // phila vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.15, 0.9); 
					glVertex2f( -0.10, 0.9); 
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( -0.10, 0.45);
					glVertex2f( 0.15, 0.45);
					glVertex2f(0.15, 0.45);
					glVertex2f(-0.10, 0.45);
				
				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f(-0.10, 0.0);
					glVertex2f(0.15, 0.0);
			glEnd();


			// last cha vertical quad
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);  // orange
					glVertex2f( 0.45, 0.9);
					glVertex2f( 0.35, 0.9);
				
				glColor3f(1.0, 1.0, 1.0);     // white
					glVertex2f( 0.35, 0.45);
					glVertex2f( 0.45, 0.45);
					glVertex2f(0.45, 0.45);
					glVertex2f(0.35, 0.45);
				
				glColor3f(0.02, 0.42, 0.22);      // green
					glVertex2f(0.35, 0.0);
					glVertex2f(0.45, 0.0);
			glEnd();

			// 1st horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);
					glVertex2f( 0.35, 0.90);
					glVertex2f( 0.15, 0.90);
		
				glColor3f(1, 0.6, 0.41);
					glVertex2f( 0.15, 0.75);
					glVertex2f( 0.35, 0.75);
			glEnd();

			// 2nd horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.86, 0.77);
					glVertex2f( 0.35, 0.525);
					glVertex2f( 0.15, 0.525);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.15, 0.465);
					glVertex2f( 0.35, 0.465);

				glColor3f(1.0, 1.0, 1.0);
					glVertex2f( 0.35, 0.465);
					glVertex2f( 0.15, 0.465);

				glColor3f(0.86, 0.92, 0.89);
					glVertex2f( 0.15, 0.365);
					glVertex2f( 0.35, 0.365);
			glEnd();


			if (flag_5 == TRUE)
				flag_Quad();

	glPopMatrix();
}

void T()
{
	glPushMatrix();
		glTranslatef(1.25, -0.5, 0.0);
			
			// 1st horizontal
			glBegin(GL_QUADS);
				glColor3f(1, 0.4, 0.12);
					glVertex2f( 0.70, 0.90);
					glVertex2f( 0.15, 0.90);
		
				glColor3f(1, 0.6, 0.41);
					glVertex2f( 0.15, 0.75);
					glVertex2f( 0.70, 0.75);
			glEnd();

			glTranslatef(-0.05, 0.0, 0.0);
				// last cha vertical quad
				glBegin(GL_QUADS);
					glColor3f(1, 0.4, 0.12);  // orange
						glVertex2f( 0.60, 0.9);
						glVertex2f( 0.35, 0.9);

					glColor3f(1.0, 1.0, 1.0);     // white
						glVertex2f( 0.35, 0.45);
						glVertex2f( 0.60, 0.45);
						glVertex2f(0.60, 0.45);
						glVertex2f(0.35, 0.45);

					glColor3f(0.02, 0.42, 0.22);      // green
						glVertex2f(0.35, 0.0);
						glVertex2f(0.60, 0.0);
				glEnd();

				glTranslatef(0.16, 0.0, 0.0);
				glScalef(1.25, 1.0, 1.0);
					
					if (flag_6 == TRUE)
						flag_Quad();
	glPopMatrix();
}