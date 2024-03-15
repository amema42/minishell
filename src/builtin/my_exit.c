/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:49:43 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 15:49:44 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

int	numeric_argument(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
			i++;
		else
			return (1);
	}
	return (0);
}

void	arg_error(char *first, char *var, char *secondigliano)
{
	ft_putstr_fd(first, 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd(secondigliano, 2);
}

int	only_n_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	exit_utils(char **args, int exit_n, int len_args, t_general *general)
{
	if (len_args == 2)
	{
		exit_n = (ft_atoi(args[1]) % 256);
		if (exit_n < 0)
			exit_n = exit_n + 256;
		printf("exit\n");
		free_and_exit(exit_n, general);
	}
	else
	{
		ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 2);
		g_last_exit_status = 1;
		return ;
	}
}

void	handle_exit(char **args, t_general *general)
{
	int	len_args;
	int	exit_n;

	len_args = 1;
	exit_n = 0;
	if (args)
		while (args[len_args])
			len_args++;
	if (len_args == 1)
	{
		printf("exit\n");
		free_and_exit(g_last_exit_status, general);
	}
	else
	{
		if (numeric_argument(args[1]) == 1)
		{
			arg_error("exit\nminishell: exit: ",
				args[1], ": numeric argument required\n");
			g_last_exit_status = 2;
			exit(g_last_exit_status);
		}
		exit_utils(args, exit_n, matrixlen(args), general);
	}
}
