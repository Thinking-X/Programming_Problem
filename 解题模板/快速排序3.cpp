#include <stdio.h>

void Ergodic(int a[])
{
	for(int i=0;i<9;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return;
} 

void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
	return; 
}

int partition(int a[], int p, int r)
{
    int i = p;
    int j = r + 1;
    int x = a[p];
    while(1)
	{
        while(i<r && a[++i]<x);
        while(a[--j]>x);
        if(i>=j) break;
        swap(a,i,j);
    }
	swap(a,p,j);//a[p]=a[j];a[j]=x;	
	Ergodic(a);
    return j;
}

void quicksort(int a[], int p, int r)
{
    if(p<r)
	{
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
    
int main()
{	
	int a[] = {-6,8,2,7,0,1,-3,5,10};//9¸öÊý	
	quicksort(a, 0, 8);	
	for(int i=0; i<9; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");	
	return 0;
}
