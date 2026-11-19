#include <stdio.h>

/* Function to clear leftover characters from the input buffer */
void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Function to read a line of text into a character array */
void readLine(char str[], int size) {
    int i = 0, c;
    while (i < size - 1) {
        c = getchar();
        if (c == '\n' || c == EOF) break;
        str[i++] = (char)c;
    }
    str[i] = '\0';
}

/* Functionality 1: Register Complaint (Name, Description) */
int registerComplaint(int sNo[], char names[][100], char desc[][500], int count) {
    printf("\n=========================================\n");
    printf("         REGISTER NEW COMPLAINT          \n");
    printf("=========================================\n");

    if (count >= 100) {
        printf("Error: Maximum complaint limit (100) reached!\n");
        return count;
    }

    sNo[count] = count + 1;
    printf("Assigned S.No: %d\n", sNo[count]);

    printf("Enter Complainant Name    : ");
    readLine(names[count], 100);

    printf("Enter Complaint Description: ");
    readLine(desc[count], 500);

    count++;
    printf("\n--> Complaint successfully registered! <--\n");
    return count;
}

/* Functionality 2: View All Complaints */
void viewAllComplaints(int sNo[], char names[][100], char desc[][500], int count) {
    int i;
    printf("\n========================================================================================\n");
    printf("                                  LIST OF ALL COMPLAINTS                                \n");
    printf("========================================================================================\n");

    if (count == 0) {
        printf("No complaints registered yet.\n");
        printf("========================================================================================\n");
        return;
    }

    printf("%-6s | %-25s | %-50s\n", "S.No", "Complainant Name", "Description");
    printf("----------------------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-6d | %-25s | %-50s\n", sNo[i], names[i], desc[i]);
    }

    printf("========================================================================================\n");
    printf("Total Complaints: %d\n", count);
}

/* Functionality 3: Search Complaint by S.No. */
void searchComplaintBySNo(int sNo[], char names[][100], char desc[][500], int count) {
    int searchNo, found = 0, i;

    printf("\n=========================================\n");
    printf("         SEARCH COMPLAINT BY S.NO        \n");
    printf("=========================================\n");

    if (count == 0) {
        printf("No complaints registered yet to search.\n");
        return;
    }

    printf("Enter S.No to search: ");
    if (scanf("%d", &searchNo) != 1) {
        printf("Invalid input! Please enter a numerical S.No.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    for (i = 0; i < count; i++) {
        if (sNo[i] == searchNo) {
            printf("\n--- Complaint Found ---\n");
            printf("S.No        : %d\n", sNo[i]);
            printf("Name        : %s\n", names[i]);
            printf("Description : %s\n", desc[i]);
            printf("------------------------\n");
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nComplaint with S.No %d was not found!\n", searchNo);
    }
}

int main(void) {
    int sNo[100];
    char names[100][100];
    char desc[100][500];
    int count = 0, choice;

    while (1) {
        printf("\n=========================================\n");
        printf("      COMPLAINT REGISTRATION SYSTEM      \n");
        printf("=========================================\n");
        printf("1. Register Complaint\n");
        printf("2. View All Complaints\n");
        printf("3. Search Complaint by S.No.\n");
        printf("4. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number (1-4).\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                count = registerComplaint(sNo, names, desc, count);
                break;
            case 2:
                viewAllComplaints(sNo, names, desc, count);
                break;
            case 3:
                searchComplaintBySNo(sNo, names, desc, count);
                break;
            case 4:
                printf("\nExiting Complaint Registration System. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select an option between 1 and 4.\n");
        }
    }

    return 0;
}
