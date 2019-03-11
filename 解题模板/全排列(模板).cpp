#include<iostream>
#include<algorithm>
using namespace std;
//int a[]={1,2,3,4,5};//1 
int a[]={5,4,3,2,1};//2
int main()
{
	int res=0;
	do
	{
		for(int i=0;i<5;i++)
		{
			printf("%d  ",a[i]);
		}
		res++;
		printf("-----%d\n",res);
	}while(prev_permutation(a,a+5));//2
	//while(next_permutation(a,a+5));//1
	printf("%d",res);
	return 0;
}
