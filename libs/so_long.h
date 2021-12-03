/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:46:44 by mcorda            #+#    #+#             */
/*   Updated: 2021/12/03 10:47:56 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# define MAG "\e[0;35m"
# define BBLK "\e[1;30m"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_window{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_check_map	position;
	t_sprite	map_img;
	t_sprite	floor;
	t_sprite	walls;
	t_sprite	exit;
	t_sprite	player;
	t_sprite	close;
	t_sprite	open;
	t_sprite	jesus;
}				t_window;

typedef struct s_check_map{
	int		x;
	int		y;
	int		k;
	int		exit;
	int		collectible;
	int		player;
	int		pos_x;
	int		pos_y;
}				t_check_map;

typedef struct s_sprite{
	int		width;
	int		height;
	void	*img;
}				t_sprite;

int			checking_function(t_window *win, char *file); //checking.c
static int	line_counter(int fd); //checking.c
static int	print_next_line(t_window *win, char *file, int nl); //checking.c
static int	check_the_damn_walls(char **map, int line); //checking.c
static int	check_solong_extension(char *file, char const *ext); //checking.c
void		define_image(t_window *win); //define_img.c
int			get_everything(char **map); //get_everything.c
void		create_map(t_window *win); //print_map.c
void		print_player(t_window *win, t_check_map var); //print_PEC.c
void		print_exit(t_window *win, t_check_map var); //print_PEC.c
void		print_collectibles(t_window *win, t_check_map var); //print_PEC.c
void		down_move(int key, t_window *win); //moves.c
void		upper_move(int key, t_window *win); //moves.c
void		left_move(int key, t_window *win); //moves.c
void		right_move(int key, t_window *win); //moves.c
void		game_is_over(t_window *win); //game_is_over.c
void		all_moves(int key, t_window *win); //moves.c
void		free_memory_line(char *line); //free_memory.c
int			get_next_line(int fd, char **line); //gnl.c
static int	cut_the_line(int index, char *rest, char **line); //gnl.c
char		*ft_free_strjoin(char const *s1, char const *s2); //gnl.c
static	int	is_char(char *str, char c); //gnl.c
char		*ft_substr(char const *s, unsigned int start, size_t len); //gnl.c
static int	make_width(char *file); //main.c
int			escape(t_window *win); //main.c
static int	make_height(char *file); //main.c
int			deal_key(int key, t_window *win); //main.c
int			main(int argc, char **argv); //main.c
void		ft_putchar(char c); // --
size_t		ft_strlen(const char *str); //mlx_utils

#endif
