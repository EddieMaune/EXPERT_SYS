/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:36:23 by emaune            #+#    #+#             */
/*   Updated: 2017/10/20 12:27:56 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*lhs;
	char	*rhs;
	t_input	*input_head;
	t_input *temp;
	t_facts	*facts;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putendl("File invalid");
			return (0);
		}
		if(!(input_head = store_input(fd)))
			return (0);
		if (!check_rule_validity(&input_head))
		{
			free_store(&input_head);
			return (0);
		}
		temp = input_head;
		facts = init_facts(temp);
		init_known_facts(facts, temp);
		i = 0;
		while (input_head)
		{
			if (input_head->rule)
			{
				rhs = get_rhs(input_head->rule);
				ft_putstr(rhs);
				ft_putchar('\n');		
			}
			input_head = input_head->next;

		}
		free_store(&temp);
	}
	else
		ft_putendl("Input file unspecified");
	return (0);
}
