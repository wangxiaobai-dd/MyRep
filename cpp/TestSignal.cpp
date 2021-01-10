#include <iostream>
#include <string>

#include <signal.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <execinfo.h>
#include <arpa/inet.h>

using namespace std;

static int count = 0;
jmp_buf env;

void dump()
{
	int* s = 0;
	(*s) = 1;
}
void printStack()
{
	int size = 16; 
	void * array[16];
	int stack_num = backtrace(array, size);
	char ** stacktrace = backtrace_symbols(array, stack_num);
	for (int i = 0; i < stack_num; ++i)
	{   
		cout << stacktrace[i] << std::endl;
	}   

	free(stacktrace);
}
//信号处理函数
void recvSignal(int sig)
{
	// 默认
	signal(SIGSEGV, SIG_DFL);
	count++;
	printf("received signal %d !!!, count:%d\n",sig, count);
	printStack();
	//longjmp(env,1);
	//dump();
} 

int main()
{
		int r = setjmp(env); // 进入信号处理函数后，阻塞信号
		if(r == 0)
		{
			signal(SIGSEGV, recvSignal);
			printf("dump");
			dump();
		}
		else
			printf("jump this code !!"); 

		return 0;

	while(1)
	{
		sleep(1);
		printf("sleep 1 \n");
	}
	return 0;
}

