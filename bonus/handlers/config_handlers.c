/*
** config_handlers.c for wolf in /home/Neferett/wolf3d/bonus
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Thu Jan 12 19:17:14 2017 Bonaldi Jordan
** Last update Fri Jan 13 15:55:04 2017 root
*/

# include "project.h"

char	*get_conf(char *name)
{
  char	*buff;
  int	fd;

  if ((fd = open(".config.w3", O_CREAT | O_RDONLY)) < 0)
    return (NULL);
  while ((buff = get_next_line(fd)))
    {
      if (!my_strncmp(name, buff, my_strlen(name)))
	{
	  close(fd);
	  return (buff += my_strlen(name) + 1);
	}
      free(buff);
    }
  close(fd);
  return (NULL);
}

int	get_int(char *name)
{
  char	*buff;
  int	fd;

  if ((fd = open(".config.w3", O_CREAT | O_RDONLY)) < 0)
    return (2);
  while ((buff = get_next_line(fd)))
    {
      if (!my_strncmp(name, buff, my_strlen(name)))
	{
	  close(fd);
	  return (my_getnbr(buff += my_strlen(name) + 1));
	}
      free(buff);
    }
  close(fd);
  return (0);
}

void	set_conf(char *name, char *data)
{
  char	*tmp;
  char	*buff;
  int	fd;

  if ((fd = open(".config.w3", O_RDONLY)) < 0 || !(tmp = malloc(1)))
    return;
  *tmp = 0;
  while ((buff = get_next_line(fd)))
    {
      if (!my_strncmp(name, buff, my_strlen(name)))
	{
	  buff[my_strlen(name) + 1] = 0;
	  buff = my_strcat(buff, data);
	}
      tmp = my_strcat(tmp, my_strcat(buff, "\n"));
      free(buff);
    }
  close(fd);
  system("rm -f .config.w3");
  if ((fd = open(".config.w3", O_CREAT | O_WRONLY)) < 0)
    return;
  system("chmod 755 .config.w3");
  write(fd, tmp, my_strlen(tmp));
  close(fd);
}

void	set_conf_char(char *name, char data)
{
  char	*tmp;
  char	*buff;
  int	fd;

  if ((fd = open(".config.w3", O_RDONLY)) < 0 || !(tmp = malloc(1)))
    return;
  *tmp = 0;
  while ((buff = get_next_line(fd)))
    {
      if (!my_strncmp(name, buff, my_strlen(name)))
	{
	  buff[my_strlen(name) + 1] = 0;
	  buff = my_strcat(buff, &data);
	}
      tmp = my_strcat(tmp, my_strcat(buff, "\n"));
      free(buff);
    }
  close(fd);
  system("rm -f .config.w3");
  if ((fd = open(".config.w3", O_CREAT | O_WRONLY)) < 0)
    return;
  system("chmod 755 .config.w3");
  write(fd, tmp, my_strlen(tmp));
  close(fd);
}
