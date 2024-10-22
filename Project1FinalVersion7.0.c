/***********************************************************************
 * Project1FinalVersion.c
 * Final version of a module mark management program. The program
 * manages students marks and allows the user choose options of what
 * to do from a list of menus and sub menus.
 * Version: Final Version: 7.0
 **********************************************************************/
 /* Pre-Processor Directive */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/* Function Prototypes */
void EmptyBuffer(void);
void MainTitleDisplay(void);
void ClearConsole(void);
void ProgramStartMenu(void);
int MainMenu(void);
int CWorkMenu();
void CWorkEnterGrades(int);
char CWorkCheck(int);
void CWorkChangeMark();
int DisplayStudentMarkMenu();
void DisplayStudentMark();
_Bool SuperMode();
char SuperModeMenu();
void SuperModeChangePin();
void SuperModeChangeMark();
void SuperModeAddStudent();
int SuperModeCorrectMenu();
void SuperModeCorrectName(int);
void NameIndexDisplay();
double CalcOverall(double, double, double);
void MainLoop(void);
/* Some Variables */
int PinNumber = 265909;//Pin Number is the same as the candidate number
float CWork1[75];
float CWork2[75];
float CWork3[75];
char FullName[75][26];
/* Main */
/* Main is used to initalize the program and call the functions
that the program will be looping in*/
int main(void)
{
    MainTitleDisplay();
    ProgramStartMenu();
    ClearConsole();
    MainTitleDisplay();
    MainLoop();
    return 0;
}
/* MainLoop gets called after main and is where the program loop runs
and where all other functions gets called from. This is why it is so
as it has to call other things and handles some validation and errors*/
void MainLoop(void)
{
    /*StudentSearchIndex is the index number of the student that
    the user wants to display the mark of*/
    int StudentSearchIndexMark = 0;
    /*StudentSearchIndexName is the index number of the student that
    the user wants to display the name of to then change*/
    int StudentSearchIndexName = 0;
    int Choice = MainMenu();
    printf("%d", Choice);
    switch(Choice)
    {
        case 1://Enter Marks.
            ClearConsole();
            MainTitleDisplay();
            switch(CWorkMenu())
            {
                case 1://Course Work 1
                    ClearConsole();
                    MainTitleDisplay();
                    CWorkEnterGrades(1);
                    break;
                case 2://Course Work 2
                    ClearConsole();
                    MainTitleDisplay();
                    CWorkEnterGrades(2);
                    break;
                case 3://Course Work 3
                    ClearConsole();
                    MainTitleDisplay();
                    CWorkEnterGrades(3);
                    break;
            }
            break;
        case 2://Display a particular students marks.
            ClearConsole();
            MainTitleDisplay();
            //Get Index Number from function and store it
            StudentSearchIndexMark = (DisplayStudentMarkMenu() - 1);
            //Go to Displaying that students marks
            printf("Marks for: %d : %s \n",
            StudentSearchIndexMark, FullName[StudentSearchIndexMark]);
            printf("==============================================\n");
            printf("Course Work 1: %d \n",
                CWork1[StudentSearchIndexMark]);
            printf("Course Work 2: %d \n",
                CWork2[StudentSearchIndexMark]);
            printf("Course Work 3: %d \n",
                CWork2[StudentSearchIndexMark]);
            //CWPass - Course Work pass through number of each array
            int CWPass1 = CWork1[StudentSearchIndexMark];
            int CWPass2 = CWork2[StudentSearchIndexMark];
            int CWPass3 = CWork3[StudentSearchIndexMark];
            //CalcOverall(CWPass1, CWPass2, CWPass3)
            printf("Overall mark as a percentage is: %f \n",
                CalcOverall(CWPass1, CWPass2, CWPass3));
            printf("The console will clear after 7 seconds.");
            Sleep(7000);
            ClearConsole();
            MainTitleDisplay();
            MainMenu();
            break;
        case 3://Supervisor mode.
            ClearConsole();
            MainTitleDisplay();
            if(SuperMode() == 1)
            {
                ClearConsole();
                MainTitleDisplay();
                switch(SuperModeMenu())
                {
                    case 'A'://Change pin
                    case 'a'://A or a to allow for upper and lower case
                        ClearConsole();
                        MainTitleDisplay();
                        SuperModeChangePin();
                        break;
                    case 'B'://Change mark
                    case 'b'://B or b to allow for upper and lower case
                        ClearConsole();
                        MainTitleDisplay();
                        SuperModeChangeMark();
                        break;
                    case 'C'://Add a student
                    case 'c'://C or c to allow for upper and lower case
                        ClearConsole();
                        MainTitleDisplay();
                        SuperModeAddStudent();
                        break;
                    case 'D'://Correct a student name
                    case 'd'://D or d to allow for upper and lower case
                        ClearConsole();
                        MainTitleDisplay();
                        /*adding index numnber from the function*/
                        StudentSearchIndexName = SuperModeCorrectMenu();
                        SuperModeCorrectName(StudentSearchIndexName);
                        break;
                    default:
                        ClearConsole();
                        MainTitleDisplay();
                        MainLoop();
                        printf("Error.Please enter a option from list");
                }
            }else
            {
                ClearConsole();
                MainTitleDisplay();
                printf("Error.Please enter a valid input.");
                MainLoop();
            }
            break;
        case 4://Exit Program
            ClearConsole();
            MainTitleDisplay();
            printf("Program Ending.");
            exit(0);
        default:
            ClearConsole();
            MainTitleDisplay();
            printf("Error");
            MainLoop();
    }
}
/* Course work menu selects the piece of course work to enter the
marks for */
int CWorkMenu()
{
    int MenuChoice;//Local Variable
    printf("[1] Enter Marks Menu.\n"
            "Please choose which course work to mark.\n"
            "==============================================\n"
            "[1] Course Work 1.\n"
            "[2] Course Work 2.\n"
            "[3] Course Work 3.\n"
            "Input: \n");
    scanf(" %d", &MenuChoice);
    return MenuChoice;
}
/* Course work enter grades goes through all students and gets the grade
for the particular piece of course work */
/*need value to pass into %d and array of student names index and
where to store value
*/
void CWorkEnterGrades(int CourseWorkNumber)
{
    printf("[1] Enter Marks Menu.\n"
            "[%d] Course Work %d.\n"
            "Please enter marks for course work %d.\n"
            "==============================================\n",
            CourseWorkNumber, CourseWorkNumber, CourseWorkNumber);
    switch(CourseWorkNumber){
        case 1:
            for(int i = 0; i <= 75; i++){
                printf("Enter mark for student number %d:\n", i + 1);
                scanf("%f", &CWork1[i]);
            }
            CWorkCheck(CourseWorkNumber);
            ClearConsole();
            MainTitleDisplay();
            MainLoop();
            break;
        case 2:
            for(int i = 0; i <= 75; i++){
                printf("Enter mark for student number %d:\n", i + 1);
                scanf("%f", &CWork2[i]);
            }
            CWorkCheck(CourseWorkNumber);
            ClearConsole();
            MainTitleDisplay();
            MainLoop();
            break;
        case 3:
            for(int i = 0; i <= 75; i++){
                printf("Enter mark for student number %d:\n", i + 1);
                scanf("%f", &CWork2[i]);
            }
            CWorkCheck(CourseWorkNumber);
            ClearConsole();
            MainTitleDisplay();
            MainLoop();
            break;
    }
}
/* Course work check asks the user if they enetered all the marks
correctly */
char CWorkCheck(int CourseWorkNumber)
{
    char MenuChoice;//Local Variable
    printf("[1] Enter Marks Menu.\n"
            "[%d] Course Work %d.\n"
            "Please check the marks for course work %d.\n"
            "If they are not then they can be changed.\n"
            "==============================================\n"
            "[Y] Yes. The marks are all correct.\n"
            "[N] No. One or more marks are incorrect.\n"
            "Input: ",
            CourseWorkNumber, CourseWorkNumber, CourseWorkNumber);
    scanf(" %c", &MenuChoice);
    return MenuChoice;
}
/* Course work change mark is used if the user enters a wrong mark and
want to change it*/
void CWorkChangeMark()
{

}
/* Lists the students and gets the index number of the student that the
user wants to view the marks of */
int DisplayStudentMarkMenu()
{
    int MenuChoice;//Local Variable
    printf("[2] Display a particular students marks.\n"
            "Please enter the number corresponding to the students\n"
            "name that you would like to see the marks of.\n"
            "==============================================\n");
    NameIndexDisplay();
    printf("Please enter the number corresponding to the student: \n");
    scanf(" %d", &MenuChoice);
    return MenuChoice;
}
/* Super mode pin handling menu before supervisor main menu*/
/* function is long due to the print statements having to wrap onto
the next line and the layout of the if and else statement */
_Bool SuperMode()
{
    _Bool Acceptance = 0;
    int PinEntered;
    printf("[3] Supervisor mode.\n"
            "Please enter the correct pin to continue.\n"
            "==============================================\n");
    while(Acceptance == 0)
    {
        printf("\nPin Number: ");
        scanf(" %d", &PinEntered);
        if(PinEntered == PinNumber)
        {
            printf("Pin Accepted.\n");
            Acceptance = 1;
        }
        else
        {
            printf("Invalid Pin. Please try again.");
        }
    }
    return Acceptance;
}
/* Supervisor mode menu to choose a sub menu to go to */
char SuperModeMenu()
{
    int MenuChoice;//Local Variable
    printf("[3] Supervisor mode.\n"
            "Supervisor menu.\n"
            "Please choose a number relating to a menu option.\n"
            "==============================================\n"
            "[A] Change the pin number.\n"
            "[B] Change a particular mark.\n"
            "[C] Add a student.\n"
            "[D] Correct a student's name.\n"
            "Input: ");
    scanf(" %c", &MenuChoice);
    return MenuChoice;
}
/* Changes the pin to a new pin */
void SuperModeChangePin()
{
    printf("[3] Supervisor mode.\n"
            "[A] Change the pin number.\n"
            "Please enter the new pin.\n"
            "==============================================\n"
            "Current Pin: %d\n"
            "New Pin: ", PinNumber);
    scanf(" %d", &PinNumber);
    ClearConsole();
    MainLoop();
}
/* Changes the mark of a student entered */
/* Function is long due to the switch case statement layout and the
print statements having to wrap around to the next line.*/
void SuperModeChangeMark()
{
    int MenuChoice;//Local Variable
    int CWorkChoice;
    double NewMark;
    printf("[3] Supervisor mode.\n"
            "[B] Change a particular mark.\n"
            "Choose a number corresponding to the student.\n"
            "==============================================\n");
    NameIndexDisplay();
    printf("Please enter the number corresponding to the student: ");
    scanf(" %d", &MenuChoice);
    printf("Please enter the course work this is for (1,2,3):");
    scanf(" %d", &CWorkChoice);
    printf("Please enter the new mark:");
    scanf(" %f", &NewMark);
    switch(CWorkChoice){
        case 1:
            CWork1[MenuChoice] = NewMark;
            break;
        case 2:
            CWork2[MenuChoice] = NewMark;
            break;
        case 3:
            CWork3[MenuChoice] = NewMark;
            break;
        default:
            ClearConsole();
            MainTitleDisplay();
            printf("Error. Out of bounds Number.");
            MainLoop();
    }
    printf("Mark successfully changed. Returning back to main menu in"
            "3 seconds\n");
    ClearConsole();
    MainTitleDisplay();
    MainLoop();
}
/* Menu to add a new student and asks for student name to be entered */
void SuperModeAddStudent()
{
    int count = sizeof(FullName);
    printf("[3] Supervisor mode.\n"
            "[C] Add a student.\n"
            "Please enter the new student name. Note the student's\n"
            "marks will be 0 until changed.\n"
            "==============================================\n"
            "Student name: ");
    scanf("%s", &count);
    EmptyBuffer();

}
/* Menu to choose a student from a list of indexed students */
int SuperModeCorrectMenu()
{
    int MenuChoice;//Local Variable
    printf("[3] Supervisor mode.\n"
            "[D] Correct a student's name.\n"
            "Please enter the number corresponding to the students\n"
            "name that you would like to correct.\n"
            "==============================================\n");
    NameIndexDisplay();
    printf("Please enter the number corresponding to the student: ");
    scanf(" %d", &MenuChoice);
    return MenuChoice;
}
/* Sub menu to correct a students name */
void SuperModeCorrectName(int SIChangeName)
{
    ClearConsole();
    MainTitleDisplay();
    printf("[3] Supervisor mode.\n"
            "[D] Correct a student's name.\n"
            "Please enter the correct student name.\n"
            "==============================================\n"
            "Current Student Name: %s\n"//add %s
            "New name: \n", FullName[SIChangeName]);
    scanf("%s", &FullName[SIChangeName]);
    printf("Name Changed. Returning to main menu in 5 seconds.\n");
    sleep(5000);
    ClearConsole();
    MainLoop();
}
/* Displays the index number and student name of all students */
void NameIndexDisplay()
{
    int count = 0;
    int ArrLenCount = 75; // FullName[75]
    for(count = 0; count < ArrLenCount; count++){
        printf("(%d): %s\n", count + 1,FullName[count]);
    }
}
/* Calculates the overall grade of the three pieces of coursework using
this formula: (CourseWork1*20% + CourseWork2*30% + CourseWork3*50%) and
then returns the result*/
double CalcOverall(double CW1, double CW2, double CW3)
{
    return ((CW1 * 0.2) + (CW2 * 0.3) + (CW3 * 0.5));
}
/* Displays the main menu and retrun sub menu choice when chosen */
int MainMenu(void)
{
    int MenuChoice;//Local Variable
    printf("Main Menu.\n"
            "Please choose a number relating to a menu option.\n"
            "==============================================\n"
            "[1] Enter marks.\n"
            "[2] Display a particular students marks.\n"
            "[3] Supervisor mode.\n"
            "[4] Exit Program.\n"
            "Input: \n");
    scanf(" %d", &MenuChoice);
    return MenuChoice;
}
/* Displays the program start screen under the main title */
/* Function is long due to the print statements having to wrap around to
the next line and for the contents of the if statement and for loop. */
void ProgramStartMenu(void)
{
    int NumStudentToEnter;
    int Count;
    int DisplayCount =0;
    printf("Program Start:\n"
            "This is a module mark management system.\n"
            "Please follow the instructions below:\n"
            "==============================================\n"
            "Please enter the number of students: ");
    scanf(" %d%*c", &NumStudentToEnter);//Notes: "%d%*c"
    if(NumStudentToEnter>75){
        ClearConsole();
        MainTitleDisplay();
        printf("Error. Please enter a number less than 75.\n");
        printf("==============================================\n");
        ProgramStartMenu();
    }
    for(Count = 0; Count < NumStudentToEnter; Count++)
    {
        printf("Please enter student %d's name: ",DisplayCount + 1);
        //Notes: %25[a-z A-Z] || %s || %*[ ]%ns%*[ ]\n
        scanf("%s", &FullName[Count]);
        DisplayCount++;
        EmptyBuffer();
    }
}
/* Clears the console */
void ClearConsole(void)
{
    getchar();
    system("cls");
}
/* Displays the main title */
void MainTitleDisplay(void)
{
    printf("==============================================\n"
            "Module Assessment Handler\n"
            "==============================================\n");
}
/* Empty the keyboard buffer */
void EmptyBuffer(void)
{
    while(getchar() != '\n')
    {
        ;
    }
}
