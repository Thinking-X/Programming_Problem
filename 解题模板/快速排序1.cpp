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
void quickSort(int array[], int head, int tail)//head=>���еĿ�ͷ //tail=>���еĽ�β 
{	
	//if (head > tail) 
	//{ return; } 
	 
	int i=head; 
	int j=tail; 		//i,jָ��ͷ��β
	int iPivot=array[i];//ѡȡ����
 	while (i<j) 
 	{ 	
	 	//ʹ��j,���������Ҷ˿�ʼɨ��,ֱ������������С���� 
 		while ((i<j) && (iPivot <= array[j])) 
 		{ j--; } //����λ�� 
 		if (i<j) 
		{ array[i++]=array[j]; } 
 		//ʹ��i,����������˿�ʼɨ��,ֱ���������������� 
  		while ((i<j) && (array[i] <= iPivot)) 
  		{ i++; } //����λ�� 
  		if (i<j) 
  		{ array[j--]=array[i]; } 
	} 
  	array[j]=iPivot; //�����������λ�� 
  	Ergodic(array);
  	if(head<i-1)quickSort(array, head, i-1); //�������������н�������ĵݹ���� 
	if(i+1<tail)quickSort(array, i+1, tail); 
}
int main()
{
	int array[]={-6,8,2,7,0,1,-3,5,10};// 9���� 
	quickSort(array, 0, 8);
	for(int n=0;n<9;n++)
	{
		printf("%d  ",array[n]);
	}
	return 0; 
}
