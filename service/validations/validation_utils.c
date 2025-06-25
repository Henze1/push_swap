/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:34:00 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/15 19:34:56 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/validation.h"

char    *trim_space(char const *s1)
{
    const char  set[] = {9, 10, 11, 12, 13, 32};
    char    *new;

    new = ft_strtrim(s1, set);
    if (!new)
        return (NULL);
    return (new);
}

int is_symbol_between(char const *str)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]))
            flag = 1;
        if (flag && !ft_isdigit(str[i]))
            return (1);
        ++i;
    }
    return (0);
}

int is_repeated_number(char **numarr)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (numarr[i])
    {
        j = i + 1;
        while (numarr[j])
        {
            if (!ft_strcmp(numarr[i], numarr[j]))
                return (1);
            ++j;
        }
        ++i;
    }
    return (0);
}

int ft_strcmp(char const *s1, char const *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        ++i;
    }
    return (s1[i] - s2[i]);
}