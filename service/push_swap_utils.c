/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:25:43 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/26 01:40:47 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/sort.h"

int *separate_numbers(char *str[], const int size)
{
    int i;
    int *numbers;

    if (!str)
        return (NULL);
    numbers = (int *)malloc(sizeof(int) * size);
    if (!numbers)
        return (NULL);
    i = 0;
    while (i < size)
    {
        numbers[i] = ft_atoi(str[i]);
        ++i;
    }
    return numbers;
}

char	*ft_strjoin_two(char *s1, char const *s2)
{
    size_t	s1len;
    size_t	s2len;
    char	*new_s;

    if (!s1 || !s2)
        return (NULL);
    s1len = ft_strlen(s1);
    s2len = ft_strlen(s2);
    new_s = (char *)malloc(s1len + s2len + 1);
    if (new_s == NULL)
        return (NULL);
    ft_memcpy(new_s, s1, s1len);
    ft_memcpy(new_s + s1len, s2, s2len);
    new_s[s1len + s2len] = '\0';
    free(s1);
    return (new_s);
}

int		count_numbers(char **num_arr)
{
    int	numbers;

    numbers = 0;
    while (num_arr[numbers])
        ++numbers;
    return (numbers);
}

void    normalize_stack(t_stack **stack)
{
    int i;
    int stck_size;
    int *arr;
    t_stack *current;

    stck_size = size(*stack);
    if (stck_size == 0) return;
    arr = (int *)malloc(sizeof(int) * stck_size);
    if (!arr)
        exit(1);
    current = *stack;
    i = 0;
    while (i < stck_size)
    {
        arr[i++] = current->number;
        current = current->next;
    }
    merge_sort(arr, 0, stck_size - 1);
    current = *stack;
    while (current)
    {
        i = 0;
        while (i < stck_size)
        {
            if (current->number == arr[i])
            {
                current->index = i;
                break;
            }
            ++i;
        }
        current = current->next;
    }
    free(arr);
}