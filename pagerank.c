#include <stdio.h>
#include <math.h>

void
kiir (double tomb[], int db)
{
    int i;
    for(i=0;i<db;++i)
    {
        printf("Pagerank%d: %f\n",i+1,tomb[i]);
    }
}

double tavolsag(double PR[], double PRv[], int n)
    {
       double osszeg=0;
int i;
        for (i=0;i<n;++i)
            osszeg+=(PRv[i]-PR[i]) * (PRv[i]-PR[i]);
            return sqrt(osszeg);

    }


int main(void)
{

    double L[4][4] = {
    {0.0,0.0,1.0/3.0,0.0},
    {1.0,1.0/2.0,1.0/3.0,1.0},
    {0.0,1.0/2.0,0.0,0.0},
    {0.0,0.0,1.0/3.0,0.0},
    };
double PR[4]={0.0,0.0,0.0,0.0};
double PRv[4]={1.0/4.0,1.0/4.0,1.0/4.0,1.0/4.0};

long int i,j;
int sor=0,oszlop=0;
for(;;)
{

    for(sor=0;sor<4;++sor)
    {
        PR[sor]=0.0;
        for(oszlop=0;oszlop<4;++oszlop)
            PR[sor]+=L[sor][oszlop]*PRv[oszlop];
    }
    if(tavolsag(PR,PRv,4)<0.00000000001)
        break;
    for (oszlop=0;oszlop<4;++oszlop)
    {
        PRv[oszlop]=PR[oszlop];
    }

}

kiir(PR,4);
return 0;
}
