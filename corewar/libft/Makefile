# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 12:17:37 by tguillem          #+#    #+#              #
#    Updated: 2018/03/18 01:53:42 by tguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wextra -Wall -Werror -march=native -I./
CC = gcc

NAME = libft.a
BASE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_putchar.c ft_putstr.c ft_putendl.c \
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_iswhitespace.c ft_isblank.c ft_islower.c ft_isupper.c \
	  ft_max.c ft_putnbrbase.c ft_wstrlen.c ft_putwchar.c ft_putwstr.c \
	  ft_min.c ft_itoa_base.c get_next_line.c ft_time.c ft_count_digit.c \
	  ft_isstralnum.c ft_putwchar_fd.c ft_putwstr_fd.c ft_prgm.c ft_path.c \
	  ft_array.c ft_isstrnum.c ft_trim.c endian.c ft_atoi.c ft_itoa.c \
	  resource_manager.c exit_utils.c

STRING = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		 ft_strncat.c ft_strlcat.c ft_strstr.c ft_strcmp.c ft_strncmp.c \
		 ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strnew.c ft_strdel.c \
		 ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		 ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		 ft_strsplit.c ft_strtrimch.c ft_strtrimcmp.c ft_strsplitcmp.c \
		 ft_memset.c ft_memalloc.c ft_memdel.c ft_memcpy.c ft_memccpy.c \
		 ft_memmove.c ft_memchr.c ft_memcmp.c ft_bzero.c

PRINTF = ft_nbrlen.c ft_printf.c ft_printu.c internal_printf.c manage_number.c \
		 manage_specials.c manage_str.c manage_str.c manage_wstr.c \
		 manager_base.c parser.c utils.c

LIST = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	   ft_lstsize.c ft_lstmap.c ft_lstget.c

MATHS = ft_maths.c vector3d_lib.c vector3d_operator.c matrix_lib.c \
	   vector3d_spheric_operations.c matrix_operations.c

SRCS = $(addprefix base/, $(BASE)) $(addprefix string/, $(STRING)) \
	   $(addprefix list/, $(LIST)) $(addprefix ft_printf/, $(PRINTF)) \
	   $(addprefix maths/, $(MATHS))

OBJ = $(SRCS:.c=.o)
REMOVE = $(OBJ)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "$<"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(REMOVE)

fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
