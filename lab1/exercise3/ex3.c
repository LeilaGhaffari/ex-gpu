#include <stdio.h>
#include "random.h"

#define NUM_VALUES 250

long int values[NUM_VALUES];

int main()
{
	float sum = 0;		
	float average = 0;		
	float min = 0;		
	float max = 0;		
    unsigned char i = 0;

    init_random();

    for (i=0; i<NUM_VALUES; i++) 
    {
        values[i] = random_uint();
        sum += values[i];

    }
    
    average = sum/NUM_VALUES;

    for (i=0; i<NUM_VALUES; i++) 
    {
        values[i] -= average;
        sum += values[i];
        min = (values[i]<min) ? values[i] : min;
        max = (values[i]>max) ? values[i] : max;
    }

    printf("\n\n sum =  %.0f \n average = %.0f \n min = %.0f \n max = %.0f \n\n", sum, average, min, max);

    
    return 0;
}


