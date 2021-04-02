#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<string>
using namespace std;

 struct DNode
 {
	/* char *name;*/
	 char name[20];
	 struct DNode *pre;
	 struct DNode *next;
 };
 DNode *create(int n)
 {
	 DNode *head,*p,*s;
	 int i;
	 head = (DNode *)malloc(sizeof(DNode));
	 head->name[0] = '\0';
	 head->pre = NULL;
	 head->next = NULL;
	 p = head;
	 for(i = 1;i<=n;i++)
	 {
		 s = (DNode *)malloc(sizeof(DNode));
		 p->next = s;
		 cout<<"�������"<<i<<"�����֣�";
	/*	 char *str=" ";
		 cin>>str;
		 s->name =str;*/
		 scanf("%s",s->name);
		 s->pre = p;
		 s->next = NULL;
		 p =s;
	 }
	 p->next = NULL;
	 return head;
 }
 void print(DNode *head)
 {
	 DNode *p =head->next;
	 while(p != NULL)
	 {
		 cout<<p->name<<"  ";
		 p = p->next;
	 }
	 cout<<endl;
 }
 DNode *search(DNode *head,char *sest)
 {
	 DNode *p =head->next;
	 char *temp ;
	 while(p !=NULL)
	 {
		 temp = p->name;
		 if(strcmp(temp,sest) ==0)
		 {
			 cout<<"�ҵ���"<<p->name<<endl;
			 /*break ;*/

			 return p;
		 } else
		 {
			 p = p->next;
		 }
	 }
	 if(p == NULL)
	 {
	cout<<"û���ҵ�"<<endl;
	 }
 }
 void mydelete(DNode *point )
 {
	 if(point->next == NULL)
	 {
		 point->pre->next = NULL;
		 free(point);
	 }else
	 {
		 point->next->pre = point->pre;
		 point->pre->next = point->next;
		 free(point);
	 }
 }
int  main()
{
	int number;
	cout<<"������˫����ĳ��ȣ�";
	cin>>number;
	DNode *head ;
	DNode *sp ;
	head = create(number);
	cout<<endl;
	cout<<"��������˫����Ϊ��";
	print(head);
	cout<<"������Ҫ�ҵ����֣�";
	char myname[10];
	scanf("%s",myname);
	sp = search(head,myname);
	mydelete(sp);
	print(head);
	system("pause");
	
}