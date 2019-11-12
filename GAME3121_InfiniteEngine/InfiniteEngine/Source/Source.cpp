#include "GameCodeApp.h"
#include <iostream>
#include "stdlib.h"
#include "string.h"
#include "tchar.h"
#include <stdio.h>
#include <wchar.h>
#include "Winuser.h"

using namespace std;

/*int main()
{
	GameCodeApp* gGameCodeApp;
	gGameCodeApp = new GameCodeApp();
	
	//gGameCodeApp->CheckMemory();




	system("PAUSE");
	return 0;
}*/

// Global variables  

// The main window class name.  
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.  
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");

HINSTANCE hInst;

static int outY = 5;
static int yInc = 20;

// Forward declarations of functions included in this code module:  
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance; // Store instance handle in our global variable  

	// The parameters to CreateWindow explained:  
	// szWindowClass: the name of the application  
	// szTitle: the text that appears in the title bar  
	// WS_OVERLAPPEDWINDOW: the type of window to create  
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)  
	// 500, 100: initial size (width, length)  
	// NULL: the parent of this window  
	// NULL: this application does not have a menu bar  
	// hInstance: the first parameter from WinMain  
	// NULL: not used in this application  
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 500,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	GameCodeApp* gGameCodeApp;
	gGameCodeApp = new GameCodeApp();

	// The parameters to ShowWindow explained:  
	// hWnd: the value returned from CreateWindow  
	// nCmdShow: the fourth parameter from WinMain  
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:  
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//  
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)  
//  
//  PURPOSE:  Processes messages for the main window.  
//  
//  WM_PAINT    - Paint the main window  
//  WM_DESTROY  - post a quit message and return  
//  
//  
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc; // handle to device context 
	TCHAR greeting[] = _T("Hello, World!");
	TCHAR keyDownInput[] = _T("Key Down!");
	TCHAR keyUpInput[] = _T("Key Up!");
	wchar_t msg[32];

	RECT rcClient;                 // client area rectangle 
	POINT ptClientUL;              // client upper left corner 
	POINT ptClientLR;              // client lower right corner 
	static POINTS ptsBegin;        // beginning point 
	static POINTS ptsEnd;          // new endpoint 
	static POINTS ptsPrevEnd;      // previous endpoint 
	static BOOL fPrevLine = FALSE; // previous line flag

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.  
		// For this introduction, we just print out "Hello, World!"  
		// in the top left corner.  
		TextOut(hdc,
			5, outY,
			greeting, _tcslen(greeting));
		// End application-specific layout section.  

		EndPaint(hWnd, &ps);
		outY += yInc;
		break;
	case WM_LBUTTONDOWN: // Capture mouse input.

	// Capture mouse input. 

		SetCapture(hWnd);

		// Retrieve the screen coordinates of the client area, 
		// and convert them into client coordinates. 

		GetClientRect(hWnd, &rcClient);
		ptClientUL.x = rcClient.left;
		ptClientUL.y = rcClient.top;

		// Add one to the right and bottom sides, because the 
		// coordinates retrieved by GetClientRect do not 
		// include the far left and lowermost pixels. 

		ptClientLR.x = rcClient.right + 1;
		ptClientLR.y = rcClient.bottom + 1;
		ClientToScreen(hWnd, &ptClientUL);
		ClientToScreen(hWnd, &ptClientLR);

		// Copy the client coordinates of the client area 
		// to the rcClient structure. Confine the mouse cursor 
		// to the client area by passing the rcClient structure 
		// to the ClipCursor function. 

		SetRect(&rcClient, ptClientUL.x, ptClientUL.y,
			ptClientLR.x, ptClientLR.y);
		ClipCursor(&rcClient);

		// Convert the cursor coordinates into a POINTS 
		// structure, which defines the beginning point of the 
		// line drawn during a WM_MOUSEMOVE message. 

		ptsBegin = MAKEPOINTS(lParam);
		return 0;
	case WM_MOUSEMOVE: // The user must hold down the mouse button to draw lines.
		// When moving the mouse, the user must hold down 
			// the left mouse button to draw lines. 

		if (wParam & MK_LBUTTON)
		{

			// Retrieve a device context (DC) for the client area. 

			hdc = GetDC(hWnd);

			// The following function ensures that pixels of 
			// the previously drawn line are set to white and 
			// those of the new line are set to black. 

			SetROP2(hdc, R2_NOTXORPEN);

			// If a line was drawn during an earlier WM_MOUSEMOVE 
			// message, draw over it. This erases the line by 
			// setting the color of its pixels to white. 

			if (fPrevLine)
			{
				MoveToEx(hdc, ptsBegin.x, ptsBegin.y,
					(LPPOINT)NULL);
				LineTo(hdc, ptsPrevEnd.x, ptsPrevEnd.y);
			}

			// Convert the current cursor coordinates to a 
			// POINTS structure, and then draw a new line. 

			ptsEnd = MAKEPOINTS(lParam);
			MoveToEx(hdc, ptsBegin.x, ptsBegin.y, (LPPOINT)NULL);
			LineTo(hdc, ptsEnd.x, ptsEnd.y);

			// Set the previous line flag, save the ending 
			// point of the new line, and then release the DC. 

			fPrevLine = TRUE;
			ptsPrevEnd = ptsEnd;
			ReleaseDC(hWnd, hdc);
		}
		break;
	case WM_LBUTTONUP:
		// The user has finished drawing the line. Reset the 
			// previous line flag, release the mouse cursor, and 
			// release the mouse capture. 

		fPrevLine = FALSE;
		ClipCursor(NULL);
		ReleaseCapture();
		return 0;
	case WM_ACTIVATEAPP:
		if (wParam == TRUE) // Get focus again to regain our mouse capture if (bIsCapture)
		{
			SetCapture(hWnd);
		}
		break;
	case WM_KEYDOWN:
		hdc = GetDC(hWnd);
		TextOut(hdc,
			5, outY,
			keyDownInput, _tcslen(keyDownInput));
		UpdateWindow(hWnd);
		outY += yInc;
		//::MessageBox(hWnd, _T("A Key"), _T("Key Pressed"), MB_OK);
		switch (wParam)
		{
		case VK_LEFT:
			//::MessageBox(hWnd, _T("Left Arrow"), _T("Key Pressed"), MB_OK);
		default:
			break;
		}
		break;
	case WM_KEYUP:
		hdc = GetDC(hWnd);
		TextOut(hdc,
			5, outY,
			keyUpInput, _tcslen(keyUpInput));
		UpdateWindow(hWnd);
		outY += yInc;
		//::MessageBox(hWnd, _T("A Key"), _T("Key Pressed"), MB_OK);
		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

