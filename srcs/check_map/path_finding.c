#include "../../includes/so_long.h"

char **map_copy(char **map, t_data *data)
{
    int i;
    int len;

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
                /*printf("%d\t%d\n", data->pos.y, data->pos.x);
                printf("%c\n", data->map[data->pos.y][data->pos.x]);*/
                return ;
            }
            j++;
        }
        i++;
    }
    ft_putstr("Error\n", 2);
    return ;
}

static void flood_fill(char **map, int x, int y, t_data *data)
{
    int row;
    int col;

    row = data->info.line;
    col = ft_strlen(data->map[0]);
    printf("%d\n", col);
    if (x < 0 || x >= row || y < 0 || y >= col)
        return ;
    if ( map[x][y] == '1')
        return ;
    map[x][y] = x;
    flood_fill(map, x + 1, y, data);
    flood_fill(map, x - 1, y, data);
    flood_fill(map, x, y + 1, data);
    flood_fill(map, x, y - 1, data);
    return ;
}

static int valid_map(char **map, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] != '1' && map[i][j] != '0' || map[i][j] != 'x')
                return (printf("Element non atteignable\n"), 0);
            j++;
        }
        i++;
    }
    return (1);
}

void check_win(char **map, t_data *data)
{
    flood_fill(map, data->pos.x, data->pos.y, data);
    if (valid_map(map, data))
        printf("win\n");
    return ;
}
