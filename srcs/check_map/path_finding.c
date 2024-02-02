#include "../../includes/so_long.h"

char **map_copy(t_data *data, char **map_copy)
{
    int i;
    int len;

    i = 0;
    len = data->info.line;
    map_copy = (char **)malloc(sizeof(char *) * (len + 2));
    if (!map_copy)
        return (NULL);
    while (map_copy && i < len)
    {
        map_copy[i] = ft_strdup(data->map[i]);
        if (!map_copy[i])
            return (ft_free_map(map_copy), NULL);
        i++;
    }
    map_copy[i] = NULL;
    return (map_copy);
}
