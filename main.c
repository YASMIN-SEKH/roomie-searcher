#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100  //pre-processor used to allocate memory for struct
#define MAX_ROOMMATES 3

struct Student {
    char name[50];
    int earlyBird;
    int lightsOff;
    int socialize;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int totalStudents, i, j;
    int selected[MAX_STUDENTS] = {0};

    printf("Enter the total number of students applying: ");
    scanf("%d", &totalStudents);

    if (totalStudents <= 0 || totalStudents > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (i = 0; i < totalStudents; ++i) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Are you an early bird or night owl? (Enter 1 for early bird, 2 for night owl): ");
        scanf("%d", &students[i].earlyBird);

        printf("Do you prefer lights on or off during the night? (Enter 1 for on, 2 for off): ");
        scanf("%d", &students[i].lightsOff);

        printf("Do you like to socialize or stay alone in the room? (Enter 1 for stay alone, 2 for socialize): ");
        scanf("%d", &students[i].socialize);
    }

    printf("\nRoommate selection:\n");

    for (i = 0; i < totalStudents; ++i) {
        if (selected[i] == 0) {
            printf("\nRoommates for %s:\n", students[i].name);
            int roommateCount = 0; // Moved initialization here
            int bestMatch = -1;
            int maxMatches = 0;

            for (j = i + 1; j < totalStudents; ++j) {
                if (selected[j] == 0 && roommateCount < MAX_ROOMMATES) {
                    int match = 0;

                    if (students[i].earlyBird == students[j].earlyBird)
                        match++;
                    if (students[i].lightsOff == students[j].lightsOff)
                        match++;
                    if (students[i].socialize == students[j].socialize)
                        match++;

                    if (match > maxMatches) {
                        maxMatches = match;
                        bestMatch = j;
                    }
                }
            }

            if (bestMatch != -1) {
                printf("%s\n", students[bestMatch].name);
                selected[bestMatch] = 1;
                roommateCount++;

                if (roommateCount == MAX_ROOMMATES)
                    selected[i] = 1; // Mark the current student as selected
            }

            if (roommateCount == 0)
                printf("No roommates found for %s\n", students[i].name);
        }
    }

    return 0;
}
