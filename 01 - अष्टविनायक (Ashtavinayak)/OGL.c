/*
    Run Commands : 
		Compile : 
				cl.exe /c /EHsc Window.c  
		Linkining : 
				link.exe Window.obj Window.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
		Run      :
				Window.exe
				
*/

/******************************************* 
	FFP DS Demo
	Date           : 13.01.2024
	Date Completed : 09.03.2024
*******************************************/

// Common Header Files
#include<windows.h>
#include<stdio.h> 
#include<stdlib.h> // for exit() 

#include"OGL.h"
#include<mmsystem.h>

// opengl header Files
#include<gl/GL.h>
#include<GL/glu.h>   // perspective sathi add keli

// for image loading ..(png, bmp, jpeg, jpg)
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"

// Macrose
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// link with OpenGL library
#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"glu32.lib")    // perspective sathi add keli

// openGl related global variables
HDC ghdc = NULL;
HGLRC ghrc = NULL;

// Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable declarations
HWND ghwnd = NULL;  
DWORD dwStyle = 0;

WINDOWPLACEMENT wpPrev = {sizeof(WINDOWPLACEMENT)};
BOOL gbfullscreen = FALSE; 

FILE* gpFILE = NULL;
BOOL gbActive = FALSE;

// For Sphere 
GLUquadric* quadric;
GLUquadric* quadric2;

// for dynamic scaling and translations 
GLfloat tx = 0.0f;
GLfloat ty = 0.0f;
GLfloat tz = 0.0f;

GLfloat sx = 0.0f;
GLfloat sy = 0.0f;
GLfloat sz = 0.0f;

GLfloat ri = 0.0f;
GLfloat ro = 0.0f;
GLfloat rp = 0.0f;

// scene 
GLint Scene_Count = 0;

// Flag
BOOL Fog_S1 = TRUE;
BOOL Fog_S2 = FALSE;
GLfloat fogColor[4] = { 1.0, 1.0, 1.0, 0.1 }; //  color blck G1 

// for Terrain
#define TERRAIN_MAP_X 257
#define TERRAIN_MAP_Z 257
#define MAP_SCALE 10.0

unsigned char* imageData = NULL;
float terrain_Height_Map[TERRAIN_MAP_X][TERRAIN_MAP_Z][3];
GLuint Texture_Terrain = 0;

// intro 
BOOL I_Flag = TRUE;

BOOL Flag_Color_Blend = TRUE;
BOOL Flag_Color_Blend1 = TRUE;
BOOL Flag_Color_Blend2 = FALSE;

HINSTANCE hInst = NULL;

////////////////////////////////////////
// User Defined Header Files 
#include"Textures_Loading.h"    // My_Load_Textures()
#include"Map_Scene.h"
#include"Wave.h"

#include"Objects.h"
#include"G_1.h"
#include"G_2.h"
#include"G_3.h"


#include"G_7.h"
#include"G_4.h"
#include"G_5.h"
#include"G_8.h"
#include"G_6.h"

#include"Intro.h"
#include"Outro.h"

////////////////////////////////////////

