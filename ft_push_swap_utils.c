/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:43:11 by hpodratc          #+#    #+#             */
/*   Updated: 2025/04/30 15:21:14 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_push_swap.h"

int *separate_words(char *str[], const int size)
{
    int i;
    int *words;

    if (!str)
        return (NULL);
    words = (int *)malloc(sizeof(int) * (size - 1));
    if (!words)
        return (NULL);
    ++str;
    i = 0;
    while (i < size - 1)
    {
        words[1] = ft_atoi(str[i]);
        ++i;
    }
    return words;
}
