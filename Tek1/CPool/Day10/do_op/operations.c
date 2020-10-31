/*n2
** EPITECH PROJECT, 2018
** operations
** File description:
** Operators
*/

#include "my.h"
#include <unistd.h>

int ad(int a, int b)
{
    my_put_nbr(a + b);
    return (0);
}

int so(int a, int b)
{
    my_put_nbr(a - b);
    return (0);
}

int mu(int a, int b)
{
    my_put_nbr(a * b);
    return (0);
}

int di(int a, int b)
{
    if ( b != 0)
        my_put_nbr(a / b);
    else
        write(2, "Stop: division by zero", 23);
    return (0);
}

int mo(int a, int b)
{
    if ( b != 0)
        my_put_nbr(a % b);
    else
        write(2, "Stop: modulo by zero", 21);
    return (0);
}