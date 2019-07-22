# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 10:37:17 by tcourtil          #+#    #+#              #
#    Updated: 2019/04/04 14:47:17 by tcourtil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

ifdef OS
else
	STRICT = -Wall -Wextra -Werror
endif

CFLAGS = $(STRICT) -I ./include

LIBFT_URL = ./src/libft
GNL_URL = ./src/gnl
PRINTF_URL = ./src/printf
DICO_URL = ./src/dico
MATH_URL = ./src/math


SRCMATH = $(MATH_URL)/ft_vec4new.o \
		  $(MATH_URL)/ft_vec4free.o \
		  $(MATH_URL)/ft_mat4new.o \
		  $(MATH_URL)/ft_mat4free.o \
		  $(MATH_URL)/ft_vecxmat4.o \


SRCGNL = $(GNL_URL)/get_next_line.o \

SRCDICO = $(DICO_URL)/ft_diconew.o \
		$(DICO_URL)/ft_keyvalue.o \
		$(DICO_URL)/ft_dicoget.o \
		$(DICO_URL)/ft_dicoput.o \
		$(DICO_URL)/ft_arraynew.o \
		$(DICO_URL)/ft_arrayfree.o \
		$(DICO_URL)/ft_arrayadd.o \
		$(DICO_URL)/ft_arrayfor.o \
		$(DICO_URL)/ft_arrayext.o \
		$(DICO_URL)/ft_arrayget.o \
		$(DICO_URL)/ft_arrayrem.o \
		$(DICO_URL)/ft_dicohaskey.o \
		$(DICO_URL)/ft_dicofree.o \
		$(DICO_URL)/ft_arrayclone.o \


