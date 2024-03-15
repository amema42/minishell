/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:23:03 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 15:23:05 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

int	get_input_redirection_index(t_general *general)
{
	t_lex	*node;
	int		i;

	i = -1;
	node = general->lexer;
	while (node)
	{
		if (node->token == 4)
			i = node->i;
		node = node->next;
	}
	return (i);
}

int	handle_input_redirections(t_general *general, int index, t_lex *node)
{
	int	file;

	file = 0;
	while (node != NULL)
	{
		if (node->token == 4)
		{
			file = open(node->command, O_RDONLY);
			if (file < 0)
			{
				ft_putstr_fd("Error opening the file\n", 2);
				g_last_exit_status = 1;
				return (-1);
			}
			if (index == node->i)
				general->input_fd = file;
			else
				close(file);
		}
		node = node->next;
	}
}

int	setup_input_redirection(t_general *general)
{
	t_lex	*node;
	int		index;

	node = general->lexer;
	index = get_input_redirection_index(general);
	if (index == -1)
		return (-1);
	if (handle_input_redirections(general, index, node) == -1)
		return (-1);
	return (index);
}
