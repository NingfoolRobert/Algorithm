
#include "CThread.h"

CNRLock::CNRLock(void)
{
	hMutex = CreateMutex(NULL, FALSE, TEXT("_tmp_mutex_lock_"));	//Create Mutex
	WaitForSingleObject(hMutex, INFINITE);					//����
}
CNRLock::~CNRLock(void)
{
	ReleaseMutex(hMutex);		//����
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
void	CNRThread::Join(DWORD dwWaitInterval = INFINITE)	// ���ý���״̬
{

}
DWORD	CNRThread::Suspend()	//����״̬
{

}
DWORD	CNRThread::Resume()	//����״̬
{

}
void	CNRThread::SetUserData(void* lpUserData)	//�û�����
{

}
void*	CNRThread::GetUserData() const
{

}
DWORD	CNRThread::GetID() const		//�߳�ID
{
	return dwThreadID;
}
HANDLE	CNRThread::GetHandle() const	//�߳̾��
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