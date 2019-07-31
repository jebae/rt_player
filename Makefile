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

LIBFT_PATH = ./graphics/libft

GMATH_PATH = ./graphics/gmath

CLKIT_PATH = ./graphics/clkit

RT_PATH = ./graphics/rt

ANIMATOR_PATH = ./graphics/animator

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)\
	-I $(LIBFT_PATH)/includes\
	-I $(GMATH_PATH)/includes\
	-I $(CLKIT_PATH)/includes\
	-I $(RT_PATH)/includes\
	-I $(ANIMATOR_PATH)/includes\

LIBS = -lmlx\
	-L ./graphics/libft -lft\
	-L ./graphics/gmath -lgmath\
	-L ./graphics/clkit -lclkit\
	-L ./graphics/rt -lrt\
	-L ./graphics/animator -lanimator\

FRAMEWORKS = -framework OpenCL\
	-framework OpenGL\
	-framework AppKit\

# srcs
SRC_EVENTS = exit.c\
	key_press.c\
	object_translate.c\
	object_rotate.c\
	camera_translate.c\
	camera_rotate.c\

SRC_SETTING = set_mlx.c\
	set_rt_global_settings.c\

SRC_UTILS = render_by_mlx.c\
	mlx_get_img_buffer.c\

# SRC_TESTS will removed after
SRC_TESTS = scene1.test.c\

# objs
OBJS = $(addprefix $(OBJDIR)/,$(SRC_EVENTS:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_SETTING:.c=.o))
OBJS += $(addprefix $(OBJDIR)/,$(SRC_UTILS:.c=.o))

# this line will be removed after
OBJS += $(addprefix $(OBJDIR)/,$(SRC_TESTS:.c=.o))

# compile objs
HEADERS = $(INCDIR)/rt_player.h\
	$(RT_PATH)/includes/rt.h\
	$(RT_PATH)/includes/rt_args.h\
	$(RT_PATH)/includes/rt_parallel.h\
	$(RT_PATH)/includes/rt_struct.h\
	$(LIBFT_PATH)/includes/libft.h\
	$(GMATH_PATH)/includes/gmath.h\
	$(CLKIT_PATH)/includes/clkit.h\
	$(ANIMATOR_PATH)/includes/animator.h\

$(OBJDIR)/%.o : $(SRCDIR)/events/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/setting/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/utils/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# this line will be removed after
$(OBJDIR)/%.o : $(SRCDIR)/__tests__/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : deps pre_build $(OBJDIR) $(OBJS) post_build
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(FRAMEWORKS) $(OBJS) test_main.c -o $(NAME)

deps :
	@$(MAKE) -C $(LIBFT_PATH) all
	@$(MAKE) -C $(GMATH_PATH) all
	@$(MAKE) -C $(CLKIT_PATH) all
	@$(MAKE) -C $(RT_PATH) all
	@$(MAKE) -C $(ANIMATOR_PATH) all
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
	@rm -rf $(OBJS)

fclean : clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(GMATH_PATH) fclean
	@$(MAKE) -C $(CLKIT_PATH) fclean
	@$(MAKE) -C $(RT_PATH) fclean
	@$(MAKE) -C $(ANIMATOR_PATH) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all deps pre_build post_build clean fclean re
