/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_find_routes_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:11:53 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/27 18:51:15 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lemd	*find_start_node(t_vect *nodes)
{
	size_t	i;
	t_lemd	*temp;

	i = 0;
	while (i < nodes->units)
	{
		temp = *((t_lemd **)v_item(nodes, i));
		if (temp->s_e == 1)
		{
			return (temp);
		}
		i++;
	}
	return (NULL);
}

t_lemd	*find_end_node(t_vect *nodes)
{
	size_t	i;
	t_lemd	*temp;

	i = 0;
	while (i < nodes->units)
	{
		temp = *((t_lemd **)v_item(nodes, i));
		if (temp->s_e == 2)
		{
			return (temp);
		}
		i++;
	}
	return (NULL);
}

void		print_shortest_path(t_vect *shortest_path)
{
	size_t		i;
	t_lemd		*temp;

	printf("shortest path:\n");
	i = 0;
	while (i < shortest_path->units)
	{
		temp = *((t_lemd **)v_item(shortest_path, i));
		printf("%s\n", temp->name);
		i++;
	}
}

void		create_path(t_vect *table_end_node_connections, 
				t_vect *shortest_path_vect)
{
	size_t		i;
	t_lemd		*node_from_dist;
	t_lemd		*temp_node;

	i = 1;
	while (i < table_end_node_connections->units)
	{
		node_from_dist = *((t_lemd **)v_item(table_end_node_connections, i));
		printf("node_from_dist->name = %s\n", node_from_dist->name);
		temp_node = (t_lemd *)ft_memalloc(sizeof(t_lemd));
		temp_node->name = node_from_dist->name;
		v_insert(shortest_path_vect, shortest_path_vect->units, temp_node);
		i++;
	}
}

t_vect		*paths_vect(t_vect *nodes, t_vect *dist_table)
{
	char	*end_node_name;
	t_lemd	*dist_table_end_node;
	t_vect	*shortest_path_vect;
	t_vect	*output_paths;

	output_paths = v_new(0, sizeof(t_vect *));
	shortest_path_vect = v_new(0, sizeof(t_lemd *));
	v_insert(output_paths, 0, shortest_path_vect);
	end_node_name = find_end_node(nodes)->name;
	dist_table_end_node = search_nodes_by_name(dist_table, end_node_name);
	create_path(dist_table_end_node->connections, shortest_path_vect);
	print_shortest_path(shortest_path_vect);
	return (shortest_path_vect);
}


































