#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  s_len;
    size_t  actual_len;
    char    *substr;

    s_len = ft_strlen(s);
    if (!s)
    return (NULL);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        actual_len = s_len - start;
    else
        actual_len = len;
    substr = (char*)malloc(sizeof(char) * (actual_len +1));
    if(!substr)
    return (NULL);
    ft_strlcpy(substr, s+start, actual_len +1);
    return (substr);


}