//----------------------------------------------------------------------
// Entry point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{ 
	// Function Declarations 
	int initialize(void);
	void uninitialize(void);
	void display(void); 
	void update(void);

	// local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SVDWindow"); 
	int iResult = 0;  // for base code
	BOOL bDone = FALSE; 

	// Local Variable for finding the center of the window
	int SW = 0;   // Screen width
	int SH = 0;   // Screen Height

	float x = 0.0f;
	float y = 0.0f;

	// Code
	gpFILE = fopen("log.txt","w");
	if (gpFILE == NULL)
	{
		MessageBox(NULL, TEXT("Log File cannot be opend..."), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}

	fprintf(gpFILE , "Program Started Successfully... \n\n");

	// WNDCLASSEX initialization  
	// structer ch inline initialization

	wndclass.cbSize			= sizeof(WNDCLASSEX);
	wndclass.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC; 
	wndclass.cbWndExtra		= 0;
	wndclass.cbClsExtra		= 0;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.hInstance		= hInstance;
	wndclass.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor		= LoadCursor(NULL,IDC_ARROW);
	wndclass.lpszClassName	= szAppName;
	wndclass.lpszMenuName	= NULL;
	wndclass.hIconSm		= LoadIcon(hInstance,MAKEINTRESOURCE(MYICON));


	// Register WNDCLASSEX 
	RegisterClassEx(&wndclass);

	// Centering of window code
	SW = GetSystemMetrics(SM_CXSCREEN); 
	SH = GetSystemMetrics(SM_CYSCREEN); 

	x = (SW / 2.0) - (WIN_WIDTH / 2.0); 
	y = (SH / 2.0) - (WIN_HEIGHT / 2.0); 


	// Create Window
	hwnd = CreateWindowEx( WS_EX_APPWINDOW,
						 szAppName,
						 TEXT("Saurabh Dhoke"),
						 WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, 
						 x,
				   		 y,
		                 WIN_WIDTH,  
		                 WIN_HEIGHT,  
						 NULL,
						 NULL,
						 hInstance,
						 NULL );

	// gloabal handel madhi value takli 
	ghwnd = hwnd; 

	//initialization
	iResult = initialize();

	if (iResult != 0)
	{
		MessageBox(hwnd, TEXT("initialize() Failed..."), TEXT("Error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);

		//uninitialize();
		//exit(0);	//  yala call kela tri chalel
	}

	// Show the Window
	ShowWindow(hwnd,iCmdShow); 
	
	SetForegroundWindow(hwnd); 
	SetFocus(hwnd); 

	// Game Loop
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{
			if (msg.message == WM_QUIT)
				bDone = TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gbActive == TRUE)  // setfocus mdhi true zalelay he gbActive 
			{
				// Render
				display();

				// Update 
				update();

			}
		}
	}

	// uninitialization
	uninitialize();
	
	return((int)msg.wParam);  
}

// CALLBACK function
LRESULT CALLBACK WndProc(HWND   hwnd, UINT   iMsg, WPARAM wParam, LPARAM lParam)
{
	// Function declarations
	void ToggleFullscreen(void);
	void resize(int,int); 


	// Code

	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActive = TRUE; 
		break;

	case WM_KILLFOCUS:
		gbActive = FALSE; 
		break;

	case WM_SIZE: //  Width           Height
		resize(LOWORD(lParam), HIWORD(lParam)); 
		break;

	case WM_ERASEBKGND:  // os ch WS_Paint vaparayach nahiy mhanun he vapralay 
		return(0);

	case WM_KEYDOWN :
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE :
			DestroyWindow(hwnd);
			break;
		}
		break;
	
	case WM_CHAR :
		switch (LOWORD(wParam))
		{
		case 'F' :
		case 'f' :
			if (gbfullscreen == FALSE)
			{
				ToggleFullscreen();
				gbfullscreen = TRUE;
			}
			else
			{
				ToggleFullscreen();
				gbfullscreen = FALSE; 
			}
			break;

		case 'X':
			tx = tx + 0.05;
			break;

		case 'x':
			tx = tx - 0.05;
			break;

		case 'Y':
			ty = ty + 0.05;
			break;

		case 'y':
			ty = ty - 0.05;
			break;

		case 'Z':
			tz = tz + 0.05;
			break;

		case 'z':
			tz = tz - 0.05;
			break;


		case 'A':
			sx = sx + 0.1;
			break;

		case 'a':
			sx = sx - 0.1;
			break;

		case 'B':
			sy = sy + 0.1;
			break;

		case 'b':
			sy = sy - 0.1;
			break;
		
		case 'C':
			sz = sz + 0.1;
			break;

		case 'c':
			sz = sz - 0.1;
			break;
		

		case 'I':
			ri = ri + 0.1;
			break;

		case 'i':
			ri = ri - 0.1;
			break;

		case 'O':
			ro = ro + 0.1;
			break;

		case 'o':
			ro = ro - 0.1;
			break;

		case 'P':
			rp = rp + 0.1;
			break;

		case 'p':
			rp = rp - 0.1;
			break;


		}
		break;

	case WM_DESTROY : 
		PostQuitMessage(0);
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	default :
		break;
	}

	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}
