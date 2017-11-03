/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inference_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:17:47 by emaune            #+#    #+#             */
/*   Updated: 2017/11/03 14:11:39 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"


static int				is_known(t_facts *facts, char q)
{
	t_facts		*index;

	index = facts;
	while (index)
	{
		if (index->fact == q)
		{
			if (index->known)
				return (1);
		}
		index = index->next;
	}
	return (0);
}

static int				is_true(t_facts *facts, char q)
{
	t_facts		*index;

	index = facts;
	while (index)
	{
		if (index->fact == q)
		{
			if (index->condition)
				return (1);
		}
		index = index->next;
	}
	return (0);
}

static int			lhs_known(t_facts *facts, char *side)
{
	int		i;
	t_facts	*index;

	i = 0;
	while (side[i])
	{
		if (ft_isupper(side[i]))
		{
			index = facts;
			while (index)
			{
				if (side[i] == index->fact)
				{
					if (!index->fact)
						return (0);
				}
				index = index->next;
			}
		}
		i++;
	}
	return (1);
}

char			*put_delimiter(char *str)
{
	char		*result;
	int			i;
	int			j;

	i = 0;
	j = 0;
	result = ft_strnew(ft_strlen(str) + ft_strlen(str));
	while (str[i])
	{
		result[j] = str[i];
		if (str + i != str + ft_strlen(str) - 1)
			result[j + 1] = ' ';
		j += 2;
		i++;
	}
	return (result);
}

int				rhs_has_op(char *str)
{
	if (ft_strchr(str, '|') || ft_strchr(str, '+') || ft_strchr(str, '!') || ft_strchr(str, '^'))
		return (1);
	return (0);
}

t_facts			*update_facts(t_facts *facts, char *side, char q)
{
	char	*bit_pat;
	char	*str;
	t_facts *index;
	int		rhs;
	int		x;

	printf("%s\t**>Converting to bit string<***\n\n", side);
//	printf("%s\n",convert_side(side));
	bit_pat = postfix_to_bit(convert_side(side), facts);
	printf("%s\t=",bit_pat);
	str = put_delimiter(bit_pat);
	index = facts;
	free(bit_pat);
	//printf("hello");
	while (index)
	{
		if (index->fact == q)
		{
			x = index->condition;
			index->condition = rpn_calc(str);
					printf("( %d == %c)\n",index->condition, index->fact);
			if (index->condition != x && index->known)
				printf("\n##################\nContradiction Detected:\n%c cannot simultaneously be True and False\n###########################s\n", q);

			index->known = 1;
		//	printf("%s = %d\n", str, index->condition);
			break	;
		}
		index = index->next;
	}
	return (facts);
}

static t_facts			*backward_chain(t_input		*input_head, t_facts *facts, char q)
{
	t_facts		*f;
	t_input		*index;
	t_input		*get_q;
	char		*rhs;
	char		*lhs;
	int			i;
	int			cert;

	f = facts;
	index = input_head;
	cert = 1;
	while (index)
	{
		if (index->rule)
		{
			rhs = get_rhs(index->rule);
			lhs = get_lhs(index->rule);
		//	if (!rhs_has_op(rhs))
			{
				if (ft_strchr(rhs, q))
				{
					cert = 0;
					i = 0;
					while (lhs[i])
					{
						if (ft_isupper(lhs[i]))
						{
							if (is_known(facts, lhs[i]))
							{
								i++;
								continue	;
							}
							else
							{
								if (!is_known(facts, q))
									printf("%c is unknown ----- Rule: %s \n", q, lhs);
								facts = backward_chain(input_head, facts, lhs[i]);
								//	printf("%c is UNknown\n", lhs[i]);
							}
						}
						i++;
					}
					get_q = input_head;
					while (get_q)
					{
						if (get_q->queries)
						{
							if (!ft_strchr(get_q->queries, q))
							{
							printf("\t%c is a sub-goal.------ Rule: %s\n", q, lhs);
									facts = update_facts(facts, lhs, q);
								if(	is_known(facts,q))
										printf("%c is known\n", q);
							//	return (facts);
							}
							else if (ft_strchr(get_q->queries, q))
							{
								facts = update_facts(facts, lhs, q);
								if (is_known(facts, q) && is_true(facts, q))
									printf("%c is True\n", q);
								else if (is_known(facts, q) && !is_true(facts, q))
									printf("%c is False\n", q);
							}
							break	;
						}
						get_q = get_q->next;
					}
				}
			}
		}
		index = index->next;
	}
	//	printf("\n****************************************\n");
	if (cert)
	{
		ft_putstr("Uncertain: No rule found to prove ");
		ft_putchar(q);
		ft_putchar('\n');
	//	return (facts);
	}
	return (facts);
}

t_facts			*inference_engine(t_input	*input_head, t_facts *facts)
{
	t_input		*index;
	t_facts		*head;
	t_input		*x;
	char		*queries;
	int			i;

	i = 0;
	index = input_head;
	while (index)
	{
		if (index->queries)
		{
			queries = index->queries;
			while (queries[i])
			{
				head = facts;
				while (head)
				{
					if (head->fact == queries[i])
					{
						if (head->known)
						{
							ft_putchar(head->fact);
							ft_putstr(" is ");
							if (head->condition)
								ft_putstr("True\n");
							else
								ft_putstr("False\n");
						}
						else
						{
							printf("%c is an unknown QUERY---Looking to for rule to prove query\n", queries[i]);
							backward_chain(input_head, facts, queries[i]);
							break	;	
							/*
							   x = input_head;
							   ft_putchar(head->fact);
							   ft_putstr(" is ");
							   ft_putstr("Unknown\n");*/
						}
					}
					head = head->next;
				}
				i++;
			}
			break	;
		}
		index = index->next;
	}
	return (facts);
}
