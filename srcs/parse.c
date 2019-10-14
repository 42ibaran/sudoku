/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:50:50 by ibaran            #+#    #+#             */
/*   Updated: 2019/10/14 13:01:13 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void		divide_line_and_fill_grid(t_cell **grid, int line_nbr, char *line)
{
	char			**word_tab;
	int				i;
	int				value;

	i = 0;
	if (!(word_tab = ft_strsplit(line, ' ')))
		error(ERR_MEMORY, 0);
	while (i < 9)
	{
		if (!word_tab[i])
			error(ERR_TOO_FEW_VALUES, line_nbr + 1);
		value = ft_atoi(word_tab[i]);
		if ((!ft_strisnum(word_tab[i]) || value < 1 || value > 9)
				&& ft_strcmp(word_tab[i], "*"))
			error(ERR_INVALID_NUMBER, line_nbr + 1);
		grid[line_nbr][i].value = (word_tab[i][0] == '*' ? 0 : value);
		grid[line_nbr][i].given = (word_tab[i][0] == '*' ? FALSE : TRUE);
		grid[line_nbr][i].error = FALSE;
		i++;
	}
	if (word_tab[9])
		error(ERR_TOO_MANY_VALUES, line_nbr + 1);
}

void		check_input(t_cell **grid)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
			if (grid[i][j].given && (!check_line(grid, i, j)
					|| !check_column(grid, i, j)
					|| !check_square(grid, i, j)))
				error(ERR_INVALID_GRID, i + 1);
	}
}

t_cell		**parse(char *file_name)
{
	int		fd;
	char	*line;
	int		line_nbr;
	int		gnl;
	t_cell	**grid;

	line_nbr = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		error(ERR_OPEN_FILE, 0);
	grid = allocate_grid();
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		if (line_nbr >= 9)
			error(ERR_TOO_MANY_LINES, 0);
		divide_line_and_fill_grid(grid, line_nbr, line);
		free(line);
		line_nbr++;
	}
	if (line_nbr != 9)
		error(ERR_TOO_FEW_LINES, 0);
	check_input(grid);
	return (grid);
}
