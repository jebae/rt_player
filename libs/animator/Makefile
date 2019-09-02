# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebae <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 18:51:06 by jebae             #+#    #+#              #
#    Updated: 2019/09/02 18:51:07 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

define compile_obj
	printf "$(KGRN)[animator]$(KNRM) compile $(1)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

# compiler
CC = gcc

# lib name
NAME = libanimator.a

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

LIBFT_PATH = ../libft

GMATH_PATH = ../gmath

CLKIT_PATH = ../clkit

RT_PATH = ../rt

PARSER_PATH = ../parser

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)\
	-I $(LIBFT_PATH)/includes\
	-I $(GMATH_PATH)/includes\
	-I $(CLKIT_PATH)/includes\
	-I $(RT_PATH)/includes\
	-I $(PARSER_PATH)/includes\

# srcs
SRC_OBJECT = cone.c\
	plane.c\
	sphere.c\
	cylinder.c\
	triangle.c\
	object_translate.c\
	object_rotate.c\

SRC_CAMERA = camera_translate.c\
	camera_rotate.c\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC_OBJECT:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_CAMERA:.c=.o))

# compile objs
HEADERS = $(INCDIR)/animator.h\
	$(LIBFT_PATH)/includes/libft.h\
	$(GMATH_PATH)/includes/gmath.h\
	$(CLKIT_PATH)/includes/clkit.h\
	$(RT_PATH)/includes/rt.h\
	$(RT_PATH)/includes/rt_func.h\
	$(RT_PATH)/includes/rt_struct.h\
	$(RT_PATH)/includes/rt_args.h\
	$(RT_PATH)/includes/rt_parallel.h\

$(OBJDIR)/%.o : $(SRCDIR)/object/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/camera/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

pre_build :
	@printf "$(KGRN)[animator] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[animator] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all pre_build post_build clean fclean re
