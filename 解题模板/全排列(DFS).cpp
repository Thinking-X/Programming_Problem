/* 
//对1-N全排列(DFS，递归+回溯)
//例如占座问题：N个人做N个座位,输出每一种情况 
#include<stdio.h>
#define N 5
int arr[N];
int state[N];
int count=0;
void func(int index)
{
	if(index == N)
	{
		for(int k=0;k<N;k++)
		{
			printf("%d  ",arr[k]);
		}		
		count++;
		printf("-----%d\n",count);
	}
	for(int i=0;i<N;i++)
	{
		if(state[i]==0)
		{
			state[i]=1;
			arr[index]=i+1;
			func(index+1);
			state[i]=0;
		}
	 } 
}
int main()
{
	for(int i=0;i<N;i++)state[i]=0;
	func(0);
	printf("%d",count); 
} 
*/ 
//对某些数全排列 
//如下，b数组是待排列的数组，a数组是用来存放每一种排列的情况
//state数组与b数组一一对应，存放b数组中每个元素的选中状态 
#include<stdio.h>
#define N 6 
int count=0;
int a[N];
int b[N]={6,7,13,1,8,9};
int state[N];
void f(int index)
{
	if(index==N)
	{
		for(int i=0;i<N;i++)
		{
			printf("%d  ",a[i]); 
		}
		count++;	
		printf("-----%d\n",count);	
	}
	for(int i=0;i<N;i++)
	{
		if(state[i]==0)
		{
			state[i]=1;
			a[index]=b[i];
			f(index+1);
			state[i]=0;
		}
	}
}
int main()
{
	for(int i=0;i<N;i++)state[i]=0;
	f(0);
	printf("%d",count);
}
