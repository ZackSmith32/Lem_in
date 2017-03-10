/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:09:57 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/10 09:11:04 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "ft_printf.h"
# include "vector.h"
# include "vect.h"

typedef struct		s_lemd
{
	char			*name;
	int				start;
	int				end;
	char			**connections;
}					t_lemd;

typedef struct		s_path
{
	char			*name;
	int				len;
	struct s_path	*n_node;
	struct s_path	*n_path;
}					t_path;

/*
**	b_parse
*/
int					parse();

/*
**	g_constructors
*/
t_lemd				*data_constructor(char *name, char **connections);
t_path				*path_constructor(char *name, int len, t_path *n_node, 
						t_path *n_path);

/*
**	i_make_graph
*/

/*
**	j_make_nodes
*/
int				make_nodes(char ***data, t_vect **nodes);

#endif