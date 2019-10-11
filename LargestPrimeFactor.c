#include <stdio.h>
int main() {
	long int number;
	int index;
	scanf("%ld",&number);
    while( number % 2 == 0 )
	    number = number / 2;                                                                                           
	for( index = 3 ; index * index <= number && number != 1 ; index+=2 )
	{
	    while( number % index == 0 )
            number = number / index;
	}
    number == 1 ? printf("%d\n", index) : printf("%ld\n", number);
	return 0;
}
