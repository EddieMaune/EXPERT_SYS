# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaune <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 16:42:04 by emaune            #+#    #+#              #
#    Updated: 2017/10/20 10:10:56 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = expert_system

SRC = main.c store_input.c free_store_input.c split_rule.c check_rule_validity.c\
	  init_facts.c init_known_facts.c check_brackets.c is_fact.c\
	  standardize_string.c get_lhs.c get_rhs.c

CC = gcc

LINKER = -Llibft -lft

CFLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
	@make -C libft
	@$(CC)  $(SRC) $(LINKER) -o $(NAME)

clean:
	@rm -f $(NAME)

re:	clean
	@make

