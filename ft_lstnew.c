#include <stdio.h>
#include <stdlib.h>
typedef struct s_list
{
void *content;
struct s_list *next;
}t_list;

t_list *ft_lstnew(void *content)
{
    t_list  *new;
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
    return (NULL);
    new -> content = content;
    new -> next = NULL;
    return (new);
}

int main()
{
    char *str ="hello";
    char *str1 ="world";
    t_list *node = ft_lstnew(str);
    t_list *node1 = ft_lstnew(str1);
    node->next = node1;
      
      t_list *tmp = node;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }

    free(node);
    free(node1);

    return 0;
}