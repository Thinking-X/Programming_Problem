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
void quicksort(int r[],int low,int high) 	/*递归排序*/
{	
    /*对顺序表r中的序列r[low…high]作快速排序*/
    int i=low,j=high;
    r[0]=r[low];               /*以子表的第一个记录作为基准记录*/
	while(i<j) 	              /*从表的两端交替地向中间扫描*/
	{
		while(i<j && r[j]>=r[0]) j--;
		if(i<j){ r[i++]=r[j]; }           /*将比基准点记录小的交换到前面*/
		while(i<j && r[i]<=r[0]) i++;
		if(i<j){ r[j--]=r[i]; }           /*将比基准点记录大的交换到后面*/
	}
	r[i]=r[0];
	Ergodic(r);
	if(low<i-1)quicksort(r,low,i-1);    /*对基准之前的子表递归排序*/
	if(i+1<high)quicksort(r,i+1,high);   /*对基准之后的子表递归排序*/
}

int main()
{
	int a[]={00,-6,8,2,7,0,1,-3,5,10};// 一共10个数，但第一个不参与排序 
	quicksort(a,1,9);
	for(int i=1; i<10; i++)
	{
		printf("%d  ",a[i]); 
	}
	return 0;
} 
