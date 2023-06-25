#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, totalDistance = 0;
    int lb, ub;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the head: ");
    scanf("%d", &head);
    printf("Enter the lower boundary of the disk: ");
    scanf("%d", &lb);
    printf("Enter the upper boundary of the disk: ");
    scanf("%d", &ub);
    int direction;
    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);
    int i, current;
    if (direction == 0) {
        printf("Sequence of movement: %d", head);
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (requests[j] > requests[j+1]) {
                    int temp = requests[j];
                    requests[j] = requests[j+1];
                    requests[j+1] = temp;
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (requests[i] >= head) {
                break;
            }
        }
        for (int j = i - 1; j >= 0; j--) {
            current = requests[j];
            printf(" -> %d", current);
            totalDistance += abs(current - head);
            head = current;
        }
        printf(" -> %d", lb);
        totalDistance += abs(lb - head);
        head = lb;
        for (int j = i; j < n; j++) {
            current = requests[j];
            printf(" -> %d", current);
            totalDistance += abs(current - head);
            head = current;
        }
    }
    else {
        printf("Sequence of movement: %d", head);
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (requests[j] > requests[j+1]) {
                    int temp = requests[j];
                    requests[j] = requests[j+1];
                    requests[j+1] = temp;
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (requests[i] > head) {
                break;
            }
        }
        for (int j = i; j < n; j++) {
            current = requests[j];
            printf(" -> %d", current);
            totalDistance += abs(current - head);
            head = current;
        }
        printf(" -> %d", ub);
        totalDistance += abs(ub - head);
        head = ub;
        for (int j = i - 1; j >= 0; j--) {
            current = requests[j];
            printf(" -> %d", current);
            totalDistance += abs(current - head);
            head = current;
        }
    }
    printf("\nTotal Head Movements: %d\n", totalDistance);
    return 0;
}