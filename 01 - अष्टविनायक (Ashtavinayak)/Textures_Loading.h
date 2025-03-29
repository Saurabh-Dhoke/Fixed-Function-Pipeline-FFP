


// Texture Object/ Variable
GLuint Flag = 0;

// Map 
GLuint M_1, M_2, M_3, M_4, M_5, M_6, M_7, M_8, M_9;

// G1
GLuint G1_Doar, G1_Stairs, G1_Stone, G1_FDesign, G1_Bricks, G1_Ganpati, G1_Wood;

// G2 
GLuint G2_Brick_1, G2_Brick_2, G2_Brick_3, G2_Ganpati, G2_Roof, G2_Soil;

// G3
GLuint G3_Stone, G3_Stone2, G3_Sky, G3_Grass_1, G3_Name, G3_Wall, G3_Tile, G3_Gate1, G3_Gate2, G3_Ganpati;

// G4
GLuint G4_Gate1, G4_Gate2, G4_Stone1, G4_Stone2, G4_Sky, G4_FGrill, G4_Grill, G4_Shree, G4_Name, G4_Ganpati, G4_Golden_design1, G4_Golden_design2, G4_Brick0, G4_Brick1, G4_Brick2, G4_Brick3, G4_Tile, G4_Tile2;

// G5
GLuint G5_Name, G5_Ganpati, G5_Gold, G5_Design1, G5_Design2, G5_Design3, G5_Brick, G5_Brick2, G5_Stone, G5_Stone1;

// G6
GLuint   G6_Doar,  G6_Ganpati, G6_Pillar, G6_Stone, G6_Stone2, G6_Png_plane;

// G7
GLuint G7_Golden, G7_Ganpati, G7_Grill_1, G7_Name, G7_Sky, G7_Grass1, G7_Grass2;

// G8 
GLuint G8_Name, G8_Rangoli1, G8_Celing_Design, G8_Slap_Design, G8_Patti_Design, G8_Design, G8_G_Design, G8_Ganpati, G8_Stone1, G8_Stone2, G8_Pole_Design;

// decorations 
GLuint Diva, Ghanta,Ghanta2, Pooja1, Pooja2;
GLuint Rangoli1, Rangoli2, Rangoli3, Rangoli4, Rangoli5, Rangoli6;
GLuint  Har2, Har3, Har4, Har5, Har6, Har7, Har8, Har9, Har10;

GLuint Steel1, Steel2;

// flowers and trees 
GLuint Mountain1, Mountain2;
GLuint Flower1,Flower2,Flower3,Flower4,Flower5,Flower6;
GLuint Grass1, Grass2, Grass3, Grass4, Grass5, Grass6, Grass7, Grass8, Grass9, Grass10, Grass11;
GLuint Tree1, Tree2, Tree3, Tree4, Tree5, Tree6, Tree7, Tree8;
GLuint Tile1, Tile2, Tile3;

// Ganpati 
GLuint G1, G2, G3, G4, G5, G6, G7, G8;

// Intro 
GLuint I_1, I_2;

// Outro
GLuint O0, O1, O2, O3, O4, O5, O6, O7, O8, O9, O10;


BOOL loadGLTexture_stb(GLuint* texture, char* fileName)
{
	// Variable declarations 
	int width;
	int height;
	int components;
	BOOL bResult = FALSE;

	                          // fileName valya file chi width n height yat bharun deto//&components madhi kiti components yet te yat bharun yeil...3..4  // last parametre sangto ki mla kiti parameters have yet  
	//unsigned char* imageData = stbi_load(fileName, &width, &height, &components, 0); 

	unsigned char* imageData = stbi_load(fileName, &width, &height, &components, 0);

	if (imageData == NULL)
	{
		fprintf(gpFILE,"Failed to load texture %s \n",fileName);
		return bResult;
	}
	else
	{
		bResult = TRUE;

		glPixelStorei(GL_UNPACK_ALIGNMENT, 4); 
		glGenTextures(1, texture);
		glBindTexture(GL_TEXTURE_2D, *texture);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		if (components == 3)
		{    // 1- target ,2-mipmap level , 6 - border ahe ka , 3- image format , 7 - opengl format donhi samech ast 99% , 8- datatype image cha , 9 - image cha data 
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,imageData);

		}
		else if (components == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

		}

	}

	return bResult;

}




