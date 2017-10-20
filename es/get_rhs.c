/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lhs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:55:10 by emaune            #+#    #+#             */
/*   Updated: 2017/10/20 10:56:26 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

char		*get_rhs(char	**rule)
{
	int		i;
	char	*lhs;
	char	*temp;

	i = 0;
	lhs = ft_strnew(0);
	while (rule[i])
	{
		if (!ft_strcmp(rule[i], "<=>") || !ft_strcmp(rule[i], "=>"))
		{
			i++;
			while (rule[i])
			{
				temp = lhs;
				lhs = ft_strjoin(temp, rule[i]);
				free(temp);
				i++;	
			}
			break	;
		}
		i++;
	}
	return (lhs);
}
