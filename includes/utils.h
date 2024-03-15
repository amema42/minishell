/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:19:16 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 17:14:49 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_matrix(char **matrix);
void	free_lex(t_lex *head);
void	matrix_clean(t_lex *node);
void	free_general(t_general *general);
void	free_and_exit(int exit_n, t_general *general);
void	print_export(char **matrix);
void	print_matrix(char **matrix);
void	index_list(t_general *general);
void	file_name_handler(t_lex *node);
void	print_matrix(char **matrix);
void	file_name_handler(t_lex *node);
int		dumb_builtin_check(char *command);
int		matrixlen(char **matrix);
int		matrixlen(char **matrix);
int		dumb_builtin_check(char *command);
char	**matrix_duplication(char **matrix);
char	**matrix_newline(char **matrix, char *str);
char	**maxxisplit(char const *s, char c);
char	**matrix_duplication(char **matrix);
char	*cleaner(char *str);
char	*cleaner(char *str);
char	**matrix_duplication(char **matrix);
char	*join_with_free(char *s1, char *s2);
int		is_whitespace_input(const char *str);

#endif
