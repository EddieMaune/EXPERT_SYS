/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:12:33 by emaune            #+#    #+#             */
/*   Updated: 2017/10/20 16:54:46 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_sytem.h"

int			is_and(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

int			is_or(char c)
{
		if (c == '|')
		return (1);
	return (0);

}

static int		is_xor(char c)
{
		if (c == '^')
		return (1);
	return (0);
}
