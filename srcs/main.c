/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:45:09 by ibaran            #+#    #+#             */
/*   Updated: 2019/10/14 12:58:13 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char **argv)
{
	t_cell		**grid;

	init_globals();
	if (argc != 2)
		error(ERR_USAGE, 0);
	grid = parse(argv[1]);
	solve(grid, 0, 0);
	if (!g_solutions)
		error(ERR_NO_SOLUTION, 0);
	f_free();
	return (0);
}
