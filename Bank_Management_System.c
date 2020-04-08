#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include<string.h>
const char pw[20]= "codebys";
int a;
int size=0;
int count=0;
int main_exit;

void menu();
struct date{
    int day,month,year;
};
struct
{
    int accntno,age;
    char name[50];
    char citizenship[50];
    float amount;
    struct date deposit;
    struct date withdraw;
    struct date dob;
    char address[50];
    double ph;
    char pass[20];

}add, transact, udt,temp,depo,withdr;

void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
        for(k=0;k<j;k++)
    {}
}
int password(char str[20])
{
    char pass[20];
    printf("\nEnter the password\n");
    scanf("%s",pass);
    if(strcmp(str,pass))
        return 0;
    else
        return 1;
}

void acntselector()
{
    FILE *act =fopen("record.dat","r");
    if(act!=NULL)
    {
        while((fscanf(act,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f",add.pass, &add.accntno,&add.deposit.day,&add.deposit.month,&add.deposit.year,add.name,&add.age,&add.dob.day,&add.dob.month,&add.dob.year,add.citizenship,add.address,&add.ph,&add.amount))!= EOF)
        {
            size++;
        }

    }
    if(size==0)
        a=2000;
    else
        a=++add.accntno;
    fclose(act);


}

void see()
{
    system("cls");
    int count=0;
    int test=0;
    FILE *det=fopen("record.dat","r");
    printf("\nPlease enter your account number\n");
    scanf("%d",&temp.accntno);
    while((fscanf(det,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f", add.pass,&add.accntno,&add.deposit.day,&add.deposit.month,&add.deposit.year,add.name,&add.age,&add.dob.day,&add.dob.month,&add.dob.year,add.citizenship,add.address,&add.ph,&add.amount))!= EOF)
    {
        if(temp.accntno==add.accntno)
        {
            test=1;
            passin3:
                system("cls");
            if(password(add.pass))
            {
                printf("\nAccount details are:\nAccount holder name : %s\nAddress : %s\nPhone number : %lf\nBalance : %f",add.name,add.address,add.ph,add.amount);

            }
            else
            {
                printf("\nInvalid entry\n");
                count++;
                if(count>2)
                {
                    printf("\nMore than 3 invalid entries......CLOSING this portal.....");
                    fordelay(26000);

                }
                else
                {
                    printf("\nPress 0 to try again\nPress any other key to exit this portal");
                    scanf("%d",&main_exit);
                    if(main_exit==0)
                        goto passin3;
                }
            }


        }
    }
    fclose(det);
    if(test==0)
    {
        printf("\nNo records found\n");
        printf("\nPress 0 to try again\nPress any other key to exit this portal\n");
        scanf("%d",&main_exit);
        if(main_exit==0)
                see();
        system("cls");
    }
        //system("cls");
        printf("\nPress 1 to go to main menu\nPress any other key to close");
        scanf("%d",&main_exit);
        if(main_exit==1)
        {
            menu();
        }
        else
            close();

}

void menu()
{

    system("cls");
    system("color 9");

    int choice;
    //menuin:
    printf("\n\t\t\t\t     \xB2\xB2\xB2\xB2\xB2   BANKING MANAGEMENT SYSTEM   \xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2   WELCOME TO MAIN MENU   \xB2\xB2\xB2\xB2\xB2\t\t\t\n");
    printf("\n1.Create new account\n2.Update current account details\n3.Account details\n4.Deposit\n5.Withdrawal\n6.View account holders list(Password protected by Bank)\n7.close");

    printf("\nEnter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        new_accnt();
        break;
    case 2:
        update();
        break;
    case 3:
        see();
        break;
    case 4:
        deposit();
        break;
    case 5:
        withdraw();
        break;
    case 6:
        view_list();
        break;
    case 7:
        close();
        break;
    default:
        printf("\nPlease Enter a valid input");
        menu();

    }

}

void view_list()
{
    system("cls");
    char view[20]="bankunlock";
    if(password(view))
    {
            FILE *view=fopen("record.dat","r");
            int test=0;
           // printf("\nName\tAccount no.\tAddress\tPhone number");
            while(fscanf(view,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f", add.pass,&add.accntno,&add.deposit.day,&add.deposit.month,&add.deposit.year,add.name,&add.age,&add.dob.day,&add.dob.month,&add.dob.year,add.citizenship,add.address,&add.ph,&add.amount)!=EOF)
            {
                printf("\nName: %s\tAccount no. : %d\tAdddress : %s\tPhone no. : %lf\n",add.name,add.accntno,add.address,add.ph);
                test++;
            }
            fclose(view);
            if(test==0)
            {
                printf("\nNo records found");
                menu();
            }
    }
    else
    {
        count++;
        printf("\nPassword incorrect\n");
        if(count>2)
        {
            printf("\nMore than 3 wrong attempt.....CLOSING THIS PORTAL...");
            fordelay(26000);
            count=0;
            menu();
        }
        else
        {
            fordelay(20000);
            system("cls");
            printf("\nPress 0 to try again\nPress any other key to quit this portal\n");
            scanf("%d",&main_exit);
            if(main_exit==0)
                view_list();
            else
                menu();
        }
    }

}

void deposit()
{

    system("cls");
    int count=0;
    int test=0;
    FILE *dep,*old;
    old=fopen("record.dat","r");
    dep=fopen("newrecord.dat","w");
    printf("Enter Account Number\n");
    scanf("%d",&depo.accntno);
    while(fscanf(old,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f", add.pass,&add.accntno,&add.deposit.day,&add.deposit.month,&add.deposit.year,add.name,&add.age,&add.dob.day,&add.dob.month,&add.dob.year,add.citizenship,add.address,&add.ph,&add.amount)!=EOF)
    {
        if(depo.accntno==add.accntno)
        {
            test=1;
            passin1:
            if(password(add.pass))
            {

            printf("\n\t\t\t\t\tWelcome %s ",add.name);
            printf("\nEnter the amount you want to deposit\n");
            scanf("%f",&depo.amount);
            depo.amount+=add.amount;
            fprintf(dep,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,depo.amount);
            printf("\nDeposited successfully");
            printf("\nYour current balance is: %f",depo.amount);
            }
            else
            {
                //fprintf(dep,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

               count++;
               if(count>2)
               {
                   printf("\nMore than 3 invalid try....CLOSING...");
                   fprintf(dep,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

                   fordelay(26000);
               }
               else
               {
                   printf("\nPress 0 to try again\nPress any other key to quit this portal\n");
                   scanf("%d",&main_exit);
                   if(main_exit==0)
                    goto passin1;
                   else
                    fprintf(dep,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

               }
            }
        }
        else
            fprintf(dep,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

    }
    fclose(old);
    fclose(dep);
    remove("record.dat");
    rename("newrecord.dat","record.dat");


    if(test==0)
    {
        printf("\nNo records found\n");
        printf("\nPress 0 to try again\nPress any other key to exit this portal\n");
        scanf("%d",&main_exit);
        if(main_exit==0)
            deposit();
            system("cls");
    }
    printf("\nPress 1 for main menu\nPress any other key to exit");
    scanf("%d",&main_exit);
    if(main_exit==1)
        menu();
    else
        close();

}



void withdraw()
{
    system("cls");
    int count=0;
    int valid=0;
    int test=0;
    FILE *with,*old;
    old=fopen("record.dat","r");
    with=fopen("newrecord.dat","w");
    printf("Enter Account Number\n");
    scanf("%d",&withdr.accntno);
    while(fscanf(old,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f",add.pass, &add.accntno,&add.deposit.day,&add.deposit.month,&add.deposit.year,add.name,&add.age,&add.dob.day,&add.dob.month,&add.dob.year,add.citizenship,add.address,&add.ph,&add.amount)!=EOF)
    {
        if(withdr.accntno==add.accntno)
        {
            test=1;
            passin2:
                system("cls");
            if(password(add.pass))
                {

                    printf("\n\t\t\t\t\tWelcome %s ",add.name);
                    printf("\nEnter the amount you want to withdraw\n");
                    scanf("%f",&withdr.amount);

                    if(withdr.amount<add.amount)
                    {
                        withdr.amount=add.amount-withdr.amount;
                        fprintf(with,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,withdr.amount);
                        printf("\nWithdrawn successfully");
                        printf("\nYour current balance is: %f",withdr.amount);
                    }
                    else
                    {
                        fprintf(with,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

                        printf("\nNot enough balance");

                    }
                }
                else
                {
                    printf("\nIncorrect password");
                    count++;
                    if(count>2)
                    {
                        printf("\nMore than 3 invalid entries.....CLOSING THIS PORTAL");
                        fordelay(26000);
                        fprintf(with,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

                    }
                    else
                    {
                        printf("\nPress 0 to try again\nPress any other key to exit this portal\n");
                        scanf("%d",&main_exit);
                        if(main_exit==0)
                            goto passin2;
                        else
                            fprintf(with,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

                    }
                }
        }
        else

            fprintf(with,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

    }
    fclose(old);
    fclose(with);
    remove("record.dat");
    rename("newrecord.dat","record.dat");
    if(test==0)
    {
        printf("\nNo records found\n");
        printf("\nPress 0 to try again\nPress any other key to exit this portal\n");
        scanf("%d",&main_exit);
        if(main_exit==0)
            withdraw();
            system("cls");

    }
    printf("\nPress 1 for main menu\nPress any other key to exit");
    scanf("%d",&main_exit);
    if(main_exit==1)
        menu();
    else
        close();

}


void update(void)
{
    system("cls");
    int choice;
    int test=0;
    FILE *old,*new_rec;
    old=fopen("record.dat","r");
    new_rec=fopen("newrecord.dat","w");
    printf("\nEnter your account number");
    scanf("%d",&udt.accntno);
    while(fscanf(old,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f",add.pass,&add.accntno,&add.deposit.day,&add.deposit.month,&add.deposit.year,add.name,&add.age,&add.dob.day,&add.dob.month,&add.dob.year,add.citizenship,add.address,&add.ph,&add.amount)!=EOF)
    {
        if(add.accntno==udt.accntno)
        {
            if(password(add.pass))
            system("cls");
            test=1;
            printf("\nEnter the field you want to change\n1.Address\n2.Phone Number");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\nEnter new address\n");
                scanf("%s",udt.address);
                fprintf(new_rec,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,udt.address,add.ph,add.amount);
                printf("\nChanges saved");

            }
            else if(choice==2)
            {
                printf("\nEnter new phone number\n");
                scanf("%lf",&udt.ph);
                fprintf(new_rec,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,udt.ph,add.amount);
                printf("\nChanges saved");

            }
            else
            {
                printf("\nInvalid Entry");
                fprintf(new_rec,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);


            }
        }
        else
            fprintf(new_rec,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

    }
    printf("test");
    fclose(old);
    fclose(new_rec);
    remove("record.dat");
    rename("newrecord.dat","record.dat");
        if(test==0)
        {
            system("cls");
            printf("\nNot found");

        }
        printf("\nPress 1 to go to main menu\nPress any other key to exit\n");
                scanf("%d",&main_exit);
                if(main_exit==1)
                    menu();
                else
                    close();
}

void new_accnt()
{
    system("cls");
    FILE* ptr;
    ptr = fopen("record.dat","a");
    printf("\n Enter your details\n");
    acntselector();
    add.accntno=a;
    printf("\nEnter today's date in DD/MM/YY format");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\nEnter your name");
    scanf("%s",add.name);
   // fflush(stdin);
    printf("\nEnter your age ");
    scanf("%d",&add.age);
    printf("\nEnter date of birth");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter citizenship");
    scanf("%s",add.citizenship);
    printf("\nEnter your address");
    scanf("%s",add.address);
    printf("\n Enter phone number");
    scanf("%lf",&add.ph);
    printf("\nEnter the amount you want to deposit");
    scanf("%f",&add.amount);
    printf("\nSet a password for your account\n");
    scanf("%s",add.pass);
    fprintf(ptr,"%s %d %d/%d/%d %s %d %d/%d/%d %s %s %lf %f\t",add.pass, add.accntno,add.deposit.day,add.deposit.month,add.deposit.year,add.name,add.age,add.dob.day,add.dob.month,add.dob.year,add.citizenship,add.address,add.ph,add.amount);

    fclose(ptr);
    printf("\nNew Account created successfully\nYour Account Number is : %d",add.accntno);
    printf("\n1.Main menu\nPress any other key to Close");
    scanf("%d",&main_exit);
    if(main_exit==1)
        menu();
    else
        close();
}

void erasedata()
{
    FILE *eraser=fopen("record.dat","w");
    fclose(eraser);
}
void close()
{
    system("cls");
    char msgs[50]="Banking Management System Developed By Mr.S";
    int i;
    printf("\n\n\n\t\t\t\t");
    for(i=0;i<43;i++)
    {
        fordelay(6000);
        printf("%c",msgs[i]);
    }
    printf("\n\n\n");
}

int main()
{
    int count=0;
    passin:
        system("cls");
   if(password(pw))
   {
       printf("\nPassword Match!!!...LOADING.");
       int i;
       for(i=0;i<25;i++)
       {
           fordelay(5000);
           printf(".");
       }
       system("cls");
        menu();

   }
   else
   {
        count++;
        if(count>2)
        {
            printf("\nMore than 3 wrong attempts...............CLOSING...........!!!!!!");
            fordelay(26000);
            close();
        }
        else
        {
            printf("\nAccess denied");
            fordelay(20000);
            goto passin;
        }
   }
    //erasedata();*/
    //view_list();
}
