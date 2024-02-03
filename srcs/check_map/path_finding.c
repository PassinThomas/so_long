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
    if (data->map)
    {
        while (i < len)
        {
            map[i] = strdup(data->map[i]);
            if (!map[i])
                return (ft_free_map(map), NULL);
            i++;
        }
    }
    map[i] = NULL;
    return (map);
}
