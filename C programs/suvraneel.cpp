/*
Suvraneel Bhuin
CSE-424
T91/CSE/194032

Assignment 3:
3a) Create a text file "student.txt" as follows: 
  3 
  01 Pritha 50
  02 Anurina 70
  03 Aradhita 30
  First line contains the number of students.
  Each line afterwards contains detailed information of a student.

  A set of students information roll, name, marks are given in a file.
  Read the name of file through command line arguments.
  Allocate an array of students records ( structure)  using dynamic memory allocation.
  Print the list of students along with their marks (one per line) in increasing order
  and write their ranks: ie. rank, roll, name, marks.

*/


#include<stdio.h>
#include<stdlib.h>

int main(int argc , char* argv[])		//to read file through command line arguments
{
    FILE *fp;
    int num, chars;
	int i = 0;
    fp = fopen(argv[1], "r");			//opens file in read mode

    if(fp == NULL)						//Error handling
    {
        printf("Error opening file\n");
        exit(1);
    }
    
	fscanf(fp, "%d", &num);				//scans no. of students
    printf("No. of students in list = %d\n",num);
    
    struct student {					//defines a template structure
	int roll_no;
	char name[50];
	int marks;
	};
	
	struct student *student_set;		//initializes an array of such structures
	//dynamic allocation of that array
	student_set= (struct student*)malloc(num * sizeof(struct student));
	
	printf("\nInitial list (from supplied file):\n");
    printf("Roll\t\tName\t\tMarks\n");
	
	int count = num; 					//storing for usage later...
    while(num-- != 0 )					//scans & prints supplied list
    {
    	fscanf(fp, "%d\t%s\t%d\n", &student_set[i].roll_no,&student_set[i].name, &student_set[i].marks);
        printf("%d\t\t%s\t\t%d\n", student_set[i].roll_no, &student_set[i].name ,student_set[i].marks);
        i++;
    }
    
    //bubble sort on array student_set
    struct student temp;
    
    	for (int i=0; i<count-1; i++)
    		for (int j=0; j<count-i-1; j++)
				if(student_set[j].marks> student_set[j+1].marks){
					temp = student_set[j];
					student_set[j]=student_set[j+1];
					student_set[j+1] = temp;
				}
	
	//print the sorted array student_set
		printf("\n\nSorted list (in increasing order of marks):\n");
		printf("Rank\t\tRoll\t\tName\t\tMarks\n");
		for(int i=0;i< count;i++)
		printf("%d\t\t%d\t\t%s\t\t%d\n", count-i,student_set[i].roll_no, &student_set[i].name ,student_set[i].marks);	


    fclose(fp);					//closes file
    return 0;
}
