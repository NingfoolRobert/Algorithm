
#include "CThread.h"

CNRLock::CNRLock(void)
{
	hMutex = CreateMutex(NULL, FALSE, TEXT("_tmp_mutex_lock_"));	//Create Mutex
	WaitForSingleObject(hMutex, INFINITE);					//加锁
}
CNRLock::~CNRLock(void)
{
	ReleaseMutex(hMutex);		//解锁
	CloseHandle(hMutex);
}



HANDLE CNRThread::Create(LPVOID lpParameter, DWORD dwInitialState, DWORD dwCreationFlag ) //Create thread
{
	dwState |= dwInitialState;
	this->lpParameter = lpParameter;
	if (dwState & STATE_ALIVE)
	{
		return hThread;
	}
	hThread = CreateThread(NULL, 0, StartAddress, this, dwCreationFlag, &dwThreadID);
	dwState |= STATE_ALIVE;
	if (dwState & STATE_CONTINUOUS)
	{
		hEvent = CreateEvent(NULL, TRUE, FALSE, TEXT("_tmp_event_"));
	}
	return hThread;
}
void	CNRThread::Join(DWORD dwWaitInterval = INFINITE)	// 设置进程状态
{

}
DWORD	CNRThread::Suspend()	//阻塞状态
{

}
DWORD	CNRThread::Resume()	//就绪状态
{

}
void	CNRThread::SetUserData(void* lpUserData)	//用户属性
{

}
void*	CNRThread::GetUserData() const
{

}
DWORD	CNRThread::GetID() const		//线程ID
{
	return dwThreadID;
}
HANDLE	CNRThread::GetHandle() const	//线程句柄
{
	return hThread;
}
DWORD	CNRThread::GetAsync() const	//
{

}
DWORD	CNRThread::GetState() const
{

}
void	CNRThread::SetState(DWORD dwNewState)
{

}
BOOL	CNRThread::Alert()//
{

}