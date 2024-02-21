NAME		:= cub3d
CFLAGS		:= -Wall -Wextra -Werror -Ofast -flto 

SRCDDIR		:= src/
BINDIR		:= bin/
COMPDIR 	:= components/
RENDDIR		:= renderer/
WORLDDIR	:= world/
PARSEDIR 	:= parse/
MODULEDIR	:= $(COMPDIR) $(RENDDIR) $(WORLDDIR) $(PARSEDIR)

SRCS		:= main.c cube.c utils.c ray.c camera.c entities.c assets.c controls.c collision.c vector.c radar.c
COMPSRCS	:= position.c direction.c control.c
RENDSRCS	:= renderer.c color.c buffer.c line.c background.c floor.c
WORLDSRCS	:= world.c draw.c
PARSESRCS	:= parsing.c parse_assets.c parse_colors.c parse_map.c parse_utils.c
SRCS		+= $(addprefix $(COMPDIR), $(COMPSRCS))
SRCS		+= $(addprefix $(RENDDIR), $(RENDSRCS))
SRCS		+= $(addprefix $(WORLDDIR), $(WORLDSRCS))
SRCS 		+= $(addprefix $(PARSEDIR), $(PARSESRCS))

LIBMLX		:= lib/MLX42
LIBFT		:= lib/libft
LIBECS		:= lib/ecs

HEADERS		:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include -I $(LIBECS)/include
LIBS		:= $(LIBECS)/ecs.a $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
OBJS		:= $(addprefix $(BINDIR), $(SRCS:.c=.o))

all: libmlx libft ecs $(NAME)

leaks:
	leaks --atExit -- ./$(NAME) maps/test.cub

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	$(MAKE) -C $(LIBFT)

ecs:
	$(MAKE) -C $(LIBECS)

$(BINDIR)%.o: $(SRCDDIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(BINDIR) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(HEADERS) -o $(NAME)

$(BINDIR) :
	mkdir $(BINDIR)
	mkdir $(addprefix $(BINDIR), $(MODULEDIR))

clean:
	@rm -r $(BINDIR)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(LIBECS) fclean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft