#include "../../includes/so_long.h"

char **map_copy(t_data *data)
{
    int i;
    int len;
    char **map;

    i = 0;
    len = data->info.line;
    map = (char **)malloc(sizeof(char *) * (len + 2));
    if (!map)
        return (NULL);
    while (i < len)
    {
        map[i] = strdup(data->map[i]);
        if (!map[i])
            return (ft_free_map(map), NULL);
        i++;
    }
    map[i] = NULL;
    return (map);
}

void get_position(t_data *data)
{
    int i;
    int j;

    data->pos.y = 0;
    data->pos.x = 0;
    i = 0;
    while (data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                data->pos.y = i;
                data->pos.x = j;
                return ;
            }
            j++;
        }
        i++;
    }
    ft_putstr("Error\n", 2);
    return ;
}
