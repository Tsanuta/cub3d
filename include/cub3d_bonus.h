/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:45:57 by olidon            #+#    #+#             */
/*   Updated: 2020/03/03 11:59:16 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../minilibx_opengl_20191021/mlx.h"
# include "../Libft/libft.h"
# include "./cub3d_struct_bonus.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef CONSTANTE
#  define CONSTANTE
#  define FOV 66
#  define CUBE_S 64
#  define MIMAP_S 160
#  define MOVE_SPEED 5
#  define ROTATION_SPEED 0.03490658503
# endif

/*
** CUB3D.C
*/
int				main(int ac, char **av);
/*
** PARSEMAP 12345.C
*/
void			ft_parse_file(char *path, t_elem *elem);
void			ft_stock_map_in_lst(t_elem *e, char *line, t_map **lstmap);
void			ft_lstmapclear(t_map **lst);
int				ft_lstmapsize(t_map *lst);
void			ft_lst_to_ptr(t_map **lstmap, t_elem *e);
void			ft_parse_elema(char *line, t_elem *e);
unsigned int	ft_fill_color(t_elem *e, char *line, char *lineb);
void			ft_fill_player_pos(t_elem *e, int i, int j);
void			ft_fill_sprite_pos_struct(t_elem *e, int i, int j);
char			*ft_fill_path(t_elem *e, char *line, char *lineb);
void			ft_fill_res(t_elem *elem, char *line, char *lineb);
char			*ft_rmspacedup(t_elem *e, char *line, char *lineb);
void			ft_check_valid_map_line(t_elem *e, int i, int j);
void			ft_complete_map_spaces(t_elem *e);
void			ft_check_valid_map(t_elem *e);
void			ft_map_flood_fill(t_elem *e);
void			ft_map_copy(t_elem *e);
unsigned int	ft_check_color_range(t_elem *e, char *linecp,
											char *lineb, int *str);
void			ft_free_mapcp(t_elem *e);
void			ft_search_walls(t_elem *e);
void			ft_case_flood_fill(t_elem *e, int x, int y);
char			*ft_rm_half_space(t_elem *e, char *line, char *lineb);
/*
** FILL_SPRITE_STRUCT.C
*/
void			ft_fill_sprite_struct(t_elem *e, float ra,
												t_sprpos *sprpos, float angle);
float			ft_find_sprite_angle(t_elem *e, float sx, float sy, float dist);
float			ft_mod_pib(float ra);
/*
** ERROR.C
*/
void			ft_disp_error_msg(t_elem *e, char *msg, char *line);
void			ft_free_struct_elem(t_elem *elem);
/*
** INIT_MLX.C
*/
void			ft_display(t_elem *e);
/*
** DISPLAY.C
*/
void			ft_display_walls(t_elem *e);
void			ft_display_sprite(t_elem *e);
/*
** DISPLAY_MINIMAP.C
*/
void			ft_display_minimap(t_elem *elem, int i, int j);
void			ft_draw_line(t_elem *e, int xb, int yb);
/*
** FIND_RAY.C
*/
float			ft_find_dist_rayx(t_elem *e, float ra, int prec);
float			ft_find_dist_rayy(t_elem *e, float ra, int prec);
void			ft_fill_wall_param(t_elem *e, float ra, int prec, int dx);
void			ft_sprite_exist(t_elem *e, float ra, float ray);
/*
** FIND_RAYX_UTILS.C
*/
float			ft_find_rayx_ay(float ra, t_elem *e, int prec);
float			ft_find_rayx_ya(float ra, int prec);
float			ft_find_rayx_ax(float ra, float ay, t_elem *e);
float			ft_find_rayx_xa(float ra, int prec);
float			ft_find_rayy_ax(float ra, t_elem *e, int prec);
float			ft_find_rayy_xa(float ra, int prec);
float			ft_find_rayy_ay(float ra, float ax, t_elem *e);
float			ft_find_rayy_ya(float ra, int prec);
/*
** FIND_RAYY_UTILS.C
*/
float			ft_find_raysx_ay(float ra, t_elem *e, int prec);
float			ft_find_raysx_ya(float ra, int prec);
float			ft_find_raysx_ax(float ra, float ay, t_elem *e);
float			ft_find_raysx_xa(float ra, int prec);
float			ft_find_raysy_ax(float ra, t_elem *e, int prec);
float			ft_find_raysy_xa(float ra, int prec);
float			ft_find_raysy_ay(float ra, float ax, t_elem *e);
float			ft_find_raysy_ya(float ra, int prec);
/*
** KEYVENTS.C
*/
int				ft_key_press(int keycode, t_elem *e);
int				ft_mouse_press(int keycode, int x, int y, t_elem *e);
int				ft_mouse_release(int keycode, int x, int y, t_elem *e);
int				ft_key_release(int keycode, t_elem *e);
int				ft_exit_windows(t_elem *e);
int				ft_move_loop(t_elem *e);
int				ft_motion_hook(int x, int y, t_elem *e);
void			ft_key_press_comp(t_elem *e);
/*
** IMG_TO_MLX.C
*/
void			ft_img_to_mlx_img(t_elem *e, t_img *img, char *path);
/*
** GET_IMG_COLOR.C
*/
unsigned int	ft_get_tcolor(t_elem *e, int wallh, int yoffset, char wallc);
/*
** FREE_SORT_SPRITE.C
*/
void			ft_sort_sprites(t_sprite **sp);
void			ft_free_sprites(t_sprite **lst);
/*
** DRAW_SPRITE.C
*/
void			ft_draw_sprites(t_elem *e, int x, float ray);
/*
** CREATE_IMG_BMP.C
*/
void			ft_mlx_img_to_bmp(t_elem *e, t_img img, int offx, int offy);

#endif
