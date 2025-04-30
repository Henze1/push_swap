/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:54:40 by hpodratc          #+#    #+#             */
/*   Updated: 2025/04/30 09:56:48 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_push_swap.h"

int	main(int argc, char *argv[])
{
    int *numbers;
    int i;

    numbers = separate_words(argv, argc);
    i = 0;
    while (i < argc)
    {
        ft_putnbr_fd(numbers[1], 1);
        ++i;
    }
    free(numbers);
    return (0);
}