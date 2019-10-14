/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:48:05 by ibaran            #+#    #+#             */
/*   Updated: 2019/10/14 17:45:28 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void		init_globals(void)
{
	g_free.grid = NULL;
	g_solutions = 0;
}

void		f_free(void)
{
	int		i;

	if (g_free.grid)
	{
		i = -1;
		while (++i < 9)
			free(g_free.grid[i]);
		free(g_free.grid);
	}
}

void		print_grid(t_cell **grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j].given)
				ft_printf("%d", grid[i][j].value);
			else
				ft_printf("{dark_green}%d{eoc}", grid[i][j].value);
			if (j < 8)
				ft_printf(" ");
			if (!((j + 1) % 3) && j < 8)
				ft_printf("| ");
			j++;
		}
		ft_printf("%s", (!((i + 1) % 3) && i < 8) ? HORIZONTAL : "\n");
		i++;
	}
}

t_cell		**allocate_grid(void)
{
	t_cell	**grid;
	int		i;

	if (!(grid = (t_cell**)malloc(sizeof(t_cell*) * 10)))
		error(ERR_MEMORY, 0);
	i = -1;
	while (++i < 9)
		if (!(grid[i] = (t_cell*)malloc(sizeof(t_cell) * 9)))
			error(ERR_MEMORY, 0);
	grid[9] = NULL;
	g_free.grid = grid;
	return (grid);
}

void		error(int flag, int line_nbr)
{
	if (flag == ERR_USAGE)
		ft_printf("usage: sudoku <filename>\n");
	if (flag == ERR_OPEN_FILE)
		ft_printf("Error: can't open file\n");
	if (flag == ERR_MEMORY)
		ft_printf("Error: can't allocate memory\n");
	if (flag == ERR_TOO_MANY_LINES)
		ft_printf("Error: too many lines in the file\n");
	if (flag == ERR_TOO_FEW_LINES)
		ft_printf("Error: too few lines in the file\n");
	if (flag == ERR_TOO_MANY_VALUES)
		ft_printf("Error: too many values on line %d\n", line_nbr);
	if (flag == ERR_TOO_FEW_VALUES)
		ft_printf("Error: too few values on line %d\n", line_nbr);
	if (flag == ERR_INVALID_NUMBER)
		ft_printf("Error: invalid value on line %d\n", line_nbr);
	if (flag == ERR_INVALID_GRID)
		ft_printf("Error: mistake in input on line %d\n", line_nbr);
	if (flag == ERR_MAX_SOLUTION)
		ft_printf("Error: too many solutions, maximum = %d. Stopping now\n",
			MAX_SOLUTIONS);
	if (flag == ERR_NO_SOLUTION)
		ft_printf("Error: can't find solution\n");
	f_free();
	exit(EXIT_FAILURE);
}
