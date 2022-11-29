int findLeap(int year1, int year2){
    int leaps=0;

        while(year1<year2){
        if((year1%4==0 && year1%100!=0) || (year1%400==0 && year1%4000!=0)) leaps+=1;
        if(leaps>0) year1+=4;
        else year1++;
        }

   
    return leaps;
}
long long int timeDelta(int year1, int month1, int day1,
                        int year2, int month2, int day2)
{
    int l=0, l2=0;
    long long int delta=findLeap(year1, year2);
    if((year1%4==0 && year1%100!=0) || (year1%400==0 && year1%4000!=0))
        l=1;
    int md[13]={0,31,28+l,31,30,31,30,31,31,30,31,30,31};
    for(int i=0; i<month1 ; i++)
        delta-=md[i];
    if((year2%4==0 && year2%100!=0) || (year2%400==0 && year2%4000!=0))
        l2=1;
    int md2[13]={0,31,28+l2,31,30,31,30,31,31,30,31,30,31};
    for(int i=0; i<month2 ; i++) delta+=md2[i];
    delta+=(year2-year1)*365+(day2-day1);
    return delta;
}
int sundayCount (int year1, int month1, int day1, long long int delta){
    if(month1<3) day1 += year1--;
    else day1 += year1-2;
    int weekday = (23*month1/9 + day1 + 4 + year1/4- year1/100 + year1/400)%7;
    int sundays =  (delta+(weekday))/7;
    if(weekday==0) sundays++;

    return sundays;
} 
int weekDay ( int year, int month, int day){
    if(month<3) day += year--;
    else day += year-2;
    int weekday = (23*month/9 + day + 4 + year/4- year/100 + year/400)%7;

    return weekday;
}  
int bells ( int y1, int m1, int d1, int h1, int i1,
            int y2, int m2, int d2, int h2, int i2,
            long long int * b1, long long int * b2 )
{
    long long int bell1=0,bell2=0;
    int leap=0,leap2=0;
    int ring1[]={0,1,3,6};
    int rings2[]={0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78,
                 79, 81, 84, 88, 93, 99, 106, 114, 123, 133, 144};
    if((y1%4==0 && y1%100!=0) || (y1%400==0 && y1%4000!=0))
        leap=1;
    if((y2%4==0 && y2%100!=0) || (y2%400==0 && y2%4000!=0))
        leap2=1;
    int md1[13]={0,31,28+leap,31,30,31,30,31,31,30,31,30,31};
    int md2[13]={0,31,28+leap2,31,30,31,30,31,31,30,31,30,31};
    if(y1<1600 || m1>12 || m1<1 || d1>31 || d1<1 || h1>23 || h1<0 || i1>59 || i1<0 ||
       y2<1600 || m2>12 || m2<1 || d2>31 || d2<1 || h2>23 || h2<0 || i2>59 || i2<0)
        return 0;
    if(md1[m1]<d1 || md2[m2]<d2)
        return 0;
    if(y1>y2 || (y1==y2 && m1>m2) || (y1==y2 && m1==m2 && i1+h1*60+d1*24*60>i2+h2*60+d2*24*60))
        return 0;
    if(weekDay(y1,m1,d1)!=0){
        bell1-=(h1*10 + ring1[i1/15]);
        bell2-=rings2[h1];
        if(i1%15==0) bell1+=i1/15;
    }
    if(weekDay(y2,m2,d2)!=0){
        bell1+=h2*10 + ring1[i2/15];
        bell2+=rings2[h2];
    }
    long long int delta=timeDelta ( y1, m1, d1,
                                    y2, m2, d2);
    int sundays=sundayCount(y1, m1, d1, delta);
    bell1+=(delta-sundays)*240;
    bell2+=(delta-sundays)*156;
    if(weekDay(y1,m1,d1)==0){
        bell1+=4;
        bell2+=12;
    }
    if(weekDay(y2,m2,d2)==0){
        bell1+=236;
        bell2+=144;
    }
    if(weekDay(y1,m1,d1)!=0 && i1==0){
        bell1+=4; bell2+=h1%12;
        if(h1%12==0) bell2+=12;
    }
    *b1=bell1;
    *b2=bell2;
    return 1;
}
