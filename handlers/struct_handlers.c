/*
** struct_handlers.c for wolf3d in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  1 19:59:16 2017 Bonaldi Jordan
** Last update Sun Jan 15 21:33:49 2017 root
*/

# include "project.h"

static void	pixels_init(t_wolf *wolf)
{
  int		i;

  i = -1;
  if (!(wolf->fb->pixels = malloc(wolf->fb->width * wolf->fb->height *
				  4 * sizeof(wolf->fb))))
    wolf->stop = 1;
  while (++i < wolf->fb->width * wolf->fb->height * 4)
    wolf->fb->pixels[i] = 0;
}

t_wolf		*initialiser(char **argv, char *format, int wall, int vo)
{
  t_wolf	*wolf;

  if (!(wolf = malloc(sizeof(*wolf))))
    wolf->stop = 1;
  if (!(wolf->fb = malloc(sizeof(*wolf->fb))))
    wolf->stop = 1;
  wolf->wall = wall;
  wolf->vo = vo;
  wolf->player = set_fvector(1.5, 1.5);
  wolf->angle = 0;
  wolf->distance = 0.25;
  wolf->filename = argv[1];
  wolf->format = format;
  wolf->fb->width = 1920;
  wolf->fb->height = 1080;
  if (!(wolf->buf = malloc(4096)))
    wolf->stop = 1;
  if (!file_manager(wolf))
    wolf->stop = 1;
  else
    wolf->stop = 0;
  pixels_init(wolf);
  return (wolf);
}
