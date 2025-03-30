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
	Dynamic Bharat 
	Date : 12-11-2023
*******************************************/

// Common Header Files
#include<windows.h>
#include<stdio.h> 
#include<stdlib.h> // for exit() 
#include <mmsystem.h>	// for PlaySound() api

#include"OGL.h"

// opengl header Files
#include<gl/GL.h>
#include<GL/glu.h>   // perspective sathi add keli

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


// Texture Object/ Variable
GLuint Texture_Earth = 0;
GLuint Texture_Background = 0;
GLuint Texture_Jet = 0;
GLuint Texture_intro = 0;

GLuint Texture_0Last = 0;
GLuint Texture_1Last = 0;
GLuint Texture_2Last = 0;
GLuint Texture_3Last = 0;

GLUquadric* quadric = NULL;

// for dynamic scaling and translations 

GLfloat tx = 0.0f;
GLfloat ty = 0.0f;
GLfloat tz = 0.0f;

GLfloat sx = 0.0f;
GLfloat sy = 0.0f;

// camera animationa 

GLfloat cam_x1 = -0.050f;
GLfloat cam_y1 = -0.105f;
GLfloat cam_z1 = -2.085f;

GLfloat cam_x2 = 0.0f;
GLfloat cam_y2 = 0.0f;

//////////////////////



// user defined header files 
#include"Earth.h"
#include"Scene1.h"
#include"Scene2.h"
#include"Scene3.h"

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
			tx = tx + 0.005;
			break;

		case 'x':
			tx = tx - 0.005;
			break;

		case 'Y':
			ty = ty + 0.005;
			break;

		case 'y':
			ty = ty - 0.005;
			break;

		case 'Z':
			tz = tz + 0.005;
			break;

		case 'z':
			tz = tz - 0.005;
			break;


		case 'A':
			sx = sx + 0.005;
			break;

		case 'a':
			sx = sx - 0.005;
			break;

		case 'S':
			sy = sy + 0.005;
			break;

		case 's':
			sy = sy - 0.005;
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
	int Texture_initializations(); 

	BOOL loadGLTexture(GLuint*, TCHAR[]);    // for texture
	
	// Variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;

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

	// Enabling Depth
	glShadeModel(GL_SMOOTH);					 // beutification line (optional)
	glClearDepth(1.0f);							// compulsary 
	glEnable(GL_DEPTH_TEST);					// compulsary
	glDepthFunc(GL_LEQUAL);						// compulsary
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST );   // optional

	// here openGl starts
	// Set the clear color of window to blue
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // blue color de as sangital ct ith color ith nhi dila jat

	PlaySound("Audio.wav", NULL, SND_ASYNC);


	// Loading Images to create Texture  
	Texture_initializations();

	// tell opengl to enable the texture (step 4)
	glEnable(GL_TEXTURE_2D);

	// initialize quadric
	quadric = gluNewQuadric();
	//:::::::::::::::::::::::::::::::::::

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	resize(WIN_WIDTH,WIN_HEIGHT);  // warm up resize call
	return(0);
}

