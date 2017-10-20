/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rule_to_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:48:02 by emaune            #+#    #+#             */
/*   Updated: 2017/10/20 16:54:42 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

int         is_and(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

int         is_or(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

static int      is_xor(char c)
{
	if (c == '^')
		return (1);
	return (0);
}

char		get_operand(char *side)
{
	int		i;

	i = 0;
	while (side[i])
	{
		if (is_add(side[i]))
			return (
	}
}

t_tree		*convert_rule_to_tree(char *side)
{
	t_tree	*rule;
	int		i;

	rule = (t_tree*)malloc(sizeof(t_tree));
	i = 0;
	while (rule[i])
	{
		i++;
	}
}
