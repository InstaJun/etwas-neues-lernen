#include <stdio.h>
#define EXIT 20
int main()
{
	char c;
	printf("bitte Charakter eingeben:");
	
	c = getchar();
	
	if(c < 32 )
		printf("this is control charakter\n");
	else if( c >= '0' && c<= '9' )
		printf( "this is number\n");
	else if( c >= 'A' && c <= 'Z')
		printf("this is capital letter\n");
	else if( c>= 'a' && c<= 'z' )
		printf( "this is small letter\n");
	else
		printf("other character\n");
	return EXIT;
		
}

