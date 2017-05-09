//客户端程序：socket--connect--send/recv--close,使用流套接字
#pragme comment(lib,"ws2_32.lib")//导入windows套接字的动态链接库
#include<WinSock2.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv)//启动时使用命令行参数
{
    if(argc<=1){//对命令行参数进行说明
        printf("USAGE:TCPClient <Server IP address.\n>");
        return;
    }
    //1.创建套接字
    WSADATA wsaData;
    int ret;
    if(ret=WSAStartup(MAKEWORD(2,2),&wsaData)!=0);//加载windows套接字并对其初始化,版本2.2
    {
        printf("WSAStartup failed with error %d\n",ret);//windows套接字初始化失败
        return;
    }
    SOCET client;//定义一个套接字变量
    if(client=(socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==INVALID_SOCKET);//创建一个新的套接字,流式套接字.若创建失败则返回无效的套接字
    {
        printf("socket failed with error %d\n",WSAGetLastError());//返回错误信息
        WSACleanup();
        return
    }
    //2.和服务端进行连接，需要先知道服务端地址和端口
    SOCKKADDR_IN ServerAddr;服务端套接字地址
    int Port=5150;//服务端套接字端口,要与服务端建立连接，必须使用服务端的端口进行连接
    ServerAddr.sin_family=AF_INET;//利用服务端套接字进行连接欸，使用internet协议
    ServerAddr.sin_port=Port;
    ServerAddr.sin_addr.S_sun.S_addr=inet_addr("127.0.0.1");//准备服务端地址(使用本机地址)并作地址转换,argc[1]:在执行使自己输入服务端程序
    printf("We are trying to connect to %s:%d...\n",inet_ntoa(ServerAddr.sin_addr),htons(ServerAddr.sin_port));//准备连接，将服务端IP地址转换成字符串显示，端口也由本机字节顺序转换成网咯字节顺序
   if(connect(client,(SOCKADDR*)&ServerAddr,sizeof(ServerAddr))==SOCKET_ERROR);//参数：客户端套接字，服务端IP地址,用客户端套接字去连接服务端地址
   {
       printf("connect failed with error %d\n",WSAGetLastError());
       closesocket(client);//如果连接失败则关闭客户端套接字
       WSACleanup();
       return;
   }
   //连接成功，打印信息
   printf("Our connection succeeded.\n");
   //3.发送数据
   printf("We will try to send a hello message.\n");//向服务端发送数据
   if((ret=send(client,"hello",5))==SOCKET_ERROR){//send函数发送数据，参数：客户端套接字，发送信息，5个字节
       printf("send failed with error",WSAGetLastError());
       closesocket(client);//如果发送失败则关闭客户端套接字
       WSACleanup();
       return;
   }
   printf("We successfully send %d byte message",ret);
   //4.关闭连接
   printf("We are closing the connection.\n");//发生成功则关闭连接
   closesocket(client);
   WSACleanup();
system("pause");
return 0;
}