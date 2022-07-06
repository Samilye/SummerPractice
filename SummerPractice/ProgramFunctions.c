#include "FunctionsDescription.h"

// Add information to linked list
void Add_to_list(node_lake** node, const char* LakeName, const char* LakeCountry, int LakeDepth, float Salinity)
{
	int id = 0;
	node_lake* new_node;
	node_lake* indicator;
	// Create the first element of the linked list
	if (*node == NULL)
	{
		new_node = (node_lake*)malloc(sizeof(node_lake));
		// If memory allocation failed
		if (!new_node) {
			printf("Error! Not enough memory");
			exit(1);
		}
		// If the memory is allocated successfully, copy the entered data to the node
		new_node->id = 0;
		strncpy(new_node->LakeName, LakeName, 20);
		strncpy(new_node->LakeCountry, LakeCountry, 30);
		new_node->LakeDepth = LakeDepth;
		new_node->Salinity = Salinity;
		new_node->next = NULL;
		*node = new_node;
		return;
	}

	indicator = *node;
	while (indicator->next)
	{
		indicator = indicator->next;
		id++;
	}


	// Create the following nodes
	new_node = (node_lake*)malloc(sizeof(node_lake));

	if (!new_node) exit(1);

	new_node->id = id + 1;
	strncpy(new_node->LakeName, LakeName, 20);
	strncpy(new_node->LakeCountry, LakeCountry, 30);
	new_node->LakeDepth = LakeDepth;
	new_node->Salinity = Salinity;
	new_node->next = NULL;

	indicator->next = new_node;
}


// Output to the console of all records
void Display_all_records(node_lake** node) {
	node_lake* indicator = *node;

	int i = 0;
	while (indicator)
	{
		printf("\nNumber: %d\nLake name: %s\nCountry: %s\nDepth: %d\nSalinity: %f\n",
			indicator->id, indicator->LakeName, indicator->LakeCountry, indicator->LakeDepth, indicator->Salinity);
		i++;

		indicator = indicator->next;
	}

	if (!i) printf("\nRecords not found\n");
}


// Writing a linked list to a file
bool Write_data_to_file(node_lake** node, const char* file)
{
	FILE* flp;

	if (!(flp = fopen(file, "w")))
		return false;

	node_lake* indicator = *node;
	fprintf(flp, "Lake name Country Depth Salinity\n");
	while (indicator)
	{
		fprintf(flp, "%d   %s   %s  %d  %f\n",
		indicator->id, indicator->LakeName, indicator->LakeCountry, indicator->LakeDepth, indicator->Salinity);
		indicator = indicator->next;
	}
	return true;

}


// Clear stdin
int clear_stdin()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}