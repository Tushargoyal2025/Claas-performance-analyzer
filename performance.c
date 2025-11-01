#include <stdio.h>

// Function to find total and average
void calculate(int m1, int m2, int m3, int *total, float *avg) {
    *total = m1 + m2 + m3;
    *avg = *total / 3.0;
}

// Function to return performance remark
char* performance(float avg) {
    if (avg >= 90)
        return "Genius";
    else if (avg >= 75)
        return "Excellent";
    else if (avg >= 50)
        return "Good";
    else if (avg >= 35)
        return "Barely Passed";
    else
        return "Try Again";
}

int main() {
    int n, i;
    int marks[3], total;
    float avg, classAvg = 0;

    printf("Welcome to the Funny Class Report!\n");
    printf("Enter number of students (max 8): ");
    scanf("%d", &n);

    if (n <= 0 || n > 8) {
        printf("Invalid number of students!\n");
        return 0;
    }

    printf("\n===== Class Performance Report =====\n");
    printf("Student\tTotal\tAverage\tPerformance\n");

    for (i = 1; i <= n; i++) {
        printf("\nEnter marks of Student %d (3 subjects):\n", i);
        for (int j = 0; j < 3; j++) {  // indexes start from 0
            printf("Enter marks of subject %d: ", j + 1);
            scanf("%d", &marks[j]);
        }

        calculate(marks[0], marks[1], marks[2], &total, &avg);
        printf("Student - %d\tTotal - %d\tAverage - %.2f\tPerformance - %s\n", i, total, avg, performance(avg));

        classAvg += avg;
    }

    classAvg /= n;
    printf("\nOverall Class Average: %.2f\n", classAvg);

    if (classAvg >= 90)
        printf("Class Performance: Genius!\n");
    else if (classAvg >= 75)
        printf("Class Performance: Excellent!\n");
    else if (classAvg >= 50)
        printf("Class Performance: Good!\n");
    else if (classAvg >= 35)
        printf("Class Performance: Barely Passed!\n");
    else
        printf("Class Performance: Try Again!\n");

    printf("\nThanks for using this silly grading app!\n");
    return 0;
}
