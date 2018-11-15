/*
问题描述
　　编写一个程序，读入一组整数，这组整数是按照从小到大的顺序排列的，它们的个数N也是
	由用户输入的，最多不会超过20。然后程序将对这个数组进行统计，把出现次数最多的那个
	数组元素值打印出来。如果有两个元素值出现的次数相同，即并列第一，那么只打印比较小
	的那个值。
	
输入格式：第一行是一个整数N(N <= 20)；接下来有N行，每一行表示一个整数，并且按照从小
	到大的顺序排列。
输出格式：输出只有一行，即出现次数最多的那个元素值。
输入输出样例
样例输入
5
100
150
150
200
250
样例输出
150
*/ 
#include<iostream>
#include<Vector>
using namespace std;
int main()
{
	int N,n_temp;
	cin >> N;
	if (N > 0 && N <= 20)
	{
		n_temp = N;
		vector<int>a = vector<int>();
		vector<int>b = vector<int>();
		int Count = 0;
		while (n_temp > 0)
		{
			int temp;
			cin >> temp;
			if (n_temp == N)
			{
				b.push_back(temp);
			}
			if (temp == b[b.size() - 1])
			{
				Count++;
			}
			else
			{
				a.push_back(Count);
				b.push_back(temp);
				Count = 1;
			}
			n_temp--;
		}
		a.push_back(Count);
		int flag_a = 0, flag_b;
		int most_Index = 0;
		for (int i = 0; i < b.size(); i++)
		{
			if (a[i] > flag_a)
			{
				flag_a = a[i];
				most_Index = i;
			}
		}
		cout << b[most_Index] << endl;
	}
	getchar();
	getchar();
    return 0;
}
