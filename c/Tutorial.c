#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define		MAX_COLS 20			/*ËùÄÜ´¦ÀíµÄ×î´óÁĞºÅ*/
#define 	MAX_INPUT 1000		/*Ã¿¸öÊäÈëĞĞµÄ×î´ó³¤¶È*/

int read_column_numbers( int columns[], int max );
void rearrange( char *output, char const *input,
	 int n_columns, int const columns[] );

int main( void)
{
	int 	n_columns;
	int		columns[MAX_COLS];
	char	input[MAX_INPUT];
	char	output[MAX_INPUT];
	
	/*
	**¶ÁÈ¡¸Ã´®ÁĞ±êºÅ
	*/
	n_columns = read_column_numbers( columns, MAX_COLS );
	
	/*
	**¶ÁÈ¡¡¢´¦ÀíºÍ´òÓ¡Ê£ÓàµÄÊäÈëĞĞ¡£
	*/
	while( gets( input ) !=NULL ){				 /*NULLÔÚÍ·ÎÄ¼şstdio¡.hÖĞ¶¨Òå*/ 
		printf( "Original input : %s\n", input);
		rearrange( output, input, n_columns, columns );
		printf( "Rearranged line: %s\n", output );
	} 
	
	return EXIT_SUCCESS;
}
	 
	 
int read_column_numbers( int columns[], int max )
{
	int num = 0;
	int ch;
	
	/*
	**È¡µÃÁĞ±êºÅ£¬Èç¹ûËùÈ¡µÃÊıĞ¡ÓÚ0ÔòÍ£Ö¹¡£
	*/
	while( num < max && scanf( "%d", &columns[num] ) == 1
		&& columns[num] >= 0 )
			num += 1;
	/*
	**È·ÈÏÒÑ¾­¶ÁÈ¡µÃ±êºÅÎªÅ¼Êı¸ö£¬ÒòÎªËûÃÇÊÇÒÔ¶ÔµÄĞÎÊ½³öÏÖµÄ¡£
	*/
	if( num % 2 !=0 ){
		puts( "Last column numner is not paired." );
		exit(  EXIT_FALLURE);
	} 
	
	/*
	**¶ªÆú¸ÄĞĞÖĞ°üº¬×îºóÒ»¸öÊı×ÖµÄÄÇ²¿·ÖÄÚÈİ¡£
	*/
	while( (ch = getchar() ) != EOF && ch != '\n' )
		; 
	
	return num;
}

/*
**´¦ÀíÊäÈëĞĞ£¬½«Ö¸¶¨ÁĞµÄ×Ö·ûÁ¬½ÓÔÚÒ»Æğ£¬Êä³öĞĞÒÔNUL½áÎ²
*/

void rearrange( char *output, char const *input,
			int n_columns, int const columns[] )
{
	int col;		/* columnsÊı×éµÄĞ¡±ê */
	int output_col; /* Êä³öÁĞ¼ÆÊıÆ÷ */
	int len;		/* ÊäÈëĞĞµÄ³¤¶È */
	
	len = strlen( input );
	output_col = 0;
	
	/*
	**´¦ÀíÃ¿¶Ô ÁĞ±êºÅ¡£
	*/
	for( col = 0; col < n_columns; col += 2 ){
		int nchars = columns[col + 1] - columns[col] + 1;
		
		/*
		**Èç¹ûÊäÈëĞĞ½áÊø»òÕßÊä³öĞĞÊı×éÒÑÂú£¬¾Í½áÊøÈÎÎñ¡£
		*/
		if( columns[col] >= len || 	
			output_col == MAX_INPUT - 1 )
				break;
		/*
		**Èç¹ûÊä³öĞĞÊı¾İ¿Õ¼ä²»¹»£¬Ö»¸´ÖÆ¿ÉÒÔÈİÄÉµÄÊı¾İ¡£
		*/
		if( output_col + nchars > MAX_INPUT -1 )
			nchars = MAX_INPUT - output_col -1;
		
		/*
		**¸´ÖÆÏà¹ØµÄÊı¾İ
		*/
		strncpy( output + output_col, input+  columns[col],
				nchars );
		output_col += nchars;
	}
	output[output_col] ='\0';
;}
