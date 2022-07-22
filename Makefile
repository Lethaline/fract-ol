# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 17:41:50 by lolemmen          #+#    #+#              #
#    Updated: 2022/07/22 17:51:10 by lolemmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean re fclean all bonus
.SILENT:

NAME = fractol

# Compilation

RM = rm -rf
CC = gcc
FLAGS = -Wall -Wextra #-Werror

# Directories

SRCSDIR = Srcs
INCSDIR = Includes
OBJSDIR = Objs

# Sources

SRC = \
		fractol.c \
		ft_burningship.c \
		ft_close.c \
		ft_colors.c \
		ft_display.c \
		ft_draw.c \
		ft_errors.c \
		ft_inits.c \
		ft_julia.c \
		ft_key_hook.c \
		ft_mandelbrot.c \
		ft_mouse_hook.c \
		ft_parsing.c \
		ft_utils.c \

INC = \
		fractol.h \

# **************************************************************************** #

# Special Chars

LOG_CLEAR = \033[2K
LOG_UP = \033[A
LOG_NOCOLOR = \033[0m
LOG_BLACK = \033[1;30m
LOG_RED = \033[1;31m
LOG_GREEN = \033[1;32m
LOG_YELLOW = \033[1;33m
LOG_BLUE = \033[1;34m
LOG_VIOLET = \033[1;35m
LOG_CYAN = \033[1;36m
LOG_WHITE = \033[1;37m

# **************************************************************************** #

SRCS = $(addprefix $(SRCSDIR)/, $(SRC))
OBJS = $(addprefix $(OBJSDIR)/, $(addsuffix .o, $(basename $(SRC))))
OBJS_DIR = $(sort $(dir $(OBJS)))

INCS_DIR = $(addsuffix /, $(INCSDIR))
INCS = $(addprefix -I , $(INCS_DIR))

all : $(NAME)

$(NAME) : build $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o$(NAME)

build :
	mkdir -p $(OBJSDIR)
	mkdir -p $(OBJS_DIR)

clean :
	$(RM) $(OBJS_DIR)
	$(RM) $(OBJSDIR)

re : fclean all

fclean : clean
	$(RM) $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	$(CC) -c -o $@ $< -Imlx $(INCS) $(FLAGS)
