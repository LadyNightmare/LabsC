#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

/**
 * ask SIZE to the user, and create a binary file with random SIZE unsigned values.
 * Use srand(time(NULL)) at the beginning, and use rand()%SIZE to create a random number between 0
 * and SIZE-1
 */
void createFile(char* filename)
{


}
/**
 * Show the contents of the file in the screen (the list of unsigned values stored in the file)
 */
void showFile(char* filename)
{

}

/**
 * Store in the tree the values read from the file)
 */

void loadFile(char* filename, TTree* tree)
{

}

int main(void) {
	char fname[50];
	printf ("Enter the file name:\n");
	fflush(stdout);
	scanf ("%s",fname);
	fflush(stdin);
	createFile(fname);
	printf("\n Now, we read its contents and show them\n");
	showFile(fname);
	fflush(stdout);

	printf ("\n Now, we load the contents in the tree\n");
	TTree mytree;
	create (&mytree);
	loadFile(fname,&mytree);
	printf ("\n Now we show the ordered values in the tree\n");
	show(mytree);
	fflush(stdout);
	printf("\n Now we write the ordered values\n");
	FILE * fd;
	fd = fopen (fname, "wb");
	save(mytree, fd);
	fclose (fd);
	printf("\n Finally, we show the ordered values in the file\n");
	showFile(fname);
	destroy (&mytree);

	return EXIT_SUCCESS;
}
