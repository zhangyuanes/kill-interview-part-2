#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define ListSize 100

 struct ListNode
{
 int data;
 struct ListNode *next; 
};


void Josephus(ListNode *head, int n, int m, int k)
{
 ListNode *p,*q;
 int i;
 p=head;
 /*���ҵ����Ϊk����*/
 for(i=1; i<k; i++)/*�ӵ�k���˿�ʼ����*/
  {
   q=p;
   p=p->next;
  }
 /*��ʱpָ���k�����*/
 
 while(p->next != p)/*������ж��Ƿ�ֻʣ��һ�����*/
  {
  /*�ҳ�����m����*/
   for(i=1; i<m; i++)/*����m���˳���*/
    {
     q=p;
     p=p->next;
    }
   /*��ʱpָ������m�Ľ��*/
   /*��ʱqָ�����m��ǰ����㣬pָ����ǵ�m�����*/
   
   q->next = p->next;/*�ⲽ���ǽ�m��ǰ�����ָ����ָ��
   m�ĺ�̽��*/
   printf("%4d",p->data);/*��ӡ�����е�����*/
   free(p);/*�ͷų��еĽ��ռ�*/
   p=q->next;/*ָ����һ����㣬���¿�ʼ����*/
  }
 printf("%4d\n", p->data);
 
}
 
/*//////////////////////////////////////////////////////////////////////////////
������:       CreateCycList
��������:   �궨��͵�������
��ڲ���: int n
���ڲ���: 
//////////////////////////////////////////////////////////////////////////////*/
ListNode *CreateCycList(int n)
{
 ListNode *head = NULL;
 ListNode *s, *r;
 int i;
 for(i = 1; i <= n; i ++ )
  {
   s = (ListNode *)malloc(sizeof(ListNode));
   s->data = i;
   s->next = NULL;
   if(head == NULL)
    head = s;
   else
    r->next = s;/*���ڵ�ָ����ָ����һ�����*/
   r = s;/*��ʱָ��ָ����һ�����*/
  }
 r->next = head;/*���һ������ָ����ָ��ͷ����γɻ�*/
 return head;/*����ͷ���ĵ�ַ*/
}
/*//////////////////////////////////////////////////////////////////////////////
������:       main()
��������:   ������
��ڲ���: 
���ڲ���: 
//////////////////////////////////////////////////////////////////////////////*/
void main()
{
 ListNode *h;
 int n,k,m;
 printf("���뻷���˵ĸ���n=");
 scanf("%d", & n);
 printf("���뿪ʼ���������k=");
 scanf("%d", & k);
 printf("����Ϊm���˳���m=");
 scanf("%d", & m);
 h=CreateCycList(n);
 Josephus(h, n, m, k);
 system("pause");
}