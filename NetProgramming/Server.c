#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

<<<<<<< HEAD
//���̻��պ���
=======
//进程回收函数
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
void recyle(int num){
    pid_t pid;
    while((pid==waitpid(-1,NULL,WNOHANG))>0){
        printf("recyle child finished. pid=%d\n",pid);
    }
}

int main(int argc, const char* argv[]){
  if(argc<2){
    printf("example: ./a.out port\n");
    exit(1);
  }
  struct sockaddr_in serv_addr;
  socklen_t serv_len = sizeof(serv_addr);
  int port = atoi(argv[1]);
  
<<<<<<< HEAD
  //�����׽���
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  
  //��ʼ�������� sockaddr_in
  memset(&serv_addr,0,serv_len); //�����ڴ�
  serv_addr.sin_family = AF_INET;  //��ַ��
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //������������IP
  serv_addr.sin_port = htons(port);
  
  //��
  bind(lfd,(struct sockaddr*)&serv_addr,serv_len);
  
  //���ü�����������
  listen(lfd,36);
  printf("listening...\n");
  
  //ʹ���źŻ����ӽ��̵�pcb
=======
  //创建套接字
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  
  //初始化服务器 sockaddr_in
  memset(&serv_addr,0,serv_len); //申请内存
  serv_addr.sin_family = AF_INET;  //地址簇
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //监听本机所有IP
  serv_addr.sin_port = htons(port);
  
  //绑定
  bind(lfd,(struct sockaddr*)&serv_addr,serv_len);
  
  //设置监听的最大个数
  listen(lfd,36);
  printf("listening...\n");
  
  //使用信号回收子进程的pcb
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
  struct sigaction act;
  act.sa_handler = recyle;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
  sigaction(SIGCHLD, &act, NULL);
  
  struct sockaddr_in client_addr;
  socklen_t cli_len = sizeof(client_addr);
  while(1){
<<<<<<< HEAD
      //������accept
=======
      //父进程accept
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
      int cfd = accept(lfd,(struct sockaddr*)&client_addr,&cli_len);
      while(cfd==-1 && errno==EINTR){
          cfd = accept(lfd,(struct sockaddr*)&client_addr,&cli_len);
          //perror("accept error");
          //exit(1);
      }
      printf("connect successful\n");
<<<<<<< HEAD
      //�����ӽ���
      pid_t pid = fork();
      if(pid == 0){
          //�ر��ӽ��̵�accept
          close(lfd);
          //�ӽ��̣�ͨ��
          //����ͨ�ţ����ܻ�ͨ�Ŷ�Σ���whileѭ��
=======
      //创建子进程
      pid_t pid = fork();
      if(pid == 0){
          //关闭子进程的accept
          close(lfd);
          //子进程，通信
          //持续通信，可能会通信多次，用while循环
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
          char ip[64];
          while(1){
              printf("client IP: %s, port:%d\n",
                      inet_ntop(AF_INET,&client_addr.sin_addr.s_addr,ip,sizeof(ip)),
                      ntohs(client_addr.sin_port));
<<<<<<< HEAD
              char buf[1024],buf_send[1024]; //��Ҫһ��buffer
              //��ȡ�ͻ��˷���������
=======
              char buf[1024],buf_send[1024]; //需要一个buffer
              //读取客户端发来的数据
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
              int len = read(cfd,buf,sizeof(buf));
              if(len==-1){
                  perror("read error");
                  exit(1);
              }else if(len==0){
                  printf("client has closed.\n");
                  close(cfd);
                  break;
              }else{
<<<<<<< HEAD
                  //��ӡ
=======
                  //打印
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
                  printf("recv buf from client: %s\n",buf);
                  for(int i=0;i<1024;i++){
                      buf_send[i]=buf[i]+1;
                  }
                  write(cfd, buf_send, len);
              }
          }
<<<<<<< HEAD
          //�˳��ӽ���
=======
          //退出子进程
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
          //return 0;
          exit(1);
      }
      else if(pid>0){
<<<<<<< HEAD
          //������
=======
          //父进程
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
          close(cfd);
      }
  } 
  close(lfd);
  return 0;
<<<<<<< HEAD
  
}
=======
}
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
