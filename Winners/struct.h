#pragma once
#ifndef DATABASE_H
#define DATABASE_H

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

void add_record(const char* filename);
void delete_record(const char* filename);
void search_record(const char* filename);
void edit_record(const char* filename, int index);
void print_records(const char* filename);

#endif 
