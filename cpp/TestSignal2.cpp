#include <iostream>
#include <string>

#include <signal.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

static int count = 0;
jmp_buf env;

void dump()
{
	int* s = 0;
	(*s) = 1;
}
//信号处理函数
void recvSignal(int sig)
{
	// 默认
	signal(SIGSEGV, SIG_DFL);
	count++;
	printf("received signal %d !!!, count:%d\n",sig, count);
	siglongjmp(env,1);
	//dump();
} 

int main()
{
	for(int i = 0; i < 2; ++i)
	{
		int r = sigsetjmp(env, 1); // 进入信号处理函数后，阻塞信号
		if(r == 0)
		{
			signal(SIGSEGV, recvSignal);
			printf("dump");
			dump();
		}
		else
			printf("jump this code !!"); 

	}

	while(1)
	{
		sleep(1);
		printf("sleep 1 \n");
	}
	return 0;
}

