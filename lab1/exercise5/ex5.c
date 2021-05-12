#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 32

int readLine(FILE *f, char buffer[]);

int main()
{
	FILE *f;
	unsigned int line;
    float in_value, sum;
	char buffer [BUFFER_SIZE];
	char command [4];

	line = 0;
    sum = 0;

	printf("Welcome to basic COM4521 calculator\nEnter command: ");
	f = fopen("commands.calc", "r");
	if (f == NULL){
		fprintf(stderr, "File not found\n");
		return;
	}


    while (readLine(f, buffer)){
		line++;
  
		// Check that the line contains 3 letters and a spaceextract
		if (!(isalpha(buffer[0]) &&  isalpha(buffer[1]) && isalpha(buffer[2]) && buffer[3]==' ')) {
			fprintf(stderr, "Incorrect command format at line %u\n", line);
			continue;
		}

		// Extract the command and in_value using sscanf
		sscanf(buffer, "%s %f", command, &in_value);

		// Check command to see if it is "add"
		if (strcmp(command, "add")==0) {
			sum += in_value;
		} else if (strcmp(command, "sub")==0) {
			sum -= in_value;
		} else if (strcmp(command, "div")==0) {
			sum /= in_value;
		} else if (strcmp(command, "mul")==0) {
			sum *= in_value;
		} else {
			fprintf(stderr, "Unknown command at line %u!\n", line);
			return;
		}
	}

    printf("Final sum is %f\n", sum);
    fclose(f);
    return 0;
}

int readLine(FILE *f, char buffer[]){
	
	int i=0;
	char c=0;

	while ((c = getc(f)) != '\n'){
		// Check end of file
		if (c == EOF)
			return 0;

        // Add character to buffer
		buffer[i++] = c;
		// Check index for overflow
		if (i == BUFFER_SIZE){
			fprintf(stderr, "Buffer size is too small for line input\n");
			exit(0);
		}		
	}

	// Ensure the buffer is correctly terminated
	buffer[i] = '\0';

	// Return 0 if buffer = "exit" otherwise return 1
	if (strncmp(buffer, "exit", 4)==0)
		return 0;
	else
		return 1;	
}
