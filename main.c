/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:25:43 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/03 17:17:26 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"
#include "headers/validation.h"

static void	free_array(char ***arr);
static int	contains_empty(char **str);

int	main(int argc, char *argv[])
{
	int		i;
	int		size;
	char	**num_array;

	if (argc < 2)
		return (1);
	--argc;
	++argv;
	num_array = shuffle_split(argv, argc);
	size = count_numbers(num_array);
	if (!is_valid(num_array, size) || contains_empty(argv))
	{
		free_array(&num_array);
		return (ft_putendl_fd("Error", 1), 1);
	}
	push_swap(num_array, size);
	i = 0;
	while (i < size)
	{
		free(num_array[i]);
		++i;
	}
	free(num_array);
	return (0);
}

static void	free_array(char ***arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = -1;
	while ((*arr)[++i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
	}
	free(*arr);
	*arr = NULL;
}

static int	contains_empty(char **str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (is_only_space(str[i++]))
			return (1);
	}
	return (0);
}
