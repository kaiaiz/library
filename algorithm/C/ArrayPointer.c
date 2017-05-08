/*for example one
#include<stdio.h>
int main()
{
    int num=1024;//整型变量
    int *ptr_num;//整型指针变量
    ptr_num=&num;//取num的地址赋给ptr_num变量
    printf("the number of num is:%d\n",num);
    printf("the address of num is:%p\n",&num);
    printf("the number of ptr_num is:%p\n",ptr_num);
    printf("the address of ptr_num is:%p\n",&ptr_num);
    printf("the number of pointer point is:%d\n",*ptr_num);
    return 0;
}*/
/*for example two
#include<stdio.h>
int main()
{
    int num1=1024;
    int num2=2048;
    int *ptr1;
    int * ptr2;
    ptr1=&num1;
    ptr2=&num2;
    printf("the number of num1 is:%d\nthe address of ptr1 is:%p\n",num1,ptr1);
    printf("the number of num2 is:%d\nthe address of ptr2 is:%p",num2,ptr2);
}*/
/*summary
指针同样是一个变量，只不过该变量中存储的是另一个对象的内存地址。
如果一个变量存储另一个对象的地址，则该变量指向这个对象。
指针变量可以赋值，指针的指向在程序执行中可以改变。
指针变量的命名规则和其他所有变量的命名规则一样。
指针不能与现有变量同名。
指针可存放C语言中的任何基本数据类型，数组和其他所有高级数据结构的地址。
若指针已声明为指向某种类型数据的地址，则它不能用于存储其他类型数据的地址。
应为指针指定一个地址后，才能在语句中使用指针，且指针变量不能赋予常量。*/
/*for example three
#include<stdio.h>
int main()
{
    //数组名就是数组的首地址
    int score[]={98,67,43,32,89};
    int *ptr_array=score;
    printf("the first address of array is:%p\nthe pointer of array is:%p\nthe address of first number is%p",score,ptr_array,&score[0]);
    return 0;
}*/
//指针的算数运算（指针的递增和递减++.--）
/*for example two
#include<stdio.h>
int main()
{
    int i;
    int array[5]={63,46,45,23,90};
    int *ptr_array;
    ptr_array=array;
    for(i=0; i<5;i++){
        printf("the size of pinter is %d\n",sizeof(ptr_array));
        printf("the number of array[i] is %d and the address of array[i] is %p ana the pointer of array[i] is %p\n",*(ptr_array+i),&array[i],(ptr_array+i));
        //改变指针的简便表达方式：*ptr_array++,每次自增一个地址量级
    }
}*/
//一个指针类型为T的指针的移动，以sizeof（T）为移动单位，但其本身一般为四个字节。
//for example four
/*#include<stdio.h>
int main()
{
    //数组名就是数组的首地址
    int i;
    int array[5]={23,53,56,87,98,};
    int *ptr_array=array;
    //使用指针访问数组元素
    printf("the first address of array is %p and the address of the first number is %p\n",array,&array[0]);
    for(i=0;i<5;i++)
    {
        printf("array[i] is %d\n",ptr_array[i]);//指针相当于数组名，都是数组首地址，因此可对等使用。
    }
    return 0;
}*/
//for example five
/*#include<stdio.h>
int main()
{
    int i;
    int array[]={23,43,64,34,87,98,65,54,};
    int *ptr_array=array;
    //使用指针访问数组
    for(i=0;i<8;i++)
    {
        //printf("the number of array[i] is %d\n",ptr_array[i]);
        //printf("the number of array[i] is %d\n",*(ptr_array+i));
        //printf("the number of array[i] is %d\n",*ptr_array++);//完成访问后指针发生移动。重新访问数组元素前，记得重置指针的位置：ptr_array=score
    }
    return 0;
}*/
//指针加上或减去某个整数值
//for example six
/*#include<stdio.h>
int main()
{
    int i;
    int array[5]={43,23,65,67,87};
    int *ptr_array=&array[1];//将第一个元素的首地址赋予指针
    ptr_array=ptr_array+2;
    printf("the three number of array is %d\n",*ptr_array);
    ptr_array=ptr_array-3;
    printf("the first number of array is %d\n",*ptr_array);
    return 0;
}*/
/*summary:
数组名就是这块连续内存单元的地址
int num[50];    num既是数组名，也是数组的首地址。
num的值与&num【0】的值是相同的
数组第i+1个元素可表示为：
    第i+1个元素的地址：&num【i+1】或num+i
    第i+1个元素的值：num【i+1】或*（num+1）
为指向数组的指针赋值：
    int *ptr_num=num;或 int *ptr_num=&num[0];
指针变量可以指向数组元素。
    int *ptr_num=&num[4];或int *ptr_num=num+4;
*/
//for example seven
/*#include<stdio.h>
int main()
{
    int array[]={32,43,56,67,98};
    int i;
    int *ptr_array=array;
    for(i=0;i<5;i++){
        printf("the number of array[%d] is %d\nthe address of array[%d] is %p\n",i,*ptr_array,i,ptr_array);
        ptr_array++;//移动指针
    }
}*/
//要再次遍历指针，需为指针重新赋予初值。
//for example eight
/*#include<stdio.h>
int main()
{
    int i;
    int array[5]={23,43,54,65,76};
    int *ptr_first=array;
    //实现数组的逆序，原理就是数组的首尾元素进行交换
    int *ptr_array_start=array;
    int *ptr_array_end=array+5-1;
    while(ptr_array_start!=ptr_array_end){
        //首尾交换，指针分别进行更新
        int temp=*ptr_array_start;
        *ptr_array_start=*ptr_array_end;
        *ptr_array_end=temp;
        //首元素指针要向后移动
        ptr_array_start++;
        //尾元素的指针要向前移动
        ptr_array_end--;
    }
    for(i=0;i<5;i++){
        printf("the number of array[%d] is %d\n",i,*(ptr_first+i));
    }
}*/
/*二维数组与指针
int[5][3]   首地址:&a[0][0]
使用指针访问二维数组中的元素
a[1]    二维数组中第二行的首地址
*(a[1]+2)   二维数组中第二行第三列的值 a[1][2]
等价于  *(*(a+1)+2)*/
//for example nine
/*#include<stdio.h>
int main()
{
    //数组名就是数组元素首地址
    //对于二维数组的理解：是由n个一维数组所组成
    int i,j;
    int array[5][3]={
        {23,43,65},
        {54,32,67},
        {32,84,76},
        {12,65,78},
        {56,75,98}
    };
    printf("the number of array[1][2] is %d\n",*(array[1]+2));
    printf("the number of array[1][2] is %d\n",*(*(array+1)+2));
    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
            //printf("%d\t",array[i][j]);//array[i]=>*(array+i)
            //printf("%d\t",*(array[i]+j));
            printf("%d\t",*(*(array+i)+j));
        }
        printf("\n");
    }
}*/
/*summary:
指针是一个变量，存储另一个变量（对象）的内存地址
指针的声明由基本类型，标识符（*）和变量名组成
为指针赋值，赋值运算符右侧必须是一个地址。
    如果是普通变量，需要在前面加一个取地址运算符&
    如果是另一个指针变量或者是一个数组，不需要加&运算符
运算符*用于返回指针指向的内存地址中存储的值。
使用指针可以访问一维数组和二维数组的元素*/
/*内置函数：由C语言提供，需要在程序前包含定义函数的头文件
        所属头文件<stdio.h>
            内置函数：printf scanf   getchar putchar
        所属头文件<time.h>
            内置函数:time
        所属头文件<string.h>
            内置函数：strcpy     string.h
        所属头文件<ctype.h>
            内置函数：int isupper(int)   返回传入的字符是否为大写字母（0为假，非0为真）
                    int islower(int)   返回传入的字符是否为小写字母
                    int isalpha(int)   返回传入的字符是否为字母（a-z|A-Z）
                    int isdigit(int)   返回传入的字符是否为数字
                    int toupper(int)   返回对应的大写字母
                    int tolower(int)   返回对应的小写字母
        所属头文件<stdlib.h>
            内置函数：int srand(unsigned int)    设置随机数种子
                    int rand(void)             随机产生一个0-32767的数字，一般与srand联用
                    void exit(int)             终止程序
                    void system(const char*)   可以执行DOS命令
                        system常见语法：
                        1.sysytem("pause");             冻结屏幕，便于观察程序的执行结果
                        2.system("cls");                清屏操作
                        3.sysytem("color 4E");          修改背景色及前景色
                        4.system("shutdown /r /t 180"); 设置自动关机
        所属头文件<malloc.h>或<alloc.h>   内容完全一致
            内置函数：malloc()
                        全称是memory allocation,中文叫动态内存分配。当无法知道内存具体位置的时候，想要绑定真正的内存空间，就需要用到动态内存分配。
                        分配长度为num bytes字节的内存块。
                        函数原型：extern void *malloc(unsigned int num byte)，由于返回 为空，所以使用时需要强转
                        如果分配成功则返回指向被分配内存的指针（此存储区中的初值不确定），否则返回空指针NULL。
                        当内存不再使用时，应用free()函数将内存块释放（原始内存中的数据不变）
            内置函数：realloc（）
                        原型：extern void *realloc (void mem_address,unsigned int newsize);
                        用法：#include<stdlib.h>,有些编译器需要#include<alloc.h>.
                        功能:改变mem_address所指内存区域大小为newsize长度。
                        说明：如果重新分配成功则返回指向被分配内存的指针，否则返回控指针NULL。
                        当内存不再使用时，应使用free（）函数将内存块释放（原始内存中的数据保持不变）
        所属头文件：string.h()
            内置函数：   size_t_strlen(const char *) 获得字符串的长度
                        char *strupr(char *)    将字符串转换为大写
                        char *strlwr(char *)    将字符串转换为小写
                        char *strcpy(char *,const char *)    把第二个字符串复制到第一个字符数组中
                        int strcmp(const char *,const char *)   根据ASCII码比较字符串
                        char *strcat(char *,const char *)   字符串连接

*/
//for example ten
/*#include<stdio.h>
#include<malloc.h>
int main()
{
    int *array;
    int i;
    array=(int *)malloc(20);//为前面的指针动态分配了20个字节的空间，等价于：int array【5】,为指针动态分配空间后，指针就变成了数组。
    /*也可写为：aray=callo(5,sizeof(int));
    TIP:calloc作用与molloc类似
    1.不需要强转，直接返回数组。
    2.两个参数，默认初始化数组元素。
    for(i=0;i<5;i++){
        printf("please input array[%d] number:\n",i);
        scanf("%d ",array+i);
    }
    printf("output array numbers\n");
    for(i=0;i<5;i++){
        printf("%d\t",*(array+i));
    }
    free(array);//释放动态分配的内存
    array=NULL;
    /*1.必须是通过molloc，calloc或realloc分配内存的指针。
      2.释放的指针必须是初始分配的地址，进行运算后需要恢复。
}*/
/*自定义头文件
    一般放一些重复使用的代码，例如函数声明，变量声明，常量定义，宏的定义等。
    #ifndef MYHEADER_H_INCLUDED
    #define MYHEADER_H_INCLUDED
    //代码部分
    #endif //MYHEADER_H_INCLUDED
    TIP:1.MYHEADER_H_INCLUDED为一个唯一的标识，命名规则和变量的命名规则一样，常根据它所在的头文件来命名。
        2.代码含义：如果没有定义MYHEADER_H_INCLUDED,则定义MYHEADER_H_INCLUDED并编译下面的代码部分，知道遇到#endif.*/
