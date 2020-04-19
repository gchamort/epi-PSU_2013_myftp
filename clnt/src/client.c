/*
** client.c for myftp in /home/chanut_g/rendu/PSU_2013_myftp/client/src
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Wed Apr  9 16:20:46 2014 Guillaume
** Last update Sun Apr 13 17:21:51 2014 Guillaume
*/

#include	<netdb.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	"client.h"

int			err_close(char *error, int sock)
{
  close(sock);
  return (myerror(error));
}

int			receive(int srvr)
{
  char			*str;
  int			ret;

  if ((str = malloc(sizeof(char) * 140)) == NULL)
    return (err_close(ERR_MALLOC, srvr));
  while (strncmp(str, "quit", strlen("quit")) != 0)
    {
      write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
      str = memset(str, '\0', sizeof(char) * MAX_READ + 1);
      ret = read(STDIN_FILENO, str, MAX_READ);
      str[ret] = '\0';
      write(srvr, str, strlen(str));
    }
  return (EXIT_SUCCESS);
}

int			client(char *ip, int port)
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			sock;
  
  if ((pe = getprotobyname("TCP")) == NULL)
    return (myerror(ERR_PROTO));
  if ((sock = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (err_close(ERR_SOCK, sock));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(ip);
  if ((connect(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
    return(err_close(ERR_CNCT, sock));
  if (receive(sock) != EXIT_SUCCESS)
    return (EXIT_FAILURE);
  close(sock);
  return (EXIT_SUCCESS);
}
