/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 11:46:18 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/03 17:18:03 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H
# include "../libft/libft.h"

int		is_valid(char *str[], const int size);
int		contains_symbol(char *str);
int		has_repeated_signs(char const *s1);
int		is_over_int(char *str);
int		is_only_space(char const *str);
int		is_symbol_between(char const *str);
int		is_repeated_number(char **numarr);
int		ft_strcmp(char const *s1, char const *s2);
long	ft_atol(const char *str);

#endif
