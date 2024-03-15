/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:19:46 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 16:55:04 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

int		find_correct_redir(t_general *general);
int		open_fd(t_general *general, int i);
int		re_dir_status(int index, t_general *general);
int		re_in(t_lex *node, t_general *general, int *save_fd);
int		setup_input_redirection(t_general *general);
int		re_out(t_lex *node, t_general *general, int *save_fd);
int		hd_manager(t_general *general);
void	executor(t_general *general);
void	builtinmanager(t_lex *node, t_general *general);
int		execute_command(t_lex *node, t_general *general, int *save_fd);
void	big_redir_finder(t_general *general);

#endif
