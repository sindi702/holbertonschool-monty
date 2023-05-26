#include "monty.h"


int main(int argc,char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
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
	{
		fprintf(stderr, "ERROR: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while(fgets(line, bufferLength, filePointer))
	{
		if (strcmp(line,"\n") == 0)
			lineCounter++;
		lineCounter++;
		j = 0;
		p = strtok(line, " ");
		while (p != NULL)
		{
			strarray[j] = p;
			p = strtok(NULL, " ");
			j++;
		}
		if (strcmp(strarray[0], "push") == 0)
		{
			if (isdigit(atoi(strarray[1])) < 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n", lineCounter);
				exit(EXIT_FAILURE);
			}
			else
				data = atoi(strarray[1]);
		}
		function_ptr p_func = NULL;
		p_func = get_op(strarray[0], lineCounter);
		p_func(&head, lineCounter);
	}   
	fclose(filePointer);
	return (0);
}
