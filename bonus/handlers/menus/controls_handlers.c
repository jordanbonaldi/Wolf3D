/*
** controls_handlers.c for wolf in /home/Neferett/wolf3d/bonus
** 
** Made by root
** Login   <root@epitech.net>
** 
** Started on  Sun Jan 15 00:40:29 2017 root
** Last update Sun Jan 15 17:48:55 2017 Bonaldi Jordan
*/

# include "project.h"

char		*get_string(t_wolf *wf, int i)
{
  if (i == 1)
    return (my_strcat(my_strcat(get_int("Lang_Type") ?
				get_conf("Lang_EN_KeyZ"):
				get_conf("Lang_FR_KeyZ"), "\t->\t"), wf->kz));
  if (i == 2)
    return (my_strcat(my_strcat(get_int("Lang_Type") ?
				get_conf("Lang_EN_KeyS"):
				get_conf("Lang_FR_KeyS"), "\t->\t"), wf->ks));
  if (i == 3)
    return (my_strcat(my_strcat(get_int("Lang_Type") ?
				get_conf("Lang_EN_KeyQ"):
				get_conf("Lang_FR_KeyQ"), "\t->\t"), wf->kq));
  if (i == 4)
    return (my_strcat(my_strcat(get_int("Lang_Type") ?
				get_conf("Lang_EN_KeyD"):
				get_conf("Lang_FR_KeyD"), "\t->\t"), wf->kd));
  return (NULL);
}

void		init_string(t_wolf *wf)
{
  sfText_setString(wf->t1, get_string(wf, 1));
  sfText_setString(wf->t2, get_string(wf, 2));
  sfText_setString(wf->t3, get_string(wf, 3));
  sfText_setString(wf->t4, get_string(wf, 4));
  sfText_setString(wf->t5, get_int("Lang_Type") ? get_conf("Lang_EN_Back"):
                   get_conf("Lang_FR_Back"));
}

char		*get_good(int i)
{
  return (!i ? "WKeyZ" : i == 1 ? "WKeyS" : i == 2 ? "WKeyQ" : "WKeyD");
}

char		*get_good_int(int i)
{
  return (!i ? "Forward" : i == 1 ? "BackWard" :
	  i == 2 ? "Move_Left" : "Move_Right");
}

void		handle_key_create(t_wolf *wf, sfEvent event)
{
  if (event.type == sfEvtKeyPressed &&
      (event.key.code != sfKeyUp && event.key.code != sfKeyDown &&
       event.key.code != sfKeyRight && event.key.code != sfKeyLeft))
    {
      set_conf(get_good_int(wf->sel), my_itoa(event.key.code));
      if (!wf->sel)
	wf->key_z = get_int(get_good_int(wf->sel));
      else if (wf->sel == 1)
	wf->key_s = get_int(get_good_int(wf->sel));
      else if (wf->sel == 2)
	wf->key_q = get_int(get_good_int(wf->sel));
      else if (wf->sel == 3)
	wf->key_d = get_int(get_good_int(wf->sel));
    }
  if (event.type == sfEvtTextEntered &&
      (event.text.unicode >= 'a' && event.text.unicode <= 'z'))
    {
      set_conf(get_good(wf->sel),
	       my_strcatc("\0", event.text.unicode - 32));
      if (!wf->sel && (wf->kz = get_conf(get_good(wf->sel)))) {}
      else if (wf->sel == 1 && (wf->ks = get_conf(get_good(wf->sel)))) {}
      else if (wf->sel == 2 && (wf->kq = get_conf(get_good(wf->sel)))) {}
      else if (wf->sel == 3 && (wf->kd = get_conf(get_good(wf->sel)))) {}
    }
}
