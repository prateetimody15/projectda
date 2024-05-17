#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
typedef struct {
    char name;
    int deadline;
    int profit;
} Job;

// Function to compare jobs by their profit (descending order)
int compare(const void *a, const void *b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Function to perform job sequencing
void jobSequencing(Job jobs[], int n) {
    // Sort jobs based on their profit (in descending order)
    qsort(jobs, n, sizeof(Job), compare);

    // Find the maximum deadline among all jobs
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Array to store the sequence of selected jobs
    char sequence[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        sequence[i] = '\0';

    // Array to keep track of the occupied slots in sequence
    int slots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        slots[i] = 0;

    // Assign jobs to slots in sequence
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == 0) {
                sequence[j] = jobs[i].name;
                slots[j] = 1;
                break;
            }
        }
    }

    printf("The sequence of selected jobs is: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (sequence[i] != '\0')
            printf("%c ", sequence[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Dynamically allocate memory for jobs
    Job *jobs = (Job*)malloc(n * sizeof(Job));

    printf("Enter the name, deadline, and profit of each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].name, &jobs[i].deadline, &jobs[i].profit);
    }

    // Perform job sequencing
    jobSequencing(jobs, n);

    // Free dynamically allocated memory
    free(jobs);

    return 0;
}
