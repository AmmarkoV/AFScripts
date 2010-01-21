#ifndef AFSCRIPTS_H_INCLUDED
#define AFSCRIPTS_H_INCLUDED

#include <stdio.h>

const int AFS_SANITY_BYTE_VALUE=666069;

struct AFSContext
{
   FILE* fp;
   unsigned char * datastream;
   unsigned int datastream_len;
   unsigned int sanity_byte;
};

bool StartParsingFile(struct AFSContext * afs , char * filename);
bool GetNextLine(struct AFSContext * afs ,char * line,unsigned int linelen);
bool StopParsingFile(struct AFSContext * afs);
#endif // AFSCRIPTS_H_INCLUDED
