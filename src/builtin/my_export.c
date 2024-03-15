/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:49:01 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 15:49:36 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

void	my_export(char *arg, char ***env, char ***enexp)
{
	char	*name;
	char	*value;

	name = NULL;
	value = NULL;
	if (is_accepted_variable(arg))
	{
		name = ft_substr(arg, 0, len_equalchar(arg));
		if (len_equalchar(arg) != ft_strlen(arg))
			value = ft_substr(arg, len_equalchar(arg), ft_strlen(arg));
		if (name != NULL && value == NULL)
		{
			if (my_setenv(name, value, enexp) == -1)
				*enexp = matrix_newline(*enexp, name);
			return ;
		}
		my_setenv(name, value, env);
		my_setenv(name, value, enexp);
	}
	else
		show_export_error(arg);
	free(name);
	free(value);
}

void	handle_export(t_general *general, t_lex *node)
{
	int	i;

	i = 1;
	if (node->command2[i] == NULL)
		print_export(general->enexp);
	while (node->command2[i])
	{
		my_export(node->command2[i], &(general->envp2), &(general->enexp));
		i++;
	}
}
