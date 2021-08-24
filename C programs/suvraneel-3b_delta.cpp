/******************************************************************************
Suvraneel Bhuin
CSE-424
T91/CSE/194032

<Work in progress (Problem 3b)>
<Program not working exactly as intended>
<This is my 5th attempt at the problem starting from scratch>

<Issues:
1. strtok doesnt parse null values properly & ignores it
2. strsep does but is not defined in ANSI
Therefore, had to alter csv file for testing purposes

3. Nested structures utilisation is not working as intended.>
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

char* prevcity = "Hypothetical";
while (fgets(buff, 1000, fpr)!= NULL){
	
    token = strtok(buff,",");            // isolate first token
	
	if (token == prevcity)
	j++;
	if (token != prevcity){
	i++;
	j=0;
	ct[i].name = strdup(token);          // allocated mem for substring and copy
	}
		
		while(token != NULL){
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
		}
	prevcity = ct[i].name;
	printf("%s", prevcity);		//test
	}

	// Function for question part a	//test
	for(i=1;i<25;i++){
		printf("==========\nCity: %s\n==========",ct[i].name );
		printf("\nDate from: %s\tDate to:\n", ct[i].day[0].dt);
		for (j=0;j<100;j++){
			
			}
		}
	
fclose(fpr);
return 0;
}

