#include <stdio.h>
#include <stdlib.h>

#include <unistd.h> //read(),write()
#include <fcntl.h> //open()
#define maxBuf 8192

int main(int argc,char *argv[]){
    char buf[maxBuf];
    int fd_in,fd_out;

    if(argc != 3){
            fprintf(stderr,"error command\n");
            exit(1);
    }
    /*打開要複製的檔案*/
    fd_in = open(argv[1],O_RDONLY);
    if(fd_in < 0){
            fprintf(stderr,"open error: %s\n",argv[1]);
            exit(1);
    }
    /*打開要寫入的檔案 , 如果沒有則建立*/
    fd_out = open(argv[2],O_CREAT | O_WRONLY, 0600);
    if(fd_out < 0){
            fprintf(stderr,"open error: %s\n",argv[2]);
            exit(1);
    }

    int readCnt;
    while((readCnt = read(fd_in,buf,maxBuf)) > 0){
            printf("readcnt %d\n",readCnt);
            write(fd_out,buf,readCnt);
    }
    /*每次從原檔讀<= maxBuf的量 寫入目標檔案 重複至內容結束*/
    exit(0);
}
