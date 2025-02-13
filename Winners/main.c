#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME  "winners.bin"

int main() {
    FILE* file = fopen(FILE_NAME, "wb");
    fclose(file);
    int choice, index;

    do {
        printf("\nMenu:\n");
        printf("1. Add record\n");
        printf("2. Print records\n");
        printf("3. Delete record\n");
        printf("4. Search record\n");
        printf("5. Edit record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            add_record(FILE_NAME);
            break;
        case 2:
            print_records(FILE_NAME);
            break;
        case 3:
            printf("Enter record index to delete: ");
            scanf_s("%d", &index);
            getchar();
            delete_record(FILE_NAME);
            break;
        case 4:
            search_record(FILE_NAME);
            break;
        case 5:
            printf("Enter record index to edit: ");
            scanf_s("%d", &index);
            getchar();
            edit_record(FILE_NAME, index);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Incorrect choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}