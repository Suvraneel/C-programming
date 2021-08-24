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
char buff[1000];
char *token;
fpr = fopen( "city_day.csv","r");

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
	} day[50], min, max;


while (fgets(buff, 1000, fpr)!= NULL){
	
    token = strtok(buff,",");            // isolate first token
    day[i].city = strdup(token);             // allocated mem for substring and copy

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
		
		
    }
    
for (int i=1; i<25; i++){

		printf("%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%d\t\t%s\n", day[i].city, day[i].date, day[i].pm2_5, day[i].pm10, day[i].no, day[i].no2, day[i].nox, day[i].nh3, day[i].co, day[i].so2, day[i].o3, day[i].benzene, day[i].toluene, day[i].xylene, day[i].aqi, day[i].aqi_bucket );
	
	if (day[i].city != day[i-1].city){
		char sdate =	day[i].date;
		
		float min1 = day[i].pm2_5;
		float max1 = day[i].pm2_5;
		
		float min2 = day[i].pm10;
		float max2 = day[i].pm10;
		
		float min3 = day[i].no;
		float max3 = day[i].no;
		
		float min4 = day[i].no2;
		float max4 = day[i].no2;
		
		float min5 = day[i].nox;
		float max5 = day[i].nox;
		
		float min6 = day[i].nh3;
		float max6 = day[i].nh3;
		
		float min7 = day[i].co;
		float max7 = day[i].co;
		
		float min8 = day[i].so2;
		float max8 = day[i].so2;
		
		float min9 = day[i].o3;
		float max9 = day[i].o3;
		
		float min10 = day[i].benzene;
		float max10 = day[i].benzene;

		float min11 = day[i].toluene;
		float max11 = day[i].toluene;
		
		float min12 = day[i].xylene;
		float max12 = day[i].xylene;
		
		int min13 = day[i].aqi;
		int max13 = day[i].aqi;
		
		}
		
	if (day[i+1].pm2_5<day[i].pm2_5) min1 = day[i+1].pm2_5 ;
	if (day[i+1].pm2_5>day[i].pm2_5) max1 = day[i+1].pm2_5 ;
	
	if (day[i+1].pm10<day[i].pm10) min2 = day[i+1].pm10 ;
	if (day[i+1].pm10>day[i].pm10) max2 = day[i+1].pm10 ;
	
	if (day[i+1].no<day[i].no) min3 = day[i+1].no ;
	if (day[i+1].no>day[i].no) max3 = day[i+1].no ;
	
	if (day[i+1].no2<day[i].no2) min4 = day[i+1].no2 ;
	if (day[i+1].no2>day[i].no2) max4 = day[i+1].no2 ;
	
	if (day[i+1].nox<day[i].nox) min5 = day[i+1].nox ;
	if (day[i+1].nox>day[i].nox) max5 = day[i+1].nox ;
	
	if (day[i+1].nh3<day[i].nh3) min6 = day[i+1].nh3 ;
	if (day[i+1].nh3>day[i].nh3) max6 = day[i+1].nh3 ;
	
	if (day[i+1].co<day[i].co) min7 = day[i+1].co ;
	if (day[i+1].co>day[i].co) max7 = day[i+1].co ;
	
	if (day[i+1].so2<day[i].so2) min8 = day[i+1].so2 ;
	if (day[i+1].so2>day[i].so2) max8 = day[i+1].so2 ;
	
	if (day[i+1].o3<day[i].o3) min9 = day[i+1].o3 ;
	if (day[i+1].o3>day[i].o3) max9 = day[i+1].o3 ;

	if (day[i+1].benzene<day[i].benzene) min10 = day[i+1].benzene ;
	if (day[i+1].benzene>day[i].benzene) max10 = day[i+1].benzene ;

	if (day[i+1].toluene<day[i].toluene) min11 = day[i+1].toluene ;
	if (day[i+1].toluene>day[i].toluene) max11 = day[i+1].toluene ;

	if (day[i+1].xylene<day[i].xylene) min12 = day[i+1].xylene ;
	if (day[i+1].xylene>day[i].xylene) max12 = day[i+1].xylene ;
	
	if (day[i+1].aqi<day[i].aqi) min13 = day[i+1].aqi ;
	if (day[i+1].aqi>day[i].aqi) max13 = day[i+1].aqi ;


if (day[i+1].city != day[i].city)	char edate =	day[i].date;
	}
	
	
fclose(fpr);
return 0;
}

