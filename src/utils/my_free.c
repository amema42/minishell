/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:35 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 16:40:38 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

void	free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free (matrix[i]);
		i++;
	}
	free (matrix);
}

void	matrix_clean(t_lex *node)
{
	if (node->next)
		matrix_clean(node->next);
	free_matrix(node->command2);
	free(node->command);
	free(node);
}

void	free_lex(t_lex *node)
{
	if (node == NULL)
		return ;
	if (node->next)
		free_lex(node->next);
	if (node->command2 != NULL)
		free_matrix(node->command2);
	free(node->command);
	free(node);
}

void	free_general(t_general *general)
{
	free_matrix(general->envp2);
	free_matrix(general->enexp);
	if (general->path != NULL)
		free_matrix(general->path);
}

void	free_and_exit(int exit_n, t_general *general)
{
	if (general != NULL)
	{
		free_general(general);
		free_lex(general->lexer);
	}
	clear_history();
	exit(exit_n);
}
