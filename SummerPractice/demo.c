#include "FunctionsDescription.h"

int main(int argc, char* argv[]) {

	node_lake* node;
	node = NULL;

	char file[] = "lakes.txt";

	char LakeName[20];
	char LakeCountry[30];
	int LakeDepth;
	float Salinity;
	bool CorrectInput;


	for (int i = 1; i < 13; i++) {

		CorrectInput = false;
		while (!CorrectInput)
		{
			printf("Enter lake name: ");
			fgets(LakeName, 20, stdin);

			// Input validation
			if (LakeName[0] == '\n' || LakeName[0] == '\0')
				CorrectInput = false;
			else
				CorrectInput = true;

			if (LakeName[strlen(LakeName) - 1] == '\n')
				LakeName[strlen(LakeName) - 1] = '\0';
			else getchar();

			if (!CorrectInput)
			{
				printf("It looks like you made a mistake when filling out this field\n\n");
			}
		}

		CorrectInput = false;
		while (!CorrectInput)
		{
			printf("Location country: ");
			fgets(LakeCountry, 30, stdin);

			// Input validation
			if (LakeCountry[0] == '\n' || LakeCountry[0] == '\0')
				CorrectInput = false;
			else
				CorrectInput = true;

			if (LakeCountry[strlen(LakeCountry) - 1] == '\n')
				LakeCountry[strlen(LakeCountry) - 1] = '\0';
			else
				getchar();

			if (!CorrectInput)
			{
				printf("It looks like you made a mistake when filling out this field\n\n");
			}
		}

		CorrectInput = false;
		while (!CorrectInput)
		{
			printf("Depth: ");
			// Input validation
			if (scanf("%d", &LakeDepth) == 1 && LakeDepth > 0)
				CorrectInput = true;

			if (!CorrectInput)
			{
				printf("It looks like you made a mistake when filling out this field\n\n");
			}

			clear_stdin();
		}

		CorrectInput = false;
		while (!CorrectInput)
		{
			printf("Salinity in percent: ");

			// Input validation
			if (scanf("%f", &Salinity) == 1 && Salinity >= 0)
				CorrectInput = true;

			if (!CorrectInput)
			{
				printf("It looks like you made a mistake when filling out this field\n\n");
			}

			clear_stdin();
		}

		// Add an entry to the list
		Add_to_list(&node, LakeName, LakeCountry, LakeDepth, Salinity);
		printf("\nRecord number %d added successfully \nPress any key to go to the next entry", i);
		getchar();

	}

	// Filling a text file with the entered information about lakes
	if (Write_data_to_file(&node, file))
		printf("List saved to file %s\n", file);
	else
		printf("An error occurred while saving\n");

	printf("Press any key to continue\n");
	getchar();

	return 0;
}