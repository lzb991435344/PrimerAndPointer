/*
** Extract whitespace-delimited tokens from a character array and
** print them one per line.
*/
#include <stdio.h>
#include <string.h>

void
print_tokens( char *line )
{
	static	char	whitespace[] = " \t\f\r\v\n";
	char	*token;
	//分解字符串 str 为一组字符串，delim 为分隔符
	//char *strtok(char *str, const char *delim)
	//该函数返回被分解的第一个子字符串，如果没有可检索的字符串，则返回一个空指针
	for( token = strtok( line, whitespace );
	    token != NULL;
	    token = strtok( NULL, whitespace ) )
		printf( "Next token is %s\n", token );
}
