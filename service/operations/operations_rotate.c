/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:51:15 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/13 10:52:04 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/operations.h"
#include "../../headers/push_swap.h"

void    rotate_stack(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
}

void    ra(t_stack **stack_a)
{
    rotate_stack(stack_a);
    ft_putendl_fd("ra", 1);
}

void    rb(t_stack **stack_b)
{
    rotate_stack(stack_b);
    ft_putendl_fd("rb", 1);
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate_stack(stack_a);
    rotate_stack(stack_b);
    ft_putendl_fd("rr", 1);
}