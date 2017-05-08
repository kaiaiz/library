/*冒泡排序
从左向右扫描数据，选择最大的数据，放在右边。
要点：比较相邻的两个数，如果左边的数大于右边的数就进行交换。
*/
#include<stdio.h>
void bubbleSort(int *array,int length);
int main()
{
    int array[10];
    int i;
    int length=10;
    printf("please enter ten numbers\n");
    for(i=0;i<length;i++){
        scanf("%d",&array[i]);
    }
    printf("output numbers before sorting\n");
    for(i=0;i<length;i++){
        printf("%d",array[i]);
        if(i=length-1){
            printf("\n");
        }
    }
    bubbleSort(array,length);
    printf("output numbers after sorting\n");
    for(i=0;i<length;i++){
        printf("%d",array[i]);
        if(i=length-1){
            printf("\n");
        }
    }
return 0;
}
void bubbleSort(int *array,int length)
{
    int i,j;
    for(i=0;i<length-1;i++){   //每次内循环都将最大的数放到最后，最末一次最小的数就在开始位置。
        for(j=0;j<length-i-1;j++){
            if(array[j]>array[j+1]){    //内循环，前一个数和后一个数作比较，将最大的数放到最后，下一次循环则不用管末尾的数
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}