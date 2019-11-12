/*
   Program name: CGPA Profiling
   Author: Rakibul Alam
   ID: 181-16-285

*/

#include<stdio.h>
#include<string.h>

struct student          // Declare student information as  Structure
{
    char std_name[50],std_id[20]; //  Student Name, Student ID as  Members of student
    int num_of_sub_completed,sum_credit; // Number of subject completed, total credit of all subjects as  Members of student
    float sum_gpa,cgpa;     //  Total GPA for all subject credits, CGPA for a student as  Members of student
    struct subjects     //Declare subject information as structure
    {
        char sub_name[50]; //  Subject name as  Member of subjects
        int sub_credits;  //Subject credits as  Member of subjects
        float sub_gpa;    // Subject GPA as  Member of subjects
    } sub[100];          // Declare array of structure variable as sub
};
// Declaration function
void input_student(struct student s);
float calculate_cgpa(struct student s);
void generate_student_file(struct student std);
// initialize i
int i = 0;

int main()
{
    struct student s; // declare student variable as s

    char  answer;

    // Take permission from user to add student
    do
    {
        input_student(s);

        fflush(stdin); // clear the memory buffer
        printf("Do you want add another student? y or n\n");
        scanf(" %c", &answer);
        if(answer == 'N' || answer =='n')
        {
            printf("=======================Your Program exit successfully===================\n Thank you");
        }

    }

    while( answer == 'y'|| answer == 'Y');

}

// Taking input of Student information from user
void input_student(struct student s)
{
    // function used for clearing Memory Buffer
    fflush(stdin);
    printf("Enter Student name:  ");
    gets(s.std_name);
    printf("Enter Student ID:  ");
    gets(s.std_id);
    printf("Enter number of subject completed:  ");
    scanf("%d",&s.num_of_sub_completed);
    s.num_of_sub_completed;

    for(i=0; i<s.num_of_sub_completed; i++)
    {
        fflush(stdin);
        printf("Enter Subject%d information:\n",i+1);

        printf("\tName:  ");
        gets(s.sub[i].sub_name);
        printf("\tCredits:  ");
        scanf("%d",&s.sub[i].sub_credits);
        {
            printf("\tGPA:  ");
            scanf("%f",&s.sub[i].sub_gpa);
        }
    }

    generate_student_file(s);
}
// calculate CGPA
float calculate_cgpa(struct student s)
{
        s.sum_credit=0;
        s.sum_gpa= 0.0;
        s.cgpa = 0.0;
        for(i=0; i<s.num_of_sub_completed; i++)
        {
            s.sum_credit = s.sub[i].sub_credits + s.sum_credit;
            s.sum_gpa= s.sub[i].sub_gpa * s.sub[i].sub_credits + s.sum_gpa;
        }
        s.cgpa = s.sum_gpa/s.sum_credit;
        return s.cgpa;
}

void generate_student_file(struct student std) // Function for creating student txt file which contains student information
{
    // create file
    FILE *file;
    strcat(std.std_id,".txt");  // String concatenation
    printf("%s ",std.std_id);
    file=fopen(std.std_id,"w");// Generate file name
    if(file==NULL)             // Check file creation
    {
        printf("error\n");

    }
    else
    {
        printf("file created\n");

        fprintf(file,"=================================\n");
        // Get student id from file name
        const char splt[2] = ".";
        char *getID;
        getID = strtok(std.std_id,splt); // Get student ID from string

        // Store student information in file
        fprintf(file,"Student ID: %s\nStudent Name:%s\nNumber Of Subjects Completed: %d\n",getID,std.std_name,std.num_of_sub_completed);
        fprintf(file,"=================================\n");
        // Initialize variable

        for(i=0; i<std.num_of_sub_completed; i++)
        {
            // store subject information in file
            fprintf(file,"Enter Subject%d information:\n\tSubject Name: %s\n\tSubject credit: %d\n\tSubject GPA: %.2f\n",i+1,std.sub[i].sub_name,std.sub[i].sub_credits,std.sub[i].sub_gpa);

            // calculation to find out CGPA

            fprintf(file,"=================================\n");
        }
        // calling CGPA calculate function
        std.cgpa = calculate_cgpa(std);

        // store CGPA in the file
        fprintf(file,"%s CGPA is: %.2f\n",std.std_name,std.cgpa);
        fprintf(file,"=================================\n");
        // close the file
        fclose(file);
    }
}








