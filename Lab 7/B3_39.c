#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n][2];
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    
    // Sort by start time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j][0] > arr[j + 1][0]) {
                int t1 = arr[j][0], t2 = arr[j][1];
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][0] = t1;
                arr[j + 1][1] = t2;
            }
        }
    }
    
    // Merge overlapping intervals
    printf("{%d, %d}", arr[0][0], arr[0][1]);
    int end = arr[0][1];
    
    for (int i = 1; i < n; i++) {
        if (arr[i][0] <= end) {
            if (arr[i][1] > end)
                end = arr[i][1];
        } else {
            printf(", {%d, %d}", arr[i][0], arr[i][1]);
            end = arr[i][1];
        }
    }
    
    printf("\n");
    return 0;
}
