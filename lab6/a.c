#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    int res, len, i;
    char s[15];
    struct {
        long mtype;
        char mtext[15];
    }
    message,buff;
    res=msgget((key_t)10,IPC_CREAT|0666);
    if(res==-1) {
        perror("message queue create failed"); 

        exit(1);
    }

    for(i = 1; i <= 3; i++) {
        printf("Enter the message to send\n");
        scanf("%s", s);
        strcpy(message.mtext, s);
        message.mtype = i;
        len = strlen(message.mtext);
        if(msgsnd(res, &message,len + 1, 0) == -1) {
            perror("message failed\n"); exit(1);
        }
    }
}