#include <stdlib.h>

static int num_len(long n)
{
    int len;

    len = 0;
    if (n <= 0)
        len++;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}
char *ft_itoa(int n)
{
    long    nbr;
    int     len;
    char    *s;

    nbr = n;
    len = num_len(nbr);
    s = (char *)malloc(sizeof(char) *(len +1));
    if(!s)
        return (NULL);
    if(nbr < 0)
        nbr = -nbr;
    s[len--] = '\0';
    while(nbr > 0)
    {
        s[len--] = (nbr % 10) + '0';
        nbr /= 10;
    }
    if(n < 0)
        s[0] = '-';
    return (s);

}