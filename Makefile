# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 16:51:35 by ohaker            #+#    #+#              #
#    Updated: 2025/05/14 17:38:36 by ohaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ftprintf.a
SRC = $(addprefix src/, \
	main.c \
	push_ops.c \
	rev_rotate_ops.c \
	rotate_ops.c \
	swap_ops.c)
	
OBJ = $(SRC:.c=.o)
	
# Color definitions for terminal output
NONE		= \033[0m
GREEN		= \033[32;01m
RED			= \033[31;01m
ORANGE		= \033[33;01m

.SILENT:

all:	$(NAME)

$(NAME): $(OBJ)
	@echo "$(ORANGE)		- Compiling $(NAME)...$(NONE)"
	@gcc $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)		- $(NAME) Compiled -$(NONE)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "$(ORANGE)		- Deleted object files$(NONE)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(ORANGE)		- Deleted $(NAME)$(NONE)"

re: fclean all

mygit:
	@git add .
	@git status
	@echo "$(ORANGE)		- Enter commit message:$(NONE)"; \
	read input; \
	if [ -z "$$input" ]; then \
		echo "$(RED)		- No commit message entered. Exiting.$(NONE)"; \
	else \
		TIMESTAMP=$$(date '+%Y-%m-%d %H:%M'); \
		git commit -m "$$input" -m "Commit date: $$TIMESTAMP"; \
		git push origin main; \
		echo "$(GREEN)		- Pushed to git$(NONE)"; \
	fi

.PHONY: all clean fclean re mygit