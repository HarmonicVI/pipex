#include "./../includes/pipex.h"

void	free_tab(char **tab)
{
	if (tab == NULL)
		return ;
	size_t	i;

	i = 0;
	while (tab[i])
		ft_memdel(tab[i++]);
	ft_memdel(tab);
}
