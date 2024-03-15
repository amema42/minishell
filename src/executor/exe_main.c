/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:32:35 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 16:32:46 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

void	executor(t_general *general)
{
	t_lex	*tmp;
	int		save_fd[2];

	if (g_last_exit_status != 0 && g_last_exit_status != 130)
		return ;
	save_fd[0] = dup(STDIN_FILENO);
	save_fd[1] = dup(STDOUT_FILENO);
	general->o_flag = re_dir_status(open_fd(general,
				find_correct_redir(general)), general);
	tmp = general->lexer;
	big_redir_finder(general);
	while (tmp)
	{
		if (tmp->token == 0)
			g_last_exit_status = execute_command(tmp, general, save_fd);
		tmp = tmp->next;
	}
	dup2(save_fd[0], STDIN_FILENO);
	dup2(save_fd[1], STDOUT_FILENO);
	close(save_fd[0]);
	close(save_fd[1]);
	general->save_exit_status = g_last_exit_status;
}
