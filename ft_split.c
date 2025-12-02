static void	free_all(char **arr, int words)
{
	int i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
static int	count_words(const char *s, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while(s[i])
    {
        while(s[i] && s[i] == c)
            i++;
        if(s[i] && s[i] != c)
        {
            count++;
            while(s[i] && s[i] != c)
            i++;
        }
    }
    return (count);
}
static int	word_len(const char *s, char c, int start)
{
    int len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	return len;
}
char **ft_split(char const *s, char c)
{
    char	**result;
	int		words;
	int		i;
	int		j;
	int		len;
    int     index;

    index = 0;
    i = 0;
    words = count_words(s,c);
    result = (char **)malloc(sizeof(char *) * (words + 1));
    if (!result)
		return NULL;
    while (i < words)
    {
        while (s[index] && s[index] == c)
            index++;
        len = word_len(s, c, index);
        result[i] = (char *)malloc(sizeof(char) * (len + 1));
        if (!result[i])
        {
            free_all(result, i);
            return NULL;
        }
        j = 0;
		while (j < len)
			result[i][j++] = s[index++];
		result[i][j] = '\0';
		i++;
    }
    result[words] = NULL;
	return result;
}