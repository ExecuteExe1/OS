#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Function to add two integers using pointers
void add(int *a, int *b,int *c, int *result) {
    *result = *a + *b + *c; // Perform addition using pointers
}

int main() {
    int num1 = 5, num2 = 10,num3=6;
    int sum;

    // Call the add function
    add(&num1, &num2,&num3, &sum);

    // Print the result
    printf("The sum of %d, %d  and %d is %d\n", num1,num3, num2, sum);

    return 0;
}

