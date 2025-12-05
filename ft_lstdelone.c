void del(void *content)
{
    free(content);
}

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
   if(!lst || !del)
    return;
   del(lst->content);
   free(lst); 

}