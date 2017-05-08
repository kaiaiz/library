//冒泡排序法
//this is for JAVA
package tools;
public class BubbleSort{
public void select(int[] arry){
int i;
for(int j=1;j<arry.length;j++){
      for(i=arry.length-1;i>=j;i--){
if(arry[i-1]>arry[i]){
int temp=arry[i-1];
arry[i-1]=arry[i];
arry[i]=temp;
}
}
}
for(int k=0;k<arry.length;k++)
System.out.print(arry[k]+",");
System.out.println();
}
}
