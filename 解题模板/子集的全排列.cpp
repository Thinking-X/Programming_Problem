//��N������ѡ��m����(m<=N),����ȫ���У�����������
//���£�num��ʾN���������飬a��m���������飬��ʾÿ�����
//state�����¼num��ĳ��λ�õ�ѡ����� 
#include<stdio.h>
#define N 7
#define m 5 
int num[N]={1,2,3,4,5,6,7};
int state[N]={0};
int a[m];
int count=0;
void func(int index)
{
	if(index==m)
	{
		count++;
		for(int i=0;i<m;i++)
		{
			printf("%d  ",a[i]);
		}
		printf("-----%d\n",count);
		return;
	}
	for(int i=0;i<N;i++)
	{
		if(!state[i])
		{
			state[i]=1;
			a[index]=num[i];
			func(index+1);
			state[i]=0;
		}
	}
}
int main()
{
	func(0);
	printf("%d",count);
	return 0;
}
