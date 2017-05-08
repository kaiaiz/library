//菱形算法
//this is for JAVA
package tools;
import java.util.*;
public class Rhombus{
public static void main(String[] args){
System.out.println("please input a number.we will print a rhombus.");
Scanner scanner=new Scanner(System.in);
int n=scanner.nextInt();
outPut(n);
}
public static void outPut(int m){
int i,j,k;
for(j=1;j<=m;j++)
{
for(i=1;i<=(m-j);i++)
System.out.print(" ");
for(k=1;k<=(2*j-1);k++)
System.out.print("*");
System.out.println();
}
for(j=(m-1);j>=1;j--)
{
  for(k=1;k<=(m-j);k++)
   System.out.print(" ");
for(i=1;i<=(2*j-1);i++)
   System.out.print("*");
   System.out.println();
}
}
}

