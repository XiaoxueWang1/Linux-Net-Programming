#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, const char* argv[]){
    if(argc<2){
      printf("example: ./a.out port\n");
      exit(1);
    }
    int port = atoi(argv[1]);
<<<<<<< HEAD
    //´´½¨Ò»¸öÌ×½Ó×Ö
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    //Á¬½Ó·þÎñÆ÷
=======
    //åˆ›å»ºä¸€ä¸ªå¥—æŽ¥å­—
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    //è¿žæŽ¥æœåŠ¡å™¨
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
    struct sockaddr_in serv;
    memset(&serv,0,sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    inet_pton(AF_INET,"127.0.0.1",&serv.sin_addr.s_addr);
    
    connect(fd,(struct sockaddr*)&serv,sizeof(serv));
    
<<<<<<< HEAD
    //Í¨ÐÅ
    while(1){
        //·¢ËÍÊý¾Ý
=======
    //é€šä¿¡
    while(1){
        //å‘é€æ•°æ®
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
        char buf[1024];
        printf("input message:\n");
        fgets(buf,sizeof(buf),stdin);
        write(fd,buf,strlen(buf));
        
<<<<<<< HEAD
        //µÈ´ý½ÓÊÕ
=======
        //ç­‰å¾…æŽ¥æ”¶
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
        int len = read(fd,buf,sizeof(buf));
        if(len==-1){
            perror("client read error.\n");
            exit(1);
        }else if(len==0){
<<<<<<< HEAD
            printf("server has closed.\n"); //¹Ø±Õºó²»»á×èÈû
            break;
        }else{
            //´òÓ¡
            printf("recv buf from server: %s\n",buf);
        }
  }
  //close(fd);
  return 0;
}
=======
            printf("server has closed.\n"); //å…³é—­åŽä¸ä¼šé˜»å¡ž
            break;
        }else{
            //æ‰“å°
            printf("recv buf from server: %s\n",buf);
        }
  }
  return 0;
}
>>>>>>> 6ca38658e167d5585afc5706fdf83b9ce25da307
