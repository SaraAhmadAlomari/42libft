void del(void *content)
{
    free(content);
}
t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
    t_list *new;
    t_list *node;
    void *new_content;

    new = NULL;
    node = NULL;
    if(!lst || !f || !del)
        return (NULL);
    while (lst)
    {
       new_content = f(lst->content);
       node = ft_lstnew(new_content);
       if(!node)
       {
        del(new_content);
        ft_lstclear(&new,del);
       }
        ft_lstadd_back(&new,node);
       lst = lst->next;
    }
    return (new);
}
