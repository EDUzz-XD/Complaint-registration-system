#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------
   Complaint Registration System
   - No #define used
   - Uses parallel arrays (no struct, no enum)
   - Functionalities:
       1. Register Complaint (Name + Description)
       2. View All Complaints
       3. Search Complaint by S.No.
------------------------------------------------------- */

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Functionality 1: Register a new complaint */
void registerComplaint(int sNo[], char names[][100], char desc[][500], int *count) {

    printf("\n=========================================\n");
    printf("         REGISTER NEW COMPLAINT          \n");
    printf("=========================================\n");

    if (*count >= 100) {
        printf("Error: Maximum complaints (100) reached!\n");
        return;
    }

    sNo[*count] = *count + 1;
    printf("S.No Assigned: %d\n", sNo[*count]);

    printf("Enter Complainant Name    : ");
    fgets(names[*count], 100, stdin);
    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("Enter Complaint Description: ");
    fgets(desc[*count], 500, stdin);
    desc[*count][strcspn(desc[*count], "\n")] = '\0';

    (*count)++;

    printf("\n--> Complaint registered successfully! <--\n");
}

/* Functionality 2: View all complaints */
void viewAllComplaints(int sNo[], char names[][100], char desc[][500], int count) {
    int i;

    printf("\n========================================================================================\n");
    printf("                              ALL REGISTERED COMPLAINTS                                 \n");
    printf("========================================================================================\n");

    if (count == 0) {
        printf("No complaints registered yet.\n");
        printf("========================================================================================\n");
        return;
    }

    printf("%-6s | %-25s | %-46s\n", "S.No", "Complainant Name", "Description");
    printf("----------------------------------------------------------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("%-6d | %-25s | %-46s\n", sNo[i], names[i], desc[i]);
    }
    printf("========================================================================================\n");
    printf("Total Complaints: %d\n", count);
}

/* Functionality 3: Search complaint by S.No. */
void searchBySNo(int sNo[], char names[][100], char desc[][500], int count) {
    int searchNo, found, i;

    printf("\n=========================================\n");
    printf("       SEARCH COMPLAINT BY S.NO          \n");
    printf("=========================================\n");

    if (count == 0) {
        printf("No complaints registered yet.\n");
        return;
    }

    printf("Enter S.No to search: ");
    if (scanf("%d", &searchNo) != 1) {
        printf("Invalid input! Please enter a valid number.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    found = 0;
    for (i = 0; i < count; i++) {
        if (sNo[i] == searchNo) {
            printf("\n--- Complaint Found ---\n");
            printf("S.No        : %d\n", sNo[i]);
            printf("Name        : %s\n", names[i]);
            printf("Description : %s\n", desc[i]);
            printf("-----------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Complaint with S.No %d not found!\n", searchNo);
    }
}

int main(void) {
    int sNo[100];
    char names[100][100];
    char desc[100][500];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=========================================\n");
        printf("      COMPLAINT REGISTRATION SYSTEM      \n");
        printf("=========================================\n");
        printf("  1. Register Complaint\n");
        printf("  2. View All Complaints\n");
        printf("  3. Search Complaint by S.No.\n");
        printf("  4. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Enter a number from 1 to 4.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                registerComplaint(sNo, names, desc, &count);
                break;
            case 2:
                viewAllComplaints(sNo, names, desc, count);
                break;
            case 3:
                searchBySNo(sNo, names, desc, count);
                break;
            case 4:
                printf("\nExiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1 to 4.\n");
        }
    }

    return 0;
}
