#include "../../includes/so_long.h"

void init_data(t_data *data)
{
    data->map = NULL;
    data->pos.x = 0;
    data->pos.y = 0;
    data->fd = 0;
	data->map_copy = NULL;
}

int check_all(t_data *data)
{
    if (check_rectangle(data) && check_wall(data)
		&& check_map_contenu(data) && check_count_info(data))
		return 1;
	return 0;
}

int	init_map(t_data *data, char *str)
{
	init_data(data);

	if (!check_path(str))
		return (free(data), 0);
	data->fd = open(str, O_RDONLY);
	if (data->fd < 0)
		return (printf("error\nfail open\n"), free(data), 0);
    data->map = get_map(data, data->fd, data->map);
	if (!data->map)
		return (close(data->fd), free(data), 0);
	if (!check_all(data))
		return (close(data->fd), ft_free_map(data->map), free(data), 0);
	close(data->fd);
	ft_free_map(data->map);
	return (1);
}
