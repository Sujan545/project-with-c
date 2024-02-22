// HEADER FILES
#include <stdio.h> //Use for standard I/O Operation
#include <stdlib.h> //Use for delay()

#include <stdlib.h>
//#include <windows.h>

char password[50];
int b, valid = 0;
// FUNCTION DECLERATION
void WelcomeScreen(void); // WelcomeScreen function decleration
void Title(void);         // Title function decleration
void MainMenu(void);      // MainMenu function decleration
void LoginScreen(void);   // LoginScreen function decleration
void Add_rec(void);       // Add_rec function declarationss
void func_list();         // function to list the patient details
void Search_rec(void);    // Search_rec function declaration
void Edit_rec(void);      // Edit_rec function declaration
void Dlt_rec(void);       // Dlt_rec function declaration
void ex_it(void);         // exit function declaration

struct patient // list of global variable
{
    int S_no;
    int Age;
    char Gender;
    char Contact_no[40];
    char N[40];
    char Address[30];
    int Ward_no;
    char Vaccine_name[30];
    long long int vaccinated_date;
} r;

int main()
{

    system("cls");
    WelcomeScreen(); // Use to call WelcomeScreen function
    Title();         // Use to call Title function
    LoginScreen();   // Use to call Menu function
}

void WelcomeScreen() // function for welcome screen
{
    system("color 3");
    system("cls");
    char number;
    printf("\n\n\n\n\n\n\n\t\t\t\t####################################################");
    printf("\n\t\t\t\t#\t\t WELCOME TO\t\t\t   #");
    printf("\n\t\t\t\t#   BIRTAMODE MUNCIPALITY VACCINATION PROGRAMME    #");
    printf("\n\t\t\t\t####################################################");
    printf("\n\n\n\n\n Press any key......\n");
    getchar();       // Use to holds screen for some seconds
    system("cls"); // Use to clear screen
}

void Title() // function for title screen
{
    system("color 5");
    system("cls");
    printf("\n\n\t\t----------------------------------------------------------------------------------");
    printf("\n\t\t\t\t      BIRTAMODE MUNCIPALITY  VACCINATION PROGRAMME       ");
    printf("\n\t\t----------------------------------------------------------------------------------");
}

void MainMenu() // function decleration
{
    system("color 70");
    system("cls");

    int choose;
    Title(); // call Title function
    printf("\n\n\n\n\n\t\t\t\t1. Add People Covid Vaccine  Details \n");
    printf("\n\t\t\t\t2. List Details \n");
    printf("\n\t\t\t\t3. Search Details \n");
    printf("\n\t\t\t\t4. Edit Details \n");
    printf("\n\t\t\t\t5. Delete Details \n");
    printf("\n\t\t\t\t6. Exit\n");

    printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
    scanf("%d", &choose);

    switch (choose) // switch to differeht case
    {

    case 1:
        Add_rec(); // Add_rec function is called
        break;
    case 2:
        func_list();
        break;
    case 3:
        Search_rec(); // View_rec function is call
        break;
    case 4:
        Edit_rec(); // Edit_rec function is call
        break;
    case 5:
        Dlt_rec(); // Dlt_rec function is call
        break;
    case 6:
        ex_it(); // ex_it function is callsss
        break;

    default:
        printf("\t\t\tInvalid entry. Please enter right option :)");
        getchar(); // holds screen
    }            // end of switch
}

void ex_it(void) // function to exit
{
    system("cls");
    Title(); // call Title function
    printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
    getchar(); // holds screen
    exit(1);
}

void LoginScreen(void) // function for login screen
{
    // list of variables
    char username[50], password[50], user[] = "admin", pass[] = "8855";
    int choice, e = 0, i = 0;
    char cont;

    FILE *fp, *fp_temp;
top:
    do
    {
        system("cls");
        Title();
        printf("\n\t\t USERNAME: ");
        scanf("%s", &username);
        printf("\n\t\t PASSWORD: ");
        for (i = 0; i < 20; i++)
        {
            password[i] = getchar();
            if (password[i] == 13)
            {
                break;
            }
            else
            {
                printf("*");
            }
        }
        password[i] = '\0';
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
        {
            printf("\n\n\t\t\t Login Success:)");
            MainMenu();
        }
        else
        {
            printf("\n\n");
            printf("You Enter wrong password Please login again.");
            e++;

            getchar();
        }
    } while (e <= 1);
    if (e > 1)
    {
        printf("You have cross the limit. You cannot login. :( :(");
        getchar();
        ex_it();
    }

    system("cls");
}

