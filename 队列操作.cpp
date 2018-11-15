/*
问题描述
　　根据输入的操作命令，操作队列：
	（1）入队、（2）出队并输出、（3）计算队中元素个数并输出。
输入格式
　　第一行一个数字N。
　　下面N行，每行第一个数字为操作命令：
	（1）入队、（2）出队并输出、（3）计算队中元素个数并输出。
输出格式
　　若干行每行显示一个2或3命令的输出结果。
	注意：2.出队命令可能会出现空队出队（下溢），请输出“no”，并退出。
样例输入
7
1 19
1 56
2
3
2
3
2
样例输出
19
1
56
0
no
数据规模和约定
　　1<=N<=50
*/ 
#include<iostream>
#include<Queue>
using namespace std;
int main()
{
	int N = 0;
	cin >> N;
	queue<int> a = queue<int>();
	int temp1,temp2;
	while (N > 0)
	{
		cin >> temp1;
		if (temp1 == 1)
		{
			cin >> temp2;
			a.push(temp2);
		}
		else if (temp1 == 2)
		{
			if (a.size() == 0)
			{
				cout << "no" << endl;
				return 0;
			}
			else
			{
				cout << a.front() << endl;
				a.pop();
			}
		}
		else
		{
			cout << a.size() << endl;
		}
		N--;
	}
	getchar();
	getchar();
    return 0;
}
