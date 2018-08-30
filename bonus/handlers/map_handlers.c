/*
** map_handlers.c for wolf in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  1 21:38:18 2017 Bonaldi Jordan
** Last update Fri Jan 13 09:29:27 2017 Bonaldi Jordan
*/

# include "project.h"

static int      get_len_line(char *file, int line)
{
  int   j;
  int   i;

  i = 0;
  j = 0;
  while (i < line)
    {
      if (file[j] == '\n')
	i++;
      j++;
    }
  i = 0;
  j--;
  while (file[++j] != '\n' && ++i);
  return (i);
}

int      **convert_map(t_wolf *wolf)
{
  int           **map;
  int           i;
  int		j;
  int		k;

  i = -1;
  j = -1;
  if (!(map = malloc(sizeof(int *) * nb_of(wolf->buf, '\n'))))
    my_exit(84, 39, "file_handler.c", "malloc int *");
  while (++i < nb_of(wolf->buf, '\n'))
    {
      if (!(map[i] = malloc(sizeof(int) * get_len_line(wolf->buf, i))))
	my_exit(84, 62, "file_handlers.c", "malloc int");
      k = -1;
      while (wolf->buf[++j] != '\n')
	  map[i][++k] = ((int)wolf->buf[j]) - 48;
    }
  wolf->size = set_vector(i - 1, j / i);
  return (map);
}
