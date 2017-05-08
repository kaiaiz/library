//插入排序
//this is for JAVA
package tools;
public class InsertSort{
public void sort(int[] arry){
for(int i=1;i<arry.length;i++){
int j=i-1;
int temp=arry[i];
while(j>=0&&temp<arry[j])
{
arry[j+1]=arry[j];
j--;
}
arry[j+1]=temp;
}
for(int k=0;k<arry.length;k++)
System.out.print(arry[k]+",");
System.out.println();
}
}
