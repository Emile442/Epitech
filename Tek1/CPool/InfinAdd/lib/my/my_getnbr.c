/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** Return number
*/

int my_strlen(char const *str);

int is_num(char s)
{
    if ((s >= '0' && s <= '9') || s == '-')
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    long tmp = 0;
    int neg = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            neg += 1;
        i++;
    }
    while ((i != my_strlen(str)) && is_num(str[i]) == 1) {
        if (is_num(str[i]) == 1)
            tmp = ((tmp * 10) + (str[i] - 48));
        if ((is_num(str[i]) == 1 && is_num(str[i-1])) && is_num(str[i+1]) == 0)
            break;
        i++;
    }
    if (neg % 2 == 1)
        tmp = (tmp * (-1));
    if (tmp < -2147483648 || tmp > 2147483647)
        return (0);
    return (tmp);
}