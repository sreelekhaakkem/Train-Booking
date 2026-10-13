#include <string.h>
#include "validation.h"

int validate_password(char password[])
{
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int special = 0;
    int i;

    if(strlen(password) < 8)
        return 0;

    for(i = 0; password[i] != '\0'; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            upper = 1;
        else if(password[i] >= 'a' && password[i] <= 'z')
            lower = 1;
        else if(password[i] >= '0' && password[i] <= '9')
            digit = 1;
        else
            special = 1;
    }

    return upper && lower && digit && special;
}
