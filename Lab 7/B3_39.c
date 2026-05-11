#include <stdio.h>

void main() {

    int number_of_Intervals;

    printf("Enter the number of intervals: ");
    scanf("%d", &number_of_Intervals);

    int intervals[number_of_Intervals][2];

    for(int i = 0; i < number_of_Intervals; i++) {
        printf("Enter the start and end of interval %d: ", i + 1);
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    // SORTING
    for(int i = 0; i < number_of_Intervals - 1; i++) {
        for(int j = 0; j < number_of_Intervals - i - 1; j++) {

            if(intervals[j][0] > intervals[j + 1][0]) {

                int temp1 = intervals[j][0];
                int temp2 = intervals[j][1];

                intervals[j][0] = intervals[j + 1][0];
                intervals[j][1] = intervals[j + 1][1];

                intervals[j + 1][0] = temp1;
                intervals[j + 1][1] = temp2;
            }
        }
    }

    printf("Intervals before merging:\n");

    for(int i = 0; i < number_of_Intervals; i++) {
        printf("[%d, %d]\n", intervals[i][0], intervals[i][1]);
    }

    // MERGING
    for(int i = 0; i < number_of_Intervals - 1; i++) {

        if(intervals[i][1] >= intervals[i + 1][0]) {

            // keep maximum ending value
            if(intervals[i + 1][1] > intervals[i][1]) {
                intervals[i][1] = intervals[i + 1][1];
            }

            // shift left
            for(int j = i + 1; j < number_of_Intervals - 1; j++) {
                intervals[j][0] = intervals[j + 1][0];
                intervals[j][1] = intervals[j + 1][1];
            }

            number_of_Intervals--;
            i--;
        }
    }

    printf("Intervals after merging:\n");

    for(int i = 0; i < number_of_Intervals; i++) {
        printf("[%d, %d]\n", intervals[i][0], intervals[i][1]);
    }
}