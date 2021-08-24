/******************************************************************************
Suvraneel Bhuin
CSE-424
T91/CSE/194032

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct city{
	char *name;
	struct date{
		char *dt;
		float pm2_5;
		float pm10;
		float no;
		float no2;
		float nox;
		float nh3;
		float co;
		float so2;
		float o3;
		float benzene;
		float toluene;
		float xylene;
		int aqi;
		char *aqi_bucket;
		}day[100], min, max, avg;
	}ct[100];


int main()		//to read file through command line arguments
{
FILE *fpr;
int i=0;
int j=0;
char buff[1000];
char *token;
fpr = fopen( "city_day.csv","r");

if(fpr == NULL)						//Error handling
    {
        printf("Error opening file\n");
        exit(1);
    }


char* prevcity = "Hypothetical";
while (fgets(buff, 1000, fpr)!= NULL){
	
    token = strtok(buff,",");           			// isolate first token
	
	//to accept data properly in the nested structure
	if (strcmp(token, prevcity) == 0)
	j++;
	else if (strcmp(token, prevcity) != 0){			//triggers everytime a new city comes up
	i++;
	j=0;
	ct[i].name = strdup(token);          // allocated mem for substring and copy
	
	// setting all parameter's min values to a BIG value everytime a new city comes up
	// NOTE: we dont need to do the same for max values because they are set to 0 by default
	ct[i].min.pm2_5 = 9999;
	ct[i].min.pm10 = 9999;
	ct[i].min.no = 9999;
	ct[i].min.no2 = 9999;
	ct[i].min.nox = 9999;
	ct[i].min.nh3 = 9999;
	ct[i].min.co = 9999;
	ct[i].min.so2 = 9999;
	ct[i].min.o3 = 9999;
	ct[i].min.benzene = 9999;
	ct[i].min.toluene = 9999;
	ct[i].min.xylene = 9999;
	ct[i].min.aqi = 9999;
	}
		
		while(token != NULL){
        token = strtok(NULL, ",");
	    if (token!= NULL)ct[i].day[j].dt = strdup(token);
	    
        token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].pm2_5 = atof(token);
		if (ct[i].day[j].pm2_5 < ct[i].min.pm2_5)	ct[i].min.pm2_5=ct[i].day[j].pm2_5;
		if (ct[i].day[j].pm2_5 > ct[i].max.pm2_5)	ct[i].max.pm2_5=ct[i].day[j].pm2_5;
		
		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].pm10 = atof(token);
		if (ct[i].day[j].pm10 < ct[i].min.pm10)	ct[i].min.pm10=ct[i].day[j].pm10;
		if (ct[i].day[j].pm10 > ct[i].max.pm10)	ct[i].max.pm10=ct[i].day[j].pm10;
		
		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].no = atof(token);
		if (ct[i].day[j].no < ct[i].min.no)	ct[i].min.no=ct[i].day[j].no;
		if (ct[i].day[j].no > ct[i].max.no)	ct[i].max.no=ct[i].day[j].no;
			
        token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].no2 = atof(token);
		if (ct[i].day[j].no2 < ct[i].min.no2)	ct[i].min.no2=ct[i].day[j].no2;
		if (ct[i].day[j].no2 > ct[i].max.no2)	ct[i].max.no2=ct[i].day[j].no2;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].nox = atof(token);
		if (ct[i].day[j].nox < ct[i].min.nox)	ct[i].min.nox=ct[i].day[j].nox;
		if (ct[i].day[j].nox > ct[i].max.nox)	ct[i].max.nox=ct[i].day[j].nox;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].nh3 = atof(token);
		if (ct[i].day[j].nh3 < ct[i].min.nh3)	ct[i].min.nh3=ct[i].day[j].nh3;
		if (ct[i].day[j].nh3 > ct[i].max.nh3)	ct[i].max.nh3=ct[i].day[j].nh3;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].co = atof(token);
		if (ct[i].day[j].co < ct[i].min.co)	ct[i].min.co=ct[i].day[j].co;
		if (ct[i].day[j].co > ct[i].max.co)	ct[i].max.co=ct[i].day[j].co;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].so2 = atof(token);
		if (ct[i].day[j].so2 < ct[i].min.so2)	ct[i].min.so2=ct[i].day[j].so2;
		if (ct[i].day[j].so2 > ct[i].max.so2)	ct[i].max.so2=ct[i].day[j].so2;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].o3 = atof(token);
		if (ct[i].day[j].o3 < ct[i].min.o3)	ct[i].min.o3=ct[i].day[j].o3;
		if (ct[i].day[j].o3 > ct[i].max.o3)	ct[i].max.o3=ct[i].day[j].o3;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].benzene = atof(token);
		if (ct[i].day[j].benzene < ct[i].min.benzene)	ct[i].min.benzene=ct[i].day[j].benzene;
		if (ct[i].day[j].benzene > ct[i].max.benzene)	ct[i].max.benzene=ct[i].day[j].benzene;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].toluene = atof(token);
		if (ct[i].day[j].toluene < ct[i].min.toluene)	ct[i].min.toluene=ct[i].day[j].toluene;
		if (ct[i].day[j].toluene > ct[i].max.toluene)	ct[i].max.toluene=ct[i].day[j].toluene;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].xylene = atof(token);
		if (ct[i].day[j].xylene < ct[i].min.xylene)	ct[i].min.xylene=ct[i].day[j].xylene;
		if (ct[i].day[j].xylene > ct[i].max.xylene)	ct[i].max.xylene=ct[i].day[j].xylene;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].aqi = atoi(token);
		if (ct[i].day[j].aqi < ct[i].min.aqi)	ct[i].min.aqi=ct[i].day[j].aqi;
		if (ct[i].day[j].aqi > ct[i].max.aqi)	ct[i].max.aqi=ct[i].day[j].aqi;

		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].aqi_bucket = strdup(token);
		}
	prevcity = ct[i].name;
	}

	// Function for question part a	//test
	for(i=1;i<5;i++){
		printf("\n\n\n\n====================\nCity: %s\n====================",ct[i].name );
		printf("\nDate from: %s\t\tDate to:%s\n", ct[i].day[0].dt, ct[i].day[j].dt);
		printf("\nPM2.5:\t Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.pm2_5, ct[i].max.pm2_5 );
		printf("\nPM10:\t Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.pm10, ct[i].max.pm10 );
		printf("\nNO:\t Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.no, ct[i].max.no );
		printf("\nNO2:\t Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.no2, ct[i].max.no2 );
		printf("\nNOx:\t Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.nox, ct[i].max.nox );
		printf("\nNH3:\t Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.nh3, ct[i].max.nh3 );
		printf("\nCO:\t Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.co, ct[i].max.co );
		printf("\nSO2:\t Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.so2, ct[i].max.so2 );
		printf("\nO3:\t Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.o3, ct[i].max.o3 );
		printf("\nBenzene: Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.benzene, ct[i].max.benzene );
		printf("\nToluene: Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.toluene, ct[i].max.toluene );
		printf("\nXylene:  Min:%.2f\t\tMax:%.2f\t\tAvg:.....",ct[i].min.xylene, ct[i].max.xylene );
		printf("\nAQI:\t Min:%d\t\tMax:%d\t\t\tAvg:.....",ct[i].min.aqi, ct[i].max.aqi );
	}	
fclose(fpr);
return 0;
}

