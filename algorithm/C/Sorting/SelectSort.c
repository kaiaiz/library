/*选择排序
从当前未排序的整数中找一个最小的整数，将它放在已排序的整数列表的最后。
要点：选择最小的数，依次放在左边
*/
#include<stdio.h>
void selectSort(int *array,int length);
int main()
{
    int array[length];
    int i;
    printf("please enter ten numbers");
    for(i=0;i<length;i++){
        scanf("%d",&a[i]);
    }
    printf("output numbers before sorting\n");
    for(i=0;i<length;i++){
        printf("%d\t",aray[i]);
        if(i=length-1){
            printf("\n")
        }
    }
    selectSort(aray,length);
    printf("output numbers after sorting\n");
    for(i=0;i<length;i++){
        printf("%d\t",array[i]);
        if(i=length-1){
            printf("\n");
        }
    }
}
void selectSort(int *aray,int length)
{
    int i,j;
    for(i=0;i<length-1;i++){
        int min=i;
        for(j=i+1;j<length;j++){
            if(a[j]<a[min]){
                min=j;
            }
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
        }
    }
}