void ToggleFullscreen(void)
{
	// Local Variable Declarations
	MONITORINFO mi = { sizeof(MONITORINFO) };

	// Code
	if (gbfullscreen == FALSE)
	{	
		dwStyle = GetWindowLong(ghwnd,GWL_STYLE);
		
		if (dwStyle & WS_OVERLAPPEDWINDOW) 
		{	
			if (GetWindowPlacement(ghwnd,&wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{    
				SetWindowLong(ghwnd,GWL_STYLE,dwStyle & ~WS_OVERLAPPEDWINDOW); // dwStyle shodh aani WS_OVERLAPPEDWINDOW kadhun tak (~ remove karto)                             
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);			
			}
		}
		ShowCursor(FALSE);
	}
	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED); // window placement allredy set zali first line la mhanun 0 dilet
		ShowCursor(TRUE); 
	}
}

int initialize(void)
{
	// Function Declarations
	void resize(int , int);
	BOOL loadGLTexture(GLuint*, TCHAR[]);    // for texture
	BOOL loadGLTexture_stb(GLuint*, char*);

	// Variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	
	int Result; // for texture

	BOOL bResult;

	// code
	ZeroMemory(&pfd,sizeof(PIXELFORMATDESCRIPTOR));

	// step 1 - initialization of pixel format descriptor
	pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion   = 1;
	pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;  /// ???????????? PFD_RGBA
	pfd.cColorBits = 32;
	pfd.cRedBits   = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits  = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;

	// step 2 - get the DC (device context)
	ghdc = GetDC(ghwnd);
	if (ghdc == 0)
	{
		fprintf(gpFILE, "GetDC() failed.. \n\n");
		return -1;
	}

	// step 3
	iPixelFormatIndex = ChoosePixelFormat(ghdc,&pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFILE, "ChoosePixelFormat() failed.. \n\n");
		return -2;
	}

	// Step 4
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFILE, "SetPixelFormat() failed.. \n\n");
		return -3;
	}

	// tell wgl library to give opengl compatable device context to this device context
	// create opengl context from device context 
	ghrc = wglCreateContext(ghdc);
	if (ghrc == 0)
	{
		fprintf(gpFILE, "wglCreateContext() failed.. \n\n");
		return -4;
	}

	// Make rendering Context current 
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFILE, "wglMakeCurrent() failed.. \n\n");
		return -5;
	}

	// Play Sound 
	//PlaySound("song.wav", NULL, SND_ASYNC);


	// Enabling Depth
	glShadeModel(GL_SMOOTH);					 // beutification line (optional)
	glClearDepth(1.0f);							// compulsary 
	glEnable(GL_DEPTH_TEST);					// compulsary
	glDepthFunc(GL_LEQUAL);						// compulsary
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST );   // optional



	GLfloat fogColor[4] = { 0.0, 0.0, 0.0, 1.0};

	glClearColor(0,0,0, 1.0f);

	//-----------------------
	// texture
	bResult = loadGLTexture_stb(&Texture_Terrain, "G6/Grass.png");
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Grass Texture failed.. \n\n");
		return -1;
	}

	// For Terrain 
	int imageWidth, imageHeight, imageChannels;
	imageData = stbi_load("G6/Terrain.png", &imageWidth, &imageHeight, &imageChannels, 0);
	if (imageData == NULL)
	{
		fprintf(gpFILE, "Loading of Image Data failed.. \n\n");
		return -2;
	}

	for (int z = 0; z < TERRAIN_MAP_Z; z++)
	{
		for (int x = 0; x < TERRAIN_MAP_X; x++)
		{
			terrain_Height_Map[x][z][0] = (float)(x) * 20.0;  // step_size = 20
			terrain_Height_Map[x][z][1] = imageData[(z * TERRAIN_MAP_Z + x) * 3];
			terrain_Height_Map[x][z][2] = -(float)(z) * 10.0;
		}
	}
	//-----------------------



	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_EXP);   // fog mod kontay 3 paiki -> GL_EXP , GL_EXP2,GL_LINEAR
	glFogfv(GL_FOG_COLOR, fogColor); // Fog color 
	glFogf(GL_FOG_DENSITY, 0.5f); 
	glHint(GL_FOG_HINT,GL_NICEST); // hi line ny dili tri default nicest ghetach te 
	glFogf(GL_FOG_START,1.0f);  // camera view mdhi fog kudhun start honar 
	glFogf(GL_FOG_END,3.5f);  // kut paryant fog asnar 

	//--------------


	// Loading Images to create Texture  
	//  ------ stbi  loading image ----------
	Result = My_Load_Textures();
	if (Result < 0)
	{
		return -7;
	}
	//-------------------------------------------

	// tell opengl to enable the texture (step 4)
	glEnable(GL_TEXTURE_2D);

	// initialize quadric
	quadric = gluNewQuadric();
	quadric2 = gluNewQuadric();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// For Blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// for wave 
	Call_in_initialize();

	PlaySound(TEXT("soundName"), hInst, SND_RESOURCE | SND_ASYNC);

	resize(WIN_WIDTH,WIN_HEIGHT);  // warm up resize call
	return(0);
}
void resize(int width, int height)
{
	// Code

	if (height <= 0) // precausion (height na division krnar y pudh )
		height = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 0.1f, 100000.0f );  // perspective sathi hi line add keli
	
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // glViewport = binocular - durbin
}
void display(void)
{
	// Local Variable Declarations
	char str[255];


	// Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Blue color hya line mul set hoto
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 


	//--------------------------------------------------------------------
	sprintf(str, "tx= %.3f, ty= %.3f, tz= %.3f || x= %.3f, y= %.3f, z= %.3f || i= %.3f, o= %.3f, p= %.3f ", tx, ty, tz, sx, sy, sz, ri, ro, rp);

	SetWindowText(ghwnd, str);
    //------------------------------------------------------------------------

	//gluLookAt(tx, ty, tz, sx, sy, 100, 0, 1, 0);

	glDisable(GL_FOG);



	if (Scene_Count == 0)
		Start_Intro();

	if (Scene_Count == 1)
		Start_G_1();

	else if (Scene_Count == 2)
		Start_G_2();

	else if (Scene_Count == 3)
		Start_G_3();

	else if (Scene_Count == 4)
		Start_G_4();

	else if (Scene_Count == 5)
		Start_G_5();

	else if (Scene_Count == 6)
		Start_G_6();

	else if (Scene_Count == 7)
		Start_G_7();

	else if (Scene_Count == 8)
		Start_G_8();
	else if(Scene_Count == 9)
		Start_Outro();

	SwapBuffers(ghdc);
}

void update(void)
{
	// Code
	
}
void uninitialize(void)
{
	// Function Declarations
	void ToggleFullscreen(void);
	
	// Code
	
	// if application is exiting in fullDcreen
	if (gbfullscreen == TRUE)    
	{
		ToggleFullscreen();     // jar kuni madhich esc kel tr window small kr fullscreen asl tr an mng close kr 
		gbfullscreen = FALSE; 
	}

	// Make the hdc as the current dc
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	// destroy / delte rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	// release the HDC 
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	// Destroy Window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}
	
	/*
	// texture uninitialize
	if (Texture_Smiley)
	{
		glDeleteTextures(1, &Texture_Smiley);
		Texture_Smiley = 0;
	}
	*/

	// Close the log file 
	if (gpFILE)
	{	
		fprintf(gpFILE, "Program Ended Successfully...\n"); 
		fclose(gpFILE);
		gpFILE = NULL;
	}

}

                                                                                                        



