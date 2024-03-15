/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:04:37 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 13:04:38 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

void	ft_unsetenv(t_general *general, t_lex *node)
{
	int		i;
	int		j;
	int		index;
	char	**envtmp;

	index = my_setenv(node->command2[1], NULL, &(general->envp2));
	if (index == -1)
		return ;
	envtmp = ft_calloc(matrixlen(general->envp2), sizeof(char *));
	i = 0;
	j = 0;
	while (general->envp2[i])
	{
		if (i == index)
			i++;
		if (general->envp2[i])
		{
			envtmp[j] = ft_strdup(general->envp2[i]);
			i++;
		}
		j++;
	}
	envtmp[j] == NULL;
	free_matrix(general->envp2);
	general->envp2 = envtmp;
}

void	ft_unset_expander(t_general *general, t_lex *node)
{
	int		i;
	int		j;
	int		index;
	char	**envtmp;

	index = my_setenv(node->command2[1], NULL, &(general->enexp));
	if (index == -1)
		return ;
	envtmp = ft_calloc(matrixlen(general->enexp), sizeof(char *));
	i = 0;
	j = 0;
	while (general->enexp[i])
	{
		if (i == index)
			i++;
		if (general->enexp[i])
		{
			envtmp[j] = ft_strdup(general->enexp[i]);
			i++;
		}
		j++;
	}
	envtmp[j] == NULL;
	free_matrix(general->enexp);
	general->enexp = envtmp;
}

void	handle_unset(t_general *general, t_lex *node)
{
	if (!node->command2[1])
		return ;
	ft_unsetenv(general, node);
	ft_unset_expander(general, node);
}
