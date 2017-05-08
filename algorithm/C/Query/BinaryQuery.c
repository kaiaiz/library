//折半查找，即二分查找，条件：数据必须先排序
#include<stdio.h>
int binaryQuery();
int main()
{
    int i;
    int lengeh;
    int array[lengeh];
    int num;
    printf("please enter ten numbers");
    for(i=0;i<lengeh;i++){
        sacnf("%d",&array[i]);
    }
    printf("please enter the number that you want to query");
    sacnf("%d",num);
    int result=binaryQuery(array[lengeh],lengeh,num);
    if(result>-1){
    printf("the number you want to quert is array[%d]",num);
    }else{
        printf("do not search this number!");
    }
    return 0;
}
int binaryQuery(int *array,int lengeh,int num)
{
    int low=0;
    int high=lengeh-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(num<array[mid]){
            high=mid-1;
        }else if(x>array[mid]){
            low=mid+1;
        else return mid;//如果查询结束则返回值num.
        }
    }
    return -1;//如果循环结束查询失败，则返回-1.
}