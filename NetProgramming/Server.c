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
//½ø³Ì»ØÊÕº¯Êý
=======
//è¿›ç¨‹å›žæ”¶å‡½æ•°
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
  //´´½¨Ì×½Ó×Ö
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  
  //³õÊ¼»¯·þÎñÆ÷ sockaddr_in
  memset(&serv_addr,0,serv_len); //ÉêÇëÄÚ´æ
  serv_addr.sin_family = AF_INET;  //µØÖ·´Ø
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //¼àÌý±¾»úËùÓÐIP
  serv_addr.sin_port = htons(port);
  
  //°ó¶¨
  bind(lfd,(struct sockaddr*)&serv_addr,serv_len);
  
  //ÉèÖÃ¼àÌýµÄ×î´ó¸öÊý
  listen(lfd,36);
  printf("listening...\n");
  
  //Ê¹ÓÃÐÅºÅ»ØÊÕ×Ó½ø³ÌµÄpcb
=======
  //åˆ›å»ºå¥—æŽ¥å­—
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  
  //åˆå§‹åŒ–æœåŠ¡å™¨ sockaddr_in
  memset(&serv_addr,0,serv_len); //ç”³è¯·å†…å­˜
  serv_addr.sin_family = AF_INET;  //åœ°å€ç°‡
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //ç›‘å¬æœ¬æœºæ‰€æœ‰IP
  serv_addr.sin_port = htons(port);
  
  //ç»‘å®š
  bind(lfd,(struct sockaddr*)&serv_addr,serv_len);
  
  //è®¾ç½®ç›‘å¬çš„æœ€å¤§ä¸ªæ•°
  listen(lfd,36);
  printf("listening...\n");
  
  //ä½¿ç”¨ä¿¡å·å›žæ”¶å­è¿›ç¨‹çš„pcb
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
      //¸¸½ø³Ìaccept
=======
      //çˆ¶è¿›ç¨‹accept
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
      int cfd = accept(lfd,(struct sockaddr*)&client_addr,&cli_len);
      while(cfd==-1 && errno==EINTR){
          cfd = accept(lfd,(struct sockaddr*)&client_addr,&cli_len);
          //perror("accept error");
          //exit(1);
      }
      printf("connect successful\n");
<<<<<<< HEAD
      //´´½¨×Ó½ø³Ì
      pid_t pid = fork();
      if(pid == 0){
          //¹Ø±Õ×Ó½ø³ÌµÄaccept
          close(lfd);
          //×Ó½ø³Ì£¬Í¨ÐÅ
          //³ÖÐøÍ¨ÐÅ£¬¿ÉÄÜ»áÍ¨ÐÅ¶à´Î£¬ÓÃwhileÑ­»·
=======
      //åˆ›å»ºå­è¿›ç¨‹
      pid_t pid = fork();
      if(pid == 0){
          //å…³é—­å­è¿›ç¨‹çš„accept
          close(lfd);
          //å­è¿›ç¨‹ï¼Œé€šä¿¡
          //æŒç»­é€šä¿¡ï¼Œå¯èƒ½ä¼šé€šä¿¡å¤šæ¬¡ï¼Œç”¨whileå¾ªçŽ¯
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
          char ip[64];
          while(1){
              printf("client IP: %s, port:%d\n",
                      inet_ntop(AF_INET,&client_addr.sin_addr.s_addr,ip,sizeof(ip)),
                      ntohs(client_addr.sin_port));
<<<<<<< HEAD
              char buf[1024],buf_send[1024]; //ÐèÒªÒ»¸öbuffer
              //¶ÁÈ¡¿Í»§¶Ë·¢À´µÄÊý¾Ý
=======
              char buf[1024],buf_send[1024]; //éœ€è¦ä¸€ä¸ªbuffer
              //è¯»å–å®¢æˆ·ç«¯å‘æ¥çš„æ•°æ®
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
                  //´òÓ¡
=======
                  //æ‰“å°
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
                  printf("recv buf from client: %s\n",buf);
                  for(int i=0;i<1024;i++){
                      buf_send[i]=buf[i]+1;
                  }
                  write(cfd, buf_send, len);
              }
          }
<<<<<<< HEAD
          //ÍË³ö×Ó½ø³Ì
=======
          //é€€å‡ºå­è¿›ç¨‹
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
          //return 0;
          exit(1);
      }
      else if(pid>0){
<<<<<<< HEAD
          //¸¸½ø³Ì
=======
          //çˆ¶è¿›ç¨‹
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
