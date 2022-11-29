#include <stdio.h>
#include <math.h>


int main (void)
{
    double ku, du;
    int dni, den, den1=-69;
    int postup=-1;
    int i=0;
    double trans;
    double ucet=0;
    

    printf("Zadejte kreditni urok [%%]:\n");
    if( scanf("%lf", &ku)!=1 )
    {
        printf("Nespravny vstup.\n");
        return 1;
    }
    printf("Zadejte debetni urok [%%]:\n");
    if( scanf("%lf", &du)!=1 )
    {
        printf("Nespravny vstup.\n");
        return 1;
    }
    printf("Zadejte transakce:\n");
   
    while(1)
    {
        
        if(scanf("%d, %lf", &den, &trans)!=2 || den<=postup || den<0 || den<0 )
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
        if(den<=den1)
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
       

        if(i>0)
        {
            
            double urok;
            dni=den-den1;
            for(int p=0 ; p<dni ; p++)
            {
                if(ucet>0)
                {
                    urok=ucet*(ku/100);
                    double g = floorl(urok * 100) / 100;
                    ucet = ucet+g;
                    
                    
                    
                }
                else
                {
                    urok=ucet*(du/100);
                    double l = ceill(urok * 100) / 100;
                    ucet = ucet+l;
                }
            }
        }
        if(i==0)
        {   
            i=1;
        }
        ucet=ucet+trans;
        den1=den;
        if(trans==0)
        {
            break;
        }
    
    }
    printf("Zustatek: %.2f\n", ucet);   
}