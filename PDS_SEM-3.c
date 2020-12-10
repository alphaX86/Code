#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Structure defining...
struct student
{
    //Details of student
    int rollno;
    char name[30];
    char address[30];
    int sem;
    float cgpa;
    int arrears;
    
    //Pointers for list
    struct student *prev;
    struct student *next;
};

//To avoid core memory dump (experienced when executing the same) and this is used only in reading file items...
struct details
{
    //Details of student
    int rollno;
    char name[30];
    char address[30];
    int sem;
    float cgpa;
    int arrears;
}user[30];

struct student *start = NULL;

//Insertion at begin is used here
void insertBegin()
{
    //Initializing
    struct student *t;
    t = (struct student *) malloc(sizeof(struct student));

    //Asking Details...
    printf("\nEnter your RollNo: ");
    scanf("%d", &t->rollno);
    printf("\nEnter your Name: ");
    scanf("%s", t->name);
    printf("\nEnter your address: ");
    scanf("%s", t->address);
    printf("\nEnter your current semester: ");
    scanf("%d", &t->sem);
    printf("\nEnter your cgpa: ");
    scanf("%f", &t->cgpa);
    printf("\nDo you have any arrears? If so, how many? ");
    scanf("%d", &t->arrears);


    //Connection part
    
    t->prev = NULL;
    t->next = start;
    start = t;
    
    //End function
    return;
}

//Find student using rollno
void find(int x)
{
    struct student *t = start;
    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    while(t->rollno != x && t->next != NULL)
    {
        t = t->next;
    }

    
    if(t->rollno == x)
    {
        printf("\nStudent found!");
        printf("\nDetails: ");
        printf("\nRollno: %d", t->rollno);
        printf("\nName: %s", t->name);
        printf("\nAddress: %s", t->address);
        printf("\nSemester: %d", t->sem);
        printf("\nCGPA: %0.3f", t->cgpa);
        printf("\nArrears: %d", t->arrears);

        return;
    }
    else
    {
        printf("\nStudent not found!");
        return;
    }
    
}

//Update function
void update(int g)
{
    struct student *t = start;
    int a, b, c;
    float d;
    char x[30], y[30];
    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    while(t->rollno != g && t!=NULL)
    {
        t = t->next;
    }

    if(t->rollno == g)
    {
        printf("\nStudent found! Now try to enter your details for updation!");
        printf("\nEnter your RollNo: ");
        scanf("%d", &t->rollno);
        printf("\nEnter your Name: ");
        scanf("%s", t->name);
        printf("\nEnter your address: ");
        scanf("%s", t->address);
        printf("\nEnter your current semester: ");
        scanf("%d", &t->sem);
        printf("\nEnter your cgpa: ");
        scanf("%f", &t->cgpa);
        printf("\nDo you have any arrears? If so, how many? ");
        scanf("%d", &t->arrears);
    }

    else
    {
        printf("\nStudent not found!");
        return;
    }
    
}

//Delete function
void delete(int g)
{
    struct student *t = start;
    struct student *p;
    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    //At begin...
    if(start->rollno == g)
    {
        start = start->next;
        start->prev = NULL;
        free(t);
        return;
    }

    while(t->rollno != g && t->next !=NULL)
    {
        p = t;
        t = t->next;
    }
    
    //If in middle
    if(t->next != NULL)
    {
        p->next = t->next;
        t->next->prev = p;
        t->prev = NULL;
        free(t);
        return;
    }
    
    //If at end...
    if(t->next == NULL)
    {
        t->prev->next = NULL;
        free(t);
        return;
    }
}

//Finding the topper
void findTop()
{
    struct student *t = start;
    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    float large = 0;
    large = t->cgpa;
    t = t->next;

    while(t!=NULL)
    {
        if(large < t->cgpa)
        {
            large = t->cgpa;
        }
        t = t->next;
    }

    //Now repeat again!
    struct student *x = start;
    while(x->cgpa != large && x->next!=NULL)
    {
        x = x->next;
    }
    if(x->cgpa == large)
    {
        printf("\nStudent found!");
        printf("\nDetails: ");
        printf("\nRollno: %d", x->rollno);
        printf("\nName: %s", x->name);
        printf("\nAddress: %s", x->address);
        printf("\nSemester: %d", x->sem);
        printf("\nCGPA: %0.3f", x->cgpa);
        printf("\nArrears: %d", x->arrears);

        return;
    }
}

