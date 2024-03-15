/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:23:22 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 15:23:24 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

int	compare_substrings(const char *str, const char *sub, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (str[i] != sub[i])
			return (0);
		i++;
	}
	return (1);
}

char	*find_substring_position(const char *str, const char *sub)
{
	size_t	len;

	len = ft_strlen(sub);
	while (*str != '\0')
	{
		if (compare_substrings(str, sub, len))
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*find_substitution(char *command, t_general *general)
{
	int		index;
	char	*replacement;

	if (strncmp(command, "$?", 2) == 0)
	{
		if (g_last_exit_status == 130)
			general->save_exit_status = 130;
		replacement = ft_itoa(general->save_exit_status);
		return (replacement);
	}
	else
	{
		index = my_setenv(command + 1, NULL, &general->envp2);
		if (index >= 0)
		{
			replacement = ft_strchr(general->envp2[index], '=') + 1;
			return (replacement);
		}
		else
		{
			return ("");
		}
	}
}

char	*calculate_first_part(char **first_part, char *input, char *position)
{
	int		len;

	len = position - input;
	*first_part = ft_substr(input, 0, len);
	return (*first_part);
}

char	*calculate_final_part(char **second_part, char *end_command)
{
	int		len;

	len = strlen(end_command);
	*second_part = ft_substr(end_command, 0, len);
	return (*second_part);
}
