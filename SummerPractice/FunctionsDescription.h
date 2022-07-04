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
	char* LakeName[20];
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
* Clear stdin
* @param none
* @return none
*/
int clear_stdin();

#endif
