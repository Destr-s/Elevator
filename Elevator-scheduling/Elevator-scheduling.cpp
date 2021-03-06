// Elevator-scheduling.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include"Elevator.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
int requestfloor;
int waitfloor;
int requesttime;
int currentfloor = 0;
int time = 0;
struct asking
{
	int requesttime;
	int waitfloor;
	int requestfloor;
	int direction;
}ask[1000];//记录所有的请求
Elevator ele;
int main()
{
	FILE *stream1, *stream2;
	fopen_s(&stream1, "input.txt", "r");
	fopen_s(&stream2, "output.txt", "w");
	int n,judge=0;
	fscanf_s(stream1, "%d", &n);
	for (int i = 1; i <=n; i++)
	{
		fscanf_s(stream1, "%d", &ask[i].requesttime);
		fscanf_s(stream1, "%d", &ask[i].waitfloor);
		fscanf_s(stream1, "%d", &ask[i].requestfloor);
		if (ask[i].requestfloor - ask[i].waitfloor > 0)ask[i].direction = 0;
		else ask[i].direction = 1;
	}//输入所有请求
	for (int i = 1; i <= n; i++)
	{
		requesttime = ask[i].requesttime;
		waitfloor = ask[i].waitfloor;
		requestfloor = ask[i].requestfloor;
		if (ask[i-1].requestfloor == ask[i].waitfloor)judge = 1;
		else judge = 0;
		if (judge == 0)
		{
			fprintf(stream2, "%d %d\n", time + abs(ask[i - 1].requestfloor - waitfloor), waitfloor);
			time++;
		}//判断进入电梯和送乘客出电梯的层数是否相等，并进行相应的输出判断
		time=ele.gotofloor(requesttime,requestfloor,time,waitfloor,ask[i-1].requestfloor);
		fprintf(stream2, "%d %d\n", time, requestfloor);
		time=ele.stop(time,requestfloor);
	}
	fclose(stream1);
	fclose(stream2);
    return 0;
}