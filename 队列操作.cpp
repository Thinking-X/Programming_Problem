/*
��������
������������Ĳ�������������У�
	��1����ӡ���2�����Ӳ��������3���������Ԫ�ظ����������
�����ʽ
������һ��һ������N��
��������N�У�ÿ�е�һ������Ϊ�������
	��1����ӡ���2�����Ӳ��������3���������Ԫ�ظ����������
�����ʽ
����������ÿ����ʾһ��2��3�������������
	ע�⣺2.����������ܻ���ֿնӳ��ӣ����磩���������no�������˳���
��������
7
1 19
1 56
2
3
2
3
2
�������
19
1
56
0
no
���ݹ�ģ��Լ��
����1<=N<=50
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
