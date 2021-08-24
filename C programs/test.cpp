/******************************************************************************
Suvraneel Bhuin
CSE-424
T91/CSE/194032

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()		//to read file through command line arguments
{
FILE *fpr;
int i=0;
char buff[20];
char *token;
fpr = fopen( "city_day_new.csv","r");

if(fpr == NULL)						//Error handling
    {
        printf("Error opening file\n");
        exit(1);
    }

struct data {					//defines a template structure
	char *city;
	char *date;
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
	} day[50];


while (fgets(buff, 20, fpr)!= NULL){
	
    token = strtok(buff,",");            // isolate first token
    day[i].city = strdup(token);             // allocated mem for substring and copy

    while (token != NULL){
        token = strtok(NULL, ",");
        day[i].date = strdup(token);
        token = strtok(NULL, ",");
		day[i].pm2_5 = atof(token);
		token = strtok(NULL, ",");
		day[i].pm10 = atof(token);
		token = strtok(NULL, ",");
		day[i].no = atof(token);
        token = strtok(NULL, ",");
		day[i].no2 = atof(token);
		token = strtok(NULL, ",");
		day[i].nox = atof(token);
		token = strtok(NULL, ",");
		day[i].nh3 = atof(token);
		token = strtok(NULL, ",");
		day[i].co = atof(token);
		token = strtok(NULL, ",");
		day[i].so2 = atof(token);
		token = strtok(NULL, ",");
		day[i].o3 = atof(token);
		token = strtok(NULL, ",");
		day[i].benzene = atof(token);
		token = strtok(NULL, ",");
		day[i].toluene = atof(token);
		token = strtok(NULL, ",");
		day[i].xylene = atof(token);
		token = strtok(NULL, ",");
		day[i].aqi = atoi(token);
		token = strtok(NULL, ",");
		day[i].aqi_bucket = strdup(token);
		i++;
		day[i].city = strdup(token);
		}
		
	
    }
    
for (int i=0; i<=50; i++)
		printf("%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%d\t%s", day[i].city, day[i].date, day[i].pm2_5, day[i].pm10, day[i].no, day[i].no2, day[i].nox, day[i].nh3, day[i].co, day[i].so2, day[i].o3, day[i].benzene, day[i].toluene, day[i].xylene, day[i].aqi, day[i].aqi_bucket );
	
fclose(fpr);
return 0;
}

