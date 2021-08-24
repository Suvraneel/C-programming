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
int j=0;
char buff[1000];
char *token;
fpr = fopen( "city_day.csv","r");

if(fpr == NULL)						//Error handling
    {
        printf("Error opening file\n");
        exit(1);
    }

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
	};
	
struct city{
	char *name;
	struct date day[100];
}ct[100];


while (fgets(buff, 1000, fpr)!= NULL){
	
    token = strtok(buff,",");            // isolate first token
	ct[i].name = strdup(token);          // allocated mem for substring and copy
    char* nextcity = "Hypothetical";
	while (1){
		while(nextcity == ct[i].name){
        token = strtok(NULL, ",");
	    ct[i].day[j].dt = strdup(token);
        token = strtok(NULL, ",");
		ct[i].day[j].pm2_5 = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].pm10 = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].no = atof(token);
        token = strtok(NULL, ",");
		ct[i].day[j].no2 = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].nox = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].nh3 = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].co = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].so2 = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].o3 = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].benzene = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].toluene = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].xylene = atof(token);
		token = strtok(NULL, ",");
		ct[i].day[j].aqi = atoi(token);
		token = strtok(NULL, ",");
		ct[i].day[j].aqi_bucket = strdup(token);
		
		token = strtok(NULL, ",");
		nextcity = strdup(token);
		j++;
		}
	i++;
	j=0;
	ct[i].name = nextcity;
	}

    }
    	
	
fclose(fpr);
return 0;
}

