#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class MyData  
{  
public:  
    MyData() : data(0), next(NULL){}      //Ĭ�Ϲ��캯��  
    MyData(int value) : data(value), next(NULL){}  //�������Ĺ��캯��  
    int data;               //������  
    MyData *next;           //��һ���ڵ�  
};  
  
class MyStack  
{  
public:  
    MyStack() : top(NULL) {}    //Ĭ�Ϲ��캯��  
    void push(MyData data);     //��ջ  
    void pop(MyData *pData);    //��ջ  
    bool IsEmpty();             //�Ƿ�Ϊ��  
    MyData *top;                //ջ��  
};  

void MyStack::push(MyData data)  
{  
    MyData *pData = NULL;  
    pData = new MyData(data.data);  //�����½ڵ�  
    pData->next = top;               //��ԭ����ջ���ڵ�����  
    top = pData;                    //ջ���ڵ�Ϊ�¼���Ľڵ�  
}  
  
void MyStack::pop(MyData *data)  
{  
    if(IsEmpty())               //�п�  
    {  
        return;  
    }  
    data->data = top->data;  
	//�������Ĳ�����ֵ  
    MyData *p = top;            //��ʱ����ԭջ���ڵ�  
    top = top->next;         //�ƶ�ջ����ָ����һ���ڵ�  
    delete p;                   //�ͷ�ԭջ���ڵ��ڴ�  
}  
  
bool MyStack::IsEmpty()  
{  
    return (NULL == top);    //���topΪ�շ���1�����򷵻�0  
}  
void main()
{
	MyData data(0);  
    MyStack s;  
    s.push(MyData(1));  //��ջ  
    s.push(MyData(2));  
    s.push(MyData(3));  
  
    s.pop(&data);       //��ջ  
    cout<<"pop "<<data.data<<endl;  
    s.pop(&data);  
    cout<<"pop "<<data.data<<endl;  
    s.pop(&data);  
    cout<<"pop "<<data.data<<endl;  
    cout<<"Empty = "<<s.IsEmpty()<<endl;  
 system("pause");
}