// Texture Loading 

int My_Load_Textures()
{
	// Local Variable Declarations 
	BOOL bResult = FALSE;

	// Local Function Declarations 
	int Map_Textures();

	// Code
	
	bResult = Map_Textures();
	if (bResult == FALSE)
		return bResult; 
	
	
	// Succesfully Return
	return 1;

}

int Map_Textures()
{
	// Local Variable Declarations 
	BOOL bResult = FALSE;

	// Code
	bResult = loadGLTexture_stb(&Flag, "Flag.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Flag Texture failed.. \n\n");
		return -1;
	}

	// 1 - Morgav 
	bResult = loadGLTexture_stb(&M_1, "Map_Textures/1_Morgav.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of M1 Texture failed.. \n\n");
		return -1;
	}

	// 2 - Theur 
	bResult = loadGLTexture_stb(&M_2, "Map_Textures/2_Theur.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of M2 Texture failed.. \n\n");
		return -2;
	}

	// 3 - Sidhtek 
	bResult = loadGLTexture_stb(&M_3, "Map_Textures/3_Sidhtek.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of M3 Texture failed.. \n\n");
		return -3;
	}

	// 4 - RajanGav 
	bResult = loadGLTexture_stb(&M_4, "Map_Textures/4_Rajangav.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of M4 Texture failed.. \n\n");
		return -4;
	}

	// 5_Ozar 
	bResult = loadGLTexture_stb(&M_5, "Map_Textures/5_Ozar.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of M5 Texture failed.. \n\n");
		return -5;
	}

	// 6_Lenyandri
	bResult = loadGLTexture_stb(&M_6, "Map_Textures/6_Lenyandri.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of M6 Texture failed.. \n\n");
		return -6;
	}

	// 7_Mahad
	bResult = loadGLTexture_stb(&M_7, "Map_Textures/7_Mahad.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of M7 Texture failed.. \n\n");
		return -7;
	}

	// 8_Pali
	bResult = loadGLTexture_stb(&M_8, "Map_Textures/8_Pali.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of M8 Texture failed.. \n\n");
		return -8;
	}

	// 8_AanadAashram
	bResult = loadGLTexture_stb(&M_9, "Map_Textures/9_AanadAashram.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of M9 Texture failed.. \n\n");
		return -888;
	}

	// Ganpati 1 
	
	// Stairs Stone 
	bResult = loadGLTexture_stb(&G1_Stairs, "G1/Stairs_G1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Stairs stone G1 Texture failed.. \n\n");
		return -10;
	}

	//  Stone 
	bResult = loadGLTexture_stb(&G1_Stone, "G1/Stone.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  stone G1 Texture failed.. \n\n");
		return -11;
	}

	//  Front Design 
	bResult = loadGLTexture_stb(&G1_FDesign, "G1/F_Design.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  F_Design G1 Texture failed.. \n\n");
		return -12;
	}

	//  Bricks
	bResult = loadGLTexture_stb(&G1_Bricks, "G1/Bricks.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Bricks G1 Texture failed.. \n\n");
		return -13;
	}

	//  Ganpati
	bResult = loadGLTexture_stb(&G1_Ganpati, "G1/Ganpati.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Ganpati G1 Texture failed.. \n\n");
		return -14;
	}

	//  Ganpati
	bResult = loadGLTexture_stb(&G1_Wood, "G1/Wood.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Wood G1 Texture failed.. \n\n");
		return -15;
	}

	//--------------------------------------
	// G2 Textures
	
	// Bricks 
	bResult = loadGLTexture_stb(&G2_Brick_1, "G2/Brick_1.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of G2_Brick_1 Texture failed.. \n\n");
		return -116;
	}


	bResult = loadGLTexture_stb(&G2_Brick_2, "G2/Brick_2.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of G2_Brick_2 Texture failed.. \n\n");
		return -16;
	}

	bResult = loadGLTexture_stb(&G2_Brick_3, "G2/Brick_3.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of G2_Brick_3 Texture failed.. \n\n");
		return -17;
	}

	//  Ganpati
	bResult = loadGLTexture_stb(&G2_Ganpati, "G2/Ganpati.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Ganpati G2 Texture failed.. \n\n");
		return -18;
	}
	
	//  Roof
	bResult = loadGLTexture_stb(&G2_Roof, "G2/Roof.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Roof G2 Texture failed.. \n\n");
		return -19;
	}

	//  tile
	bResult = loadGLTexture_stb(&G2_Soil, "G2/Soil.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Ganpati G2 Texture failed.. \n\n");
		return -20;
	}

	//----------------------------------------------------------------
	// G3 

	//  Stone
	bResult = loadGLTexture_stb(&G3_Stone, "G3/Stone.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Stone G3 Texture failed.. \n\n");
		return -21;
	}

	//  Stone2
	bResult = loadGLTexture_stb(&G3_Stone2, "G3/Stone2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Stone2 G3 Texture failed.. \n\n");
		return -95;
	}

	//  Sky
	bResult = loadGLTexture_stb(&G3_Sky, "G3/Sky.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Sky G3 Texture failed.. \n\n");
		return -22;
	}

	//  Sky
	bResult = loadGLTexture_stb(&G3_Grass_1, "G3/Grass_1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Grass G3 Texture failed.. \n\n");
		return -23;
	}

	// Name
	bResult = loadGLTexture_stb(&G3_Name, "G3/Name.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Name G3 Texture failed.. \n\n");
		return -24;
	}

	// Wall
	bResult = loadGLTexture_stb(&G3_Wall, "G3/Wall.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Wall G3 Texture failed.. \n\n");
		return -25;
	}

	// Tile
	bResult = loadGLTexture_stb(&G3_Tile, "G3/Tile_1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Tile G3 Texture failed.. \n\n");
		return -26;
	}

	// Gate1
	bResult = loadGLTexture_stb(&G3_Gate1, "G3/Gate1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Gate1 G3 Texture failed.. \n\n");
		return -27;
	}
	
	// GAte 2
	bResult = loadGLTexture_stb(&G3_Gate2, "G3/Gate2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Gate2 G3 Texture failed.. \n\n");
		return -28;
	}

	// Ganpati
	bResult = loadGLTexture_stb(&G3_Ganpati, "G3/Ganpati.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Ganpati G3 Texture failed.. \n\n");
		return -29;
	}


	//---------------------------------------
	// G7 

	// Goldem
	bResult = loadGLTexture_stb(&G7_Golden, "G7/Golden.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Golden G3 Texture failed.. \n\n");
		return -30;
	}

	// Ganpati
	bResult = loadGLTexture_stb(&G7_Ganpati, "G7/Ganpati.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Ganpati G7 Texture failed.. \n\n");
		return -31;
	}

	// Grill 1
	bResult = loadGLTexture_stb(&G7_Grill_1, "G7/Grill1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Grill G7 Texture failed.. \n\n");
		return -32;
	}

	// Name
	bResult = loadGLTexture_stb(&G7_Name, "G7/Name.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Name G7 Texture failed.. \n\n");
		return -33;
	}

	// Sky 
	bResult = loadGLTexture_stb(&G7_Sky, "G7/Sky.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Sky G7 Texture failed.. \n\n");
		return -34;
	}

	// Grass 
	bResult = loadGLTexture_stb(&G7_Grass1, "G7/Grass1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Grass1 G7 Texture failed.. \n\n");
		return -35;
	}

	// Grass 2
	bResult = loadGLTexture_stb(&G7_Grass2, "G7/Grass2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Grass2 G7 Texture failed.. \n\n");
		return -36;
	}

	//------------------------------------------------------------
	// G4
	// Golden Design1 
	bResult = loadGLTexture_stb(&G4_Golden_design1, "G4/Golden_design1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Golden design1 g4 Texture failed.. \n\n");
		return -37;
	}

	// Golden Design2
	bResult = loadGLTexture_stb(&G4_Golden_design2, "G4/Golden_design2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Golden design2 g4 Texture failed.. \n\n");
		return -38;
	}


	// Brick 0 
	bResult = loadGLTexture_stb(&G4_Brick0, "G4/Brick0.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Brick0 g4 Texture failed.. \n\n");
		return -43;
	}

	// Brick 1 
	bResult = loadGLTexture_stb(&G4_Brick1, "G4/Brick1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Brick1 g4 Texture failed.. \n\n");
		return -39;
	}

	// Brick 2 
	bResult = loadGLTexture_stb(&G4_Brick2, "G4/Brick2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Brick2 g4 Texture failed.. \n\n");
		return -40;
	}

	// Brick 3 
	bResult = loadGLTexture_stb(&G4_Brick3, "G4/Brick3.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Brick3 g4 Texture failed.. \n\n");
		return -41;
	}

	// Tile
	bResult = loadGLTexture_stb(&G4_Tile, "G4/Tile.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Tile g4 Texture failed.. \n\n");
		return -42;
	}

	// Tile2
	bResult = loadGLTexture_stb(&G4_Tile2, "G4/Tile2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Tile2 g4 Texture failed.. \n\n");
		return -44;
	}

	// Ganpati
	bResult = loadGLTexture_stb(&G4_Ganpati, "G4/Ganpati.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Ganpati g4 Texture failed.. \n\n");
		return -45;
	}

	// Shree
	bResult = loadGLTexture_stb(&G4_Shree, "G4/Shree.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Shree g4 Texture failed.. \n\n");
		return -46;
	}

	// Name
	bResult = loadGLTexture_stb(&G4_Name, "G4/Name.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Name g4 Texture failed.. \n\n");
		return -47;
	}

	// Grill
	bResult = loadGLTexture_stb(&G4_Grill, "G4/Grill.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Grill g4 Texture failed.. \n\n");
		return -48;
	}

	// Sky
	bResult = loadGLTexture_stb(&G4_Sky, "G4/Sky.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Sky g4 Texture failed.. \n\n");
		return -49;
	}

	// Stone1
	bResult = loadGLTexture_stb(&G4_Stone1, "G4/Stone1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Stone1 g4 Texture failed.. \n\n");
		return -50;
	}

	// Stone2
	bResult = loadGLTexture_stb(&G4_Stone2, "G4/Stone2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Stone2 g4 Texture failed.. \n\n");
		return -51;
	}

	// Front Grill
	bResult = loadGLTexture_stb(&G4_FGrill, "G4/FGrill.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Front Grill g4 Texture failed.. \n\n");
		return -52;
	}

	// Gate 1
	bResult = loadGLTexture_stb(&G4_Gate1, "G4/Gate1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Gate1 g4 Texture failed.. \n\n");
		return -53;
	}

	// Gate 2
	bResult = loadGLTexture_stb(&G4_Gate2, "G4/Gate2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Gate2 g4 Texture failed.. \n\n");
		return -54;
	}

	// Design1
	bResult = loadGLTexture_stb(&G5_Design1, "G5/Design1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Design1 G5 Texture failed.. \n\n");
		return -55;
	}

	// Design2
	bResult = loadGLTexture_stb(&G5_Design2, "G5/Design2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Design2 G5 Texture failed.. \n\n");
		return -56;
	}

	// Brick
	bResult = loadGLTexture_stb(&G5_Brick, "G5/Brick.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Brick G5 Texture failed.. \n\n");
		return -57;
	}

	// Stone
	bResult = loadGLTexture_stb(&G5_Stone, "G5/Stone.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Stone G5 Texture failed.. \n\n");
		return -58;
	}

	// Stone1
	bResult = loadGLTexture_stb(&G5_Stone1, "G5/Stone1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Stone1 G5 Texture failed.. \n\n");
		return -59;
	}

	// Name
	bResult = loadGLTexture_stb(&G5_Name, "G5/Name.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Name G5 Texture failed.. \n\n");
		return -60;
	}

	// Brick2
	bResult = loadGLTexture_stb(&G5_Brick2, "G5/Brick2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Brick G5 Texture failed.. \n\n");
		return -61;
	}

	// Design3 slap 
	bResult = loadGLTexture_stb(&G5_Design3, "G5/Design3.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Design3 G5 Texture failed.. \n\n");
		return -62;
	}

	// Gold
	bResult = loadGLTexture_stb(&G5_Gold, "G5/Gold.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Gold G5 Texture failed.. \n\n");
		return -63;
	}

	//  Ganpati
	bResult = loadGLTexture_stb(&G5_Ganpati, "G5/Ganpati.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Ganpati G5 Texture failed.. \n\n");
		return -64;
	}

	//----------------------------------------------------------------------
	// G8 

	//  Ganpati
	bResult = loadGLTexture_stb(&G8_Ganpati, "G8/Ganpati.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Ganpati G8 Texture failed.. \n\n");
		return -65;
	}

	//  Design
	bResult = loadGLTexture_stb(&G8_Design, "G8/Design.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Design G8 Texture failed.. \n\n");
		return -66;
	}
	
	//  G_Design
	bResult = loadGLTexture_stb(&G8_G_Design, "G8/G_Design.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  G_Design G8 Texture failed.. \n\n");
		return -67;
	}

	
	//  Pole Design
	bResult = loadGLTexture_stb(&G8_Pole_Design, "G8/Pole_Design.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Pole_Design G8 Texture failed.. \n\n");
		return -70;
	}

	//  patti Design
	bResult = loadGLTexture_stb(&G8_Patti_Design, "G8/Patti_Design.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Patti_Design G8 Texture failed.. \n\n");
		return -71;
	}

	//  Slap Design
	bResult = loadGLTexture_stb(&G8_Slap_Design, "G8/Slap_Design.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Slap_Design G8 Texture failed.. \n\n");
		return -72;
	}
	

	//  Celing Design
	bResult = loadGLTexture_stb(&G8_Celing_Design, "G8/Celing_Design.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Celing_Design G8 Texture failed.. \n\n");
		return -73;
	}

	//  Rangoli
	bResult = loadGLTexture_stb(&G8_Rangoli1, "G8/Rangoli1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Rangoli1 G8 Texture failed.. \n\n");
		return -74;
	}

	//  Name
	bResult = loadGLTexture_stb(&G8_Name, "G8/Name.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Name G8 Texture failed.. \n\n");
		return -75;
	}

	//--------------------------------------------------------------------
	// Decorations 
	////  Diva
	//bResult = loadGLTexture_stb(&Diva, "Deco/Diva.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Diva Texture failed.. \n\n");
	//	return -76;
	//}

	//  Ghanta
	bResult = loadGLTexture_stb(&Ghanta, "Deco/Ghanta.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Ghanta Texture failed.. \n\n");
		return -77;
	}

	
	//  Ghanta2
	bResult = loadGLTexture_stb(&Ghanta2, "Deco/Ghanta2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Ghanta2 Texture failed.. \n\n");
		return -95;
	}


	////  Pooja1
	//bResult = loadGLTexture_stb(&Pooja1, "Deco/Pooja1.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Pooja1 Texture failed.. \n\n");
	//	return -78;
	//}

	//  Pooja2
	bResult = loadGLTexture_stb(&Pooja2, "Deco/Pooja2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Pooja2 Texture failed.. \n\n");
		return -79;
	}

	//  Har2
	bResult = loadGLTexture_stb(&Har2, "Deco/Har2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Har2 Texture failed.. \n\n");
		return -81;
	}

	//  Har3
	bResult = loadGLTexture_stb(&Har3, "Deco/Har3.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Har3 Texture failed.. \n\n");
		return -82;
	}

	//  Har4
	bResult = loadGLTexture_stb(&Har4, "Deco/Har4.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Har4 Texture failed.. \n\n");
		return -83;
	}

	//  Har5
	bResult = loadGLTexture_stb(&Har5, "Deco/Har5.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Har5 Texture failed.. \n\n");
		return -84;
	}

	//  Har6
	bResult = loadGLTexture_stb(&Har6, "Deco/Har6.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Har6 Texture failed.. \n\n");
		return -85;
	}

	//  Har7
	bResult = loadGLTexture_stb(&Har7, "Deco/Har7.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Har7 Texture failed.. \n\n");
		return -86;
	}

	////  Har8
	//bResult = loadGLTexture_stb(&Har8, "Deco/Har8.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Har8 Texture failed.. \n\n");
	//	return -87;
	//}

	//  Har9
	bResult = loadGLTexture_stb(&Har9, "Deco/Har9.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Har9 Texture failed.. \n\n");
		return -88;
	}

	//  Har10
	bResult = loadGLTexture_stb(&Har10, "Deco/Har10.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Har10 Texture failed.. \n\n");
		return -89;
	}


	//  Rangoli1
	bResult = loadGLTexture_stb(&Rangoli1, "Deco/Rangoli1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Rangoli1 Texture failed.. \n\n");
		return -80;
	}

	
	//  Rangoli2
	bResult = loadGLTexture_stb(&Rangoli2, "Deco/Rangoli2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Rangoli2 Texture failed.. \n\n");
		return -90;
	}

	//  Rangoli3
	bResult = loadGLTexture_stb(&Rangoli3, "Deco/Rangoli3.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Rangoli3 Texture failed.. \n\n");
		return -91;
	}

	////  Rangoli4
	//bResult = loadGLTexture_stb(&Rangoli4, "Deco/Rangoli4.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Rangoli4 Texture failed.. \n\n");
	//	return -92;
	//}

	//  Rangoli5
	bResult = loadGLTexture_stb(&Rangoli5, "Deco/Rangoli5.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Rangoli5 Texture failed.. \n\n");
		return -93;
	}

	//  Rangoli6
	bResult = loadGLTexture_stb(&Rangoli6, "Deco/Rangoli6.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Rangoli6 Texture failed.. \n\n");
		return -94;
	}

	// Steel1
	bResult = loadGLTexture_stb(&Steel1, "Flower&Trees/Steel.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Steel Texture failed.. \n\n");
		return -95;
	}
	// Steel2
	bResult = loadGLTexture_stb(&Steel2, "Flower&Trees/Steel2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Steel2 Texture failed.. \n\n");
		return -96;
	}

	//-----------------------------------------------------------------------
	// flower and trees 
	
	////Mountain1
	//bResult = loadGLTexture_stb(&Mountain1, "Flower&Trees/Mountain1.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Mountain1 Texture failed.. \n\n");
	//	return -97;
	//}

	////Mountain2
	//bResult = loadGLTexture_stb(&Mountain2, "Flower&Trees/Mountain2.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Mountain2 Texture failed.. \n\n");
	//	return -98;
	//}

	////Flower1
	//bResult = loadGLTexture_stb(&Flower1, "Flower&Trees/Flower1.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Flower1 Texture failed.. \n\n");
	//	return -99;
	//}

	////Flower2
	//bResult = loadGLTexture_stb(&Flower2, "Flower&Trees/Flower2.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Flower2 Texture failed.. \n\n");
	//	return -100;
	//}

	//Flower3
	bResult = loadGLTexture_stb(&Flower3, "Flower&Trees/Flower3.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Flower3 Texture failed.. \n\n");
		return -101;
	}
	
	//Flower4
	bResult = loadGLTexture_stb(&Flower4, "Flower&Trees/Flower4.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Flower4 Texture failed.. \n\n");
		return -102;
	}
	
	//Flower5
	bResult = loadGLTexture_stb(&Flower5, "Flower&Trees/Flower5.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Flower5 Texture failed.. \n\n");
		return -103;
	}

	////Flower6
	//bResult = loadGLTexture_stb(&Flower6, "Flower&Trees/Flower6.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Flower6 Texture failed.. \n\n");
	//	return -104;
	//}

	//Tree

	//Tree1
	bResult = loadGLTexture_stb(&Tree1, "Flower&Trees/Tree1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Tree1 Texture failed.. \n\n");
		return -105;
	}

	//Tree2
	bResult = loadGLTexture_stb(&Tree2, "Flower&Trees/Tree2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Tree2 Texture failed.. \n\n");
		return -106;
	}

	//Tree3
	bResult = loadGLTexture_stb(&Tree3, "Flower&Trees/Tree3.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Tree3 Texture failed.. \n\n");
		return -107;
	}

	//Tree4
	bResult = loadGLTexture_stb(&Tree4, "Flower&Trees/Tree4.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Tree4 Texture failed.. \n\n");
		return -108;
	}

	//Tree5
	bResult = loadGLTexture_stb(&Tree5, "Flower&Trees/Tree5.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Tree5 Texture failed.. \n\n");
		return -109;
	}

	////Tree6
	//bResult = loadGLTexture_stb(&Tree6, "Flower&Trees/Tree6.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Tree6 Texture failed.. \n\n");
	//	return -110;
	//}

	//Tree7
	bResult = loadGLTexture_stb(&Tree7, "Flower&Trees/Tree7.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Tree7 Texture failed.. \n\n");
		return -111;
	}

	////Tree8
	//bResult = loadGLTexture_stb(&Tree8, "Flower&Trees/Tree8.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Tree8 Texture failed.. \n\n");
	//	return -112;
	//}

	//Grass
	
	//// Grass1
	//bResult = loadGLTexture_stb(&Grass1, "Flower&Trees/Grass1.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Grass1 Texture failed.. \n\n");
	//	return -114;
	//}
	
	// Grass2
	bResult = loadGLTexture_stb(&Grass2, "Flower&Trees/Grass2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Grass2 Texture failed.. \n\n");
		return -115;
	}
	
	//// Grass3
	//bResult = loadGLTexture_stb(&Grass3, "Flower&Trees/Grass3.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Grass3 Texture failed.. \n\n");
	//	return -116;
	//}
	//
	//// Grass4
	//bResult = loadGLTexture_stb(&Grass4, "Flower&Trees/Grass4.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Grass4 Texture failed.. \n\n");
	//	return -117;
	//}
	
	// Grass5
	bResult = loadGLTexture_stb(&Grass5, "Flower&Trees/Grass5.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Grass5 Texture failed.. \n\n");
		return -118;
	}
	
	// Grass6
	bResult = loadGLTexture_stb(&Grass6, "Flower&Trees/Grass6.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Grass6 Texture failed.. \n\n");
		return -119;
	}
	
	// Grass7
	bResult = loadGLTexture_stb(&Grass7, "Flower&Trees/Grass7.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Grass7 Texture failed.. \n\n");
		return -120;
	}
	
	// Grass8
	bResult = loadGLTexture_stb(&Grass8, "Flower&Trees/Grass8.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Grass8 Texture failed.. \n\n");
		return -121;
	}
	
	//// Grass9
	//bResult = loadGLTexture_stb(&Grass9, "Flower&Trees/Grass9.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Grass9 Texture failed.. \n\n");
	//	return -122;
	//}
	
	//// Grass10
	//bResult = loadGLTexture_stb(&Grass10, "Flower&Trees/Grass10.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Grass10 Texture failed.. \n\n");
	//	return -123;
	//}
	//

	//// Grass11
	//bResult = loadGLTexture_stb(&Grass11, "Flower&Trees/Grass11.png");
	//if (bResult == FALSE)
	//{
	//	fprintf(gpFILE, "Loading of  Grass11 Texture failed.. \n\n");
	//	return -124;
	//}

	// Tile1
	bResult = loadGLTexture_stb(&Tile1, "Flower&Trees/Tile1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Tile1 Texture failed.. \n\n");
		return -125;
	}

	// Tile2
	bResult = loadGLTexture_stb(&Tile2, "Flower&Trees/Tile2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Tile2 Texture failed.. \n\n");
		return -133;
	}

	// Tile3
	bResult = loadGLTexture_stb(&Tile3, "Flower&Trees/Tile3.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Tile3 Texture failed.. \n\n");
		return -134;
	}

	// Ganpati aatale Ranjan gav 
	bResult = loadGLTexture_stb(&G1, "Ganpati/G1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  G1 Texture failed.. \n\n");
		return -126;
	}

	bResult = loadGLTexture_stb(&G2, "Ganpati/G2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  G2 Texture failed.. \n\n");
		return -127;
	}

	bResult = loadGLTexture_stb(&G3, "Ganpati/G3.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  G3 Texture failed.. \n\n");
		return -128;
	}

	bResult = loadGLTexture_stb(&G4, "Ganpati/G4.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  G4 Texture failed.. \n\n");
		return -129;
	}

	bResult = loadGLTexture_stb(&G5, "Ganpati/G5.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  G5 Texture failed.. \n\n");
		return -130;
	}

	bResult = loadGLTexture_stb(&G6, "Ganpati/G6.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  G6 Texture failed.. \n\n");
		return -131;
	}

	bResult = loadGLTexture_stb(&G7, "Ganpati/G7.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  G6 Texture failed.. \n\n");
		return -132;
	}

	bResult = loadGLTexture_stb(&G8, "Ganpati/G8.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  G6 Texture failed.. \n\n");
		return -135;
	}
	
	// G8
	//  Stone1
	bResult = loadGLTexture_stb(&G8_Stone1, "G8/Stone1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Ston1 G8 Texture failed.. \n\n");
		return -68;
	}

	//  Stone2
	bResult = loadGLTexture_stb(&G8_Stone2, "G8/Stone2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of  Ston2 G8 Texture failed.. \n\n");
		return -69;
	}

	//----------------------------
	// G6 	
	// Ganpati
	bResult = loadGLTexture_stb(&G6_Ganpati, "G6/Ganpati.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of G6_Ganpati Texture failed.. \n\n");
		return -136;
	}

	// Pillar 
	bResult = loadGLTexture_stb(&G6_Pillar, "G6/Pillar.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of G6_Pillar Texture failed.. \n\n");
		return -137;
	}

	// Stone 
	bResult = loadGLTexture_stb(&G6_Stone, "G6/Stone.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of G6_Stone Texture failed.. \n\n");
		return -138;
	}

	// Stone2 
	bResult = loadGLTexture_stb(&G6_Stone2, "G6/Stone2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of G6_Stone2 Texture failed.. \n\n");
		return -139;
	}

	// Plane png 
	bResult = loadGLTexture_stb(&G6_Png_plane, "G6/Png_Plane.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of G6_Png_plane Texture failed.. \n\n");
		return -140;
	}

	// Doar 
	bResult = loadGLTexture_stb(&G6_Doar, "G6/doar.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of G6_Doar Texture failed.. \n\n");
		return -140;
	}

	//-------------------------
	// intro 
	

	// i_1
	bResult = loadGLTexture_stb(&I_1, "Intro/I_1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of I_1 Texture failed.. \n\n");
		return -141;
	}


	// i_2
	bResult = loadGLTexture_stb(&I_2, "Intro/I_2.bmp");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of I_2 Texture failed.. \n\n");
		return -142;
	}
	
	//--------------------------
	// Outro 
	// O1
	bResult = loadGLTexture_stb(&O1, "Outro/1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O1 Texture failed.. \n\n");
		return -143;
	}
	
	// O2
	bResult = loadGLTexture_stb(&O2, "Outro/2.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O2 Texture failed.. \n\n");
		return -144;
	}
	
	// O3
	bResult = loadGLTexture_stb(&O3, "Outro/3.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O3 Texture failed.. \n\n");
		return -145;
	}
	
	// O4
	bResult = loadGLTexture_stb(&O4, "Outro/4.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O4 Texture failed.. \n\n");
		return -146;
	}
	
	// O5
	bResult = loadGLTexture_stb(&O5, "Outro/5.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O5 Texture failed.. \n\n");
		return -147;
	}
	
	// O6
	bResult = loadGLTexture_stb(&O6, "Outro/6.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O6 Texture failed.. \n\n");
		return -148;
	}
	
	// O7
	bResult = loadGLTexture_stb(&O7, "Outro/7.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O7 Texture failed.. \n\n");
		return -149;
	}
	
	// O8
	bResult = loadGLTexture_stb(&O8, "Outro/8.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O8 Texture failed.. \n\n");
		return -150;
	}
	
	// O0
	bResult = loadGLTexture_stb(&O0, "Outro/0.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O0 Texture failed.. \n\n");
		return -151;
	}
	// O9
	bResult = loadGLTexture_stb(&O9, "Outro/9.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O9 Texture failed.. \n\n");
		return -152;
	}
	// 10
	bResult = loadGLTexture_stb(&O10, "Outro/10.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of O10 Texture failed.. \n\n");
		return -153;
	}



	// Succesfully Return
	return 1;


}
