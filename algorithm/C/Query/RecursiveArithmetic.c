/*递归算法：自己调用自己
计算阶乘的方法
1.使用递归
2.使用迭代（就是循环）
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