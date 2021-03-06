// main.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include"elevator.h"
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct eleask
{
	int requesttime;
	int waitfloor;
	int requestfloor;
}ask[10000];//记录乘客的所有请求
elevator ele[3];//定义三个电梯
int main(int argc,char *argv[])
{
	FILE *stream1, *stream2, *stream3, *stream4;
	if (argc < 2)
	{
		cout << "输入数量过少" << endl;
		return 0;
	}
	else if (argc > 2 && argc < 5)
	{
		cout << "输入数量与本题不符" << endl;
		return 0;
	}
	else if (argc > 5)
	{
		cout << "输入数量过多" << endl;
		return 0;
	}
	else if (argc == 2)
	{
		if (strstr(argv[0], "Elevator") == NULL || strstr(argv[1], "input") == NULL)
		{
			cout << "输入格式有误" << endl;
			return 0;
		}
	}
	else if (argc == 5)
	{
		if (strstr(argv[0], "Elevator") == NULL || strstr(argv[1], "input") == NULL || strstr(argv[2], "output1") == NULL || strstr(argv[3], "output2") == NULL || strstr(argv[4], "output3") == NULL)
		{
			cout << "输入格式有误" << endl;
			return 0;
		}
	}
	
		fopen_s(&stream1, "input.txt", "r");
		fopen_s(&stream2, "output1.txt", "w");
		fopen_s(&stream3, "output2.txt", "w");
		fopen_s(&stream4, "output3.txt", "w");//文件读写打开方式
		int n, i;
	fscanf_s(stream1, "%d", &n);
	for (i = 1; i <= n; i++)
	{
		fscanf_s(stream1, "%d %d %d", &ask[i].requesttime, &ask[i].waitfloor, &ask[i].requestfloor);
	}//输入所有请求
	for (i = 1; i <= n; i++)
	{
		if (ask[i].requestfloor % 2 == 0||ask[i].requestfloor==1)
		{
			if (ask[i].requesttime > ele[2].gettime())
			{
				ele[2].settime(ask[i].requesttime+abs(ele[2].getcurrentfloor()-ask[i].waitfloor));
				ele[2].setcurrentfloor(ask[i].waitfloor);
				fprintf(stream4, "%d %d\n", ele[2].gettime(), ele[2].getcurrentfloor());
				ele[2].settime(ele[2].gettime() + abs(ask[i].requestfloor - ask[i].waitfloor));
				ele[2].setcurrentfloor(ask[i].requestfloor);
				fprintf(stream4, "%d %d\n", ele[2].gettime(), ele[2].getcurrentfloor());
			}//对偶数请求进行处理
			else
			{
				ele[1].settime(ele[1].gettime() + abs(ele[1].getcurrentfloor() - ask[i].waitfloor));
				ele[1].setcurrentfloor(ask[i].waitfloor);
				fprintf(stream3, "%d %d\n", ele[1].gettime(), ele[1].getcurrentfloor());
				ele[1].settime(ele[1].gettime() + abs(ask[i].requestfloor - ask[i].waitfloor));
				ele[1].setcurrentfloor(ask[i].requestfloor);
				fprintf(stream3, "%d %d\n", ele[1].gettime(), ele[1].getcurrentfloor());
			}
		}
		else if (ask[i].requestfloor % 2 == 1)
		{
			if (ask[i].requesttime > ele[2].gettime())
			{
				ele[0].settime(ask[i].requesttime + abs(ele[0].getcurrentfloor() - ask[i].waitfloor));
				ele[0].setcurrentfloor(ask[i].waitfloor);
				fprintf(stream2, "%d %d\n", ele[0].gettime(), ele[0].getcurrentfloor());
				ele[0].settime(ele[0].gettime() + abs(ask[i].requestfloor - ask[i].waitfloor));
				ele[0].setcurrentfloor(ask[i].requestfloor);
				fprintf(stream2, "%d %d\n", ele[0].gettime(), ele[0].getcurrentfloor());
			}//对奇数请求进行处理
			else
			{
				ele[1].settime(ele[1].gettime() + abs(ele[1].getcurrentfloor() - ask[i].waitfloor));
				ele[1].setcurrentfloor(ask[i].waitfloor);
				fprintf(stream3, "%d %d\n", ele[1].gettime(), ele[1].getcurrentfloor());
				ele[1].settime(ele[1].gettime() + abs(ask[i].requestfloor - ask[i].waitfloor));
				ele[1].setcurrentfloor(ask[i].requestfloor);
				fprintf(stream3, "%d %d\n", ele[1].gettime(), ele[1].getcurrentfloor());
			}
		}
	}
	fclose(stream1);
	fclose(stream2);
	fclose(stream3);
	fclose(stream4);//关闭文件
	return 0;
}

