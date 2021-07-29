/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:00:32 by olidon            #+#    #+#             */
/*   Updated: 2020/02/21 18:44:28 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_BONUS_H
# define CUB3D_STRUCT_BONUS_H

typedef struct	s_map
{
	char			*map;
	struct s_map	*next;
}				t_map;

typedef struct	s_line
{
	int			xa;
	int			ya;
}				t_line;

typedef struct	s_player
{
	int			x;
	int			y;
	float		a;
}				t_player;

typedef struct	s_sprpos
{
	int				x;
	int				y;
	int				ox;
	int				oy;
	float			dist;
	float			angle;
	int				vis;
	int				life;
	int				shoot;
	struct s_sprpos	*next;
}				t_sprpos;

typedef struct	s_sprite
{
	int				offset;
	int				gridx;
	int				gridy;
	float			dist;
	int				dead;
	int				shoot;
	struct s_sprite	*next;
}				t_sprite;

typedef struct	s_img
{
	int				rx;
	int				ry;
	void			*ptr;
	unsigned int	*data;
	int				bpp;
	int				l;
	int				end;
}				t_img;

typedef struct	s_text
{
	char		*nop;
	int			exno;
	t_img		no;
	char		*sop;
	int			exso;
	t_img		so;
	char		*wep;
	int			exwe;
	t_img		we;
	char		*eap;
	int			exea;
	t_img		ea;
	char		*sp;
	int			exsp;
	t_img		s;
	t_img		s1;
	t_img		s2;
	t_img		s3;
	t_img		w1;
	t_img		w1sc;
	t_img		w2;
	t_img		w2sc;
	t_img		dead;
	t_img		deadsc;
	t_img		point;
	t_img		pointsc;
	t_img		life;
	t_img		lifesc;
}				t_text;

typedef struct	s_color
{
	unsigned int	c;
	unsigned int	f;
	int				exc;
	int				exf;
}				t_color;

typedef struct	s_argb
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_argb;

typedef struct	s_coord
{
	float		ax;
	float		ay;
	float		ya;
	float		xa;
}				t_coord;

typedef struct	s_mvmnt
{
	int			a;
	int			d;
	int			ml;
	int			mousey;
	int			mousex;
	int			w;
	int			s;
	int			an;
	int			sprint;
}				t_mvmnt;

typedef struct	s_const
{
	float		scdist;
	float		schl;
	float		seglen;
	float		fov;
	int			loop;
	int			life;
	int			sprint;
}				t_const;

typedef struct	s_elem
{
	int			save;
	t_const		cst;
	float		rayan;
	void		*m_ptr;
	void		*w_ptr;
	t_img		cimg;
	t_img		mimg;
	t_coord		rayx;
	t_coord		rayy;
	t_mvmnt		mvmnt;
	t_sprite	*sp;
	t_sprpos	*sprpos;
	t_line		l;
	int			offset;
	char		wallc;
	int			exmap;
	int			endmap;
	char		**map;
	char		**mapcp;
	int			msy;
	int			msx;
	int			rx;
	int			ry;
	int			exres;
	t_text		t;
	t_player	p;
	int			exp;
	t_color		c;
	char		*bmp;
}				t_elem;

#endif
