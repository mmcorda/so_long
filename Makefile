# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 20:27:18 by mcorda            #+#    #+#              #
#    Updated: 2021/12/03 12:01:07 by mcorda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m

NAME = so_long

# Files

FOLDER_LIBS = libs/

FOLDER = SRCS/

PATH_OBJS = OBJS/

LIBS = $(addprefix ${FOLDER_LIBS},${LIBS_FILE})

LIBS_FILE = so_long.h \
				mlx_keycode.h \

SRC = $(addprefix ${FOLDER},${SRCS})

SRCS =  main.c checking.c define_img.c \
			free_memory.c game_is_over.c \
			get_everything.c gnl.c moves.c \
			print_map.c print_PEC.c \

OBJS = $(SRCS:.c=.o)

LIB = libft.a

LIBFT = Libft/libft.a

# Compilation

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX = minilibx/libmlx.a

LIB_MLX = -I SRCS/main.c -L /libs -lmlx -framework OpenGL -framework AppKit
#A MODIFIER#

# Rules

all: $(NAME) $(LIB_MLX) $(HEADER)

.c.o:
		$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

$(LIB): @make -C Libft all

$(NAME):$(OBJS) $(LIBS)
		@$(CC) $(CFLAGS) $(LIB_MLX) $(LIBFT) $(OBJS) -o $(NAME)
		@echo "\n$(GREEN)[OK]:\t\t$(YELLOW)Minilibx"
		@echo "$(GREEN)[OK]:\t\t$(YELLOW)so_long"

clean:
		$(MAKE) clean -C minilibx/
		$(MAKE) clean -C Libft/
		$(RM) SRCS/.c.o
		@make -C ./Libft clean
		@echo "$(GREEN) [CLEAN]:\t\t$(YELLOW)objs"
		$(RM) $(OBJS)

fclean: clean
			@make -C ./Libft fclean
			@$(RM) $(NAME)
			@printf "The folder has been cleaned \n"
			@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re