void Add_rec(void)
{
    char cont;
    system("cls");
    Title(); // call Title function

    FILE *bm;
A:
    fflush(stdin);
    printf("\n\t\t Serial_No: ");
    scanf("%d", &r.S_no);

    printf("\n\t\t Name:");
    scanf("%s", r.N);
    printf("\n\t\t Gender[M/F]:");
    scanf("%s", &r.Gender);
    printf("\n\t\t Address:");
    scanf("%s", r.Address);
    printf("\n\t\t Ward_no:");
    scanf("%d", &r.Ward_no);
    printf("\n\t\t Age:");
    scanf("%d", &r.Age);

    do
    {
    D:
        printf("\n\t\t Contact no: ");
        scanf("%s", r.Contact_no);
        if (strlen(r.Contact_no) > 10 || strlen(r.Contact_no) != 10)
        {
            printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
            goto D;
        }
        else
        {
            for (b = 0; b < strlen(r.Contact_no); b++)
            {
                if (!isalpha(r.Contact_no[b]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
                goto D;
            }
        }
    } while (!valid);

    printf("\n\t\t Vaccine Name:");
    scanf("%s", r.Vaccine_name);
    printf("\n\t\t Vccinated Date(DD MM YY):");
    scanf("%lld", &r.vaccinated_date);
    bm = fopen("Record.txt", "a");
    fwrite(&r, sizeof(r), 1, bm);
    if (fwrite)
    {
        printf("\n\t\t\tsuccess:)");
    }
    else
    {
        printf("failed\n");
    }
    fclose(bm);
    printf("\n\n\t\t----------------------------------------------------------------------------------");
    printf("\n\n\t\t Do you want to continue ?");
    printf("\n\t\t----------------------------------------------------------------------------------");
    printf("\n\n\t\tType Y/y for yes and n/N for no.");

    cont = getchar();
    system("cls");
    if (cont == 'y')
    {
        Title();
        goto A;
    }
    else
    {
        MainMenu();
    }
}

void func_list()
{
    int row;
    system("cls");
    Title();
    FILE *bm;
    bm = fopen("Record.txt", "r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!\n");
    while (fread(&r, sizeof(r), 1, bm))
    {
        if (r.Age <= 18)
        {

            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t Details of under 18 age group :)");
            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t Serial No: %d", r.S_no);
            printf("\n\t\t Name: %s", r.N);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vccinated Date(DD MM YY): %lld", r.vaccinated_date);
        }
        else if (r.Age > 18 && r.Age <= 50)
        {

            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\tDetails of 18-50 age group :)");
            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t Serial No: %d", r.S_no);
            printf("\n\t\t Name:%s", r.N);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vccinated Date(DD MM YY): %lld", r.vaccinated_date);
        }
        else
        {

            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\tDetails of above 50 age group :)");
            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t Serial No: %d", r.S_no);
            printf("\n\t\t Name:%s", r.N);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vccinated Date(DD MM YY): %lld", r.vaccinated_date);
        }
    }

    fclose(bm);
    getchar();
    MainMenu();
}

void Search_rec(void) // search function
{
    int sno;
    int flag = 0;
    system("cls");
    Title(); // call Title function
    FILE *bm;
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Details !!!!!!!!!!!!!\n");
    fflush(stdin);
    printf("\n\t\t Serial No:");
    scanf("%d", &sno);
    bm = fopen("Record.txt", "r");
    while (fread(&r, sizeof(r), 1, bm))
    {
        if (sno == r.S_no)
        {
            flag = 1;
            printf("\n\t\t Serial No: %d", r.S_no);
            fflush(stdin);
            printf("\n\t\t Name:%s", r.N);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vccinated Date(DD MM YY): %lld", r.vaccinated_date);
        }
    }
    if (flag != 1)
    {
        printf("result could not be found:");
    }
    fclose(bm);
    getchar();
    MainMenu();
}

