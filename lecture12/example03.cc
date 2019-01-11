#include <TRandom3.h>

#define NDOTS		10000
float dotR[NDOTS][3], dotG[NDOTS][3], dotB[NDOTS][3];

#define NCHROMOS	100
float chromo[NCHROMOS*2][18], fitness[NCHROMOS*2];

TRandom3 rnd(1234);

void PrepareData()
{
    TRandom3 rnd_data(1234);
    for(int i=0;i<NDOTS;i++) {
        dotR[i][0] = rnd_data.Gaus(0.,1.0);
        dotR[i][1] = rnd_data.Gaus(0.,1.0);
        dotR[i][2] = rnd_data.Gaus(0.,1.0);
        
        dotG[i][0] = rnd_data.Gaus(3.,1.2);
        dotG[i][1] = rnd_data.Gaus(2.,1.2);
        dotG[i][2] = rnd_data.Gaus(1.,1.2);
        
        dotB[i][0] = rnd_data.Gaus(1.,0.8);
        dotB[i][1] = rnd_data.Gaus(2.,0.8);
        dotB[i][2] = rnd_data.Gaus(3.,0.8);
    }
}

void PrepareChromosomes()
{
    for(int i=0;i<NCHROMOS;i++) {
        for(int j=0;j<18;j++)
            chromo[i][j] = rnd.Uniform(-10.,10);
    }
}

void ApplyCrossOver()
{
    for(int i=NCHROMOS;i<NCHROMOS*2;i++) {
        int s1 = (int)rnd.Uniform(0.,NCHROMOS);
        int s2 = (int)rnd.Uniform(0.,NCHROMOS);
        
        for(int j=0;j<18;j++) {
            if (rnd.Uniform()<0.5) chromo[i][j] = chromo[s1][j];
            else 				   chromo[i][j] = chromo[s2][j];
        }
    }
}

void ApplyMutation()
{
    for(int i=NCHROMOS;i<NCHROMOS*2;i++) {
        for(int j=0;j<18;j++) {
            if (rnd.Uniform()<0.10)
                chromo[i][j] += rnd.Gaus(0.,0.5);
        }
    }
}

