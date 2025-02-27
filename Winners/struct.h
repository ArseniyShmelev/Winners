#pragma once
#include <stdio.h>

#define MAX_NAME 50
#define MAX_REGION 50
#define MAX_SUBJECT 50
#define MAX_LENGTH 50

typedef struct {
	char full_name[MAX_NAME];
	int school_number;
	char region[MAX_REGION];
	char subject[MAX_SUBJECT];
	int year;
} Winner;

void add_record(FILE* file);
void delete_record(FILE* file);
void search_record(FILE* file);
void edit_record(FILE* file, int index);
void print_records(FILE* file);
void print_prefilled_array(FILE* file);

