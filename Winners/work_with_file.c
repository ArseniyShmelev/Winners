#define _CRT_SECURE_NO_WARNINGS
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>


void delete_record(const char* filename)
{
	FILE* file = fopen(filename, "rb+");
	if (!file) {
		printf("opening error\n");
		return;
	}
	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	int total_records = file_size / sizeof(Winner);

	if (total_records == 0) {
		printf("No records to delete.\n");
		fclose(file);
		return;
	}

	int index;
	do {
		printf("Enter a number to delete from 1 to %d: ", total_records);
		if (scanf_s("%d", &index) != 1) {
			printf("Incorrect number, enter a correct number.");
			while (getchar() != '\n');
			continue;
		}

		if (index < 1 || index > total_records) {
			printf("Invalid index! Please enter a number between 1 and %d.\n", total_records);
		}
	} while (index < 1 || index > total_records);


	if (index == total_records) {
		int fd = _fileno(file);  // Получаем файловый дескриптор
		_chsize_s(fd, (total_records - 1) * sizeof(Winner));  // Обрезаем файл
		fclose(file);
		printf("Last record deleted successfully!\n");
		return;
	}

	Winner last_record;
	fseek(file, (total_records - 1) * sizeof(Winner), SEEK_SET);
	fread(&last_record, sizeof(Winner), 1, file);

	fseek(file, (index - 1) * sizeof(Winner), SEEK_SET);
	fwrite(&last_record, sizeof(Winner), 1, file);

	int fd = _fileno(file);
	_chsize_s(fd, (total_records - 1) * sizeof(Winner));

	fclose(file);
	printf("Record deleted\n");
}

void search_record(const char* filename) {
	FILE* file = fopen(filename, "rb");
	if (!file) {
		printf("open error\n");
		return;
	}

	int choice;
	printf("Search by:\n");
	printf("1. Full Name\n");
	printf("2. School Number\n");
	printf("3. Region\n");
	printf("4. Subject\n");
	printf("5. Year of Participation\n");
	printf("Enter your choice (1-5): ");
	scanf_s("%d", &choice);
	while (getchar() != '\n');

	char search_name[MAX_LENGTH];
	int search_number;

	switch (choice) {
	case 1:
		printf("Enter full name: ");
		fgets(search_name, MAX_LENGTH, stdin);
		search_name[strcspn(search_name, "\n")] = '\0'; // Убираем \n
		break;
	case 2:
		printf("Enter school number: ");
		scanf("%d", &search_number);
		break;
	case 3:
		printf("Enter region: ");
		fgets(search_name, MAX_LENGTH, stdin);
		search_name[strcspn(search_name, "\n")] = '\0';
		break;
	case 4:
		printf("Enter subject: ");
		fgets(search_name, MAX_LENGTH, stdin);
		search_name[strcspn(search_name, "\n")] = '\0';
		break;
	case 5:
		printf("Enter year of participation: ");
		scanf_s("%d", &search_number);
		break;
	default:
		printf("Invalid choice!\n");
		fclose(file);
		return;
	}

	Winner winner;
	int found = 0;
	while (fread(&winner, sizeof(Winner), 1, file)) {
		if ((choice == 1 && strcmp(winner.full_name, search_name) == 0) ||
			(choice == 2 && winner.school_number == search_number) ||
			(choice == 3 && strcmp(winner.region, search_name) == 0) ||
			(choice == 4 && strcmp(winner.subject, search_name) == 0) ||
			(choice == 5 && winner.year == search_number)) {

			printf("\nRecord Found:\n");
			printf("Full Name: %s\n", winner.full_name);
			printf("School Number: %d\n", winner.school_number);
			printf("Region: %s\n", winner.region);
			printf("Subject: %s\n", winner.subject);
			printf("Year: %d\n", winner.year);
			found = 1;
		}

		if (!found) {
			printf("No matching records found.\n");
		}

		fclose(file);
	}
}
	void edit_record(const char* filename, int index){ 
		FILE* file = fopen(filename, "rb+");
		if (!file) {
			printf("Error opening file!\n");
			return;
		}

		fseek(file, index * sizeof(Winner), SEEK_SET);
		Winner winner;
		printf("Enter new full name: ");
		fgets(winner.full_name, MAX_NAME, stdin);
		strtok(winner.full_name, "\n");
		printf("Enter new school number: ");
		scanf_s("%d", &winner.school_number);
		getchar();
		printf("Enter new region: ");
		fgets(winner.region, MAX_REGION, stdin);
		strtok(winner.region, "\n");
		printf("Enter new subject: ");
		fgets(winner.subject, MAX_SUBJECT, stdin);
		strtok(winner.subject, "\n");
		printf("Enter new year: ");
		scanf_s("%d", &winner.year);
		getchar();

		fwrite(&winner, sizeof(Winner), 1, file);
		fclose(file);
		printf("Record edited\n");
	}
	
	
