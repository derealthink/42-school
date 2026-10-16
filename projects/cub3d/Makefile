# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aielo <aielo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 17:03:34 by aielo             #+#    #+#              #
#    Updated: 2026/03/10 13:05:10 by aielo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# Libraries
LIB_DIR = Libft
LIB_NAME = ft
LIB_LIB = $(LIB_DIR)/lib$(LIB_NAME).a
LIB_INC = $(LIB_DIR)

MLX_DIR = mlx_linux

# Directories
INCLUDES 	= includes
OBJ_DIR 	= obj

BUILT_DIR 	= src/builtins
CONFIG_DIR	= src/configuration
EXEC_DIR 	= src/execution
EXIT_DIR	= src/exit
PARS_DIR 	= src/parsing
RENDER_DIR 	= src/render
UTILS_DIR 	= src/utils

# Sources
CONFIG_SRCS	= $(CONFIG_DIR)/init_data.c \
				$(CONFIG_DIR)/init_mlx.c \
				$(CONFIG_DIR)/init_parsing.c \
				$(CONFIG_DIR)/init_textures.c

EXEC_SRCS 	= $(EXEC_DIR)/key_input.c \
				$(EXEC_DIR)/player_direction.c \
				$(EXEC_DIR)/player_movements.c \
				$(EXEC_DIR)/player_position.c \
				$(EXEC_DIR)/player_rotation.c

EXIT_SRCS 	= $(EXIT_DIR)/error.c \
				$(EXIT_DIR)/exit.c \
				$(EXIT_DIR)/free.c

PARS_SRCS 	= $(PARS_DIR)/read_map.c \
				$(PARS_DIR)/color_config.c \
				$(PARS_DIR)/flood_fill.c \
				$(PARS_DIR)/linked_list.c \
				$(PARS_DIR)/list_padding.c \
				$(PARS_DIR)/map_validity.c \
				$(PARS_DIR)/map_config.c \
				$(PARS_DIR)/map.c \
				$(PARS_DIR)/parse_utils.c \
				$(PARS_DIR)/parsing.c \
				$(PARS_DIR)/prep_id.c \
				$(PARS_DIR)/texture_config.c \
				$(PARS_DIR)/validity_id.c \
				$(PARS_DIR)/parse_utils_1.c \
				$(PARS_DIR)/color_validity.c \

RENDER_SRCS = $(RENDER_DIR)/render_main.c \
				$(RENDER_DIR)/render_raycasting.c \
				$(RENDER_DIR)/render_utils.c \
				$(RENDER_DIR)/texture.c \
				$(RENDER_DIR)/minimap.c

UTILS_SRCS 	= $(UTILS_DIR)/utils.c

SOURCES 	= cub3d.c \
				$(CONFIG_SRCS) \
				$(EXEC_SRCS) \
				$(EXIT_SRCS) \
				$(PARS_SRCS) \
				$(RENDER_SRCS) \
				$(UTILS_SRCS)

# Objects
OBJECTS 	= $(SOURCES:%.c=$(OBJ_DIR)/%.o)

# Compiler
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CEXTRA_INC	= -I. -I$(LIB_INC) -I$(INCLUDES)
CEXTRA_LIB	= -L$(LIB_DIR) -l$(LIB_NAME)

# Dependency
DEPENDS		= $(SOURCES:%.c=$(OBJ_DIR)/%.d)

# Rules
all: $(OBJ_DIR) libft mlx_linux $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJECTS) | $(LIB_LIB)
	$(CC) $(CFLAGS) $(CEXTRA_INC) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(CEXTRA_LIB)

libft:
	$(MAKE) -C $(LIB_DIR)

mlx_linux:
	cd $(MLX_DIR) && chmod 777 configure && cd ..
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CEXTRA_INC) -I/usr/include -I. -Imlx_linux -O3 -MMD -MP -c $< -o $@ -std=gnu89

-include $(DEPENDS)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

# Valgrind rules ( --suppressions=mlx.supp \ )
val: all
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./$(NAME) ./maps/map2.cub

valre: re val

.PHONY: all clean fclean re libft mlx_linux val valre
