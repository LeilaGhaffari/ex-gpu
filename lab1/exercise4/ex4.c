#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 32

int readLine(char buffer[]);

int main()
{
    float in_value, sum;
	char buffer [BUFFER_SIZE];
	char command [4];
    sum = 0;

	printf("Welcome to basic COM4521 calculator\nEnter command: ");

    while (readLine(buffer)){
  
		//4.5 Check that the line contains 3 letters and a spaceextract
		if (!(isalpha(buffer[0]) &&  isalpha(buffer[1]) && isalpha(buffer[2]) && buffer[3]==' ')) {
			fprintf(stderr, "Incorrect command format\n");
			continue;
		}

		//4.6 Extract the command and in_value using sscanf
		sscanf(buffer, "%s %f", command, &in_value);

		// 4.7-8 Check command to see if it is "add"
		if (strcmp(command, "add")==0) {
			sum += in_value;
		} else if (strcmp(command, "sub")==0) {
			sum -= in_value;
		} else if (strcmp(command, "div")==0) {
			sum /= in_value;
		} else if (strcmp(command, "mul")==0) {
			sum *= in_value;
		} else {
			printf("Unknown command\n");
		}

		printf("\tSum is %f\n", sum);
		printf("Enter next command: ");
	}

    return 0;
}

int readLine(char buffer[]){
	
	int i=0;
	char c=0;

	while ((c = getchar()) != '\n'){
        //4.1 Add character to buffer
		buffer[i++] = c;
		//4.2 Check index for overflow
		if (i == BUFFER_SIZE){
			fprintf(stderr, "Buffer size is too small for line input\n");
			exit(0);
		}		
	}

	//4.3 Ensure the buffer is correctly terminated
	buffer[i] = '\0';

	//4.4 Return 0 if buffer = "exit" otherwise return 1
	if (strncmp(buffer, "exit", 4)==0)
		return 0;
	else
		return 1;	
}
