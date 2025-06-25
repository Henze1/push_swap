/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:12:09 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/16 00:14:20 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H
# include <stdlib.h>

typedef struct  s_stack
{
    int number;
    int index;
    struct s_stack *next;
} t_stack;

t_stack *create_stack(int number);
void    push(t_stack **stack, t_stack *node);
void    pop(t_stack **stack);
t_stack *tail(t_stack **stack);
int size(t_stack *stack);

#endif //STACK_UTILS_H
