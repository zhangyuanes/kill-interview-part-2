#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
//��ͨ����
char *reverse(char *str)
{
	//��qָ���ַ������һ���ַ�
	char *p = str;
	while(*p++);
	p=p-2;
	 //����ռ䣬�洢�������ַ�����
	char *q = new char[sizeof(char) * (p-str+2)];
	char *r=q;
	// ����洢
	while(p>=str)
	{
		*q++=*p--;
	}
	*q='\0';//û�н�����ʶ���Ļ������ӡ��������
	return r;
}
//ԭ������
char *reverse2(char *str)
{
	char *p = str;
	char *q =str;
	while(*q)
	{
		++q;
	}
	q--;

	while(q>p)
	{
		/*char t;
		 t = *p;
		*p = *q;
		*q = t;
		p++;
		q--;*/

		/* char t = *p ;
        *p++ = *q ;
        *q-- = t ;*/

		swap(*p++,*q--);
	}
	return str;
}
//�ǵݹ�����
char *reverse3(char *str,int left,int right)
{
	if(left >= right)
	{
		return str;
	}
	char t;
	t = str[left];
	str[left++] = str[right];
	str[right--] = t;
	return str;

}
//�ݹ�����
char *reverse4(char *str,int left,int right)
{
	if(left >= right)
	{
		return str;
	}
	char t;
	t = str[left];
	str[left] = str[right];
	str[right] = t;
	reverse4(str,left++,right--);

}
// �����Ӱ���������
char* ReverseSentence(char *s)
{
    // ������ָ������ȷ��һ�����ʵ���β�߽�
    char *start = s ;    // ָ�򵥴ʵ����ַ�
    char *end = s ;    // ָ��ո���� '\0'
	char *ptr =s;
    while(*ptr++ != '\0')
    {
        if (*ptr == ' '||*ptr =='\0')//���һ������Ϊ��\0��
        {
			end = ptr-1;
			while(start < end)
            {
				swap(*start++, *end--) ;
			}
            start = end = ptr+1 ; // ָ����һ���������ַ�
        }
       
    }
	//end = ptr-1;
 //   swap(*start++, *end--) ; // �����һ����������
	start = s; end = ptr -2;
	while(start < end)
    {
		swap(*start++, *end--) ; // ��������������
	}
    return s ;
}
//
void reversepart(char *str,int num)
{
	char *start =str;//ͷָ��

	char *end2 =str;
	while(*end2++);
	end2 = end2 -2;//βָ��


	char *end1 =start+num-1;
	char *start2 =start+num;
	char *end3 = end2;
	while(start < end1)
	swap(*start++,*end1--);//ǰ��ν���

	while(start2 < end3)
	swap(*start2++,*end3--);//���ν���
	
	start = str;
	while(start < end2)
	swap(*start++,*end2--);//���彻��

}
int main()
{
	//char *a="ididndijfser cl";
	char a[]="123456789";
	cout<<a<<endl;
	//int len = strlen(a);
	/*cout<<len<<endl;*/
	//cout<<reverse(a)<<endl;
	//cout<<reverse2(a)<<endl;
	/*reverse_word(a);*/
	/*cout<<reverse3(a,0,len)<<endl;*/
	/*cout<<ReverseSentence(a)<<endl;*/
	reversepart(a,3);
	cout<<a;
	system("pause");
}