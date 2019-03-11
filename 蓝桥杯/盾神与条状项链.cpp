/*
��������
������һ�죬������˺ö�ö�������ɫ�����ӣ���������Щ������ôƯ������������һ��
	����Ȼ���͸������ǵ�Ů��~������������һЩ���������˳���Ϊn������������׼��������
	��β��ӵ�ʱ�����������ˡ�
����������ô���ĵ�������Ҳ���ó�����������
����������֪�����������ĳ����������ǫ��������������ô���ܰ���������Ư����
�����������~������Ҫ���������һ��������ɫ�����ӣ�Ȼ��������ȥ��������ӣ�Ȼ�󡭡���
	����㿴���ǲ���Ư���ܶ���~������һ����˵����m���޸Ĳ��衣
�����������������˹���̫�鷳�ˣ����ǽ������㡣
�����ʽ
������һ�����������ֱ�Ϊn��m��
�����ڶ���n��������ʾ����һ��ʼ����������i������ʾ��i�����ӵ���ɫ��
����������m�У�Ϊ������ʽ֮һ��
����ADD P Q����ʾ����ɫΪP������ǰ�����һ����ɫΪQ�����ӡ�
����DEL P����ʾ����ɫΪP������ȥ������������ڶ˵㴦������Ҫ�����Աߵ���������
	������������ĳʱ������״̬Ϊ1 4 5 8����ִ��DEL 4����1 5 8��ִ��DEL 1��
	���4 5 8��
�������뱣֤��ÿ�β���֮ǰ����������ɫΪP�����ӣ�������ʱ��������ɫ������ͬ��
�����ʽ
������һ��Ϊһ����len��Ϊ�������в����������ĳ��ȡ�
�����ڶ���len��������ʾ��ʱ������״̬����i������ʾ��i�����ӵ���ɫ��
��������
10 5
1 2 3 4 5 6 7 8 9 10
DEL 5
ADD 7 5
DEL 10
ADD 4 20
ADD 20 12
�������
11
1 2 3 12 20 4 6 5 7 8 9
���ݹ�ģ��Լ��
������ʾ��ɫ�����ֲ�����10^5��������1<=n<=10^4��1<=m<=10^4��
*/ 

#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct node
{
	int data;
	struct node * next;
}link;
link * create(int n)
{
	link * head, * s, * new_next;
	int i;	
	head=(link*)malloc(sizeof(link));
	s=head;
	for(i=0;i<n;i++)
	{
		new_next=(link*)malloc(sizeof(link));
		scanf("%d",&new_next->data);
		s->next=new_next;
		s=new_next;
	}
	s->next=NULL;
	return head;
}
void ADD(link * head,int P,int Q)
{
	link * s, * new_next;
	s=head->next;
	new_next=(link*)malloc(sizeof(link));
	new_next->data=Q;
	if(s->data==P)
	{
		new_next->next=s;
		head->next=new_next;
		return;
	}
	while(s->next->data!=P)
	{
		s=s->next;
	}	
	new_next->next=s->next;
	s->next=new_next;	
	return;
}
void DEL(link * head,int P)
{
	link * s;
	s=head->next;
	if(s->data==P)
	{
		head->next=s->next;
		return;
	}
	while(s->next->data!=P)
	{
		s=s->next;
	}
	s->next=s->next->next;
	return;
}
int main()
{
	int n,m,P,Q,len;
	link * head, * s1, * s2;
	char array[4];
	char a[4]="ADD";
	char d[4]="DEL";	
	scanf("%d%d",&n,&m);
	head=create(n);	
	for(int i=0;i<m;i++)
	{
		scanf("%s",array); 
		if(strcmp(array,a)==0)
		{
			scanf("%d%d",&P,&Q);
			ADD(head,P,Q);
		}		
		if(strcmp(array,d)==0)
		{
			scanf("%d",&P);
			DEL(head,P);
		}
		memset(array, 0, sizeof(array));
	}
	s2=s1=head->next;
	for(len=0;s1!=NULL;s1=s1->next)
	{
		len++;		
	}
	printf("%d\n",len);
	while(s2!=NULL)
	{
		printf("%d ",s2->data);
		s2=s2->next;
	}
	return 0;
}
