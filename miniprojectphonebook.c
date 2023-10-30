#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
struct person                     //STRUCTURE
{
    char name[30];
    char country_code[4];
    long int mble_no;
    char gender[8];
    char mail[100];
};
typedef struct person person;    // Defining person data type.
void remove_all();               // All function declaration.
void print_menu();
void add_person();
void list_record();
void search_person();
void remove_person();
void update_person();
void start();
void take_input(person *p);
int main()                        // Program starts here.
{
    start();
    return 0;
}
void start()                       // This function will start our program.
{
    int choice;
    while(1)
    {
        print_menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                list_record();
                getchar();
                getchar();
                break;
            case 2:
                add_person();
                getchar();
                getchar();
                break;
            case 3:
                search_person();
                getchar();
                getchar();
                break;
            case 4:
                remove_person();
                getchar();
                getchar();
                break;
            case 5:
                update_person();
                getchar();
                getchar();
                break;
            case 6:
                remove_all();
                getchar();
                getchar();
                break;
            default :
                system("cls");
                printf("Thanks for using phonebook visit again : )\n");
                getchar();
                getchar();
                exit(1);
        }
    }
}
void print_menu()                            // This will print main menu.
{
    system("cls");
    printf("\t\t*******************************************************************************\n");
    printf("\t\t*                     Welcome TO PhoneBook application                        *\n");
    printf("\t\t*******************************************************************************\n\n");
    printf("\t\t\t1) list record\n\n");
    printf("\t\t\t2) Add person\n\n");
    printf("\t\t\t3) Search person Details\n\n");
    printf("\t\t\t4) Remove person\n\n");
    printf("\t\t\t5) Update person\n\n");
    printf("\t\t\t6) Delete all contacts\n\n");
    printf("\t\t\t7) exit Phonebook\n\n\n");
    printf("\t\t\tEnter your Choice : ");
}
void add_person()// This function will add contact into phonebook.
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook_db", "ab+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("cls");
        printf("Record added Successfully\n");
        printf("Press any key to continue ....\n");
    }
}
void take_input(person *p)                   // By this we take contact information.
{
    system("cls");                          // This getchar is for taking \n occured by previous functions.
    getchar();                             // So that scanset in scanf will work properly.
    printf("Enter name : ");              // Here we are using scanset '^' - >  until get
    scanf("%[^\n]s",p->name);
    printf("Enter country code : ");
    scanf("%s",p->country_code); 
    printf("Enter mobile no : ");
    scanf("%ld",&p->mble_no); 
    printf("Enter Gender : ");
    scanf("%s",p->gender); 
    printf("Enter email : ");
    scanf("%s",p->mail); 
}
void list_record()// This function will list contact available in phonebook.
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        printf("\n\t\t\t\t******************************************************************************\n");
        printf("\t\t\t\t*                  Here is all records listed in phonebook                   *\n");
        printf("\t\t\t\t******************************************************************************\n\n\n");
        printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    GENDER\t\t         EMAIL\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");// fseek(fp,-(sizeof(p)*2L),2);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            int i;
            int len1 = 40 - strlen(p.name);
            int len2 = 19 - strlen(p.country_code);
            int len3 = 15;
            int len4 = 21 - strlen(p.gender);
            printf("%s",p.name);
            for(i=0;i<len1;i++) printf(" ");
            printf("%s",p.country_code);
            for(i=0;i<len2;i++) printf(" ");
            printf("%ld",p.mble_no);
            for(i=0;i<len3;i++) printf(" ");
            printf("%s",p.gender);
            for(i=0;i<len4;i++) printf(" ");
            printf("%s",p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n"); 
    }
}
void search_person()   // This function will search contact in phonebook.
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the person you want to search : ");
    scanf("%ld",&phone);
    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone)
            {
                printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    GENDER\t\t             EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
                int len1 = 40 - strlen(p.name);
                int len2 = 19 - strlen(p.country_code);
                int len3 = 15;
                int len4 = 21 - strlen(p.gender);
                printf("%s",p.name);
                for(i=0;i<len1;i++) printf(" ");
                printf("%s",p.country_code);
                for(i=0;i<len2;i++) printf(" ");
                printf("%ld",p.mble_no);
                for(i=0;i<len3;i++) printf(" ");
                printf("%s",p.gender);
                for(i=0;i<len4;i++) printf(" ");
                printf("%s",p.mail);
                printf("\n");
                flag = 1;
                break;
            }
            else continue;
            // fflush(stdin);
        }
        if(flag == 0) 
        {
            system("cls");
            printf("Person is not in the Phonebook\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }
}
void remove_person()                       // This function will remove contact from phonebook.
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the person you want to remove from phonebook : ");
    scanf("%ld",&phone);
    FILE *fp,*temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone)
            {
                system("cls");
                printf("Person removed successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found for %d number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp","phonebook_db");
        fflush(stdin);
        printf("Press any key to continue....\n");  
    }
}
void update_person()                //UPDATION
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the person you want to update details : ");
    scanf("%ld",&phone);
    FILE *fp,*temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone) 
            {   
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("cls");
                printf("Data updated successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found for %d number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp","phonebook_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}
void remove_all()                   //REMOVE FUNCTION
{
    char choice;
    system("cls");
    remove("./phonebook_db");
    printf("All data in the phonebook deleted successfully\n");
    printf("Press any key to continue ... \n");
}
