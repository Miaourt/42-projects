# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 16:01:11 by llaporte          #+#    #+#              #
#    Updated: 2017/06/06 16:39:20 by llaporte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

LIBFTDIR := libft
UNAME := $(shell uname)
MLXDIR := minilibx/$(UNAME)
MLXVER := $(shell if [ $$(UNAME) == "Darwin" ]; then sw_vers -productVersion | cut -d. -f2; else echo "x11"; fi)

SRCDIR := srcs
SRC := 	main.c \
				img_utils.c \
				fract.c \
				hooks.c \
				nav.c \

SRCS := $(addprefix $(SRCDIR)/, $(SRC))

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:$(SRCDIR)/%.c
	@echo "Compiling $@"
	@gcc -Wall -Wextra -Werror -Ofast -I includes -c $< -o $@

deps:
	@echo "Making libft..."
	@make -C $(LIBFTDIR)
	@echo "Making minilibx..."
	@make -C $(MLXDIR)/$(MLXVER)

$(NAME): deps $(OBJ)
	@echo "Create $(NAME)..."
	gcc -Wall -Wextra -Werror -Ofast $(OBJ) $(LIBFTDIR)/libft.a -L $(MLXDIR)/$(MLXVER) -l mlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\x1b[32;01mDone !\x1b[0m"

linux: deps $(OBJ)
	@echo "Create $(NAME)..."
	gcc -Wall -Wextra -Werror -Ofast $(OBJ) $(MLXDIR)/$(MLXVER)/libmlx_Linux.a $(LIBFTDIR)/libft.a -L $(MLXDIR)/$(MLXVER) -L/usr/include/X11 -lX11 -lXext -L/usr/include/ -o $(NAME)
	@echo "\x1b[32;01mDone !\x1b[0m"

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MLXDIR)/$(MLXVER) clean

re: fclean all
