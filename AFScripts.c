#include "AFScripts.h"
#include <string.h>

bool AFSContextOK(struct AFSContext * afs)
{
    if ( afs == 0 ) { return false; }
    return true;
}


bool StartParsingFile(struct AFSContext * afs , char * filename)
{
   if (!AFSContextOK(afs)) { return false; }
   afs->fp = fopen(filename,"r");
   if (afs->fp == NULL) { return false; }

   afs->sanity_byte=AFS_SANITY_BYTE_VALUE;


   return true;
}


bool GetNextLine(struct AFSContext * afs ,char * line,unsigned int linelen)
{
    if (!AFSContextOK(afs)) { return false; }
    if ( afs->fp != 0 ) {
                          bool retres = (fgets(line,linelen,afs->fp)!=0);
                          unsigned int len = strlen ( line );
                          if ( len > 0 )
                           {
                                 if (line[len-1]==10) { line[len-1]=0; /*fprintf(stderr,"-1 newline \n");*/ }
                                 if (line[len-1]==13) { line[len-1]=0; /*fprintf(stderr,"-1 newline \n");*/ }
                           }
                          if ( len > 1 )
                           {
                                 if (line[len-2]==10) { line[len-2]=0; /*fprintf(stderr,"-2 newline \n");*/ }
                                 if (line[len-2]==13) { line[len-2]=0; /*fprintf(stderr,"-2 newline \n");*/ }
                           }

                          return retres;
                        }
    return false;
}


bool StopParsingFile(struct AFSContext * afs)
{
  if (!AFSContextOK(afs)) { return false; }
  fclose(afs->fp);
  return true;
}

