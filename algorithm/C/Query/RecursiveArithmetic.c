/*�ݹ��㷨���Լ������Լ�
����׳˵ķ���
1.ʹ�õݹ�
2.ʹ�õ���������ѭ����
*/
//for example one
#include<stdio.h>
int main()
{
	int num;
	int result;
	printf("please enter a number");
	scanf("%d",num);
	result=factory(num);
	printf("the factorial of %d is",result,num);
	doHello();
	return 0;
}
void doHello()
{
	printf("hello world");
	doHello();
}
int factorial(int num)
{
	if(num==0){
		return 1;}
	else{
		return num * factory();
}
}