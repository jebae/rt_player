# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almoraru <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 10:41:01 by almoraru          #+#    #+#              #
#    Updated: 2019/09/04 23:16:46 by almoraru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC_DIR = srcs

OBJ_DIR = srcs

COLOR = \x1b[1;34m

COLOR2 = \x1b[1;35m

COLOR3 = \x1b[0;32m

COLOR4 = \x1b[0;36m

COLOREND = \033[0;0m

SRCS = $(SRC_DIR)/parse.c $(SRC_DIR)/parse_sphere.c $(SRC_DIR)/free_strings.c	 \
$(SRC_DIR)/parse_camera.c $(SRC_DIR)/check_optional.c $(SRC_DIR)/parse_cylinder.c\
$(SRC_DIR)/parse_plane.c $(SRC_DIR)/handle_numbers.c $(SRC_DIR)/parse_cone.c	 \
$(SRC_DIR)/basic_checks.c $(SRC_DIR)/check_important.c $(SRC_DIR)/parse_utils.c  \
$(SRC_DIR)/handle_strings.c $(SRC_DIR)/check_objects.c $(SRC_DIR)/init_parse.c   \
$(SRC_DIR)/errors.c $(SRC_DIR)/parse_lights.c $(SRC_DIR)/check_lights.c			 \
$(SRC_DIR)/check_utils.c $(SRC_DIR)/check_utils_objects.c						 \
$(SRC_DIR)/check_utils_lights.c $(SRC_DIR)/parse_utils2.c						 \
$(SRC_DIR)/check_optional_values.c

NAME = libparse.a

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:%.c=%.o)

LIB_PATH = ../libft/

GMATH_PATH = ../gmath/

RT_PATH = ../rt/

HEADER_PATH = includes/

INCLUDES = $(HEADER_PATH)/

INCLUDE = -I $(LIB_PATH)includes\
	-I $(RT_PATH)includes\
	-I $(GMATH_PATH)includes\
	-I $(HEADER_PATH)\

all: $(NAME)

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES)
	@$(CC) -c $< -o $@ $(FLAGS) $(INCLUDE)

$(NAME): $(OBJECTS)
	@ar -rc $@ $^
	@echo "$(COLOR)RTv1 : Parser installed baby$(COLOREND)"
clean:
	@echo "$(COLOR3)Cleaning objects!$(COLOREND)"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "$(COLOR)Removing :("
	@rm -f $(NAME)
	@echo "$(COLOR4)You murderer!$(COLOREND)"

re: fclean all

.PHONY: all clean fclean re
