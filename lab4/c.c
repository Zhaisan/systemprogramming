#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *source, *destination;
    char ch;

    source = fopen("test.txt", "r");

    if(source==NULL) {
        printf("File error!");
        exit(1);
    }

    destination = fopen("test2.txt","w");
    if(source==NULL) {
        printf("File error!");
        exit(1);
    }

    do {
        ch = fgetc(source);
        fputc(ch, destination);
    } while(ch!=EOF);
    
    freopen("test.txt", "w", source);

    fclose(source);
    fclose(destination);

    printf("Moved");
    return 0;
}