/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:16:07 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/26 01:40:22 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sort.h"

t_stack *find_max(t_stack **stack)
{
    t_stack *max;
    t_stack *tmp;

    max = *stack;
    tmp = (*stack)->next;
    while (tmp)
    {
        if (tmp->number > max->number)
            max = tmp;
        tmp = tmp->next;
    }
    return (max);
}

t_stack *find_min(t_stack **stack)
{
    t_stack *min;
    t_stack *tmp;

    min = *stack;
    tmp = (*stack)->next;
    while (tmp)
    {
        if (tmp->number < min->number)
            min = tmp;
        tmp = tmp->next;
    }
    return (min);
}

void    merge_halves(int *arr, int left, int middle, int right)
{
    int *left_temp;
    int *right_temp;
    int n1;
    int n2;
    int vars[5];

    n1 = middle - left + 1;
    n2 = right - middle;
    left_temp = (int *)malloc(n1 * sizeof(int));
    right_temp = (int *)malloc(n2 * sizeof(int));
    if (!left_temp || !right_temp)
        exit(1);
    copy_data_to_temp(left_temp, arr, left, n1);
    copy_data_to_temp(right_temp, arr, middle + 1, n2);
    vars[0] = 0;
    vars[1] = 0;
    vars[2] = left;
    vars[3] = n1;
    vars[4] = n2;
    execute_merge(arr, left_temp, right_temp, vars);
    free(left_temp);
    free(right_temp);
}

void    execute_merge(int *arr, int *l_tmp, int *r_tmp, int *vars)
{
    while (vars[0] < vars[3] && vars[1] < vars[4])
    {
        if (l_tmp[vars[0]] <= r_tmp[vars[1]])
        {
            arr[vars[2]] = l_tmp[vars[0]];
            vars[0] = vars[0] + 1;
        }
        else
        {
            arr[vars[2]] = r_tmp[vars[1]];
            vars[1] = vars[1] + 1;
        }
        vars[2] = vars[2] + 1;
    }
    while (vars[0] < vars[3])
    {
        arr[vars[2]] = l_tmp[vars[0]];
        vars[0] = vars[0] + 1;
        vars[2] = vars[2] + 1;
    }
    while (vars[1] < vars[4])
    {
        arr[vars[2]] = r_tmp[vars[1]];
        vars[1] = vars[1] + 1;
        vars[2] = vars[2] + 1;
    }
}

void    copy_data_to_temp(int *dest, int *src, int start_idx, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        dest[i] = src[start_idx + i];
        i = i + 1;
    }
}