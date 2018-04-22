// Elevator-scheduling.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Elevator.h"
#include<iostream>
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
}ask[1000];
Elevator ele;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		cin >> ask[i].requesttime >> ask[i].waitfloor >> ask[i].requestfloor;
		if (ask[i].requestfloor - ask[i].waitfloor > 0)ask[i].direction = 0;
		else ask[i].direction = 1;
	}
	//fun(n);
	cout << ask[1].waitfloor << " " << ask[1].waitfloor << endl;
	time++;
	for (int i = 1; i <= n; i++)
	{
		requesttime = ask[i].requesttime;
		waitfloor = ask[i].waitfloor;
		requestfloor = ask[i].requestfloor;
		time=ele.gotofloor(requesttime,requestfloor,time,waitfloor,ask[i-1].requestfloor);
		time=ele.stop(time,requestfloor);
	}
    return 0;
}