float CalculateFitness(int idx)
{
    int Nred, Ngreen, Nblue;
    float xmin,xmax,ymin,ymax,zmin,zmax;
    float Sred, Sgreen, Sblue;
    
    // Deal with red dots
    xmin = chromo[idx][0];
    xmax = chromo[idx][1];
    ymin = chromo[idx][2];
    ymax = chromo[idx][3];
    zmin = chromo[idx][4];
    zmax = chromo[idx][5];
    if (xmin>xmax) {float t = xmin; xmin = xmax; xmax = t;}
    if (ymin>ymax) {float t = ymin; ymin = ymax; ymax = t;}
    if (zmin>zmax) {float t = zmin; zmin = zmax; zmax = t;}
    
    Nred = Ngreen = Nblue = 0;
    for(int i=0;i<NDOTS;i++) {
        if (dotR[i][0]>xmin && dotR[i][0]<xmax &&
            dotR[i][1]>ymin && dotR[i][1]<ymax &&
            dotR[i][2]>zmin && dotR[i][2]<zmax) Nred++;
        if (dotG[i][0]>xmin && dotG[i][0]<xmax &&
            dotG[i][1]>ymin && dotG[i][1]<ymax &&
            dotG[i][2]>zmin && dotG[i][2]<zmax) Ngreen++;
        if (dotB[i][0]>xmin && dotB[i][0]<xmax &&
            dotB[i][1]>ymin && dotB[i][1]<ymax &&
            dotB[i][2]>zmin && dotB[i][2]<zmax) Nblue++;
    }
    if (Nred+Ngreen+Nblue>0)
        Sred = (float)Nred / sqrt((float)(Nred+Ngreen+Nblue));
    else Sred = 0.;
    
    // Deal with green dots
    xmin = chromo[idx][6];
    xmax = chromo[idx][7];
    ymin = chromo[idx][8];
    ymax = chromo[idx][9];
    zmin = chromo[idx][10];
    zmax = chromo[idx][11];
    if (xmin>xmax) {float t = xmin; xmin = xmax; xmax = t;}
    if (ymin>ymax) {float t = ymin; ymin = ymax; ymax = t;}
    if (zmin>zmax) {float t = zmin; zmin = zmax; zmax = t;}
    
    Nred = Ngreen = Nblue = 0;
    for(int i=0;i<NDOTS;i++) {
        if (dotR[i][0]>xmin && dotR[i][0]<xmax &&
            dotR[i][1]>ymin && dotR[i][1]<ymax &&
            dotR[i][2]>zmin && dotR[i][2]<zmax) Nred++;
        if (dotG[i][0]>xmin && dotG[i][0]<xmax &&
            dotG[i][1]>ymin && dotG[i][1]<ymax &&
            dotG[i][2]>zmin && dotG[i][2]<zmax) Ngreen++;
        if (dotB[i][0]>xmin && dotB[i][0]<xmax &&
            dotB[i][1]>ymin && dotB[i][1]<ymax &&
            dotB[i][2]>zmin && dotB[i][2]<zmax) Nblue++;
    }
    if (Nred+Ngreen+Nblue>0)
        Sgreen = (float)Ngreen / sqrt((float)(Nred+Ngreen+Nblue));
    else Sgreen = 0.;
    
    // Deal with blue dots
    xmin = chromo[idx][12];
    xmax = chromo[idx][13];
    ymin = chromo[idx][14];
    ymax = chromo[idx][15];
    zmin = chromo[idx][16];
    zmax = chromo[idx][17];
    if (xmin>xmax) {float t = xmin; xmin = xmax; xmax = t;}
    if (ymin>ymax) {float t = ymin; ymin = ymax; ymax = t;}
    if (zmin>zmax) {float t = zmin; zmin = zmax; zmax = t;}
    
    Nred = Ngreen = Nblue = 0;
    for(int i=0;i<NDOTS;i++) {
        if (dotR[i][0]>xmin && dotR[i][0]<xmax &&
            dotR[i][1]>ymin && dotR[i][1]<ymax &&
            dotR[i][2]>zmin && dotR[i][2]<zmax) Nred++;
        if (dotG[i][0]>xmin && dotG[i][0]<xmax &&
            dotG[i][1]>ymin && dotG[i][1]<ymax &&
            dotG[i][2]>zmin && dotG[i][2]<zmax) Ngreen++;
        if (dotB[i][0]>xmin && dotB[i][0]<xmax &&
            dotB[i][1]>ymin && dotB[i][1]<ymax &&
            dotB[i][2]>zmin && dotB[i][2]<zmax) Nblue++;
    }
    if (Nred+Ngreen+Nblue>0)
        Sblue = (float)Nblue / sqrt((float)(Nred+Ngreen+Nblue));
    else Sblue = 0.;
    
    return Sred + Sgreen + Sblue;
}

void example03()
{
    PrepareData();
    PrepareChromosomes();
    for(int i=0;i<NCHROMOS;i++)
        fitness[i] = CalculateFitness(i);
    
    // Evolution loop
    for(int gen = 0; gen<1000; gen++) {
        ApplyCrossOver();
        ApplyMutation();
        
        for(int i=NCHROMOS;i<NCHROMOS*2;i++)
            fitness[i] = CalculateFitness(i);
        
        // Sorting
        for(int i=0;i<NCHROMOS*2;i++) {
            int idx = i;
            for(int j=i+1;j<NCHROMOS*2;j++)
                if (fitness[j]>fitness[idx]) idx = j;
            
            float t = fitness[idx];
            fitness[idx] = fitness[i];
            fitness[i] = t;
            for(int j=0;j<18;j++) {
                t = chromo[idx][j];
                chromo[idx][j] = chromo[i][j];
                chromo[i][j] = t;
            }
        }
        
        float f_avg = 0., f_rms = 0.;
        for(int i=0;i<NCHROMOS;i++) f_avg += fitness[i];
        f_avg /= NCHROMOS;
        for(int i=0;i<NCHROMOS;i++) f_rms += (fitness[i]-f_avg)*(fitness[i]-f_avg);
        f_rms = sqrt(f_rms/NCHROMOS);
        
        // Print out
        printf("================= %d generation =================\n", gen+1);
        printf("Average fitness = %.4f, rms: %.4f\n",f_avg,f_rms);
        for(int i=0;i<10;i++) {
            printf("%2d: fitness = %.4f, chromo: ",i,fitness[i]);
            for(int j=0;j<18;j++) 
                printf("%.2f ",chromo[i][j]);
            printf("\n");
        }
        
        if (f_rms<f_avg*0.00001) break;
    }
}
