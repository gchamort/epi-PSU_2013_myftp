/*
** error.h for myftp in /home/chanut_g/rendu/PSU_2013_myftp/clnt/include
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Sun Apr 13 17:05:57 2014 Guillaume
** Last update Sun Apr 13 17:20:55 2014 Guillaume
*/

#ifndef		ERROR_H_
# define	ERROR_H_

# define	ERR		"[ERROR]: "
# define	ERR_USAGE	"usage: ./client <ip addr> <port>\n"
# define	ERR_PROTO	"client: getprotobyname() failed\n"
# define	ERR_SOCK	"client: socket() failed\n" 
# define	ERR_CNCT	"client: connect() failed\n"
# define	ERR_MALLOC	"system: malloc() failed\n"

int             myerror(char *);
int             err_close(char *, int);

#endif     // ERROR_H_ 
