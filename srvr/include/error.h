/*
** error.h for myftp in /home/chanut_g/rendu/PSU_2013_myftp/srvr/include
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Sun Apr 13 16:19:26 2014 Guillaume
** Last update Sun Apr 13 16:21:18 2014 Guillaume
*/

#ifndef		ERROR_H_
# define	ERROR_H_

# define	ERR		"[ERROR]: "
# define	ERR_USAGE	"Usage: ./serveur <port>\n"
# define	ERR_PROTO	"serveur: getprotobyname() failed\n"
# define	ERR_SOCK	"serveur: socket() failed\n"
# define	ERR_BIND	"serveur: bind() failed\n"
# define	ERR_LISTEN	"serveur: listen() failed\n"
# define	ERR_ACCEPT	"serveur: accept() failed\n"
# define	ERR_MALLOC	"system: malloc() failed\n"

int		myerror(char *);
int		err_close(char *, int);

#endif     // ERROR_H_
