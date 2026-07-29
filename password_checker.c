#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define MAX_LENGTH 8

int check_password_strength(const char *password);

int main()
{
    char password[50];

    printf("Password Guidelines:\n");
    printf("Must contain at least one upper and lower letter.\n");
    printf("Should contain at least one digit\n");
    printf("Should contain at least one special character(!@#$&*^)\n");

    for(int j=0;j<3;j++)//available attempts
    {
       printf("\nEnter Password: ");
       fgets(password,sizeof(password),stdin);

       int strength = check_password_strength(password);

       if(strength==3)
       {
           printf("Strong Password\n");
       }
       else if(strength==2)
       {
           printf("Medium Password\n");
       }
       else if(strength==0)
       {
           printf("Weak Password\n");
       }
       else
       {
           printf("Invalid Password\n");
       }
    }
    
    getchar();
    return 0;
}

int check_password_strength(const char *password)
{
    int length = strlen(password);
    bool has_upper, has_lower, has_digit, has_special=false;
    const char special_characters[]="!@#$&*^";

    for(int i=0;i<length;i++)
    {
        if(isupper(password[i]))
        {
            has_upper=true;
        }
        else if(islower(password[i]))
        {
            has_lower=true;
        }
        else if(isdigit(password[i]))
        {
            has_digit=true;
        }
        else if(strchr(special_characters,password[i]))
        {
            has_special=true;
        }
    }

    if(length < MAX_LENGTH )
    {
        return 0;
    }
    if(has_upper && has_lower && has_digit && has_special)
    {
        return 3;
    }
    if((has_upper || has_lower)&& has_digit)
    {
        return 2;
    }
    
    return 1;
}