/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:19:40 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 15:19:42 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <limits.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "structure.h"
# include "parser.h"
# include "visual.h"
# include "utils.h"
# include "builtin.h"
# include "executor.h"

extern int	g_last_exit_status;

#endif
