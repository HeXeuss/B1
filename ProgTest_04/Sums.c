#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX  2000
#define MAX2 500000

int size2=0;
void Sums(int sequence[] , int size, int start, int sums[]){
    int sum=sequence[start-1];
    for(int i=start ; i<size ; i++){
        sum+=sequence[i];
        sums[size2]=sum;
        ++size2;
    }
}
void gradual_Sums( int sequence[] , int size,int sums[] ){
    for (int i=1 ; i<size ; i++){
        Sums(sequence, size, i, sums);
    }
}
int count_Occurances(int sums[], int values[], int start2, int start){
    int count=0;
    int value=sums[start];
    for (int i=start; i < start2; i++){
        if (sums[i]==value){
            values[i]=1;
            ++count;
        }
    }
    return count;
}
int main(void){
    int number, size=0, groups=0, numOccurarce;
    int sums[MAX2], sequence[MAX];
    int values[MAX2];
    printf("Posloupnost:\n");
    while(1)
    {
        int input=scanf("%d",&number);
        if(input==EOF && size==0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        if(input==EOF){
            break;
        }
        if(input!=1){
            printf("Nespravny vstup.\n");
            return 1;
        }
        sequence[size]=number;
        ++size;
        if(size>MAX){
            printf("Nespravny vstup.\n");
            return 1;
        } 
        input=0;
        fflush(stdin);
    }
    gradual_Sums(sequence, size, sums);
    for(int i=0; i<size2 ; i++){
        values[i]=0;
    }
    for (int i = 0; i < size2; i++){
        if (values[i]==0) {
            numOccurarce=count_Occurances (sums, values, size2, i);
            if(numOccurarce>1) groups += ( numOccurarce * (numOccurarce-1) ) / 2;
        }
    }
    printf("Pocet dvojic: %d\n",groups);
}
