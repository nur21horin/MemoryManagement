#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(25);
    
    // Populate the array
    for (int i = 0; i < 8; i++)
        ptr[i] = i + 2;
        
    // Print the array
    for (int i = 0; i < 8; i++)
        printf("%d ", ptr[i]);
    return 0;
}