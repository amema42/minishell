/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:19:52 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 15:19:54 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

void	handle_exit(char **args, t_general *general);
void	handle_cd(t_general *general, t_lex *node);
void	handle_pwd(void);
void	handle_export(t_general *general, t_lex *node);
void	handle_unset(t_general *general, t_lex *node);
void	handle_env(t_general *general);
void	handle_echo(t_general *general, t_lex *node);
void	supporter_remover(char *str, char c);
void	show_export_error(char *arg);
void	show_cd_error(char *cmd2, char *error);
int		my_setenv(char *name, char *value, char ***environ);
int		ft_idx_quotes(char *str, char c);
int		ft_nb_quotes(char *str, char c);
int		remove_quotes(char *str, int idx_double, t_general *general, int index);
int		quotes_main_manager(char *str, t_general *general, int i);
int		ft_cd_only(char **env, char **command2,
			t_general *general, char *old_dir);
int		ft_change_dir(char *new_dir, char **cmd2,
			t_general *general, char *old_dir);
int		is_accepted_variable(char *var);
int		len_equalchar(char *str);

#endif
