/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:14:16 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/26 01:40:53 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack_utils.h"

t_stack *create_stack(int number)
{
    t_stack *stack;

    stack  = NULL;
    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->number = number;
    stack->index = -1;
    stack->next = NULL;
    return (stack);
}

void    push(t_stack **stack, t_stack *node)
{
    t_stack *tmp;

    if (!*stack)
        return ;
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}

void    pop(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
}

t_stack *tail(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack)
        return (NULL);
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

int size(t_stack *stack)
{
    int size;
    t_stack *tmp;

    if (!stack)
        return (0);
    size = 0;
    tmp = stack;
    while (tmp)
    {
        ++size;
        tmp = tmp->next;
    }
    return (size);
}