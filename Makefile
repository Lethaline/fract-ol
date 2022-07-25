# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 17:41:50 by lolemmen          #+#    #+#              #
#    Updated: 2022/07/25 15:57:59 by lolemmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean re fclean all
.SILENT:

NAME = fractol

# Compilation

RM = rm -rf
CC = gcc
FLAGS = -Wall -Wextra -Werror

# Directories

SRCSDIR = Srcs
INCSDIR = Includes
OBJSDIR = Objs
MLXDIR = minilibx

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

MLX_INC	= -I $(MLXDIR)
MLX_LIB	= $(addprefix $(MLXDIR)/,libmlx.a)
MLX_LINK = -L $(MLXDIR) -l mlx -framework OpenGL -framework AppKit

all : $(NAME) $(MLX_LIB)

$(NAME) : mlx $(OBJS)
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_CYAN)assembling... $(LOG_NOCOLOR)$(LOG_UP)"
	$(CC) $(OBJS) $(MLX_LINK) -lm -o$(NAME)
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_GREEN)compiled $(LOG_GREEN)✓$(LOG_NOCOLOR)"

mlx :
	@make -C $(MLXDIR)
	

clean :
	$(RM) $(OBJS_DIR)
	$(RM) $(OBJSDIR)
	make -C $(MLXDIR) clean 

re : fclean all
	

fclean : clean
	$(RM) $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	mkdir -p $(OBJSDIR) $(OBJS_DIR)
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	$(CC) -c -o $@ $< $(MLX_INC) $(INCS) $(FLAGS)
