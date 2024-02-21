NAME		:= cub3d
CFLAGS		:= -Wall -Wextra -Werror -Ofast -flto 

SRCDDIR		:= src/
BINDIR		:= bin/
RENDDIR		:= renderer/
WORLDDIR	:= world/
PARSEDIR 	:= parse/
MODULEDIR	:= $(COMPDIR) $(RENDDIR) $(WORLDDIR) $(PARSEDIR)

SRCS		:= main.c cube.c utils.c ray.c camera.c assets.c controls.c collision.c vector.c radar.c player.c
RENDSRCS	:= renderer.c color.c buffer.c line.c background.c floor.c
WORLDSRCS	:= world.c draw.c
PARSESRCS	:= parsing.c parse_assets.c parse_colors.c parse_map.c parse_utils.c
SRCS		+= $(addprefix $(RENDDIR), $(RENDSRCS))
SRCS		+= $(addprefix $(WORLDDIR), $(WORLDSRCS))
SRCS 		+= $(addprefix $(PARSEDIR), $(PARSESRCS))

LIBMLX		:= lib/MLX42
LIBFT		:= lib/libft

HEADERS		:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS		:= $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm

GLFW_HEADER := /Users/$(USER)/.brew/opt/glfw

TEST_RESULT := $(shell test -d $(GLFW_HEADER) && echo yes || echo no)

ifeq ($(TEST_RESULT),yes)
    LIBS += -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
else
    $(error GLFW headers not found, please install GLFW)
endif

OBJS		:= $(addprefix $(BINDIR), $(SRCS:.c=.o))

all: libmlx libft $(NAME)

bonus: CFLAGS += -DBONUS=1

bonus: all

leaks:
	leaks --atExit -- ./$(NAME) maps/test.cub

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	$(MAKE) -C $(LIBFT)

$(BINDIR)%.o: $(SRCDDIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(BINDIR) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(HEADERS) -o $(NAME)

$(BINDIR) :
	mkdir $(BINDIR)
	mkdir $(addprefix $(BINDIR), $(MODULEDIR))

clean:
	@rm -rf $(BINDIR)
	$(MAKE) -C $(LIBFT) fclean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft, bonus, leaks