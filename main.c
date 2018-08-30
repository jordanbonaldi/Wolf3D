/*
** main.c for main in /home/Neferett/bin/IMPORT
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update Sun Jan 15 21:34:09 2017 root
*/

#include "project.h"

int		main(int argc, char **argv)
{
  t_wolf	*wolf;

  if (argc != 2)
    return (84);
  wolf = initialiser(argv, "w3", 1, 0);
  if (wolf->stop == 1)
    return (84);
  init_window(wolf);
  return (0);
}
