#include <stdio.h>
#include "random.h"

#define NUM_VALUES 250

long int values[NUM_VALUES];

int main()
{
	unsigned long long int sum = 0;
	unsigned int average = 0;			
	signed long long min = 0;
	signed long long max = 0;
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

    printf("\n\n sum =  %llu \n average = %u \n min = %lld \n max = %lld \n\n", sum, average, min, max);

    
    return 0;
}


