#ifndef __PROGTEST__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int dup_Check ( const char * (*replace)[2] )
{
    size_t ii=0;
    while(replace[ii+1][0]!=NULL)
    {
        size_t i=ii+1;
        while(replace[i][0]!=NULL)
        {
            if(strstr( replace[i][0], replace[ii][0] )==replace[i][0] )
            {
                return 0;
            }
            if(strstr( replace[ii][0], replace[i][0] )==replace[ii][0])
            {
                return 0;
            }            
            ++i;  
        }
        ++ii;
    }
    return 1;
}

char * newSpeak ( const char * text, const char * (*replace)[2] )
{
    size_t text_length = strlen(text);
    size_t new_length=text_length*2+1;
    if(text_length==0)
    {
      char * rep = (char*) malloc (1);
      strncpy(rep, text, 1);
      return rep;
    }
if(dup_Check(replace)!=1)
{
    return NULL;
}
    char * res = (char*) malloc (new_length);
    size_t i=0;
    size_t ii=0;
    int change=0;
    while(i<text_length)
    {
        size_t y=0;
        while( replace[y][0]!=NULL )
        {
            if(strstr(&text[i], replace[y][0]) == &text[i])
            { 
                int p=strlen(replace[y][1]);
                if( p+ii > new_length)
                {

                  res = (char*) realloc (res, new_length*2+p);
                  new_length=new_length*2+p;
                }
                strcpy(&res[ii], replace[y][1]);
                ii+=p;
                i +=strlen(replace[y][0]);
                change=1;
                break;   
            } else change=0;
            y++;
        }
        if(change==0)
        {  
            res[ii]=text[i];
            i++;
            ii++;
        }
        res[ii]='\0';
    }
    return res;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  char * res;

  const char * d1 [][2] =
  {
    { "murderer", "termination specialist" },
    { "failure", "non-traditional success" },
    { "specialist", "person with certified level of knowledge" },
    { "dumb", "cerebrally challenged" },
    { "teacher", "voluntary knowledge conveyor" },
    { "evil", "nicenest deprived" },
    { "incorrect answer", "alternative answer" },
    { "student", "client" },
    { NULL, NULL }
  };


  const char * d2 [][2] =
  {
    { "fail", "suboptimal result" },
    { "failure", "non-traditional success" },
    { NULL, NULL }
  };


  res = newSpeak ( "Everybody is happy.", d1 );
  assert ( ! strcmp ( res, "Everybody is happy." ) );
  free ( res );

  res = newSpeak ( "The student answered an incorrect answer.", d1 );
  assert ( ! strcmp ( res, "The client answered an alternative answer." ) );
  free ( res );

  res = newSpeak ( "He was dumb, his failure was expected.", d1 );
  assert ( ! strcmp ( res, "He was cerebrally challenged, his non-traditional success was expected." ) );
  free ( res );

  res = newSpeak ( "The evil teacher became a murderer.", d1 );
  assert ( ! strcmp ( res, "The nicenest deprived voluntary knowledge conveyor became a termination specialist." ) );
  free ( res );

  res = newSpeak ( "Devil's advocate.", d1 );
  assert ( ! strcmp ( res, "Dnicenest deprived's advocate." ) );
  free ( res );

  res = newSpeak ( "Hello.", d2 );
  assert ( ! res );
  
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
