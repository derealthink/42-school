# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 13:19:32 by aielo             #+#    #+#              #
#    Updated: 2026/04/22 17:54:47 by aielo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

# Colors
GREEN		= \033[0;32m
RESET		= \033[0m

# Directories
INC_DIR		= includes
SRC_DIR		= srcs
OBJ_DIR 	= obj

# Libft
LIBFT_DIR 	= $(SRC_DIR)/libft
LIBFT_SRCS	= ft_atoi.c ft_atoi_long.c ft_bzero.c ft_calloc.c \
				ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isnumber.c \
				ft_isprint.c ft_itoa_p.c ft_itoa_u.c ft_itoa_unsign.c \
				ft_itoa_x.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c \
				ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
				ft_toupper.c

# Ft_Printf
PRINTF_DIR	= $(SRC_DIR)/ft_printf
PRINTF_SRCS	=  ft_printf.c \
				srcs/ft_flag_precision.c srcs/ft_flag_width.c srcs/ft_flags.c \
				srcs/ft_printf_c.c srcs/ft_printf_di.c srcs/ft_printf_p.c \
				srcs/ft_printf_per.c srcs/ft_printf_s.c srcs/ft_printf_u.c \
				srcs/ft_printf_x.c

# Get Next Line
GNL_DIR 	= $(SRC_DIR)/gnl
GNL_SRCS	= get_next_line.c get_next_line_delimiter.c

# Sources
SOURCES		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS)) \
				$(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS)) \
				$(addprefix $(GNL_DIR)/, $(GNL_SRCS))

# Objects & Dependency
OBJECTS 	= $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPENDS 	= $(OBJECTS:.o=.d)

# Compiler
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -I$(INC_DIR)
AR			= ar rcs
RM			= rm -rf

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS)
	@echo "$(GREEN) $(NAME) compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN) Objects and dependencies removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN) $(NAME) removed.$(RESET)"

re: fclean all

-include $(DEPENDS)

.PHONY: all clean fclean re
