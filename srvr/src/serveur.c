/*
** serveur.c for myftp in /home/chanut_g/rendu/PSU_2013_myftp/serveur/src
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon Apr  7 18:14:36 2014 Guillaume
** Last update Sun Apr 13 17:26:02 2014 Guillaume
*/

#include	"serveur.h"

int			err_close(char *error, int sock)
{
  close(sock);
  return (myerror(error));
}

int			receive(int client)
{
  char			*str;
  int			ret;
  
  if ((str = malloc(sizeof(char) * (MAX_BUFF + 1))) == NULL)
    return (myerror(ERR_MALLOC));
  while (1)
    {
      str = memset(str, 0, sizeof(char) * (MAX_BUFF));
      ret = read(client, str, MAX_BUFF);
      str[ret] = '\0';
      /* entré dans le tableau de pt/fonctions et appel de la correspondante */
      write(STDOUT_FILENO, str, strlen(str));
    }
  return (EXIT_SUCCESS);
}

int			serveur(int port, char __attribute__((unused))*path)
{
  t_serveur		srv;
  int			client;
  int			client_size;
  struct sockaddr_in	sin_client;

  if ((srv.pe = getprotobyname("TCP")) == NULL)
    return (myerror(ERR_PROTO));
  if ((srv.sock = socket(AF_INET, SOCK_STREAM, srv.pe->p_proto)) == -1)
    return (err_close(ERR_SOCK, srv.sock));
  srv.sin.sin_family = AF_INET;
  srv.sin.sin_port = htons(port);
  srv.sin.sin_addr.s_addr = INADDR_ANY;
  if ((bind(srv.sock, (const struct sockaddr *)&srv.sin, sizeof(srv.sin))) == -1)
    return (err_close(ERR_BIND, srv.sock));
  if ((listen(srv.sock, MAX_CLIENT)) == -1)
    return (err_close(ERR_LISTEN, srv.sock));
  client_size = sizeof(sin_client);
  if ((client = accept(
       srv.sock, (struct sockaddr *)&sin_client, (socklen_t *)&client_size)) == -1)
    return (err_close(ERR_ACCEPT, srv.sock));
  srv.ip_addr = inet_ntoa(sin_client.sin_addr);
  printf("%s %i - %s\n", CONNECT, client, srv.ip_addr);
  if (receive(client) != EXIT_SUCCESS)
    {
      close(srv.sock);
      return (EXIT_FAILURE);
    }
  close(srv.sock);
  return (EXIT_SUCCESS);
}
