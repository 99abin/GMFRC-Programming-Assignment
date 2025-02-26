#include <stdio.h>
#include <math.h>

// Function to update the values of a and b
void update(int *a, int *b) {
    int temp_a = *a; // Store the original value of a in a temporary variable
    *a = *a + *b;    // Update a to be the sum of a and b
    *b = abs(temp_a - *b); // Update b to be the absolute difference between the original a and b
}

int main() {
    int a, b; // Declare two integer variables
    int *pa = &a, *pb = &b; // Create pointers to a and b

    // Read two integers from standard input
    scanf("%d %d", &a, &b);
    // Call the update function, passing the addresses of a and b
    update(pa, pb);
    // Print the updated values of a and b
    printf("%d\n%d", a, b);

    return 0; // Return 0 to indicate successful execution
}
