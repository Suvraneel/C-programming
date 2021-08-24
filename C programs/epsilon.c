/******************************************************************************
Suvraneel Bhuin
CSE-424
T91/CSE/194032

<Work in progress (Problem 3b)>
<Program not working exactly as intended>
<This is my 9th attempt at the problem starting from scratch>

Issues:
1. strtok doesnt parse null values properly & ignores it
2. strsep does but is not defined in ANSI
Therefore, had to alter csv file for testing purposes
All the (null) values in csv file have been changed "#"

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
		}day[10000], min, max, sum, count;
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
	ct[i].min.pm2_5 = 999;
	ct[i].min.pm10 = 999;
	ct[i].min.no = 999;
	ct[i].min.no2 = 999;
	ct[i].min.nox = 999;
	ct[i].min.nh3 = 999;
	ct[i].min.co = 999;
	ct[i].min.so2 = 999;
	ct[i].min.o3 = 999;
	ct[i].min.benzene = 999;
	ct[i].min.toluene = 999;
	ct[i].min.xylene = 999;
	ct[i].min.aqi = 999;
	
	// setting all parameter's sum (for finding avg) values to 0 everytime a new city comes up
	ct[i].sum.pm2_5 = 0;
	ct[i].sum.pm10 = 0;
	ct[i].sum.no = 0;
	ct[i].sum.no2 = 0;
	ct[i].sum.nox = 0;
	ct[i].sum.nh3 = 0;
	ct[i].sum.co = 0;
	ct[i].sum.so2 = 0;
	ct[i].sum.o3 = 0;
	ct[i].sum.benzene = 0;
	ct[i].sum.toluene = 0;
	ct[i].sum.xylene = 0;
	ct[i].sum.aqi = 0;
	
	// setting all parameter's count (for finding avg) values to 0 everytime a new city comes up	
	ct[i].count.pm2_5 = 0;
	ct[i].count.pm10 = 0;
	ct[i].count.no = 0;
	ct[i].count.no2 = 0;
	ct[i].count.nox = 0;
	ct[i].count.nh3 = 0;
	ct[i].count.co = 0;
	ct[i].count.so2 = 0;
	ct[i].count.o3 = 0;
	ct[i].count.benzene = 0;
	ct[i].count.toluene = 0;
	ct[i].count.xylene = 0;
	ct[i].count.aqi = 0;
	}
		
		while(token != NULL){
        token = strtok(NULL, ",");
	    if (token!= NULL)
		ct[i].day[j].dt = strdup(token);
	    
	    
        token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].pm2_5 = atof(token);
		if (ct[i].day[j].pm2_5 < ct[i].min.pm2_5 && ct[i].day[j].pm2_5 !=0)
		ct[i].min.pm2_5=ct[i].day[j].pm2_5;
		if (ct[i].day[j].pm2_5 > ct[i].max.pm2_5)
		ct[i].max.pm2_5=ct[i].day[j].pm2_5;
		ct[i].count.pm2_5++;
		ct[i].sum.pm2_5 += ct[i].day[j].pm2_5;
		}
		
		
		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].pm10 = atof(token);
		if (ct[i].day[j].pm10 < ct[i].min.pm10 && ct[i].day[j].pm10 !=0)
		ct[i].min.pm10=ct[i].day[j].pm10;
		if (ct[i].day[j].pm10 > ct[i].max.pm10)
		ct[i].max.pm10=ct[i].day[j].pm10;
		ct[i].count.pm10++;
		ct[i].sum.pm10 += ct[i].day[j].pm10;
		}
		
		
		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].no = atof(token);
		if (ct[i].day[j].no < ct[i].min.no && ct[i].day[j].no !=0)
		ct[i].min.no=ct[i].day[j].no;
		if (ct[i].day[j].no > ct[i].max.no)
		ct[i].max.no=ct[i].day[j].no;
		ct[i].count.no++;
		ct[i].sum.no += ct[i].day[j].no;
		}
			
						
        token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].no2 = atof(token);
		if (ct[i].day[j].no2 < ct[i].min.no2 && ct[i].day[j].no2 !=0)
		ct[i].min.no2=ct[i].day[j].no2;
		if (ct[i].day[j].no2 > ct[i].max.no2)
		ct[i].max.no2=ct[i].day[j].no2;
		ct[i].count.no2++;
		ct[i].sum.no2 += ct[i].day[j].no2;
		}


		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].nox = atof(token);
		if (ct[i].day[j].nox < ct[i].min.nox && ct[i].day[j].nox !=0)
		ct[i].min.nox=ct[i].day[j].nox;
		if (ct[i].day[j].nox > ct[i].max.nox)
		ct[i].max.nox=ct[i].day[j].nox;
		ct[i].count.nox++;
		ct[i].sum.nox += ct[i].day[j].nox;
		}

		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].nh3 = atof(token);
		if (ct[i].day[j].nh3 < ct[i].min.nh3 && ct[i].day[j].nh3 !=0)
		ct[i].min.nh3=ct[i].day[j].nh3;
		if (ct[i].day[j].nh3 > ct[i].max.nh3)
		ct[i].max.nh3=ct[i].day[j].nh3;
		ct[i].count.nh3++;
		ct[i].sum.nh3 += ct[i].day[j].nh3;
		}
		

		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].co = atof(token);
		if (ct[i].day[j].co < ct[i].min.co && ct[i].day[j].co !=0)
		ct[i].min.co=ct[i].day[j].co;
		if (ct[i].day[j].co > ct[i].max.co)
		ct[i].max.co=ct[i].day[j].co;
		ct[i].count.co++;
		ct[i].sum.co += ct[i].day[j].co;
		}
		

		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].so2 = atof(token);
		if (ct[i].day[j].so2 < ct[i].min.so2 && ct[i].day[j].so2 !=0)
		ct[i].min.so2=ct[i].day[j].so2;
		if (ct[i].day[j].so2 > ct[i].max.so2)
		ct[i].max.so2=ct[i].day[j].so2;
		ct[i].count.so2++;
		ct[i].sum.so2 += ct[i].day[j].so2;
		}
		

		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].o3 = atof(token);
		if (ct[i].day[j].o3 < ct[i].min.o3 && ct[i].day[j].o3 !=0)
		ct[i].min.o3=ct[i].day[j].o3;
		if (ct[i].day[j].o3 > ct[i].max.o3)
		ct[i].max.o3=ct[i].day[j].o3;
		ct[i].count.o3++;
		ct[i].sum.o3 += ct[i].day[j].o3;
		}
		

		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].benzene = atof(token);
		if (ct[i].day[j].benzene < ct[i].min.benzene && ct[i].day[j].benzene !=0)
		ct[i].min.benzene=ct[i].day[j].benzene;
		if (ct[i].day[j].benzene > ct[i].max.benzene)
		ct[i].max.benzene=ct[i].day[j].benzene;
		ct[i].count.benzene++;
		ct[i].sum.benzene += ct[i].day[j].benzene;
		}


		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].toluene = atof(token);
		if (ct[i].day[j].toluene < ct[i].min.toluene && ct[i].day[j].toluene !=0)
		ct[i].min.toluene=ct[i].day[j].toluene;
		if (ct[i].day[j].toluene > ct[i].max.toluene)
		ct[i].max.toluene=ct[i].day[j].toluene;
		ct[i].count.toluene++;
		ct[i].sum.toluene += ct[i].day[j].toluene;
		}


		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].xylene = atof(token);
		if (ct[i].day[j].xylene < ct[i].min.xylene && ct[i].day[j].benzene !=0)
		ct[i].min.xylene=ct[i].day[j].xylene;
		if (ct[i].day[j].xylene > ct[i].max.xylene)
		ct[i].max.xylene=ct[i].day[j].xylene;
		ct[i].count.xylene++;
		ct[i].sum.xylene += ct[i].day[j].xylene;
		}

		
		token = strtok(NULL, ",");
		if (token!= NULL && token != "#"){
		ct[i].day[j].aqi = atoi(token);
		if (ct[i].day[j].aqi < ct[i].min.aqi && ct[i].day[j].aqi !=0)
		ct[i].min.aqi=ct[i].day[j].aqi;
		if (ct[i].day[j].aqi > ct[i].max.aqi)
		ct[i].max.aqi=ct[i].day[j].aqi;
		ct[i].count.aqi++;
		ct[i].sum.aqi += ct[i].day[j].aqi;
		}
		
		
		token = strtok(NULL, ",");
		if (token!= NULL)ct[i].day[j].aqi_bucket = strdup(token);
		}
	prevcity = ct[i].name;
	}




	// Function for question part a
	int imax = i;
	for(i=1; i<= imax; i++){
		printf("\n\n\n\n====================\nCity: %s\n====================",ct[i].name );
		printf("\nDate from: %s\t\tDate to:%s\n", ct[i].day[0].dt, ct[i].day[j].dt);
		printf("\nPM2.5:\t Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.pm2_5, ct[i].max.pm2_5, (ct[i].sum.pm2_5/ct[i].count.pm2_5));
		printf("\nPM10:\t Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.pm10, ct[i].max.pm10, (ct[i].sum.pm10/ct[i].count.pm10));
		printf("\nNO:\t Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.no, ct[i].max.no, (ct[i].sum.no/ct[i].count.no));
		printf("\nNO2:\t Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.no2, ct[i].max.no2, (ct[i].sum.no2/ct[i].count.no2));
		printf("\nNOx:\t Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.nox, ct[i].max.nox, (ct[i].sum.nox/ct[i].count.nox));
		printf("\nNH3:\t Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.nh3, ct[i].max.nh3, (ct[i].sum.nh3/ct[i].count.nh3));
		printf("\nCO:\t Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.co, ct[i].max.co, (ct[i].sum.co/ct[i].count.co));
		printf("\nSO2:\t Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.so2, ct[i].max.so2, (ct[i].sum.so2/ct[i].count.so2));
		printf("\nO3:\t Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.o3, ct[i].max.o3, (ct[i].sum.o3/ct[i].count.o3));
		printf("\nBenzene: Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.benzene, ct[i].max.benzene, (ct[i].sum.benzene/ct[i].count.benzene));
		printf("\nToluene: Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.toluene, ct[i].max.toluene, (ct[i].sum.toluene/ct[i].count.toluene));
		printf("\nXylene:  Min:%.2f\t\tMax:%.2f\t\tAvg:%.2f",ct[i].min.xylene, ct[i].max.xylene, (ct[i].sum.xylene/ct[i].count.xylene));
		printf("\nAQI:\t Min:%d\t\t\tMax:%d\t\t\tAvg:%d",ct[i].min.aqi, ct[i].max.aqi, (ct[i].sum.aqi/ct[i].count.aqi));
	}	
	
	
	
	
	//Function for question part b
	float minpm2_5 = 999;
	float minpm10 = 999;
	float minno = 999;
	float minno2 = 999;
	float minnox = 999;
	float minnh3 = 999;
	float minco = 999;
	float minso2 = 999;
	float mino3 = 999;
	float minbenzene = 999;
	float mintoluene = 999;
	float minxylene = 999;
	int minaqi = (ct[1].sum.aqi/ct[1].count.aqi);
	
	float maxpm2_5 = 0;
	float maxpm10 = 0;
	float maxno = 0;
	float maxno2 = 0;
	float maxnox = 0;
	float maxnh3 = 0;
	float maxco = 0;
	float maxso2 = 0;
	float maxo3 = 0;
	float maxbenzene = 0;
	float maxtoluene = 0;
	float maxxylene = 0;
	int maxaqi = 0;
	
	char *cityminpm2_5 ;
	char *cityminpm10 ;
	char *cityminno ;
	char *cityminno2 ;
	char *cityminnox ;
	char *cityminnh3 ;
	char *cityminco ;
	char *cityminso2 ;
	char *citymino3 ;
	char *cityminbenzene ;
	char *citymintoluene ;
	char *cityminxylene ;
	char *cityminaqi ;
	
	char *citymaxpm2_5 ;
	char *citymaxpm10 ;
	char *citymaxno ;
	char *citymaxno2 ;
	char *citymaxnox ;
	char *citymaxnh3 ;
	char *citymaxco ;
	char *citymaxso2 ;
	char *citymaxo3 ;
	char *citymaxbenzene ;
	char *citymaxtoluene ;
	char *citymaxxylene ;
	char *citymaxaqi ;
	
	
	for(i=1; i<= imax; i++){
		// for obtaining name of city with minimum average value
		if((ct[i].sum.pm2_5/ct[i].count.pm2_5) < minpm2_5 
		&& (ct[i].sum.pm2_5/ct[i].count.pm2_5) != 0){
			minpm2_5 = (ct[i].sum.pm2_5/ct[i].count.pm2_5);
			cityminpm2_5 =  strdup( ct[i].name );
		}

		if((ct[i].sum.pm10/ct[i].count.pm10) < minpm10 
		&& (ct[i].sum.pm10/ct[i].count.pm10) != 0){
			minpm10 = (ct[i].sum.pm10/ct[i].count.pm10);
			cityminpm10 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.no/ct[i].count.no) < minno 
		&& (ct[i].sum.no/ct[i].count.no) != 0){
			minno = (ct[i].sum.no/ct[i].count.no);
			cityminno =  strdup( ct[i].name );
		}

		if((ct[i].sum.no2/ct[i].count.no2) < minno2 
		&& (ct[i].sum.no2/ct[i].count.no2) != 0){
			minno2 = (ct[i].sum.no2/ct[i].count.no2);
			cityminno2 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.nox/ct[i].count.nox) < minnox 
		&& (ct[i].sum.nox/ct[i].count.nox) != 0){
			minnox = (ct[i].sum.nox/ct[i].count.nox);
			cityminnox =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.nh3/ct[i].count.nh3) < minnh3 
		&& (ct[i].sum.nh3/ct[i].count.nh3) != 0){
			minnh3 = (ct[i].sum.nh3/ct[i].count.nh3);
			cityminnh3 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.co/ct[i].count.co) < minco 
		&& (ct[i].sum.co/ct[i].count.co) != 0){
			minco = (ct[i].sum.co/ct[i].count.co);
			cityminco =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.so2/ct[i].count.so2) < minso2 
		&& (ct[i].sum.so2/ct[i].count.so2) != 0){
			minso2 = (ct[i].sum.so2/ct[i].count.so2);
			cityminso2 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.o3/ct[i].count.o3) < mino3 
		&& (ct[i].sum.o3/ct[i].count.o3) != 0){
			mino3 = (ct[i].sum.o3/ct[i].count.o3);
			citymino3 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.benzene/ct[i].count.benzene) < minbenzene 
		&& (ct[i].sum.benzene/ct[i].count.benzene) != 0){
			minbenzene = (ct[i].sum.benzene/ct[i].count.benzene);
			cityminbenzene =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.toluene/ct[i].count.toluene) < mintoluene 
		&& (ct[i].sum.toluene/ct[i].count.toluene) >= 0.01){
			mintoluene = (ct[i].sum.toluene/ct[i].count.toluene);
			citymintoluene =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.xylene/ct[i].count.xylene) < minxylene 
		&& (ct[i].sum.xylene/ct[i].count.xylene) >= 0.01){
			minxylene = (ct[i].sum.xylene/ct[i].count.xylene);
			cityminxylene =  strdup( ct[i].name );
		}
	
		if((ct[i].sum.aqi/ct[i].count.aqi) < minaqi 
		&& (ct[i].sum.aqi/ct[i].count.aqi) != 0){
			minaqi = (ct[i].sum.aqi/ct[i].count.aqi);
			cityminaqi =  strdup( ct[i].name );
		}

		
		
		
		// for obtaining name of city with maximum average value
		if((ct[i].sum.pm2_5/ct[i].count.pm2_5) > maxpm2_5 
		&& (ct[i].sum.pm2_5/ct[i].count.pm2_5) != 999){
			maxpm2_5 = (ct[i].sum.pm2_5/ct[i].count.pm2_5);
			citymaxpm2_5 =  strdup( ct[i].name );
		}

		if((ct[i].sum.pm10/ct[i].count.pm10) > maxpm10 
		&& (ct[i].sum.pm10/ct[i].count.pm10) != 999){
			maxpm10 = (ct[i].sum.pm10/ct[i].count.pm10);
			citymaxpm10 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.no/ct[i].count.no) > maxno 
		&& (ct[i].sum.no/ct[i].count.no) != 999){
			maxno = (ct[i].sum.no/ct[i].count.no);
			citymaxno =  strdup( ct[i].name );
		}

		if((ct[i].sum.no2/ct[i].count.no2) > maxno2 
		&& (ct[i].sum.no2/ct[i].count.no2) != 999){
			maxno2 = (ct[i].sum.no2/ct[i].count.no2);
			citymaxno2 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.nox/ct[i].count.nox) > maxnox 
		&& (ct[i].sum.nox/ct[i].count.nox) != 999){
			maxnox = (ct[i].sum.nox/ct[i].count.nox);
			citymaxnox =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.nh3/ct[i].count.nh3) > maxnh3 
		&& (ct[i].sum.nh3/ct[i].count.nh3) != 999){
			maxnh3 = (ct[i].sum.nh3/ct[i].count.nh3);
			citymaxnh3 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.co/ct[i].count.co) > maxco 
		&& (ct[i].sum.co/ct[i].count.co) != 999){
			maxco = (ct[i].sum.co/ct[i].count.co);
			citymaxco =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.so2/ct[i].count.so2) > maxso2 
		&& (ct[i].sum.so2/ct[i].count.so2) != 999){
			maxso2 = (ct[i].sum.so2/ct[i].count.so2);
			citymaxso2 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.o3/ct[i].count.o3) > maxo3 
		&& (ct[i].sum.o3/ct[i].count.o3) != 999){
			maxo3 = (ct[i].sum.o3/ct[i].count.o3);
			citymaxo3 =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.benzene/ct[i].count.benzene) > maxbenzene 
		&& (ct[i].sum.benzene/ct[i].count.benzene) != 999){
			maxbenzene = (ct[i].sum.benzene/ct[i].count.benzene);
			citymaxbenzene =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.toluene/ct[i].count.toluene) > maxtoluene 
		&& (ct[i].sum.toluene/ct[i].count.toluene) < 999){
			maxtoluene = (ct[i].sum.toluene/ct[i].count.toluene);
			citymaxtoluene =  strdup( ct[i].name );
		}
		
		if((ct[i].sum.xylene/ct[i].count.xylene) > maxxylene 
		&& (ct[i].sum.xylene/ct[i].count.xylene) < 999){
			maxxylene = (ct[i].sum.xylene/ct[i].count.xylene);
			citymaxxylene =  strdup( ct[i].name );
		}
	
		if((ct[i].sum.aqi/ct[i].count.aqi) > maxaqi 
		&& (ct[i].sum.aqi/ct[i].count.aqi) < 999){
			maxaqi = (ct[i].sum.aqi/ct[i].count.aqi);
			citymaxaqi =  strdup( ct[i].name );
		}

	}
	
	printf("\n\n\n\t\tMin\t\t\t\tMax\n");
	printf("\nPM2.5:\t\t%s(%.2f)\t\t\t%s(%.2f)", cityminpm2_5,minpm2_5, citymaxpm2_5,maxpm2_5 );
	printf("\nPM10:\t\t%s(%.2f)\t\t\t%s(%.2f)", cityminpm10, minpm10, citymaxpm10, maxpm10 );
	printf("\nNO:\t\t%s(%.2f)\t\t\t%s(%.2f)", cityminno,minno, citymaxno, maxno );
	printf("\nNO2:\t\t%s(%.2f)\t\t\t%s(%.2f)", cityminno2, minno2, citymaxno2, maxno2 );
	printf("\nNOx:\t\t%s(%.2f)\t\t\t%s(%.2f)", cityminnox, minnox, citymaxnox, maxnox );
	printf("\nNH3:\t\t%s(%.2f)\t\t\t%s(%.2f)", cityminnh3, minnh3, citymaxnh3, maxnh3 );
	printf("\nCO:\t\t%s(%.2f)\t\t\t%s(%.2f)", cityminco, minco, citymaxco, maxco );
	printf("\nSO2:\t\t%s(%.2f)\t\t\t%s(%.2f)", cityminso2, minso2, citymaxso2, maxso2 );
	printf("\nO3:\t\t%s(%.2f)\t\t\t%s(%.2f)", citymino3, mino3, citymaxo3, maxo3 );
	printf("\nBenzene:\t%s(%.2f)\t\t%s(%.2f)", cityminbenzene, minbenzene, citymaxbenzene, maxbenzene );
	printf("\nToluene:\t%s(%.2f)\t\t%s(%.2f)", citymintoluene, mintoluene, citymaxtoluene, maxtoluene );
	printf("\nXylene:\t\t%s(%.2f)\t\t\t%s(%.2f)", cityminxylene, minxylene, citymaxxylene, maxxylene );
	printf("\nAQI:\t\t%s(%d)\t\t\t%s(%d)", cityminaqi, minaqi, citymaxaqi, maxaqi );
	
	
	
fclose(fpr);
return 0;
}

