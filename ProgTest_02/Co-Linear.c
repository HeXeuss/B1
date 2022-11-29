#include <stdio.h>
#include <math.h>

double check_if_a_line(double Xa, double Ya, double Xb, double Yb, double Xc, double Yc)
{
    double slopeAB= (Yb-Ya)/(Xb-Xa);
    double slopeBC= (Yc-Yb)/(Xc-Xb);
    double slopeAC= (Yc-Ya)/(Xc-Xa);
    if( (Xa==Xb && Xa==Xc && Xc==Xb) || (Ya==Yb && Ya==Yc && Yc==Yb))
    {
       printf("Body lezi na jedne primce.\n");
       return 0;
    }
    if( (Xa==Xb && Xa==Xc && Xc!=Xb) || (Ya==Yb && Ya!=Yc && Yc==Yb) || (Ya!=Yb && Ya==Yc && Yc==Yb))
    {
        printf("Body nelezi na jedne primce.\n");
        return 1;
    }
    else if(abs(slopeAB - slopeAC ) <= __DBL_EPSILON__*1e3*abs(slopeAB+slopeAC)
    && abs(slopeAB - slopeBC ) <= __DBL_EPSILON__*1e3*abs(slopeAB+slopeBC)
    && abs(slopeAC - slopeBC ) <= __DBL_EPSILON__*1e3*abs(slopeAC+slopeBC))
    {
       printf("Body lezi na jedne primce.\n");
       return 0;
    }
    else
    {
        printf("Body nelezi na jedne primce.\n");
        return 1;
    }
    
}
    double is_mid(double Xa, double Ya, double Xb, double Yb, double Xc, double Yc)
{
    if(Xa!=Xb && Xa!=Xc && Xb!=Xc)
    {
        if((Xa > Xb && Xa < Xc) || (Xa > Xc && Xa < Xb))
        {
            printf("Prostredni je bod A.\n");
        }
        else if((Xb > Xa && Xb < Xc) || (Xb > Xc && Xb < Xa))
        {
            printf("Prostredni je bod B.\n");
        }
        else if((Xc > Xa && Xc < Xb) || (Xc > Xb && Xc < Xa))
        {
            printf("Prostredni je bod C.\n");
        }
    }
    
    else
    {
        if((Ya > Yb && Ya < Yc) || (Ya > Yc && Ya < Yb))
        {
            printf("Prostredni je bod A.\n");
        }
        else if((Yb > Ya && Yb < Yc) || (Yb > Yc && Yb < Ya))
        {
            printf("Prostredni je bod B.\n");
        }
        else if((Yc > Ya && Yc < Yb) || (Yc > Yb && Yc < Ya))
        {
            printf("Prostredni je bod C.\n");
        } 
    }
    return 0;
}

int main(void)
{
    double xa, ya, xb ,yb, xc, yc;
    printf("Bod A:\n");
    if(scanf("%lf %lf", &xa, &ya)!=2)
    {
        printf("Nespravny vstup.\n");
        return 1;
    }
    printf("Bod B:\n");
    if(scanf("%lf %lf", &xb, &yb)!=2 )
    {
        printf("Nespravny vstup.\n");
        return 1;
    }
    printf("Bod C:\n");
    if(scanf("%lf %lf", &xc, &yc)!=2)
    {
        printf("Nespravny vstup.\n");
        return 1;
    }
    if( (xa==xb && ya==yb ) || (xa==xc && ya==yc ) || (xb==xc && yb==yc ) )
    {
        printf("Nektere body splyvaji.\n");
        return 1;
    }
    int isline = check_if_a_line(  xa,ya,  xb,yb,  xc,yc );
    
    if (isline == 0)
    {
        is_mid( xa,ya,  xb,yb,  xc,yc );
    }

    return 0;    
}