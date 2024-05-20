#include <stdio.h>

// Function to move a disk from source pole to destination pole
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary pole using destination as the auxiliary pole
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination pole
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move the n-1 disks from auxiliary pole to destination pole using source as the auxiliary pole
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Tower of Hanoi solution for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C'); // A, B, and C are the names of the three poles

    return 0;
}

