/*
������ҵ

����Сѧ����ѧ��ĿҲ������ô����ġ�
�������������ҵ��

   �� + �� = ��
   �� - �� = ��
   �� �� �� = ��
   �� �� �� = ��
   
ÿ���������1~13�е�ĳһ�����֣��������ظ���
���磺
 6  + 7 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

�Լ��� 
 7  + 6 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

�������ֽⷨ�����ӷ����˷������ɺ��㲻ͬ�ķ�����
 
��һ���ҵ��˶����ַ�����


����д��ʾ������Ŀ��������
ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�

�𰸣�64
*/ 

//ֱ���㷨 
#include <stdio.h>
#define _MAX 13

int ans = 0;
int num[_MAX] = {0};
int visited[_MAX] = {0};
bool test(int t[])
{
	bool s1=(t[0]+t[1]==t[2]);
	bool s2=(t[3]+t[4]==t[5]);
	bool s3=(t[6]*t[7]==t[8]);
	bool s4=(t[9]*t[10]==t[11]);
	if(s1&&s2&&s3&&s4)
	{
		return true;
	}
	return false;
}
void dfs(int n)
{
	if(n==13)
	{
		if (test(num))   //��������Ϲ������������֧
	    {
	        for(int i=0;i<12;i++)
	        {
	        	printf("%d  ",num[i]);
			}
			ans++;
			printf("-----%d\n",ans);
	        
	    }
	}	
    for (int i = 0; i < _MAX; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            num[n] = i + 1;
            
            dfs(n + 1);
            visited[i] = 0;
        }
    }
    return ;
}
int main(int argc, const char * argv[])
{
    dfs(0);
    printf("%d\n", ans);
    return 0;
}

 
//�Ż��㷨
#include<stdio.h>
#define N 13
int num[N];
int state[N]={0};
int count=0;
bool test(int n)
{
	//��n==2,5,8,11����������ʽʱ �� n!=2,5,8,11ʱ��return true
	//�������return false����n==2,5,8,11���Ҳ�������ʽʱ 
	if (n == 2)
    {
        if (num[0] + num[1] == num[2])
        {
            return true;
        }
    }
    else if (n == 5)
    {
        if (num[3] + num[4] == num[5])
        {
            return true;
        }
    }
    else if (n == 8)
    {
        if (num[6] * num[7] == num[8])
        {
            return true;
        }
    }
    else if (n == 11)
    {
        if (num[9] * num[10] == num[11])
        {
			count++;
        	for(int i=0;i<12;i++)
	        {
	        	printf("%d  ",num[i]);
			}			
			printf("-----%d\n",count);          
            return true;
        }
    }
    else
    {
        return true;
    }
    return false;
 } 
void func(int index)
{	
	for(int i=0;i<N;i++)
	{
		if(!state[i])
		{
			state[i]=1;
			num[index]=i+1;
			if(!test(index))//��������Ϲ������������֧
			{
				state[i]=0;
				continue;
			}
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

