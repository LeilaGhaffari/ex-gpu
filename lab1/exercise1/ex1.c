
#include <stdio.h>
#include "random.h"

#define NUM_VALUES 250

int values[NUM_VALUES];

int main()
{
    unsigned int sum     = 0,
                 average = 0;
    int min = 0,
        max = 0;
    unsigned char i = 0;

    init_random();

    for (i=0; i<NUM_VALUES; i++) 
    {
        values[i] = random_ushort();
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

    printf("\n\n sum =  %u \n average = %u \n min = %d \n max = %d \n\n", sum, average, min, max);

    
    return 0;
}


