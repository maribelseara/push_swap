# include "push_swap.h"

long long int   ft_atol(const char   *str)
{
    long long int   num;
    int is_negative;

    is_negative = 1;
    num = 0;
    while(ft_isspace(*str) == 1)
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            is_negative = -1;
        str++;
    }
    while(*str && *str >= '0' && *str <='9')
    {
       num = num * 10 + (*str - '0');
       str++;
    }
    num = num * is_negative;
    return(num);
}

