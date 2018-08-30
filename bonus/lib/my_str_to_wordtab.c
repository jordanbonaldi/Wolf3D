/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/Neferett/CPool_Day08/task04
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Oct 12 10:53:16 2016 Bonaldi Jordan
** Last update Sun Jan  8 14:17:53 2017 Bonaldi Jordan
*/

# include "lib.h"

char	**my_str_to_wordtab(char *, char);
char	**tab_complete(char **, char *, int, char);

char	**my_str_to_wordtab(char *str, char c)
{
  char	**tab;
  int	i;

  i = 0;
  if (!(tab = malloc(my_strlen(str) * 10)))
    exit(84);
  tab = tab_complete(tab, str, i, c);
  return (tab);
}

char	**tab_complete(char **tab, char *str, int i, char c)
{
  int	j;
  char	*arr;

  j = -1;
  if (!(arr = malloc(my_strlen(str))))
    exit(84);
  while (*str && !(i = 0) && (!++(j) ? 1 : 1))
    {
      while (*str == c && (str++)) {}
      while (*str != c && *str)
	if ((arr[i] = *str) && (++i) && !(arr[i] = 0) && (str++)) {}
      if (arr && (tab[j] = my_strdup(arr)))
	while (*++arr);
    }
  tab[++j] = NULL;
  return (tab);
}
