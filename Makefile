NAME = cub3d

LIBFT_DIR = utils/libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIB_DIR = minilibx-linux
MINILIB = $(MINILIB_DIR)/libmlx.a

GNL_DIR = utils/getnextline
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)


CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
INCLUDES = -I./includes -I./$(LIBFT_DIR) -I./$(GNL_DIR) -Iminilibx-linux -I./$

SRCS = sources/main.c \
	   sources/clear.c \
	   sources/parsing.c \
	   sources/parsing_utils.c \
	   sources/init.c \
	   sources/init_camera.c \
	   sources/init_sprites.c \
	   sources/init_engine.c \
	   sources/get_map_file.c \
	   sources/parse_map.c \
	   sources/flood_fill.c \
	   sources/ft_images.c \
	   sources/ft_images_utils.c \
	   sources/ft_map.c \
	   sources/ft_player.c \
	   sources/ft_raycast.c \
	   sources/ft_raycast_utils.c \
	   sources/ft_raycast_utils_2.c \
	   sources/ft_raycast_utils_3.c \
	   sources/ft_load_textures.c \
	   sources/ft_vars.c \
	   sources/ft_hooks.c \
	   sources/ft_player_draw.c \
	   sources/ft_utils.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT)  $(GNL_OBJS) $(OBJS) $(MINILIB)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(MINILIB) $(LIBFT) -o $(NAME) -lXext -lX11 -lm

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIB):
	make -C $(MINILIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(GNL_OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MINILIB_DIR)
	rm -f $(NAME)
	rm -f $(OBJS_BONUS)

re: fclean all

.PHONY: all clean fclean re 
