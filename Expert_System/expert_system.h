/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:53:57 by emaune            #+#    #+#             */
/*   Updated: 2017/10/19 16:34:34 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_H
# define EXPERT_SYSTEM_H

# include "libft/libft.h"

typedef struct		s_input
{
	char			*line;
	char			*comment;
	char			**rule;
	char			*initial_facts;
	char			*queries;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

typedef struct		s_fact
{
	char			fact;
	int				condition;
	struct s_fact	*next;
	struct s_fact	*prev;
}					t_facts;

t_input				*store_input(int fd);
int					free_store(t_input	**input_head);
int					check_brackets(char *str);
int					is_fact(char *s);
char				**split_rule(char *facts);
int					check_rule_validity(t_input **input_head);
t_facts				*init_facts(t_input *input_head);
t_facts				*init_known_facts(t_facts *facts, t_input *input_head);
char				*standardize_string(char *s);
char				*get_lhs(char **rule);

#endif
