#pragma once
#include <process.h>
#include <Windows.h>
/*

*/
CRITICAL_SECTION   m_clsLock1;
CRITICAL_SECTION   m_clsLock2;
int num = 0;
unsigned int  _stdcall data_process1(void* lParam)
{
	EnterCriticalSection(&m_clsLock1);
	Sleep(5);
	EnterCriticalSection(&m_clsLock2);
	num++;
	std::cout << num << std::endl;

	LeaveCriticalSection(&m_clsLock2);
	LeaveCriticalSection(&m_clsLock1);

	return 0;
}

unsigned int  _stdcall data_process2(void* lParam)
{
	EnterCriticalSection(&m_clsLock2);
	Sleep(5);
	EnterCriticalSection(&m_clsLock1);
	num++;
	std::cout << num << std::endl;
	LeaveCriticalSection(&m_clsLock1);
	LeaveCriticalSection(&m_clsLock2);

	return 0;
}

void TestDeadLock()
{
	InitializeCriticalSection(&m_clsLock1);
	InitializeCriticalSection(&m_clsLock2);

	_beginthreadex(NULL, NULL, &data_process1, NULL, NULL, NULL);
	_beginthreadex(NULL, NULL, &data_process2, NULL, NULL, NULL);

	DeleteCriticalSection(&m_clsLock1);
	DeleteCriticalSection(&m_clsLock2);
	while (true);

}