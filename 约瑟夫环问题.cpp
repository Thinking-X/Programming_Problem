/*
���б��Ϊ1��2��������n��n(n>0)����Χ��һ��Ȧ���ӵ�1���˿�ʼ����������mʱֹͣ������
��m���˳�Ȧ���ٴ�������һ���������±���������mʱֹͣ��������m�ĳ�Ȧ�������������ȥ��
ֱ��������ȫ����ȦΪֹ�����������n��m������㷨��n���˳�Ȧ�Ĵ���

����������n���ˣ����1~n)����1��ʼ����������m���˳���ʣ�µ��˼�����1��ʼ������ 
��ʤ���ߵı�š�
*/ 
#include<stdio.h>
#include<malloc.h> 
typedef struct Node
{
	int data;
	struct Node* next;
}LNode;
void Ergodic(LNode* L)
{
	LNode* p = L;
	printf("%d  ",p->data);
	p=p->next;
	while(p != L)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");
	return;
}
LNode* Create_Link()//����һ����ͷ�ڵ�ĵ���ѭ������ 
{
	int n; 
	LNode *L, *New, *p;
	printf("���뻷�ĳ��ȣ�\n");
	scanf("%d",&n);	
	p=L=(LNode*)malloc(sizeof(LNode));	
	p->data=1;
	for(int i=2;i<=n;i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		New->data=i;
		p->next=New;
		p=New;
	}
	p->next=L;
	return L;
}
void Algorithm(LNode* L)
{
	int m;
	LNode* p;
	printf("�����޳��ĺ��룺\n"); 
	scanf("%d",&m);
	for(int i=1; L->next != L; i++)
	{
		if((i+1)%m == 0)//����Ҫɾ������һ���ڵ�ִ��
		{			
			p=L->next;
			L->next=p->next;
			free(p);					
		}
		else
		{
			L=L->next;
		}
	}
	p=NULL;
	/*�ڶ��ַ��� 
	int i=0;
	while(L->next != L)
	{
		i++;
		if(m-1 == i)
		{
			L->next=L->next->next;
			i=0;
		}
		L=L->next;
	}	
	*/
	printf("�Ҵ��ߣ�\n%d",L->data);
	return;
}
int main()
{
	LNode *L;
	L=Create_Link();
	Ergodic(L);
	Algorithm(L);
	return 0; 
}
