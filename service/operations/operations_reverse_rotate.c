/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:52:36 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/13 10:58:53 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/operations.h"
#include "../../headers/push_swap.h"

void    reverse_rotate_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *last;

    last = *stack;
    while (last->next->next)
        last = last->next;
    tmp = last->next;
    last->next = NULL;
    tmp->next = *stack;
    *stack = tmp;
}

void    rra(t_stack **stack_a)
{
    reverse_rotate_stack(stack_a);
    ft_putendl_fd("rra", 1);
}

void    rrb(t_stack **stack_b)
{
    reverse_rotate_stack(stack_b);
    ft_putendl_fd("rrb", 1);
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate_stack(stack_a);
    reverse_rotate_stack(stack_b);
    ft_putendl_fd("rrr", 1);
}