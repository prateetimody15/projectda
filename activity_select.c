#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
typedef struct {
    int start;
    int finish;
} Activity;

// Function to compare activities by their finish time
int compare(const void *a, const void *b) {
    return ((Activity*)a)->finish - ((Activity*)b)->finish;
}

// Function to perform activity selection
void activitySelection(Activity activities[], int n) {
    // Sort activities based on their finish time
    qsort(activities, n, sizeof(Activity), compare);

    printf("The following activities are selected:\n");

    // The first activity is always selected
    int i = 0;
    printf("(%d, %d) ", activities[i].start, activities[i].finish);

    // Consider rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected activity,
        // then select it
        if (activities[j].start >= activities[i].finish) {
            printf("(%d, %d) ", activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Dynamically allocate memory for activities
    Activity *activities = (Activity*)malloc(n * sizeof(Activity));

    printf("Enter the start and finish times of each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Perform activity selection
    activitySelection(activities, n);

    // Free dynamically allocated memory
    free(activities);

    return 0;
}
