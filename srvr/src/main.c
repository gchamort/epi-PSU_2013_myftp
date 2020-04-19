/*
** main.c for myftp in /home/chanut_g/rendu/PSU_2013_myftp/serveur/src
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon Apr  7 18:13:38 2014 Guillaume
** Last update Sun Apr 13 17:00:52 2014 Guillaume
*/

#include	"serveur.h"

int			myerror(char *error)
{
  write(STDERR_FILENO, ERR, strlen(ERR));
  write(STDERR_FILENO, error, strlen(error));
  return (EXIT_FAILURE);
}

char			*get_path(char **env)
{
  int			i;
  char			*str;

  i = 0;
  while (env[i] != NULL)
    {
      if (strncmp(env[i], "PWD=", strlen("PWD=")) == 0)
	{
	  if ((str = malloc(sizeof(char) * (strlen(env[i]) + 1))) == NULL)
	    return (NULL);
	  strcpy(str, env[i]);
	  return (&str[strlen("PWD=")]);
	}
      i++;
    }
  return (NULL);
}

int			main(int ac, char **av, char **env)
{
  if ((ac == 2) && (env[0] != NULL))
    return (serveur(atoi(av[1]), get_path(env)));
  return (myerror(ERR_USAGE));
}
