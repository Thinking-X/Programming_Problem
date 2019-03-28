#include <stdio.h>
int f(int k,int n)
{
	if(k==0||k==n) return 1;
	return f(k,n-1)+f(k-1,n-1);
}
int main() 
{	
	int n,k;
	scanf("%d%d",&k,&n);
	printf("%d",f(k,n));
	return 0;
}
