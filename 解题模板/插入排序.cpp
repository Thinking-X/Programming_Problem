//��������
#include<stdio.h>
void InsertionSort(int a[],int N)
{
	int T;
	for(int i=1; i<N; i++)
	{
		if(a[i-1]>a[i])//���������ǰ��С�� 
		{
			T=a[i];		//��T��ʱ�����ߵ��� 
			int j;
			for(j=i-1; a[j]>T; j--)//T��ǰ�Ƚϣ�������С��Ϊֹ 
			{
				a[j+1]=a[j];//Tǰ���Ԫ�غ��� 
			}
			a[j+1]=T;//�Ͼ�forѭ������ʱ��a[j]<=T,����a[j+1]=T 
		}
	}
	return;
}
int main()
{
	int a[]={13,2,10,12,15,7,9};//7���� 
	InsertionSort(a,7);
	for(int i=0; i<7; i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