//LRESULT APIENTRY MainWndProc(HWND hwndMain, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;                       // handle to device context 
//	RECT rcClient;                 // client area rectangle 
//	POINT ptClientUL;              // client upper left corner 
//	POINT ptClientLR;              // client lower right corner 
//	static POINTS ptsBegin;        // beginning point 
//	static POINTS ptsEnd;          // new endpoint 
//	static POINTS ptsPrevEnd;      // previous endpoint 
//	static BOOL fPrevLine = FALSE; // previous line flag
//
//	switch (uMsg)
//	{
//	case WM_LBUTTONDOWN: // Capture mouse input.
//		
//		// Capture mouse input. 
//
//		SetCapture(hwndMain);
//
//		// Retrieve the screen coordinates of the client area, 
//		// and convert them into client coordinates. 
//
//		GetClientRect(hwndMain, &rcClient);
//		ptClientUL.x = rcClient.left;
//		ptClientUL.y = rcClient.top;
//
//		// Add one to the right and bottom sides, because the 
//		// coordinates retrieved by GetClientRect do not 
//		// include the far left and lowermost pixels. 
//
//		ptClientLR.x = rcClient.right + 1;
//		ptClientLR.y = rcClient.bottom + 1;
//		ClientToScreen(hwndMain, &ptClientUL);
//		ClientToScreen(hwndMain, &ptClientLR);
//
//		// Copy the client coordinates of the client area 
//		// to the rcClient structure. Confine the mouse cursor 
//		// to the client area by passing the rcClient structure 
//		// to the ClipCursor function. 
//
//		SetRect(&rcClient, ptClientUL.x, ptClientUL.y,
//			ptClientLR.x, ptClientLR.y);
//		ClipCursor(&rcClient);
//
//		// Convert the cursor coordinates into a POINTS 
//		// structure, which defines the beginning point of the 
//		// line drawn during a WM_MOUSEMOVE message. 
//
//		ptsBegin = MAKEPOINTS(lParam);
//		return 0;
//	case WM_MOUSEMOVE: // The user must hold down the mouse button to draw lines.
//		// When moving the mouse, the user must hold down 
//			// the left mouse button to draw lines. 
//
//		if (wParam & MK_LBUTTON)
//		{
//
//			// Retrieve a device context (DC) for the client area. 
//
//			hdc = GetDC(hwndMain);
//
//			// The following function ensures that pixels of 
//			// the previously drawn line are set to white and 
//			// those of the new line are set to black. 
//
//			SetROP2(hdc, R2_NOTXORPEN);
//
//			// If a line was drawn during an earlier WM_MOUSEMOVE 
//			// message, draw over it. This erases the line by 
//			// setting the color of its pixels to white. 
//
//			if (fPrevLine)
//			{
//				MoveToEx(hdc, ptsBegin.x, ptsBegin.y,
//					(LPPOINT)NULL);
//				LineTo(hdc, ptsPrevEnd.x, ptsPrevEnd.y);
//			}
//
//			// Convert the current cursor coordinates to a 
//			// POINTS structure, and then draw a new line. 
//
//			ptsEnd = MAKEPOINTS(lParam);
//			MoveToEx(hdc, ptsBegin.x, ptsBegin.y, (LPPOINT)NULL);
//			LineTo(hdc, ptsEnd.x, ptsEnd.y);
//
//			// Set the previous line flag, save the ending 
//			// point of the new line, and then release the DC. 
//
//			fPrevLine = TRUE;
//			ptsPrevEnd = ptsEnd;
//			ReleaseDC(hwndMain, hdc);
//		}
//		break;
//	case WM_LBUTTONUP:
//		// The user has finished drawing the line. Reset the 
//			// previous line flag, release the mouse cursor, and 
//			// release the mouse capture. 
//
//		fPrevLine = FALSE;
//		ClipCursor(NULL);
//		ReleaseCapture();
//		return 0;
//	case WM_ACTIVATEAPP:
//		if (wParam == TRUE) // Get focus again to regain our mouse capture if (bIsCapture)
//		{
//			SetCapture(hwndMain);
//		}
//		break;
//	}
//	return 0;
//}