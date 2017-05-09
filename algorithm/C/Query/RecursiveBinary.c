//递归算法的折半查找
//for example
#include<stdio.h>
int main()
{
	int num,
	int array[10];
	int lower=0;
	int length=10;
	int high=length-1;
	int result;
	printf("please enter the array that you want");
	for(int i=0;i<length;i++){
		sacnf("%d",&array[i]);
	}
	printf("please enter a number you want to query");
	sacnf("%d",&num);
	result=recurisiveBinary(array,lower,high,num);
	if(num<=-1){
		printf("not find");
	}else{
		printf("the number of array[%d] is %d",num,result);
	}
	return 0;
}
int recursiveBinary(int *array,int lower,int high,int num)
{
	int mid;
	if(low<high){
		mid=(low+high)/2;
		if(array[mid]=num){
			return mid;}
		else if(array[mid]<num){
			lowe=mid+1;
			}
		else if(array[mid]>num){
			high=mid-1;
			}
	return recursiveBinary(array,num,low,high);
		}
	return -1;
}