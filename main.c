/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:25:43 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/16 00:17:21 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"
#include "headers/validation.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	size;
	char	**num_array;

    if (argc < 2)
		return (1);
	--argc;
	++argv;
	num_array = shuffle_split(argv, argc);
	size = count_numbers(num_array);
    if (!is_valid(num_array, size))
    	return (ft_putendl_fd("Error", 1), 1);
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
