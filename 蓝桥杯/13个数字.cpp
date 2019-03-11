/*
寒假作业

现在小学的数学题目也不是那么好玩的。
看看这个寒假作业：

   □ + □ = □
   □ - □ = □
   □ × □ = □
   □ ÷ □ = □
   
每个方块代表1~13中的某一个数字，但不能重复。
比如：
 6  + 7 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

以及： 
 7  + 6 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

就算两种解法。（加法，乘法交换律后算不同的方案）
 
你一共找到了多少种方案？


请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

答案：64
*/ 

//直接算法 
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
		if (test(num))   //如果不符合规则，则撤销这个分支
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

 
//优化算法
#include<stdio.h>
#define N 13
int num[N];
int state[N]={0};
int count=0;
bool test(int n)
{
	//当n==2,5,8,11并且满足表达式时 或 n!=2,5,8,11时，return true
	//其他情况return false，即n==2,5,8,11并且不满足表达式时 
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
			if(!test(index))//如果不符合规则，则撤销这个分支
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

