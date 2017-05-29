#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void eulerstep(double* x, double* y, double h, double vx1, double vy1, int lepes)
{
	//fizikai állandók:
	double fold=5.9736e+24; //kg
	double hold=7.349e+22; //kg
	double apog=405500000; //meter
	double vapog=964; //m/s
	double peri=363300000; //meter
	double vperi=1076; //m/s
	double gamma=6.67384e-11; //m3/kgs2
	
	int i=0;
	double t=0;
	double fx, fy;
	double vx2, vy2;
	FILE* f;
		
	f=fopen("kimenet.txt", "w");
	
	while (t<lepes)
	{
		fx=(-gamma*fold*hold*x[i])/(pow(pow(x[i],2.0)+pow(y[i],2.0),(3.0/2.0)));
		fy=(-gamma*fold*hold*y[i])/(pow(pow(x[i],2.0)+pow(y[i],2.0),(3.0/2.0)));
		x[i+1]=x[i]+vx1*h;
		vx2=vx1+1/hold*fx*h;
		y[i+1]=y[i]+vy1*h;
		vy2=vy1+1/hold*fy*h;
		
		//if (i<100)
		printf("%lf \t %lf\n", x[i], y[i]);
		fprintf(f,"%lf \t %lf\n", x[i], y[i]);
		
		vx1=vx2;
		vy1=vy2;
		t+=h;
		i++;
	}
}

int main()
{
	//fizikai állandók:
	double fold=5.9736e+24; //kg
	double hold=7.349e+22; //kg
	double apog=405500000; //meter
	double vapog=964; //m/s
	double peri=363300000; //meter
	double vperi=1076; //m/s
	double gamma=6.67384e-11; //m3/kgs2
	
	int lepes=3600*24*30;
	double h=1200;
	double* x;
	double* y;
	
	x=(double*)calloc(lepes, sizeof(double));
	y=(double*)calloc(lepes, sizeof(double));
	
	x[0]=0;
	y[0]=apog;
	
	eulerstep(x, y, h, vapog, 0.0, lepes);
	
	return 0;
}
