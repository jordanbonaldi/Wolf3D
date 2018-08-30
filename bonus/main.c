/*
** main.c for main in /home/Neferett/bin/IMPORT
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update Thu Jan 12 20:24:49 2017 Bonaldi Jordan
*/

#include "project.h"

int		main(void)
{
  t_wolf	*wolf;

  wolf = initialiser();
  init_window(wolf);
  return (0);
}
