/********************************************************
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

*********************************************************/


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
    int k,j;
    	for (k=0; k<count-1; k++)
    		for (j=0; j<count-k-1; j++)
				if(student_set[j].marks> student_set[j+1].marks){
					temp = student_set[j];
					student_set[j]=student_set[j+1];
					student_set[j+1] = temp;
				}
	
	//print the sorted array student_set
		printf("\n\nSorted list (in increasing order of marks):\n");
		printf("Rank\t\tRoll\t\tName\t\tMarks\n");
		int z;
		for(z=0;z< count;z++)
		printf("%d\t\t%d\t\t%s\t\t%d\n", count-z,student_set[z].roll_no, &student_set[z].name ,student_set[z].marks);	


    fclose(fp);					//closes file
    return 0;
}

/*
Command line arguments:
$ suvraneel-3a.exe student.txt

Sample Output:
No. of students in list = 3

Initial list (from supplied file):
Roll		Name		Marks
1		Pritha		50
2		Anurina		70
3		Aradhita		30


Sorted list (in increasing order of marks):
Rank		Roll		Name		Marks
3		3		Aradhita		30
2		1		Pritha		50
1		2		Anurina		70


*/
