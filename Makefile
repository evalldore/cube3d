NAME		:= cube3d
CFLAGS		:= -Wall -Wextra -Werror -Ofast -flto

SRCDDIR		:= src/
BINDIR		:= bin/
COMPDIR 	:= components/
RENDDIR		:= renderer/

SRCS		:= main.c cube.c world.c utils.c ray.c camera.c entities.c assets.c controls.c collision.c vector.c
COMPSRCS	:= position.c direction.c control.c
RENDSRCS	:= renderer.c color.c buffer.c line.c background.c floor.c
SRCS		+= $(addprefix $(COMPDIR), $(COMPSRCS))
SRCS		+= $(addprefix $(RENDDIR), $(RENDSRCS))

LIBMLX		:= lib/MLX42
LIBFT		:= lib/libft
LIBECS		:= lib/ecs

HEADERS		:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include -I $(LIBECS)/include
LIBS		:= $(LIBECS)/ecs.a $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
OBJS		:= $(addprefix $(BINDIR), $(SRCS:.c=.o))

all: libmlx libft ecs $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	$(MAKE) -C $(LIBFT)

ecs:
	$(MAKE) -C $(LIBECS)

$(BINDIR)%.o: $(SRCDDIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(BINDIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BINDIR) :
	mkdir $(BINDIR)
	mkdir $(BINDIR)$(COMPDIR)
	mkdir $(BINDIR)$(RENDDIR)

clean:
	@rm -r $(BINDIR)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(LIBECS) fclean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft