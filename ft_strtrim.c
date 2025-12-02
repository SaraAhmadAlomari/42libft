#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	char_in_set(char c, const char *set)
{
    int i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}
char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    char    *new_str;
    size_t  i;

    if (!s1 || !set)
    return (NULL);
    start = 0;
    end = ft_strlen(s1);
    i = 0;
    while (s1[start] && char_in_set(s1[start], set))
        start++;
    while (end > start && char_in_set(s1[end -1], set))
        end--;
    new_str = malloc(sizeof(char) * (end - start +1));
    if (!new_str)
        return (NULL);
    while (start < end)
        new_str[i++] = s1[start++];
    new_str[i] = '\0';
    return (new_str);
}
int main(void)
{
    char *s1 = "abhello";
    char *set = "abc";
    char *result;

    result = ft_strtrim(s1, set);
    if (result)
    {
        printf("Original: \"%s\"\n", s1);
        printf("Set: \"%s\"\n", set);
        printf("Trimmed: \"%s\"\n", result);
        free(result);
    }
    else
        printf("Memory allocation failed\n");

    return 0;
}