SRCLIB = $(LIBFT_URL)/ft_utoa.o \
		$(LIBFT_URL)/ft_lstdelall.o \
		$(LIBFT_URL)/ft_convert.o \
		$(LIBFT_URL)/ft_strpbrki.o \
		$(LIBFT_URL)/ft_lstadde.o \
		$(LIBFT_URL)/ft_min.o \
		$(LIBFT_URL)/ft_max.o \
		$(LIBFT_URL)/ft_clamp.o \
		$(LIBFT_URL)/ft_pow.o \
		$(LIBFT_URL)/ft_atof.o \
		$(LIBFT_URL)/ft_floor.o \
		$(LIBFT_URL)/ft_ceil.o \
		$(LIBFT_URL)/ft_round.o \
		$(LIBFT_URL)/ft_lstmap.o \
		$(LIBFT_URL)/ft_lstiter.o \
		$(LIBFT_URL)/ft_lstadd.o \
		$(LIBFT_URL)/ft_lstdel.o \
		$(LIBFT_URL)/ft_lstnew.o \
		$(LIBFT_URL)/ft_lstdelone.o \
		$(LIBFT_URL)/ft_putnbr_fd.o \
		$(LIBFT_URL)/ft_putendl_fd.o \
		$(LIBFT_URL)/ft_putstr_fd.o \
		$(LIBFT_URL)/ft_putchar_fd.o \
		$(LIBFT_URL)/ft_putnbr.o \
		$(LIBFT_URL)/ft_putendl.o \
		$(LIBFT_URL)/ft_putstr.o \
		$(LIBFT_URL)/ft_putchar.o \
		$(LIBFT_URL)/ft_itoa.o \
		$(LIBFT_URL)/ft_strsplit.o \
		$(LIBFT_URL)/ft_strtrim.o \
		$(LIBFT_URL)/ft_strjoin.o \
		$(LIBFT_URL)/ft_strsub.o \
		$(LIBFT_URL)/ft_strnequ.o \
		$(LIBFT_URL)/ft_strequ.o \
		$(LIBFT_URL)/ft_strmapi.o \
		$(LIBFT_URL)/ft_strmap.o \
		$(LIBFT_URL)/ft_striteri.o \
		$(LIBFT_URL)/ft_striter.o \
		$(LIBFT_URL)/ft_strclr.o \
		$(LIBFT_URL)/ft_memalloc.o \
		$(LIBFT_URL)/ft_memdel.o \
		$(LIBFT_URL)/ft_strnew.o \
		$(LIBFT_URL)/ft_strdel.o \
		$(LIBFT_URL)/ft_atoi.o \
		$(LIBFT_URL)/ft_memcmp.o \
		$(LIBFT_URL)/ft_memchr.o \
		$(LIBFT_URL)/ft_memmove.o \
		$(LIBFT_URL)/ft_memcpy.o \
		$(LIBFT_URL)/ft_memccpy.o \
		$(LIBFT_URL)/ft_bzero.o \
		$(LIBFT_URL)/ft_memset.o \
		$(LIBFT_URL)/ft_strcmp.o \
		$(LIBFT_URL)/ft_strncmp.o \
		$(LIBFT_URL)/ft_strnstr.o \
		$(LIBFT_URL)/ft_strstr.o \
		$(LIBFT_URL)/ft_strrchr.o \
		$(LIBFT_URL)/ft_strchr.o \
		$(LIBFT_URL)/ft_strncpy.o \
		$(LIBFT_URL)/ft_strcpy.o \
		$(LIBFT_URL)/ft_strlcat.o \
		$(LIBFT_URL)/ft_strncat.o \
		$(LIBFT_URL)/ft_strcat.o \
		$(LIBFT_URL)/ft_strdup.o \
		$(LIBFT_URL)/ft_strlen.o \
		$(LIBFT_URL)/ft_isalpha.o \
		$(LIBFT_URL)/ft_isdigit.o \
		$(LIBFT_URL)/ft_isalnum.o \
		$(LIBFT_URL)/ft_isascii.o \
		$(LIBFT_URL)/ft_isprint.o \
		$(LIBFT_URL)/ft_toupper.o \
		$(LIBFT_URL)/ft_tolower.o \
		$(LIBFT_URL)/ft_ftoa.o \
		$(LIBFT_URL)/ft_strnbadd.o \
		$(LIBFT_URL)/ft_strnbmul.o \
		$(LIBFT_URL)/ft_strnbdiv.o \
		$(LIBFT_URL)/ft_strnbrem.o \
		$(LIBFT_URL)/ft_abs.o \
		$(LIBFT_URL)/ft_dtoa.o \
		$(LIBFT_URL)/ft_lstsize.o \
		$(LIBFT_URL)/ft_lstdelwith.o \
		$(LIBFT_URL)/ft_lstdelallwith.o \



SRC = $(PRINTF_URL)/ft_printff.o \
		 $(PRINTF_URL)/ft_printfu.o \
		 $(PRINTF_URL)/ft_printfohh.o \
		 $(PRINTF_URL)/ft_printfoh.o \
		 $(PRINTF_URL)/ft_printfoll.o \
		 $(PRINTF_URL)/ft_printfo.o \
		 $(PRINTF_URL)/ft_printfdi.o \
		 $(PRINTF_URL)/ft_printfx.o \
		 $(PRINTF_URL)/ft_getparams.o \
		 $(PRINTF_URL)/ft_printfmod.o \
		 $(PRINTF_URL)/ft_format.o \
		 $(PRINTF_URL)/ft_getflag.o \
		 $(PRINTF_URL)/ft_printfcsp.o \
		 $(PRINTF_URL)/ft_printf.o \
		 $(PRINTF_URL)/ft_printflx.o \
		 $(PRINTF_URL)/ft_printfhdi.o \
		 $(PRINTF_URL)/ft_printfllx.o \
		 $(PRINTF_URL)/ft_formatp.o \
		 $(PRINTF_URL)/ft_printfcolor.o \

all: $(NAME)

$(NAME): $(SRCLIB) $(SRC) $(SRCGNL) $(SRCDICO) $(SRCMATH)
	@ar rcs $(NAME) $^ 

clean:
	@rm -rf $(SRCLIB) $(SRC) $(SRCGNL) $(SRCDICO) $(SRCMATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<;

.PHONY: clean fclean re all
