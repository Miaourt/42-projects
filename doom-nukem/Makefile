# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groberto <groberto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 17:16:08 by tcourtil          #+#    #+#              #
#    Updated: 2019/05/15 15:13:44 by groberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOOM = doom-nukem

ABSOLUTE_DIR = $(shell pwd)
ifeq ($(OS),WIN)
	OS_SPECIFIC = WIN
else ifeq ($(OS),LINUX)
	OS_SPECIFIC = LINUX
else
	STRICT = -Wall -Wextra -Werror
endif

CFLAGS = $(STRICT) -I ./include -I ./libft/include -I ./SDL2/include

SDL2_SRC = $(ABSOLUTE_DIR)/SDL2-2.0.9
SDL2_MIXER_SRC = $(ABSOLUTE_DIR)/SDL2_mixer-2.0.4

DOOM_URL = ./src/doom

SRC_DOOM = $(DOOM_URL)/main.o \
		  $(DOOM_URL)/screen.o \
		  $(DOOM_URL)/init_world.o \
		  $(DOOM_URL)/render.o \
		  $(DOOM_URL)/render_wall.o \
		  $(DOOM_URL)/update.o \
		  $(DOOM_URL)/key.o \
		  $(DOOM_URL)/cleaner.o \
		  $(DOOM_URL)/raycasting.o \
		  $(DOOM_URL)/file_utils.o \
		  $(DOOM_URL)/move.o \
		  $(DOOM_URL)/color.o \
		  $(DOOM_URL)/ui.o \
		  $(DOOM_URL)/ghost.o \
		  $(DOOM_URL)/initghost.o \
		  $(DOOM_URL)/barrel.o \
		  $(DOOM_URL)/utils.o \
		  $(DOOM_URL)/init_entity.o \
		  $(DOOM_URL)/init_win.o \
		  $(DOOM_URL)/wall_size.o \
		  $(DOOM_URL)/render_sprite.o \
		  $(DOOM_URL)/action.o \
		  $(DOOM_URL)/gameloop.o \
		  $(DOOM_URL)/collide.o \
		  $(DOOM_URL)/init_render.o \
		  $(DOOM_URL)/cleaner2.o \
		  $(DOOM_URL)/ser_ent.o \
		  $(DOOM_URL)/ser_img.o \
		  $(DOOM_URL)/ser_prim.o \
		  $(DOOM_URL)/ser_str.o \
		  $(DOOM_URL)/ser_world.o \
		  $(DOOM_URL)/gilet.o \
		  $(DOOM_URL)/text_ui.o \
		  $(DOOM_URL)/editor.o \
		  $(DOOM_URL)/editor2.o \
		  $(DOOM_URL)/editor3.o \
		  $(DOOM_URL)/editor4.o \
		  $(DOOM_URL)/texture_editor.o \
		  $(DOOM_URL)/map_editor.o \
		  $(DOOM_URL)/money.o \
		  $(DOOM_URL)/tax.o \
		  $(DOOM_URL)/signal_handler.o \
		  $(DOOM_URL)/editor_spawn.o \
		  $(DOOM_URL)/entity_editor.o \
		  $(DOOM_URL)/loadmap.o \
		  $(DOOM_URL)/edit_settings.o \
		  $(DOOM_URL)/editor_config.o \
		  $(DOOM_URL)/coin.o \
		  $(DOOM_URL)/coin_anim.o \
		  $(DOOM_URL)/jetpack.o \





all: lib SDL2 $(DOOM) $(OS_SPECIFIC)

lib: 
	@make -C libft/

SDL2:
	mkdir -p SDL2
	mkdir -p SDL2/build
	cd SDL2/build; \
		$(SDL2_SRC)/configure --prefix $(ABSOLUTE_DIR)/SDL2; \
		make -j6; \
		make install; \
		$(SDL2_MIXER_SRC)/configure --prefix $(ABSOLUTE_DIR)/SDL2; \
		make -j6; \
		make install;

WIN:
	@cp ./SDL2/bin/SDL2.dll .

LINUX:
	@echo "Loonix"

$(DOOM): $(SRC_DOOM)
	@gcc -o $(DOOM) $^ -L ./libft -lft -lm -lpthread $(shell $(ABSOLUTE_DIR)/SDL2/bin/sdl2-config --libs) -lSDL2_mixer
clean:
	@make -C libft/ clean
	@rm -rf $(SRC_DOOM)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(DOOM)
	@rm -rf ./SDL2.dll
	@rm -rf ./libft/*.o
	@rm -rf ./SDL2

re: fclean all

%.o: %.c ./include/doom.h ./include/editor.h
	gcc $(CFLAGS) -o $@ -c $<;
