/*
��������
������дһ�����򣬶���һ�����������������ǰ��մ�С�����˳�����еģ����ǵĸ���NҲ��
	���û�����ģ���಻�ᳬ��20��Ȼ����򽫶�����������ͳ�ƣ��ѳ��ִ��������Ǹ�
	����Ԫ��ֵ��ӡ���������������Ԫ��ֵ���ֵĴ�����ͬ�������е�һ����ôֻ��ӡ�Ƚ�С
	���Ǹ�ֵ��
	
�����ʽ����һ����һ������N(N <= 20)����������N�У�ÿһ�б�ʾһ�����������Ұ��մ�С
	�����˳�����С�
�����ʽ�����ֻ��һ�У������ִ��������Ǹ�Ԫ��ֵ��
�����������
��������
5
100
150
150
200
250
�������
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
