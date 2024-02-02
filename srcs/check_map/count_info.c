#include "../../includes/so_long.h"

void init_contenu(t_data *data)
{
	data->info.player = 0;
    data->info.collect = 0;
    data->info.exit = 0;
}

int check_map_contenu(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
	init_contenu(data);
    while(data->map[i])
    {
        while(data->map[i][j])
        {
            if (data->map[i][j] != '1' && data->map[i][j] != '0' && data->map[i][j] != 'C'
            && data->map[i][j] != 'P' && data->map[i][j] != 'E')
                return(ft_putstr(UNKNOWN, 2), 0);
			else if (data->map[i][j] == 'P')
                data->info.player++;
            else if (data->map[i][j] == 'C')
                data->info.collect++;
            else if (data->map[i][j] == 'E')
                data->info.exit++;
            j++;
        }
        i++;
        j = 0;
    }
    return (1);
}

int check_count_info(t_data *data)
{
    if (data->info.player != 1)
        return (ft_putstr("Error\n1 player required\n", 2), 0);
    else if (data->info.collect < 1)
        return (ft_putstr("Error\nnot collectible\n", 2), 0);
    else if(data->info.exit != 1)
         return (ft_putstr("Error\nonly 1 exit required\n", 2), 0);
    printf("MAP OK\n");
    return (1);
}
