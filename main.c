#include "monty.h"


int main(int argc,char *argv[])
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack_t *head = NULL;
	FILE* filePointer;
	char line[255];
	int j = 0, lineCounter = 0, bufferLength = 255;
	char *p = NULL;
	char *strarray[50];

	data++;
	filePointer = fopen(argv[1], "r");
	if (filePointer == NULL)
		exit(EXIT_FAILURE);
	while(fgets(line, bufferLength, filePointer))
	{
		j = 0;
		p = strtok(line, " ");
		while (p != NULL)
		{
			strarray[j] = p;
			p = strtok(NULL, " ");
			j++;
		}
		lineCounter++;
		if (strcmp(strarray[0], "push") == 0)
			data = atoi(strarray[1]);
		function_ptr p_func = NULL;
		p_func = get_op(strarray[0], lineCounter);
		p_func(&head, lineCounter);
	}   
	fclose(filePointer);
	return (0);
}
