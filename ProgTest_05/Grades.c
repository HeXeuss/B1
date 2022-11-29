#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Bin search inspired by Ing. Ladislav Vagner, Ph.D.
int Count_Occurance(int * grades, int length, int from, int to) 
{
    int start  = 0, end  = length;
    int start2 = 0, end2 = length;
    while (start < end) 
    {
        int middle = start+(end-start)/2;
       
        if (from > grades[middle]) 
        {
            start = middle+1;
        } 
        else
        {
            end = middle;
        }
    }
    while (start2 < end2) 
    {
        int middle = start2+(end2-start2)/2;
        if (to >= grades[middle]) 
        {
            start2 = middle+1;
        } 
        else 
        {
            end2 = middle;
        }
    }
    return (start2)-(end);
}

int Compare ( const void *p1, const void *p2)
{
    return ( *(int*)p1- *(int*)p2 );
}


int main ( void )
{
    int * grades = (int*) malloc (sizeof (int) );
    char input_check;
    long long grow=2;
    long long length=1;

    printf("Pocty bodu:\n");
    scanf("%c", &input_check);
    if (input_check!='{')
    {
        printf("Nespravny vstup.\n");
        free(grades);
        return 1;
    }
    int i=0;
    int input;
    while(input_check!='}')
    {
        input=scanf("%d %c", &grades[i], &input_check);
        if(grades[i]>1000000000 || grades[i]<0 )
        {
            printf("Nespravny vstup.\n");
            free(grades);
            return 1;
        }
        ++i;
        if(input!=2 ||(input_check!=',' && input_check!='}') || (input==EOF && input_check!='}'))
        {
            printf("Nespravny vstup.\n");
            free(grades);
            return 1;
        }
        if(length==i)
        {
            grades = (int*) realloc (grades, grow * sizeof(*grades));
            grow *= 2;
            length*=2;
        }
    }

    qsort(grades , i , sizeof(int), Compare);

    char r,l;
    printf("Intervaly:\n");

    while(1)
    {
        int from=0, to=0;
        int input2=scanf(" %c %d ; %d %c ", &l, &from, &to, &r);
        if(input2==EOF) break;
        if (input2!=4){
            printf("Nespravny vstup.\n");
            free(grades);
            return 1;
        }
        if(l=='(') {++from;}
        if(r==')') {--to;}

        if(    (l!='(' && l!='<') ||  (r!=')' && r!='>')  ){
            printf("Nespravny vstup.\n");
            free(grades);
            return 1;
        }

        int count=Count_Occurance(grades, i, from, to);
        if(count<0) count=0;
        printf(" -> %d\n", count );
    }
   
    free(grades);
}
