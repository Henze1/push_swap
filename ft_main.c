/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:54:40 by hpodratc          #+#    #+#             */
/*   Updated: 2025/04/30 15:21:16 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_push_swap.h"

int	main(int argc, char *argv[])
{
//    int *numbers;
    int i;

    if (argc < 2)
		return (0);
//    numbers = separate_words(argv, argc);
//    i = 0;
//    while (i < argc - 1)
//    {
//        ft_putnbr_fd(numbers[i], 1);
//		ft_putchar_fd(' ', 1);
//        ++i;
//    }
//    free(numbers);

    i = 0;
    while (i < argc)
    {
    	ft_putstr_fd(argv[i], 1);
        ft_putchar_fd(' ', 1);
    	++i;
    }
    return (0);
}