int Texture_initializations()
{
	// Local variable declarations 
	BOOL bResult; // for texture


	// Loading Images to create Texture  
	bResult = loadGLTexture(&Texture_Earth, MAKEINTRESOURCE(MY_EARTH_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Earth Texture failed.. \n\n");
		return -6;
	}

	bResult = loadGLTexture(&Texture_Background, MAKEINTRESOURCE(MY_BACKGROUND_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Background Texture failed.. \n\n");
		return -7;
	}
	
	bResult = loadGLTexture(&Texture_Jet, MAKEINTRESOURCE(MY_JETTEXTURE_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Jet Texture failed.. \n\n");
		return -8;
	}
	
	bResult = loadGLTexture(&Texture_intro, MAKEINTRESOURCE(MY_INTROIMAGE_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of intro Texture failed.. \n\n");
		return -9;
	}


	bResult = loadGLTexture(&Texture_0Last, MAKEINTRESOURCE(MY_0LAST_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of 0 Last Texture failed.. \n\n");
		return -10;
	}

	bResult = loadGLTexture(&Texture_1Last, MAKEINTRESOURCE(MY_1LAST_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of 1 Last Texture failed.. \n\n");
		return -11;
	}

	bResult = loadGLTexture(&Texture_2Last, MAKEINTRESOURCE(MY_2LAST_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of 2 Last Texture failed.. \n\n");
		return -12;
	}

	bResult = loadGLTexture(&Texture_3Last, MAKEINTRESOURCE(MY_3LAST_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of 3 Last Texture failed.. \n\n");
		return -13;
	}
	return(0);
}

// texture sathi add kel 
BOOL loadGLTexture(GLuint* texture, TCHAR imageResourceID[])
{
	// Local variable declarations 
	HBITMAP hBitmap = NULL;
	BITMAP bmp; 

	// Load the image                  (step 5)
	hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceID, IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
	if (hBitmap == NULL)
	{
		fprintf(gpFILE, "LoadImage() failed.. \n\n");
		return FALSE; 
	}

	// Get image data                  (step 6)
	GetObject(hBitmap, sizeof(BITMAP),&bmp);

	// create opengl texture object     (step 6)
	glGenTextures(1,texture);

	// bind to generated texture        (step 7)
	glBindTexture(GL_TEXTURE_2D, *texture);

	// unpacked image					(step 8)
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	// set texture parameters			(Step 9)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);  

	// create multiple mitmap images    (step 10)
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3,bmp.bmWidth,bmp.bmHeight,GL_BGR_EXT,GL_UNSIGNED_BYTE,(void *)bmp.bmBits);

	// unbined the texture              (step 11)
	glBindTexture(GL_TEXTURE_2D, 0);

	// delete image resoure             (step 12)
	DeleteObject(hBitmap);
	hBitmap = NULL;

	return TRUE;
}


void resize(int width, int height)
{
	// Code

	if (height <= 0) // precausion (height na division krnar y pudh )
		height = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 0.1f, 100.0f );  // perspective sathi hi line add keli
	
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // glViewport = binocular - durbin
}

void display(void)
{
	char str[255];

	// Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Blue color hya line mul set hoto
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 

	//////////////////////////
	sprintf(str, "tx= %.3f, ty= %.3f, tz= %.3f || sx= %.3f, sy= %.3f", tx, ty, tz, sx, sy);
	SetWindowText(ghwnd, str);

	//--------------------------------------------------------------------
	
	
	//gluLookAt(tx, ty, tz, sx, sy, 100, 0, 1, 0);

	if (cam_z1 <= -0.095)
	{
		gluLookAt(cam_x1, cam_y1, cam_z1,
			cam_x2, cam_y2, 100,
			0, 1, 0);

		Start_Scene1();
	}

	else if (Blend_Value <= 0.6)
		Start_Scene2();

	else
		Start_Scene3();

	//-------------------------------------------------------------------

	SwapBuffers(ghdc);
}

void update(void)
{
	// Code
	
	// first scene camera aat 
	if (cam_z1 <= -1.095)
		cam_z1 = cam_z1 + 0.0005;

	else if (cam_z1 <= -0.095)
		cam_z1 = cam_z1 + 0.0008;


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
	
	// texture uninitialize
	if (Texture_Earth)
	{
		glDeleteTextures(1, &Texture_Earth);
		Texture_Earth = 0;
	}

	if (Texture_Background)
	{
		glDeleteTextures(1, &Texture_Background);
		Texture_Background = 0;
	}

	if (Texture_Jet)
	{
		glDeleteTextures(1, &Texture_Jet);
		Texture_Jet = 0;
	}

	// free quadric
	if (quadric)
	{
		gluDeleteQuadric(quadric);
		quadric = NULL;
	}

	// Close the log file 
	if (gpFILE)
	{	
		fprintf(gpFILE, "Program Ended Successfully...\n"); 
		fclose(gpFILE);
		gpFILE = NULL;
	}

}

                                                                                                        



