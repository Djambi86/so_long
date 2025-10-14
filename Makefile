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

NAME        := so_long

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g
AR          := ar rcs
RM          := rm -f

# External libs to build first
LIB_DIRS    := include/ft_printf include/libft
FTPRINTF_A  := include/ft_printf/libftprintf.a
LIBFT_A		:= include/libft/libft.a

# Project sources
LIB_SRCS    := src/read_map.c src/rect_map.c
MAIN_SRC    := src/main.c

LIB_OBJS    := $(LIB_SRCS:.c=.o)
MAIN_OBJ    := $(MAIN_SRC:.c=.o)

# **************************************************************************** #
#                                   RULES                                       #
# **************************************************************************** #

all: libs $(NAME)

# Build sub-libraries first
libs:
	@for dir in $(LIB_DIRS); do \
		$(MAKE) -C $$dir; \
	done

# Link the final executable (NOW includes your objects!)
$(NAME): $(MAIN_OBJ) $(LIB_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(LIB_OBJS) $(FTPRINTF_A) $(LIBFT_A) -o $(NAME)

# Compile rules
%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

# Housekeeping
clean:
	$(RM) $(LIB_OBJS) $(MAIN_OBJ)
	@for dir in $(LIB_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	$(RM) $(NAME)
	@for dir in $(LIB_DIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

.PHONY: all libs clean fclean re

