#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define    maxBuf    8192
void tolower_func(char *nbuf,char *buf);

int main(int argc,char *argv[]){
    char buf[maxBuf],nbuf[maxBuf];
    if(argc != 2){
            fprintf(stderr,"error command!\n");
            exit(1);
    }

    int fd = open(argv[1],O_RDWR);
    if(fd < 0){
            fprintf(stderr,"open error: %s\n ",argv[1]);
            exit(1);
    }

    int readCnt;
    while((readCnt = read(fd,buf,maxBuf)) > 0){
            tolower_func(nbuf,buf);
            write(fd,nbuf,readCnt);
    }

    exit(0);
}
void tolower_func(char *nbuf,char *buf){
        char *ptr = buf;
        char *qtr = nbuf;
        while(*ptr){
                if(isupper(*ptr)){
                        *qtr++ = *ptr - 'A' + 'a';
                        ptr++;
                }
                *qtr++ = *ptr++;
        }
        *qtr = '\0';
        return;
}
