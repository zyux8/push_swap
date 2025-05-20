# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 16:51:35 by ohaker            #+#    #+#              #
#    Updated: 2025/05/18 17:05:55 by ohaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror
SRC = $(addprefix src/, \
	list_helpers.c \
	main.c \
	push_ops.c \
	radix.c \
	rev_rotate_ops.c \
	rotate_ops.c \
	swap_ops.c \
	utils.c)
	
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
	@make -C libft --silent
	@make -C ft_printf --silent
	@gcc $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)		- $(NAME) Compiled -$(NONE)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make clean -C libft
	@make clean -C ft_printf
	@echo "$(ORANGE)		- Deleted object files$(NONE)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C ft_printf
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
		git push origin master; \
		echo "$(GREEN)		- Pushed to git$(NONE)"; \
	fi

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap "string" &> VALGRIND

.PHONY: all clean fclean re mygit valgrind