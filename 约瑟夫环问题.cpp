/*
设有编号为1，2，……，n的n(n>0)个人围成一个圈，从第1个人开始报数，报到m时停止报数，
报m的人出圈，再从他的下一个人起重新报数，报到m时停止报数，报m的出圈，……，如此下去，
直到所有人全部出圈为止。当任意给定n和m后，设计算法求n个人出圈的次序。

问题描述：n个人（编号1~n)，从1开始报数，报到m的退出，剩下的人继续从1开始报数。 
求胜利者的编号。
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
LNode* Create_Link()//生成一个无头节点的单向循环链表 
{
	int n; 
	LNode *L, *New, *p;
	printf("输入环的长度：\n");
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
	printf("输入剔除的号码：\n"); 
	scanf("%d",&m);
	for(int i=1; L->next != L; i++)
	{
		if((i+1)%m == 0)//在需要删除的上一个节点执行
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
	/*第二种方法 
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
	printf("幸存者：\n%d",L->data);
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
