/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:48:22 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/26 01:40:02 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/operations.h"
#include "../../headers/push_swap.h"

void swap_stack(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}

void sa(t_stack **stack_a)
{
    swap_stack(stack_a);
    ft_putendl_fd("sa", 1);
}

void sb(t_stack **stack_b)
{
    swap_stack(stack_b);
    ft_putendl_fd("sb", 1);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap_stack(stack_a);
    swap_stack(stack_b);
    ft_putendl_fd("ss", 1);
}