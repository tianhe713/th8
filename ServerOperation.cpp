#include "ServerOperation.h"

#include <iostream>

using namespace std;

//构造函数
ServerOperation::ServerOperation(ServerInfo * info)
{
	//1. 参数检查
	if (NULL == info)
	{
		cout << "参数非法" << endl;
		return;
	}

	mInfo = new ServerInfo;
	if (NULL == mInfo)
	{
		cout << "new ServerInfo failed.." << endl;
		return;
	}
	memset(mInfo, 0, sizeof(ServerInfo));
	//拷贝数据
	memcpy(mInfo, info, sizeof(ServerInfo));

	mShm = new SecKeyShm(mInfo->shmKey, mInfo->maxNode);

	mServer = new TcpServer();

}

//析构函数
ServerOperation::~ServerOperation()
{
	delete mInfo;
	delete mShm;
	delete mServer;

	mInfo = NULL;
	mShm = NULL;
	mServer = NULL;
}

void ServerOperation::startWork()
{
}

int ServerOperation::secKeyAgree(RequestMsg * reqmsg, char ** outData, int & outLen)
{
	return 0;
}

int ServerOperation::secKeyCheck(RequestMsg * reqmsg, char ** outData, int & outLen)
{
	return 0;
}

int ServerOperation::secKeyRevoke(RequestMsg * reqmsg, char ** outData, int & outLen)
{
	return 0;
}

int ServerOperation::secKeyView(void)
{
	return 0;
}

//生成随机序列函数
void ServerOperation::getRandString(int len, char * randBuf)
{
	int tag = -1;

	//参数检查
	if (len <= 0 || NULL == randBuf)
	{
		cout << "参数非法" << endl;
		return;
	}

	//设置随机种子
	srandom(time(NULL));

	memset(randBuf, 0, len);
	for (int i = 0; i < len; i++)
	{
		//随机字符种类
		tag = random() % 4;

		switch (tag)
		{
			//大写字母
		case 0:
			randBuf[i] = 'A' + random() % 26;
			break;
			//小写字母
		case 1:
			randBuf[i] = 'a' + random() % 26;
 			break;
			//数字
		case 2:
			randBuf[i] = '0' + random() % 10;
			break;

			//特殊字符
		case 3:
			randBuf[i] = "~!@#$%^&*()_+"[random() % 13];
			break;
		}
	}
}