//Display all list items
void list()
{
    struct student *t = start;
    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nDetails of all students");
    while(t!=NULL)
    {
        printf("\nDetails: ");
        printf("\nRollno: %d", t->rollno);
        printf("\nName: %s", t->name);
        printf("\nAddress: %s", t->address);
        printf("\nSemester: %d", t->sem);
        printf("\nCGPA: %0.3f", t->cgpa);
        printf("\nArrears: %d", t->arrears);
        printf("\n");
        t = t->next;
    }
}

//Display students who have arrears
void listArr()
{
    struct student *t = start;
    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nDetails of students who have arrears:");
    while(t!=NULL)
    {
        if(t->arrears != 0)
        {
            printf("\nDetails: ");
            printf("\nRollno: %d", t->rollno);
            printf("\nName: %s", t->name);
            printf("\nAddress: %s", t->address);
            printf("\nSemester: %d", t->sem);
            printf("\nCGPA: %0.3f", t->cgpa);
            printf("\nArrears: %d", t->arrears);
            printf("\n");
        }
        t = t->next;
    }
}

//Main program
int main()
{
    int X = 1;
    printf("\nHello there!\n");
    while(X != 0)
    {
        int g = 0, y = 0; //This is for roll no
        printf("\nEnter your option! ");
        printf("\n1.Insert student data\n2.Search a student via Rollno\n3.Update details\n4.List all students\n5.List all students who have arrear\n6.Find the topper\n7.Delete student detail\n8.Read previous executed data\n");
        scanf("%d", &y);
        switch(y)
        {
            case 1:
                insertBegin();
                break;
            case 2:
                printf("\nEnter roll no: ");
                scanf("%d", &g);
                find(g);
                break;
            case 3:
                printf("\nEnter roll no: ");
                scanf("%d", &g);
                update(g);
                break;
            case 4:
                list();
                break;
            case 5:
                listArr();
                break;
            case 6:
                findTop();
                break;
            case 7:
                printf("\nEnter roll no: ");
                scanf("%d", &g);
                delete(g);
                break;
            case 8:
                //For reading from a file (function isn't used here)
                printf("\nAcquiring data from the file...");
                FILE *q;
                q = fopen("student.txt", "r");
                int i=0;
                while(!feof(q))
                {
                    fscanf(q, "%d\n", &user[i].rollno);
                    fscanf(q, "%s\n", &user[i].name);
                    fscanf(q, "%s\n", &user[i].address);
                    fscanf(q, "%d\n", &user[i].sem);
                    fscanf(q, "%f\n", &user[i].cgpa);
                    fscanf(q, "%d\n", &user[i].arrears);
                    
                    printf("\nRollNo: %d", user[i].rollno);
                    printf("\nName: %s", user[i].name);
                    printf("\nAddress: %s", user[i].address);
                    printf("\nSemester: %d", user[i].sem);
                    printf("\nCGPA %0.2f", user[i].cgpa);
                    printf("\nArrears: %d", user[i].arrears);

                    i++;
                }
                    
                printf("\nComplete!");
                fclose(q);
                break;
            default:
                printf("\nWrong option!");
                break;
        }
        printf("\nContinue? (Type 1 for yes / 0 for no) ");
        scanf("%d", &X);
    }

    //File write part before ending...
    printf("\nAcquiring data from the program and writing into file...");
    FILE *w;
    w = fopen("student.txt", "w+");
    struct student *s = start;
    while(s!=NULL)
    {
        fprintf(w, "%d\n", s->rollno);
        fprintf(w, "%s\n", s->name);
        fprintf(w, "%s\n", s->address);
        fprintf(w, "%d\n", s->sem);
        fprintf(w, "%0.2f\n", s->cgpa);
        fprintf(w, "%d\n", s->arrears);

        s = s->next;
    }
    printf("\nData recorded!");
    printf("\nEnding program...\n");
    fclose(w);
    return 0;
}