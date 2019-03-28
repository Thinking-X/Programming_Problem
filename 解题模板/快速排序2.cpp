#include<stdio.h>
void Ergodic(int a[])
{
	for(int i=1;i<10;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return;
} 
void quicksort(int r[],int low,int high) 	/*�ݹ�����*/
{	
    /*��˳���r�е�����r[low��high]����������*/
    int i=low,j=high;
    r[0]=r[low];               /*���ӱ�ĵ�һ����¼��Ϊ��׼��¼*/
	while(i<j) 	              /*�ӱ�����˽�������м�ɨ��*/
	{
		while(i<j && r[j]>=r[0]) j--;
		if(i<j){ r[i++]=r[j]; }           /*���Ȼ�׼���¼С�Ľ�����ǰ��*/
		while(i<j && r[i]<=r[0]) i++;
		if(i<j){ r[j--]=r[i]; }           /*���Ȼ�׼���¼��Ľ���������*/
	}
	r[i]=r[0];
	Ergodic(r);
	if(low<i-1)quicksort(r,low,i-1);    /*�Ի�׼֮ǰ���ӱ�ݹ�����*/
	if(i+1<high)quicksort(r,i+1,high);   /*�Ի�׼֮����ӱ�ݹ�����*/
}

int main()
{
	int a[]={00,-6,8,2,7,0,1,-3,5,10};// һ��10����������һ������������ 
	quicksort(a,1,9);
	for(int i=1; i<10; i++)
	{
		printf("%d  ",a[i]); 
	}
	return 0;
} 
