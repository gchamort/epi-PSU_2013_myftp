/*
** main.c for myftp in /home/chanut_g/rendu/PSU_2013_myftp/client/src
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Wed Apr  9 16:07:48 2014 Guillaume
** Last update Thu Apr 10 18:27:22 2014 Guillaume
*/

#include	"client.h"

int			myerror(char *error)
{
  write(STDERR_FILENO, ERR, strlen(ERR));
  write(STDERR_FILENO, error, strlen(error));
  return (EXIT_FAILURE);
}

int			main(int ac, char **av)
{
  if (ac == 3)
    return (client(av[1], atoi(av[2])));
  return (myerror(ERR_USAGE));
}
