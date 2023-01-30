#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sumOdd = 0, sumEven = 0, n, i;
    n = fork();
 
    if (n > 0) {
        for (i = 0; i < 10; i++) {
            if (a[i] % 2 == 0) sumEven = sumEven + a[i];
        }
        printf("Child process\n");
        printf("Sum of even number is %d\n", sumEven);
    }
 
    else {
        for (i = 0; i < 10; i++) {
            if (a[i] % 2 != 0) sumOdd = sumOdd + a[i];
        }

        printf("Parent process\n");
        printf("Sum of odd number is %d\n", sumOdd);
    }
    return 0;
}