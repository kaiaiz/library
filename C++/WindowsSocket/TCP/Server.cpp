/*
套接字有两种：
流套接字：TCP/IP（SOCK_STREAM）
数据报套接字：UDP/IP(SOCK_DGRAM)
客户端和服务器端通过Socket通信。
Socket函数：
	socket()
	bind()
	listen()
	accept()
	connect()
	send()
	recv()
	select()
	closesocket()
1.IP地址转换
	点分IP地址--32位无符号长整型
	转换函数：s_addr=inet_addr("162.105.11.145");|
2.字节转换：
	大端字节：big-endian
	小端字节：little-endian
	主机字节：host-byte
	网络字节：network-byte
3.TCP Socket编程
	流式套接字：TCP/IP （SOCK_STREAM）
	服务端程序：
		socket--bind--listen--accept-send/recv--close
	客户端程序：
		socket--connect--send/recv--close
4.网络程序=客户端程序+服务器端程序
	客户端：初始化Socket--建立连接--收发数据--关闭连接
	->
	服务端--初始化监听Socket--接受新的客户端连接--收发数据--关闭连接
*/
#pragma comment(lib,"ws2_32.lib")包含windows socket动态链接库，版本2.2.
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>//包含windows socket头文件 版本2.2,
int main(void)
{
	//1.初始化windwows套接字
    WSADATA wsaData;//定义变量，用于初始化winsows套接字
    if((ret=WSAStartup(MAKEWORD(2,2),&wsaData))!=0){//WSAStartup函数初始化winsowes套接字网络库，版本2.2，如果返回值不为0，则初始化失败
        printf("error",ret);//检测错误信息
        return 1;
    }
	//2.创建服务端套接字,用来监听客户端请求
	SOCKET ListeningSocket//定义一个套接字，用于监听请求
	if(ListeningSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)==INVALID_SOCKET){//AF_INET:使用internent协议，SOCK_STREAM:流式套接字，IPPROTO_TCP:使用TCP协议
	printf("socket failed witherror %d\n",WSAGetLastError);//检测是否成功,WSAGetLastError:返回错误信息
	WSACleanup();//创建套接字失败，清理
	return；
	}
	//3.将套接字和服务端地址+端口绑定
	SOCKADDR_IN ServerAddr;//准备服务端地址
	ServerAddr.cin_family=AF_INET;//family:协议，AF_INET:internet协议
	//int Port=5150//创建一个未被占用的空闲端口的变量
	ServerAddr.cin_port=htons(Port)//指定未被占用端口,将端口号变成网络字节顺序（本机--网络）
	ServerAddr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//INADDR_ANY指定的地址可以接收客户端IP地址的请求，可以接受任何客户端IP的请求,不限定任何一个客户端的连接（本机到网络字节顺序的转换）
	if(bind(ListeningSocket,(SOCKADDR*)&ServerAddr,sizeof(ServerAddr))==SOCKET_ERROR);{//将服务端的套接字和服务端地址及端口绑定
	printf("bind failed with error %d\n",WSAGetLastError);//返回绑定失败的消息}
	closesocket(ListeningSocket);//关闭套接字，释放资源
	WSACleanup();//清理
	return;}
	//若绑定成功，则开始监听
	if(listen(ListeningSocket,5)==SOCKET_ERROR){//利用服务端的套接字进行监听,设置一个五个连接的队列，即一次性最多可以有5个客户的请求在队列里
	printf("listen failed with error &d]n",WSAGetLastError);//若监听失败，则返回错误信息}
	closesocket(ListeningSocket);//关闭套接字
	WSACleanup();//清理
	return;}
	//若监听成功，则服务端处于等待客户端请求的状态,即等待连接状态
	printf("We are waiting a connection on port %d.\n",Port);
	printf("Listen(正在监听)...");
	//如果在监听过程中有客户端连接，则接受请求
	SOCKADDR_IN ClientAddr;//声明客户端地址
	int ClientAddrLen=sizeof(SOCKADDR);//客户端地址长度
	SOCKET NewConnection;//若连接成功则得到一个客户端套接字，表明一个新的连接
	if((NewConnection=accept(ListeningSocket,(SOCKADDR*)&ClientAddr,&ClientAddrLen)==INVALID_SOCKET){//参数：服务端套接字，客户端套接字,客户端地址,客户端地址长度.每一个客户端请求在服务端得到接受后会得到一个客户端请求,若连接失败，则得到一个非法套接字
	printf("accept failed with error %d\n",WSAGetLastError);
	closesocket(ListeningSocket);//若接收请求失败则关闭套接字
	WSACleanup();//清理
	return;}
	//若接受请求成功，则成功获得一个客户端到服务端的链接
	printf("We successfully got a connection from %s:%d\n",inet_ntoa(ClientAddr,sin_addr),ntohs(ClientAddr,sin_port));//客户端IP地址（sin_addr:32位无符号长整型，需要转换成字符串显示），客户端端口从网络字节顺序变为本机地址
	closesocket(ListeningSocket);//连接上就可以关闭服务端用于监听的套接字,也可以不关闭继续监听来自其他客户端套接字的请求
	printf("We are waiting to receive data.");//有一个客户端连接上来就可以停止监听，然后等待客户端发送数据
	char dataBuffer[1024];//定义一个字节数组作为缓存
    int ret;
	if(ret=recv(NewConnection,dataBuffer,sizeof(dataBuffer),0)==SOCKET_ERROR){//客户端套接字，接收到的数据放到缓存中
	printf("recv failed with data\n");//如果接收失败，输出错误信息
	closesocket(NewConnection);//关闭客户端套接字
	WSACleanup();//清理
	return;
	}
printf("We successfully received %d byte.\n",Ret);//从客户端接收到的字节数
dataBuffer[ret]='\0';//从客户端接收到的数据缓存,加上'\0'作为结束
printf("%s\n",dataBuffer);
printf("We are now going to close the client connection.\n");//接收到数据可以断开连接
closesocket(NewConnection);//关闭客户端套接字
WSACleanup();//清理
system("pause");	
return 0;
}