#ifndef FUNCTIONSDESCRIPTION_H
#define FUNCTIONSDESCRIPTION_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct node {
	int id;
	char* LakeName[30];
	char* LakeCountry[30];
	int LakeDepth;
	float Salinity;
	struct node* next;
} node_lake;


/**
* Add an entry to the list
*
* @param node Зв'язний список
* @param LakeName Назва озера
* @param LakeCountry Країна розташування
* @param LakeDepth Глибина
* @param Salinity Солоність
*/
void Add_to_list(node_lake** node, const char* LakeName, const char* LakeCountry, int LakeDepth, float Salinity);


/**
* Remove linked list from memory
*
* @param node Зв'язний список
*/
void Delete_list_from_memory(node_lake** node);


/**
* Output to the console of all records
*
* @param node Зв'язний список
*/
void Display_all_records(node_lake** node);


/**
* Display information about lakes less than 50 meters deep and salinity greater than 20%
*
* @param node Зв'язний список
*/
void Display_records_by_characteristics(node_lake** node);


/**
* Write data to file
*
* @param node Зв'язний список
* @param file Ім'я файлу
* @return Успіх операції
*/
bool Write_data_to_file(node_lake** node, const char* file);


/**
* Clear stdin
*
* @param none
* @return none
*/
int clear_stdin();

#endif
