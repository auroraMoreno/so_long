/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 07:43:07 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/20 13:59:16 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//funcion para unir todo el mapa en una misma linea 
// y asi sea más facil calcular el width y el height
// maybe use it to parse too
static int ft_join_map_line(char *line, char **joined_str)
{
    char *aux;
    aux = ft_strjoin(*joined_str,line);
    //si da fallo we free line and joined_str
    //devolvemos 0
    if(!aux)
    {
        free(*joined_str);
        free(line);
        return (0);
    }
    //si todo va bien devolvemos 1 
    free(*joined_str);
    free(line);
    *joined_str = aux;
    //si está vacía: 
    if(!*joined_str)
        return(0);
    return (1);
}

static void ft_process_map_line(char *joined_str, t_game *game)
{
    // hay que obtener el width and height primero 
    // porq lo vamos a usar en el map is valid 
    //calculate width and height
    ft_get_width(joined_str, game);
    ft_get_height(joined_str, game);
    // printf("%d\n", game->map_width);
    // printf("%d\n", game->map_heigth);
    //check if map is valid QUITAR QUE AQUI DEVULVA UN INT, SI FALLA EL METODO HACE EXIT
    if(ft_map_is_valid(game, joined_str) == 0)
    {
        printf("invalid map not the correct shape \n");
        exit(EXIT_FAILURE);
    }
       // ft_free_game(game, "El mapa no es válido");
    
    //allocate memory for the map based on the map height
    game->map = malloc(sizeof(t_map *) * game->map_heigth);
	if(!game->map)
	{
		free(joined_str);
		ft_free_game(game, "Error alloc de memoria");		
	}
    ft_innit_x_row(game);

    //add otro metodo que sea fill x_row
    ft_fill_x_row(game, joined_str);

    // AQUI ADD EL VALID ROUTE
    ft_valid_route(game);
}

void ft_fill_x_row(t_game *game, char *joined_str)
{
    int i;
    int j;
    int x;
    
    i = 0;
    x = 0;
    while(i < game->map_heigth)
    {
        j = 0;
        while(j < game->map_width)
        {
            if(joined_str[x] == '\n')
            {
                x++;
                continue;
            }
            //set the coordinates
            game->map[i][j].x= i;
            game->map[i][j].y = j;
            //set the value of given coordinate
            game->map[i][j].value=joined_str[x];
            j++;
            x++;
        }
        i++;
    }
        
    
}

void ft_innit_x_row(t_game *game)
{
    int i;

    i = 0;
    while(i < game->map_heigth)
    {
        game->map[i] = malloc(sizeof(t_map) * game->map_width);
        if(!game->map[i])
            ft_free_game(game, "Error alloc x row");
        i++;
    }
}

// hacer método para init collectables y todo esooo
void ft_init_map(t_game *game, char *file)
{
    int fd;
    char *joined_str;
    char *line; 
    // primero open el fichero 
    fd = open(file, O_RDONLY);
    if(fd == -1){
         // el problema esq libero memoria pero aun no hice innit ni nada
        //ft_free_game(game, "Invalid file.\n");
        free(game);
        ft_putendl_fd("File not found.", 2);
        exit(EXIT_FAILURE);
    }
    // luego tendremos que ir linea a linea 
    joined_str = ft_calloc(1, sizeof(char));
    if(!joined_str)
        ft_free_game(game, "Error en calloc");
    //(podremos uusar el gnl i guess)
    line = get_next_line(fd);
    // si resulta que es un cuadrado, devolvemos error 
    while(line)
    {
        //join the line 
        if(ft_join_map_line(line,&joined_str) == 0)
            // SI RETURNS 0 ESQ ESTÁ MAL 
            ft_free_game(game, "Error en el joinmapline");
        //update line
        line = get_next_line(fd);
    }
    close(fd);
    //process map: the function will get the line height and width
    /*MAP CHECKS IN FUNCTION BELOW*/
    ft_process_map_line(joined_str, game);
    free(joined_str); //since we are using join inside the loop 
    
}




