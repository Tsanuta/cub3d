# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 12:09:28 by olidon            #+#    #+#              #
#    Updated: 2020/03/03 11:56:52 by olidon           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEADER			=		./include/cub3d.h

HEADERA			=		./include/cub3d_struct.h

HEADERBNS		=		./include/cub3d_bonus.h

HEADERBNSA		=		./include/cub3d_struct_bonus.h

SRC_PATH		=		sources

SRCS_NAME		=		cub3d.c					\
						ft_init_mlx.c			\
						ft_parsemap.c			\
						ft_parsemap2.c			\
						ft_parsemap3.c			\
						ft_parsemap4.c			\
						ft_parsemap5.c			\
						ft_parsemap6.c			\
						ft_parsemap7.c			\
						ft_fill_sprite_struct.c	\
						ft_error.c				\
						ft_display.c			\
						ft_find_ray.c			\
						ft_find_rayx_utils.c	\
						ft_find_rayy_utils.c	\
						ft_draw_sprite.c 		\
						ft_free_sort_sprite.c 	\
						ft_img_to_mlx.c			\
						ft_loop.c				\
						ft_key_events.c			\
						ft_key_events2.c		\
						ft_create_img_bmp.c		\
						ft_get_img_color.c		\

SRCS_NAMEBNS	=		cub3d_bonus.c					\
						ft_init_mlx_bonus.c				\
						ft_parsemap_bonus.c				\
						ft_parsemap2_bonus.c			\
						ft_parsemap3_bonus.c			\
						ft_parsemap4_bonus.c			\
						ft_parsemap5_bonus.c			\
						ft_parsemap6_bonus.c			\
						ft_parsemap7_bonus.c			\
						ft_fill_sprite_struct_bonus.c	\
						ft_error_bonus.c				\
						ft_display_bonus.c				\
						ft_find_ray_bonus.c				\
						ft_find_rayx_utils_bonus.c		\
						ft_find_rayy_utils_bonus.c		\
						ft_display_minimap_bonus.c		\
						ft_draw_sprite_bonus.c 			\
						ft_free_sort_sprite_bonus.c 	\
						ft_img_to_mlx_bonus.c			\
						ft_loop_bonus.c					\
						ft_key_events_bonus.c			\
						ft_key_events2_bonus.c			\
						ft_create_img_bmp_bonus.c		\
						ft_get_img_color_bonus.c		\

SRCS			=		$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

SRCSBNS			=		$(addprefix $(SRC_PATH)/,$(SRCS_NAMEBNS))

OBJS			= 		${SRCS:.c=.o}

OBJSBNS			=		${SRCSBNS:_bonus.c=_bonus.o}

NAME			=		Cub3D

NAMEBNS			=		Cub3DBonus

FLAGS			+=		-O3 -march=native -flto -ffast-math -Wall -Wextra -Werror

FLAGSBNS		+=		-O3 -march=native -flto -ffast-math -Wall -Wextra -Werror

all				:		$(NAME)

bonus			:		$(NAMEBNS)

%_bonus.o		:		%_bonus.c $(HEADERBNS) $(HEADERBNSA)
						gcc $(FLAGSBNS) -c $< -o $(<:_bonus.c=_bonus.o)

%.o				:		%.c $(HEADER) $(HEADERA)
						gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAMEBNS)		:		lib minilibx $(OBJSBNS)
						gcc $(FLAGSBNS) -o $(NAME) libft/libft.a minilibx_opengl_20191021/libmlx.a $(OBJSBNS) -framework OpenGL -framework AppKit -lz

$(NAME)			:		lib minilibx $(OBJS)
						gcc $(FLAGS) -o $(NAME) libft/libft.a minilibx_opengl_20191021/libmlx.a $(OBJS) -framework OpenGL -framework AppKit -lz

lib				:
						make -C ./Libft

minilibx		:
						make -C ./minilibx_opengl_20191021

clean			:
						make -C ./libft clean
						make -C ./minilibx_opengl_20191021 clean
						rm -f $(OBJS) $(OBJSBNS)

fclean			:		clean
						make -C ./libft fclean
						rm -f libft.a $(NAME)

re				:      	fclean all

.PHONY			:		all lib clean fclean re
