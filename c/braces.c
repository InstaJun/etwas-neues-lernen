#include <stdio.h>


int main ()
{
	char ch; 
	int braces,i=0;
	
	braces = 0;
		
	while( (ch = getchar()) != '\n' )
	{
	
		if( ch == '{' )
			braces += 1;
		
		if( ch == '}' )
			if( braces == 0 )
				printf( "%dExtra closing brace!\n",i+1 );
			else
				braces -= 1;
				
		printf("%d\n", ++i );
	}
		if( braces > 0)
			printf( "%o unmatched",braces );
	
	
	return 0;
		
}

