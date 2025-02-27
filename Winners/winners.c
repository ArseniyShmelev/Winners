#define _CRT_SECURE_NO_WARNINGS
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_record(FILE* file)
{
	Winner winner;

	printf("Enter full name: ");
	fgets(winner.full_name, MAX_NAME, stdin);
	strtok(winner.full_name, "\n");

	printf("Enter school number: ");
	scanf_s("%d", &winner.school_number);
	getchar();

	printf("Enter region: ");
	fgets(winner.region, MAX_REGION, stdin);
	strtok(winner.region, "\n");

	printf("Enter subject: ");
	fgets(winner.subject, MAX_SUBJECT, stdin);
	strtok(winner.subject, "\n");

	printf("Enter year: ");
	scanf_s("%d", &winner.year);
	getchar();


	fwrite(&winner, sizeof(Winner), 1, file);
	printf("Record added!");
}

void print_records(FILE* file) {
	if (!file) {
		printf("Error opening file!\n");
		return;
	}

	fseek(file, 0, SEEK_SET);
	Winner winner;
	printf("%-30s %-10s %-20s %-15s %-5s\n", "Full Name", "School", "Region", "Subject", "Year");
	printf("-------------------------------------------------------------------------------\n");
	while (fread(&winner, sizeof(Winner), 1, file)) {
		printf("%-30s %-10d %-20s %-15s %-5d\n", winner.full_name, winner.school_number, winner.region, winner.subject, winner.year);
	}
}

Winner arr[] = { {"Adam", 1, "Tver", "Math", 1}};

void print_prefilled_array(FILE* file) {
	for (int i = 0; i < (sizeof(arr) / sizeof(Winner)); ++i) {
		fwrite(&arr[i], sizeof(Winner), 1, file);
	}
}