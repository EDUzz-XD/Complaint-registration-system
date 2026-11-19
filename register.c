#include <stdio.h>

/* function to clear input buffer */
void clear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* function to take string input */
void getString(char str[], int size) {
    int i = 0, c;
    while (i < size - 1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        str[i++] = (char)c;
    }
    str[i] = '\0';
}

/* 1. Register Complaint */
int input(int sNo[], char names[][100], char desc[][500], int count) {
    printf("\n--- Register Complaint ---\n");

    if (count >= 100) {
        printf("Error: List is full!\n");
        return count;
    }

    sNo[count] = count + 1;
    printf("Assigned S.No: %d\n", sNo[count]);

    printf("Enter Name: ");
    getString(names[count], 100);

    printf("Enter Description: ");
    getString(desc[count], 500);

    count++;
    printf("Complaint registered successfully!\n");
    return count;
}

/* 2. View All Complaints */
void display(int sNo[], char names[][100], char desc[][500], int count) {
    int i;
    printf("\n--- All Complaints ---\n");

    if (count == 0) {
        printf("No complaints registered yet.\n");
        return;
    }

    printf("%-6s | %-20s | %-40s\n", "S.No", "Name", "Description");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-6d | %-20s | %-40s\n", sNo[i], names[i], desc[i]);
    }

    printf("Total: %d\n", count);
}

/* 3. Search Complaint by S.No */
void search(int sNo[], char names[][100], char desc[][500], int count) {
    int searchNo, found = 0, i;

    printf("\n--- Search Complaint ---\n");

    if (count == 0) {
        printf("No complaints to search.\n");
        return;
    }

    printf("Enter S.No to search: ");
    if (scanf("%d", &searchNo) != 1) {
        printf("Invalid input!\n");
        clear();
        return;
    }
    clear();

    for (i = 0; i < count; i++) {
        if (sNo[i] == searchNo) {
            printf("\nComplaint Found:\n");
            printf("S.No        : %d\n", sNo[i]);
            printf("Name        : %s\n", names[i]);
            printf("Description : %s\n", desc[i]);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Complaint with S.No %d not found.\n", searchNo);
    }
}

int main() {
    int sNo[100];
    char names[100][100];
    char desc[100][500];
    int count = 0, choice;

    while (1) {
        printf("\n=== COMPLAINT SYSTEM ===\n");
        printf("1. Register Complaint\n");
        printf("2. View Complaints\n");
        printf("3. Search by S.No\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Try again.\n");
            clear();
            continue;
        }
        clear();

        switch (choice) {
            case 1:
                count = input(sNo, names, desc, count);
                break;
            case 2:
                display(sNo, names, desc, count);
                break;
            case 3:
                search(sNo, names, desc, count);
                break;
            case 4:
                printf("Exiting... Bye!\n");
                return 0;
            default:
                printf("Invalid choice! Enter 1-4.\n");
        }
    }

    return 0;
}
