#include "struct.h"
#include <stdio.h>
#include <stdlib.h> 

#define FILE_NAME  "winners.bin"

int main() {
    FILE* file = fopen(FILE_NAME, "wb+");
    if (!file) {
        printf("Error opening file!");
        fclose(file);
        return;
    }
    int choice, index;

    do {
        printf("\nMenu:\n");
        printf("1. Add record\n");
        printf("2. Print records\n");
        printf("3. Delete record\n");
        printf("4. Search record\n");
        printf("5. Edit record\n");
        printf("6. Fill table with prefilled massive\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            add_record(file);
            break;
        case 2:
            print_records(file);
            break;
        case 3:
            delete_record(file);
            break;
        case 4:
            search_record(file);
            break;
        case 5:
            printf("Enter record index to edit: ");
            scanf_s("%d", &index);
            getchar();
            edit_record(file, index);
            break;
        case 6:
            print_prefilled_array(file);
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Incorrect choice. Try again.\n");
        }
    } while (choice != 7);

    fclose(file);

    return 0;
}