//for example eleven
/*#include<stdio.h>
int *changeNums()
{
    //局部变量
    int num1=5,num2=3;
    num1=55;
    num2=288;
    //nums是局部变量
    int nums[]={3,43,5,7,8}
    //函数执行完毕后，会自动销毁函数内部定义的变量。
    return nums;
}
int main()
{
    int *nums=changeNums();
    int i;
    for(i=0;i<5;i++){
        printf("%d\t",*(nums+i));
    }
}*/
/*
使用数组作为函数参数。
1.数组作为函数实参时，只传递数组的地址，并不传递整个数组的空间。
2.当用数组名作为实参调用函数时，数组首地址指针被传递到函数中。
*/
//for example tewelve
/*#include<stdio.h>
void show(int[]);
void sort(int[]);
void show(int[]);
int main()
{
    int array[5];
    //1.录入
    input(array);
    printf("sort present");
    show(array);
    //2.排序
    sort(array);
    //3.按照某种格式打印
    printf("sort forward");
    show(array);
    reutrn 0;
}
void input(int array[])
{
    int i;
    for(i=0;i<5;i++){
        printf("please input gradeds",i+1);
        //scanf("%d",&array[i]);
        scanf("%d",(array+i));
    }
}
void show(int array[])
{
    int i;
    printf("********************");
    printf("chinese/math/English");
    for(i=0;i<5;i++)
    {
        printf("%d",*(array+i));
    }
    printf("********************");
}
void sort(int array[])
{
    int i,j;
    int temp;
    for(i=0;i<5;i++){
        for(j=0;j<5-i-1;j++){
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
        }
    }
}*/
/*数组和指针
diff in 数组形式&指针
    1.初始化字符数组时会把静态存储区的字符串拷贝到数组中。
    2.初始化指针时只把字符串的地址拷贝给指针。
    #include<stdio.h>
    int main()
    {
        char str[]="what a magnificant masterpiece";
        char *ptr_str="what a magnificent masterpiece";
        printf("字符串常量的地址:%p\n","what a magnificent masterpiece");
        printf("字符串常量的地址:%p\n",str);
        printf("字符指针的取值：%p\n",ptr_str);
    }
结构：
    定义：结构是一种构造数据类型，由若干数据项组合而成。
    for example:
    struct StructName
    {
        //构造成员
        Data Type var1;
        Data Type var2;
        ...
    }
    struct Hero
    {
        char name[20];
        int level;
        char job[10];
        char skill[10];
    }
    TIP:
        1.结构定义并不预留内存。
        2.结构定义一般放在程序的开始部分（头文件声明之后）
        3.结构定义仅用来描述结构的形式，使用结构需要声明结构变量。
        for example
        #include<stdio.h>
        struct Hero
        {
            int id;
            char name[20];
            char level;
            int hp;
            int mp;
            char skill[10];
        };
        int main()
        {
            //使用结构体
            struct Hero hero;   //struct hero1={3,"mark",500,100,"fire"};
            hero.id=3;
            strcpy(hero1.name,"mark");//定义字符串后即为常量，内容固定，无法再次复制。或    hero.name=(cahr *)malloc(50);   printf("%s",heroq.name);
            hero1.hp=500;
            hero1.mp=100;
            strcpy(hero1.skill,"fire");
            printf("%d\t%s\t%d\t%d\t%s\t",hero.id,heroq.name,hero1.level,hero.hp,hero1.skill);
            return 0;
        }
传递结构
    struct Account
    {
        char *bankname;
        char *userName;
        double limit;
        double billAmount;
    };
    //计算并返回当月还款
    double GetRepayment(struct Account account)
    {
        return account.limit-account.billAmount;
    }
    //赋值
    struct Account asAcc;
    zsAcc.bankName="bank";
    zsAcc.userNmae="kaiai";
    zsAcc.limit=50000;
    zsAcc.billAmount=35000;
    double result=GetRepayment(zsAcc);
    printf("本月应还款：%.2lf\n",result);
传递结构成员
    struct Account
    {
        char *bankname;
        char *userName;
        double limit;
        double billAmount;
    };
    //计算并返回当月还款
    double GetRepayment(double m1,double m2)
    {
        return m1-m2;
    }
    //赋值
    struct Account asAcc;
    zsAcc.bankName="bank";
    zsAcc.userNmae="kaiai";
    zsAcc.limit=50000;
    zsAcc.billAmount=35000;
    double result=GetRepayment(zsAcc.limit,zsAcc.billAmount);
    printf("本月应还款：%.2lf\n",result);
*/