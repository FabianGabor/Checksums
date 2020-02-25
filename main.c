#include <stdio.h>
#include <strings.h>

typedef char buffer[];

unsigned long int Fletcher16( buffer data, int count )
{
   unsigned long int sum1 = 0;
   unsigned long int sum2 = 0;
   int index;

   for ( index = 0; index < count; ++index )
   {
      sum1 = (sum1 + data[index]) % 255;
      sum2 = (sum2 + sum1) % 255;
   }

   return (sum2 << 8) | sum1;
}

int main()
{    
    buffer buffer = "Fabian Gabor";
    int length = sizeof(buffer)-1;

    printf("Fletcher16: %lu\n", Fletcher16(buffer, length));
    printf("Fletcher16: %x\n", (unsigned int) Fletcher16(buffer, length));

    return 0;
}
