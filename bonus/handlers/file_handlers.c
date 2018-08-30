/*
** file_handlers.c for wolf3d in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  1 19:53:35 2017 Bonaldi Jordan
** Last update Sun Jan 15 16:03:35 2017 root
*/

# include "project.h"

static char	*parse_filename(char *name)
{
  if (nb_of(name, '.') != 1)
    my_exit(84, 16, "file_handlers.c", ". != 1");
  while (name && *++name != '.');
  return (++name);
}

static Boolean	check_file(char *file, t_wolf *wolf)
{
  while (*file)
    {
      if (*file != wolf->wall + 48 && *file != wolf->vo + 48
	  && *file != '3' && *file != '\n')
	my_exit(84, 26, "file_handlers.c", "Bad map");
      file++;
    }
  return (true);
}

void	file_manager(t_wolf *wolf)
{
  if (my_strcmp(wolf->format, parse_filename(wolf->filename)) != 0)
    my_exit(84, 35, "file_handlers.c", "cmp format");
  if ((wolf->fd = open(wolf->filename, O_RDONLY)) < 0)
    my_exit(84, 37, "file_handlers.c", "opening file");
  if ((wolf->read = read(wolf->fd, wolf->buf, 4096)) < 0)
    my_exit(84, 39, "file_handlers.c", "read file");
  wolf->buf[wolf->read] = 0;
  check_file(wolf->buf, wolf);
  wolf->map = convert_map(wolf);
}
