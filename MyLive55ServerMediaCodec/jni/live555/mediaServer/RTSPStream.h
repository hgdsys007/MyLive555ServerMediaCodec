/******************************************************************** 
filename:   RTSPStream.h
created:    2013-08-01
author:     firehood 
purpose:    ͨ��live555ʵ��H264 RTSPֱ��
*********************************************************************/ 
#pragma once
#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

#ifdef WIN32
typedef HANDLE       ThreadHandle;
#define mSleep(ms)   Sleep(ms)
#else
typedef unsigned int SOCKET;
typedef pthread_t    ThreadHandle;
#define mSleep(ms)   usleep(ms*1000)
#endif

#define FILEBUFSIZE (1024 * 1024) 


class CRTSPStream
{
public:
	CRTSPStream(void);
	~CRTSPStream(void);
public:
	// ��ʼ��
	bool Init();
    // ж��
	void Uninit();
	// ����H264�ļ�
	bool SendH264File(const char *pFileName);
	// ����H264����֡
    int SendH264Data(const unsigned char *data,unsigned int size);
};
