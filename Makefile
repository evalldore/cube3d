NAME	:= cube3d
CFLAGS	:= -Wunreachable-code -Ofast -flto
SRCDDIR	:= ./src/
BINDIR	:= ./bin/
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft
ECS		:= ./lib/ecs

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include -I $(ECS)/include
LIBS	:= $(ECS)/ecs.a $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
SRCS	:= main.c cube.c renderer.c world.c utils.c ray.c camera.c entities.c line.c assets.c controls.c \
			components/position.c components/direction.c components/control.c
OBJS	:= $(addprefix $(BINDIR), $(SRCS:.c=.o))

all: libmlx libft ecs $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	$(MAKE) -C $(LIBFT)

ecs:
	$(MAKE) -C $(ECS)

$(BINDIR)%.o: $(SRCDDIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(BINDIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BINDIR) :
	mkdir $(BINDIR)
	mkdir $(BINDIR)/components

clean:
	@rm -r $(BINDIR)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(ECS) fclean
	@rm -r $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft