/*
** client.h for myftp in /home/chanut_g/rendu/PSU_2013_myftp/client/include
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Wed Apr  9 16:05:09 2014 Guillaume
** Last update Sun Apr 13 17:12:15 2014 Guillaume
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# include	<string.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	"error.h"

/* typedef struct	s_client */
/* { */  
/* }		t_client; */

# define	PROMPT		"client-> "
# define	MAX_READ	140

int		client(char *, int);
int		receive(int);

#endif	     // CLIENT
