# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebae <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 17:14:05 by jebae             #+#    #+#              #
#    Updated: 2019/09/09 18:33:14 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

define compile_obj
	printf "$(KGRN)[rt_player]$(KNRM) compile $(1)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

# compiler
CC = gcc

# program name
NAME = rtv1

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

LIBDIR = libs

LIBFT_PATH = ./$(LIBDIR)/libft

GMATH_PATH = ./$(LIBDIR)/gmath

CLKIT_PATH = ./$(LIBDIR)/clkit

RT_PATH = ./$(LIBDIR)/rt

ANIMATOR_PATH = ./$(LIBDIR)/animator

PARSER_PATH = ./$(LIBDIR)/parser

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)\
	-I $(LIBFT_PATH)/includes\
	-I $(GMATH_PATH)/includes\
	-I $(CLKIT_PATH)/includes\
	-I $(RT_PATH)/includes\
	-I $(ANIMATOR_PATH)/includes\
	-I $(PARSER_PATH)/includes\

LIBS = -lmlx\
	-L ./$(LIBDIR)/libft -lft\
	-L ./$(LIBDIR)/gmath -lgmath\
	-L ./$(LIBDIR)/clkit -lclkit\
	-L ./$(LIBDIR)/rt -lrt\
	-L ./$(LIBDIR)/animator -lanimator\
	-L ./$(LIBDIR)/parser -lparse\

FRAMEWORKS = -framework OpenCL\
	-framework OpenGL\
	-framework AppKit\

# srcs
SRC_MAIN = main.c\

SRC_EVENTS = exit.c\
	key_press.c\
	key_press2.c\
	object_translate.c\
	object_rotate.c\
	camera_translate.c\
	camera_rotate.c\
	select_object.c\

SRC_SETTING = set_rt_settings.c\

SRC_MAP_SCENE = map_camera.c\
	map_objects.c\
	map_lights.c\
	map_scene.c\

SRC_MLX = render_by_mlx.c\
	mlx_get_img_buffer.c\
	set_mlx.c\

SRC_CLEAR = clear.c\

SRC_HANDLE_ERROR = handle_error.c\

SRC_HANDLE_OPTIONS = handle_options.c\

# objs
OBJS = $(addprefix $(OBJDIR)/,$(SRC_MAIN:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_EVENTS:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_SETTING:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_MLX:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_MAP_SCENE:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_CLEAR:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_HANDLE_ERROR:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_HANDLE_OPTIONS:.c=.o))

# compile objs
HEADERS = $(INCDIR)/rt_player.h\
	$(RT_PATH)/includes/rt.h\
	$(RT_PATH)/includes/rt_func.h\
	$(RT_PATH)/includes/rt_args.h\
	$(RT_PATH)/includes/rt_parallel.h\
	$(RT_PATH)/includes/rt_struct.h\
	$(LIBFT_PATH)/includes/libft.h\
	$(GMATH_PATH)/includes/gmath.h\
	$(CLKIT_PATH)/includes/clkit.h\
	$(ANIMATOR_PATH)/includes/animator.h\
	$(PARSER_PATH)/includes/parse.h\

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/events/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/setting/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/mlx/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/map_scene/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/clear/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/handle_error/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/handle_options/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : deps pre_build $(OBJDIR) $(OBJS) post_build
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(FRAMEWORKS) $(OBJS) -o $(NAME)

deps :
	@$(MAKE) -C $(LIBFT_PATH) all
	@$(MAKE) -C $(GMATH_PATH) all
	@$(MAKE) -C $(CLKIT_PATH) all
	@$(MAKE) -C $(RT_PATH) all
	@$(MAKE) -C $(ANIMATOR_PATH) all
	@$(MAKE) -C $(PARSER_PATH) all
	@ln -sf $(RT_PATH)/kernels ./

pre_build :
	@printf "$(KGRN)[rt_player] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[rt_player] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(GMATH_PATH) clean
	@$(MAKE) -C $(CLKIT_PATH) clean
	@$(MAKE) -C $(RT_PATH) clean
	@$(MAKE) -C $(ANIMATOR_PATH) clean
	@$(MAKE) -C $(PARSER_PATH) clean
	@rm -rf $(OBJS)

fclean : clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(GMATH_PATH) fclean
	@$(MAKE) -C $(CLKIT_PATH) fclean
	@$(MAKE) -C $(RT_PATH) fclean
	@$(MAKE) -C $(ANIMATOR_PATH) fclean
	@$(MAKE) -C $(PARSER_PATH) fclean
	@rm -rf $(NAME)
	@rm -rf ./kernels

re : fclean all

.PHONY : all deps pre_build post_build clean fclean re
