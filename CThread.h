#ifndef  _CTHREAD_H_
#define  _CTHREAD_H_

#include <windows.h>

#define STATE_RUNNING		0x0001
#define STATE_READY			0x0002
#define STATE_BLOCKED		0x0004
#define STATE_ALIVE			0x0008
#define STATE_ASYNC			0x0010
#define STATE_SYNC			0x0020
#define STATE_CONTINUOUS	0x0040


class CNRLock
{
public:
	CNRLock(void);
	~CNRLock(void);
private:
	HANDLE	hMutex;
};

class CNRThread
{
public:
	CNRThread():hThread(0),dwThreadID(0),dwState(0),lpUserData(0),lpParameter(0){}
	HANDLE	Create(LPVOID lpParameter, DWORD dwInitialState = STATE_ASYNC, DWORD dwCreationFlag = 0); //Create thread
	void	Join(DWORD dwWaitInterval = INFINITE);	// 设置进程状态
	DWORD	Suspend();	//阻塞状态
	DWORD	Resume();	//就绪状态
	void	SetUserData(void* lpUserData);	//用户属性
	void*	GetUserData() const;
	DWORD	GetID() const;		//线程ID
	HANDLE	GetHandle() const;	//线程句柄
	DWORD	GetAsync() const;	//
	DWORD	GetState() const;
	void	SetState(DWORD dwNewState);
	BOOL	Alert();		//
protected:
	virtual void Run(LPVOID lpParameter = 0);
	LPVOID lpParameter;
private:
	static	DWORD WINAPI StartAddress(LPVOID lpParameter);
	HANDLE	hThread;
	DWORD	dwThreadID;
	DWORD	dwState;
	void*	lpUserData;
	HANDLE	hEvent;
};
#endif
