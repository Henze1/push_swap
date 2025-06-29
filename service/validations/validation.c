/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:25:12 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/26 01:40:30 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"
#include "../../headers/validation.h"

int	is_valid(char *str[], const int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (contains_symbol(str[i]) || has_repeated_signs(str[i]))
			return (0);
		else if (is_over_int(str[i]) || is_only_space(str[i]))
			return (0);
		else if (ft_strlen(str[i]) == 1 && !ft_isdigit(str[i][0]))
			return (0);
		else if (is_symbol_between(str[i]) || is_repeated_number(str))
			return (0);
		++i;
	}
	return (1);
}

int	contains_symbol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'
			&& !((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			return (1);
		++i;
	}
	return (0);
}

int	has_repeated_signs(char const *s1)
{
	int	has_sign;
	int	i;

	i = 0;
	has_sign = 0;
	while (s1[i])
	{
		if (s1[i] == '-' || s1[i] == '+')
		{
			if (has_sign)
				return (1);
			has_sign = 1;
		}
		++i;
	}
	return (0);
}

int	is_over_int(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		++i;
	}
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	is_only_space(char const *str)
{
	int	i;

	if (!str || !*str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
		++i;
	}
	return (1);
}
