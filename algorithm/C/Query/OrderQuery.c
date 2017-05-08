//顺序查询，即线性查询，效率较低
#include<stdio.h>
int orderQuery();
int main()
{
    int array[10];
    int length=10;
    int num;//will query number
    int i;
    printf("please enter ten numbers");
    for(i=0;i<length;i++){
        scanf("%d",&array[i]);
    }
    printf("please enter a number that you want to query");
    int result=orderQuery(array,length,num);
    printf("the query number is array[%d] in array",num);
    return 0;
}
int orderQuery(int *array,int length,int num)
{
    int i;
    for(i=0;i<length;i++){
        if(array[i]==x){
            return 1;
        }
        if(i==length){
            return -1;
        }
    }
}