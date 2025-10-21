# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 11:17:15 by dabdulka          #+#    #+#              #
#    Updated: 2025/10/14 20:06:43 by dabdulka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC         = src/read_map.c src/rect_map.c src/main.c
OBJ         = $(SRC:.c=.o)

FT_PRINTF_DIR = include/ft_printf
LIBFT_DIR = include/libft

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBS        = $(FT_PRINTF_LIB) $(LIBFT_LIB)

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@echo "linking $(NAME)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(NAME) created successfully!"

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory clean
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory fclean
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory fclean

re: fclean all

libs: $(LIBS)

.PHONY: all clean fclean re libs

