/* 
凑算式

     B      DEF
A + --- + ------- = 10
     C      GHI	 
	 
这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。

比如：
6+8/3+952/714 就是一种解法，
5+3/1+972/486 是另一种解法。

这个算式一共有多少种解法？

注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。
答案：29
*/ 
//解法一
#include<stdio.h>
bool fun(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
	int arr[10];
	arr[0]=a;
	arr[1]=b;
	arr[2]=c;
	arr[3]=d;
	arr[4]=e;
	arr[5]=f;
	arr[6]=g;
	arr[7]=h;
	arr[8]=i;
	for(int m=0;m<9;m++)
	{
		for(int n=m+1;n<9;n++)
		{
			if(arr[m]==arr[n])
			return false;
		}
	}
	return true;
}
int main()
{
	int count=0;
	for(int a=1;a<10;a++)
	{
		for(int b=1;b<10;b++)
		{
			for(int c=1;c<10;c++)
			{
				for(int d=1;d<10;d++)
				{
					for(int e=1;e<10;e++)
					{
						for(int f=1;f<10;f++)
						{
							for(int g=1;g<10;g++)
							{
								for(int h=1;h<10;h++)
								{
									for(int i=1;i<10;i++)
									{
										if(((a*c*(g*100+h*10+i)+b*(g*100+h*10+i)+c*(d*100+e*10+f))==10*c*(g*100+h*10+i))&&fun(a,b,c,d,e,f,g,h,i))
										{
											count++;
										}
									}									
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d  ",count);
 } 


//解法二
#include <stdio.h>
int num[9];//num[0],num[1],num[2],....,num[7],num[8];
int sta[9];//sta[0],sta[1],sta[2],....,sta[7],sta[8];
//sta的下标与下标对应的元素存在关系：
//如果数值(下标+1)被取过，则该下标对应的元素为1，否则为0
//num用来存储1~9，且没有重复元素
int flag=0;
int count=0;

bool Judge()
{
	int a=num[0],b=num[1],c=num[2],d=num[3],e=num[4],f=num[5],g=num[6],h=num[7],i=num[8];
	if((a*c*(g*100+h*10+i)+b*(g*100+h*10+i)+c*(d*100+e*10+f))==10*c*(g*100+h*10+i))
	{			
		return true;
	}
	return false;
}
void Fun(int m)//DFS,递归+回溯 
{
	if(m==9)
	{
		if(flag < 10)
		{
			for(int k=0;k < 9;k++)
			{
				printf("%d ",num[k]);				
			}	
			printf("\n");
			flag++;
		}
		
		if(Judge())
		{	 
			count++;
		}
	}
	for(int i=0;i<9;i++)
	{  
		if(0 == sta[i])
		{
			sta[i]=1;			//回溯法
			num[m]=i+1;
			Fun(m+1);
			sta[i]=0;
		}
	}
}
int main()
{
	for(int i=0;i<9;i++) sta[i]=0; 
	Fun(0);
	printf("%d ",count); 
}
