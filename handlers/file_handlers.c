/*
** file_handlers.c for wolf3d in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  1 19:53:35 2017 Bonaldi Jordan
** Last update Sun Jan 15 21:31:22 2017 Bonaldi Jordan
*/

# include "project.h"

static char	*parse_filename(char *name)
{
  if (nb_of(name, '.') != 1)
    return ("0");
  while (name && *++name != '.');
  return (++name);
}

static Boolean	check_file(char *file, t_wolf *wolf)
{
  while (*file)
    {
      if (*file != wolf->wall + 48 && *file != wolf->vo + 48 && *file != '\n')
	return (false);
      file++;
    }
  return (true);
}

Boolean	file_manager(t_wolf *wolf)
{
  if (my_strcmp(wolf->format, parse_filename(wolf->filename)) != 0)
    return (false);
  if ((wolf->fd = open(wolf->filename, O_RDONLY)) < 0)
    return (false);
  if ((wolf->read = read(wolf->fd, wolf->buf, 4096)) < 0)
    return (false);
  wolf->buf[wolf->read] = 0;
  if (!check_file(wolf->buf, wolf))
    return (false);
  wolf->map = convert_map(wolf);
  return (true);
}
