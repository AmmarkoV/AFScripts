#include "../AFScripts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    struct AFSContext afs;

    printf("Starting AFScript Test v%u..!\n\n",AFSVersion());
    printf("Generating String to test against\n");
    char * str_to_get_line = { "LINE1\nNEWLINE2\nLINE3\n\nMITOULES\n\n\n:)\0" };
    unsigned int len = strlen( str_to_get_line );
    printf("%s\n",str_to_get_line);



    unsigned int linelen=2048;
    printf("Allocating memory for each line , going for %u bytes \n",linelen);
    char * line;
    line = (char*) malloc( (linelen+1) * sizeof ( char ) );

    if ( line == 0 ) {printf("Error getting memory for line data\n"); return 1; }
    if ( StartParsingString(&afs,str_to_get_line,len)!=1 ) { printf("Failed to start parsing String\n"); return 1; }

    printf("\nStarting to parse the String\n");
    while ( NoNextLineString(&afs)==0 )
    {
        GetNextLineString(&afs,line,linelen);
        printf(">%s<\n",line);
    }

     free (line);

    StopParsingString(&afs);

    return 0;
}
