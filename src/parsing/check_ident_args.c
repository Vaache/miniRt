#include "minirt.h"

int	check_args_amb(char **line);
int	check_args_cam(char **line);
int	check_args_light(char **line);

int	check_args_amb(char **line)
{
	char	**colors;
	char	*amb;

	amb = ft_strdup(line[1]);
	if (valid_float(&amb, 1) || ft_atof(line[1]) < 0.0 || \
				ft_atof(line[1]) > 1.0 || count_comma(line[1]) != 0)
	{
		free(amb);
		return (err("Error : Ambient light factor is not in range\n"));
	}
	free(amb);
	colors = ft_split(line[2], ',');
	if (count_comma(line[2]) != 2 || check_number(NULL, colors, 0) || \
												strlen_2d(colors) != 3)
	{
		free_2d(colors);
		return(err("Error : Wrong RGB number\n"));
	}
	if (valid_colors(colors))
	{
		free_2d(colors);
		return (err("Error : Color number is out of range\n"));
	}
	free_2d(colors);
	return (0);
}
int	check_args_cam(char **line)
{
	int		fov;
	char	**vect;
	char	**n_vect;

	vect = ft_split_2(line[1], ',');
	n_vect = ft_split_2(line[2], ',');
	fov = ft_atoi(line[3]);
	if (count_comma(line[1]) != 2 || count_comma(line[2]) != 2 || \
			valid_coord(n_vect) || check_number(NULL, vect, 0) || \
			check_number(NULL, n_vect, 0) || strlen_2d(vect) != 3 || \
				strlen_2d(n_vect) != 3)
	{
		free_2d(n_vect);
		return (err("Error : Wrong coordinates for camera\n"));
	}
	if (fov < 0 || fov > 180 || count_comma(line[3]) != 0 || \
									check_number(line[3], NULL, 1))
	{
		free_2d(n_vect);
		return (err("Error : The field of view is out of range\n"));
	}
	free_2d(n_vect);
	return (0);
}

int	check_args_light(char **line)
{
	char	**colors;
	char	**vect;
	char	*light;

	vect = ft_split(line[1], ',');
	if (count_comma(line[1]) != 2 || strlen_2d(vect) != 3 || \
									check_number(NULL, vect, 0))
		return (err("Error : Wrong coordinates for light\n") + free_2d(vect));
	free_2d(vect);
	colors = ft_split(line[3], ',');
	light = ft_strdup(line[2]);
	if (valid_float(&light, 1) || ft_atof(line[2]) < 0.0 || \
		ft_atof(line[2]) > 1.0 || count_comma(line[2]) != 0)
	{
		free_of_n(light, NULL, colors, 2);
		return (err("Error : Wrong brightnes for light\n"));
	}
	if (count_comma(line[3]) != 2 || valid_colors(colors) || \
			strlen_2d(colors) != 3 || check_number(NULL, colors, 1))
	{
		free_of_n(light, NULL, colors, 3);
		return (err("Error : Wrong colors for light\n"));
	}
	free_of_n(light, NULL, colors, 2);
	return (0);
}
