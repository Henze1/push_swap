/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_scale.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:44:48 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/19 14:44:54 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sort.h"
#include "../../headers/operations.h"

static int	get_max_bits(t_stack **stack)
{
    t_stack	*head;
    int		max;
    int		max_bits;

    head = *stack;
    max = head->index;
    max_bits = 0;
    while (head)
    {
        if (head->index > max)
            max = head->index;
        head = head->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void    radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    t_stack	*head_a;
    int		i;
    int		j;
    int		stack_size;
    int		max_bits;

    i = 0;
    head_a = *stack_a;
    stack_size = size(head_a);
    max_bits = get_max_bits(stack_a);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < stack_size)
        {
            head_a = *stack_a;
            if (((head_a->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while (size(*stack_b) != 0)
            pa(stack_a, stack_b);
        i++;
    }
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

void    merge_sort(int *arr, int left, int right)
{
    int middle;

    if (left < right)
    {
        middle = left + (right - left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge_halves(arr, left, middle, right);
    }
}
