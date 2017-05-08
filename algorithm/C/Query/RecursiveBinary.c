//µİ¹éËã·¨µÄÕÛ°ë²éÕÒ
//for example
#include<stdio.h>
int main()
{
	int num,
	int array[10];
	int lower=0;
	int length=10;
	int high=length-1;
	printf("please enter the array that you want");
	printf("please enter a number");
	sacnf("%d",&num);
	array=RecurisiveBinary(array,lower,high,num);
	return 0;
}
int RecursiveBinary(int *array,int lower,int high,int num)
{
	int mid;
	if(low<high){
		mid=(low+high)/2;
		if(array[mid]=num){
			return mid;}
		else if(array[mid]<num){
			lowe=mid+1
			}
		else if(array[mid]>num){
			high=mid-1;
			}
	return RecursiveBinary(array,num,low,high);
		}
	return -1;
}