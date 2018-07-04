#pragma once
////////////////////////////////////////////////////////////////////////////////
// Filename: systemclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_

///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define WIN32_LEAN_AND_MEAN

//////////////
// INCLUDES //
//////////////
#include <windows.h>

#include "Inputclass.h"
#include "Graphicsclass.h"
#include "Fpsclass.h"
#include "Cpuclass.h"
#include "Timerclass.h"
#include "Positionclass.h"

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND hwnd, UINT unit, WPARAM wParam, LPARAM lParam);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	GraphicsClass* m_Graphics;
	FpsClass* m_Fps;
	CpuClass* m_Cpu;
	TimerClass* m_Timer;
	PositionClass *m_Position;
};

static LRESULT CALLBACK WndProc(HWND hwnd, UINT uint, WPARAM wParam, LPARAM lParam);

static SystemClass* ApplicationHandle = 0;

#endif