/*
** controls_handlers.c for wolf in /home/Neferett/wolf3d/bonus
** 
** Made by root
** Login   <root@epitech.net>
** 
** Started on  Sun Jan 15 00:40:29 2017 root
** Last update Sun Jan 15 17:49:35 2017 Bonaldi Jordan
*/

# include "project.h"

static char	*get_string(t_wolf *wf, int i)
{
  if (i == 1)
    return (my_strcat(my_strcat(get_int("Lang_Type") ?
				get_conf("Lang_EN_MiniMap"):
				get_conf("Lang_FR_MiniMap"), "\t->\t"), wf->mpp));
  if (i == 2)
    return (my_strcat(my_strcat(get_int("Lang_Type") ? get_conf("Lang_EN_CL"):
				get_conf("Lang_FR_CL"), "\t->\t"), wf->clp));
  return (NULL);
}

void		init_string_mp(t_wolf *wf)
{
  sfText_setString(wf->t1, get_string(wf, 1));
  sfText_setString(wf->t2, get_string(wf, 2));
  sfText_setString(wf->t3, get_int("Lang_Type") ? get_conf("Lang_EN_Back"):
                   get_conf("Lang_FR_Back"));
}

static char		*get_good(int i)
{
  return (!i ? "WMiniMap" : "CurrentLevelPos");
}

void		handle_position(t_wolf *wf, sfEvent event)
{
  int		i;

  i = -1;
  if (event.type == sfEvtTextEntered &&
      (event.text.unicode >= '0' && event.text.unicode <= '3'))
    {
      set_conf(get_good(wf->sel), my_strcatc("\0", event.text.unicode));
      if (!wf->sel && (wf->mpp = get_conf(get_good(wf->sel)))) {}
      else if (wf->sel == 1 && (wf->clp = get_conf(get_good(wf->sel)))) {}
      if (!wf->sel && (!(wf->minimap = get_int(get_good(wf->sel))) ? 1 : 1)
	  && reset_pixel(wf))
	draw_circle(wf);
      else if (wf->sel == 1)
	{
	  sfText_setString(wf->t5, get_int("Lang_Type") ?
			   my_strcat(my_strcat(get_conf("Lang_EN_Current_Lvl"), ": "),
				     get_conf("WCurrentLevel")) :
			   my_strcat(my_strcat(get_conf("Lang_FR_Current_Lvl"), ": "),
				     get_conf("WCurrentLevel")));
	  sfText_setPosition(wf->t5, get_right_pos());
	  while (++i < wf->fb->width * wf->fb->height * 4)
	    wf->fb->pixels[i] = 0;
	}
    }
}
