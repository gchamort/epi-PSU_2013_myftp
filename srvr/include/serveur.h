/*
** serveur.h for myftp in /home/chanut_g/rendu/PSU_2013_myftp/serveur/include
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon Apr  7 18:14:53 2014 Guillaume
** Last update Sun Apr 13 16:59:39 2014 Guillaume
*/

#ifndef		SERVEUR_H_
# define	SERVEUR_H_

# include		<string.h>
# include		<unistd.h>
# include		<stdlib.h>
# include		<stdio.h>
# include		<netdb.h>
# include		<sys/types.h>
# include		<sys/socket.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		"error.h"

# define		MAX_BUFF	140
# define		MAX_CLIENT	12
# define		CONNECT		"client connected <fd> <ip_addr> :"

typedef struct		s_serveur
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			sock;
  char			*home_path;
  char			*path;
  char			*ip_addr;
}			t_serveur;

char			*get_path(char **);
int			serveur(int, char *);
int			receive(int);

#endif	     // SERVEUR
