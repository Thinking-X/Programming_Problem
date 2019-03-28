#include<stdio.h>
void Ergodic(int a[])
{
	for(int i=0;i<9;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return;
} 
void quickSort(int array[], int head, int tail)//head=>序列的开头 //tail=>序列的结尾 
{	
	//if (head > tail) 
	//{ return; } 
	 
	int i=head; 
	int j=tail; 		//i,j指向头和尾
	int iPivot=array[i];//选取枢轴
 	while (i<j) 
 	{ 	
	 	//使用j,从序列最右端开始扫描,直到遇到比枢轴小的数 
 		while ((i<j) && (iPivot <= array[j])) 
 		{ j--; } //交换位置 
 		if (i<j) 
		{ array[i++]=array[j]; } 
 		//使用i,从序列最左端开始扫描,直到遇到比枢轴大的数 
  		while ((i<j) && (array[i] <= iPivot)) 
  		{ i++; } //交换位置 
  		if (i<j) 
  		{ array[j--]=array[i]; } 
	} 
  	array[j]=iPivot; //最后填入枢轴位置 
  	Ergodic(array);
  	if(head<i-1)quickSort(array, head, i-1); //对枢轴两边序列进行排序的递归调用 
	if(i+1<tail)quickSort(array, i+1, tail); 
}
int main()
{
	int array[]={-6,8,2,7,0,1,-3,5,10};// 9个数 
	quickSort(array, 0, 8);
	for(int n=0;n<9;n++)
	{
		printf("%d  ",array[n]);
	}
	return 0; 
}
