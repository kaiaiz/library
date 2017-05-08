//主函数体内
/*#include<stdio.h>
int main()
{
    int a,b,temp;
    a=1;
    b=10;
    printf("a=%d,b=%d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("a=%d,b=%d",a,b);
    return 0;
}*/
//主函数外
#include<stdio.h>
int main()
{
    int a=1;
    int b=10;
    printf("a=%d,b=%d\n",a,b);
    swap(&a,&b);
    printf("a=%d,b+%d\n",a,b);
    return 0;
}
void swap(int *ptr_x,int *ptr_y)
{
    int temp;
    temp=ptr_x;
    *ptr_x=*ptr_y;
    *ptr_y=temp;
}
//宏定义
/*#include<stdio.h>
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
int main()
{
    int a,b,temp;
    a=1;
    b=10;
    printf("a=%d,b=%d\n",a,b);
    swap(a,b,t)；
    printf("a=%d,b=%d",a,b);
    return 0;
}*/