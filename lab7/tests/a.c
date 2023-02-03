#include <stdio.h>


void go() {
    printf("Hello, World!");
}
int main() {
   int t = 1;
   while(t--) {
    go();
   }
}