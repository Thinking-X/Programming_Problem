/* 
����ʽ

     B      DEF
A + --- + ------- = 10
     C      GHI	 
	 
�����ʽ��A~I����1~9�����֣���ͬ����ĸ����ͬ�����֡�

���磺
6+8/3+952/714 ����һ�ֽⷨ��
5+3/1+972/486 ����һ�ֽⷨ��

�����ʽһ���ж����ֽⷨ��

ע�⣺���ύӦ���Ǹ���������Ҫ��д�κζ�������ݻ�˵�������֡�
�𰸣�29
*/ 
//�ⷨһ
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


//�ⷨ��
#include <stdio.h>
int num[9];//num[0],num[1],num[2],....,num[7],num[8];
int sta[9];//sta[0],sta[1],sta[2],....,sta[7],sta[8];
//sta���±����±��Ӧ��Ԫ�ش��ڹ�ϵ��
//�����ֵ(�±�+1)��ȡ��������±��Ӧ��Ԫ��Ϊ1������Ϊ0
//num�����洢1~9����û���ظ�Ԫ��
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
void Fun(int m)//DFS,�ݹ�+���� 
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
			sta[i]=1;			//���ݷ�
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
