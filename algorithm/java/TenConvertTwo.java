//十进制转二进制
//this is for JAVA
package tools;
public class TenConvertTwo{
public void convert(int k){
int result,j,i;
int[] arry=new int[20];
for(i=0;i<arry.length;i++){
while(k!=0)
{
result=k%2;
k=k/2;
arry[i]=result;
i++;
}
}
for(j=arry.length-1;j>=0;j--)
System.out.print(arry[j]);
System.out.println();
}
}
