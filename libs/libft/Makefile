# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebae <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 18:09:31 by jebae             #+#    #+#              #
#    Updated: 2019/08/19 17:33:19 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

# compiler
CC = gcc

# lib name
NAME = libft.a

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)

# srcs
SRCS = ft_bzero.c\
	ft_lstadd.c\
	ft_lstdel.c\
	ft_lstiter.c\
	ft_lstiter_with_arg.c\
	ft_lstnew.c\
	ft_memalloc.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_strcat.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strlen.c\
	get_file_content.c\
	get_next_line.c\
	put_color_str.c\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# compile objs
$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/libft.h $(INCDIR)/get_next_line.h
	@printf "$(KGRN)[libft]$(KNRM) compile $<\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))

# build
all : $(NAME)

$(NAME) : pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

pre_build :
	@printf "$(KGRN)[libft] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[libft] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all pre_build post_build clean fclean re
