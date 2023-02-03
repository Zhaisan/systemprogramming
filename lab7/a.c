#include <stdio.h>
#include <sys/types.h>        
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {

   int a;
   if((a = semget(IPC_PRIVATE,1,0777|IPC_CREAT))==-1) {             
           perror("\nFailed to create semaphore.");
           exit(0);
   }
 
   if((semctl(a,0,IPC_RMID,0))==-1) {                             
           perror("\nCan't RPC_RMID.");                                             
           exit(0);                                                                                
    }
  
   return 0;
}