void Edit_rec(void)
{
    FILE *bm, *ft;
    int flag = 0;
    int sno;

    system("cls");
    Title(); // call Title window
    ft = fopen("temp.txt", "a");
    bm = fopen("Record.txt", "r");
    if (bm == NULL)
    {
        printf("\n\t Can not open file!! ");
        getchar();
        MainMenu();
    }
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Details !!!!!!!!!!!!!\n");
    fflush(stdin);
    printf("\n\t\t Serial No: ");
    scanf(" %d", &sno);
    while (fread(&r, sizeof(r), 1, bm))
    {
        if (sno == r.S_no)
        {
            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t!!!!!!!!!!!!!!Details!!!!!!!!!!!!!!!!!");
            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t Serial No: %d\n", r.S_no);
            printf("\n\t\t Name:%s", r.N);
            printf("\n\t\t Gender[M/F]: %c", r.Gender);
            printf("\n\t\t Address: %s", r.Address);
            printf("\n\t\t Ward_No: %d", r.Ward_no);
            printf("\n\t\t Age: %d", r.Age);
            printf("\n\t\t Contact_No: %s", r.Contact_no);
            printf("\n\t\t Vaccine Name: %s", r.Vaccine_name);
            printf("\n\t\t Vccinated Date(DD MM YY): %lld", r.vaccinated_date);
            fflush(stdin);
            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!Add New Details!!!!!!!!!!!!!");
            printf("\n\t\t----------------------------------------------------------------------");
            printf("\n\t\t Serial No:");
            scanf("%d", &r.S_no);
            fflush(stdin);
            printf("\t\t Name:");
            scanf("%s", &r.N);
            printf("\n\t\t Gender[M/F]:");
            scanf("%s", &r.Gender);
            printf("\n\t\t Address:");
            scanf("%s", r.Address);
            printf("\n\t\t Ward_No:");
            scanf("%d", &r.Ward_no);
            printf("\n\t\t Age:");
            scanf("%d", &r.Age);
            printf("\n\t\t Contact_No:");
            scanf("%s", &r.Contact_no);
            printf("\n\t\t Vaccine Name:");
            scanf("%s", r.Vaccine_name);
            printf("\n\t\t Vccinated Date(DD MM YY):");
            scanf("%lld", &r.vaccinated_date);
            fwrite(&r, sizeof(r), 1, ft);
        }
        else
        {
            fwrite(&r, sizeof(r), 1, ft);
            flag = 1;
        }
    }
    fclose(ft);
    fclose(bm);
    remove("Record.txt");
    rename("temp.txt", "Record.txt");
    if (flag == 0)
    {
        printf("record update successful");
    }
    else
        printf("record couldnot be updated");
    getchar();
    MainMenu();
}

void Dlt_rec()
{
    int sno;

    int flaag = 0;
    system("cls");
    Title(); // call Title function
    FILE *bm, *ft;
    ft = fopen("temp_file.txt", "a");
    bm = fopen("Record.txt", "r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Record !!!!!!!!!!!!!\n");
    fflush(stdin);
    printf("\n\t\t Serial No:");
    scanf("%d", &sno);
    while (fread(&r, sizeof(r), 1, bm))
    {
        if (sno != r.S_no)
        {
            fwrite(&r, sizeof(r), 1, ft);
        }
        else
        {
            flaag = 1;
        }
    }

    fclose(bm);
    fclose(ft);
    remove("Record.txt");
    rename("temp_file.txt", "Record.txt");
    if (flaag == 1)
    {
        printf("record deleted sucessfully");
    }
    else
    {
        printf("Record couldn't be Found And Cannot Be Deleted");
    }
    getchar();
    MainMenu();
}