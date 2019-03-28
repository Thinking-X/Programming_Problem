#include<stdio.h>
int main()
{
	int a,b,i=0;
	int arr[100];
	printf("输入需要转换的数："); 
	scanf("%d",&a);
	printf("输入需要转换的进制：");
	scanf("%d",&b); 
	while(a != 0)
	{
		arr[i]=a%b;
		a=a/b;
		i++;
	}
	for(int j=i-1;j>=0;j--)
	{
		printf("%d",arr[j]);
	}
	return 0;
 } 
