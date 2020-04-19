##
## Makefile for myftp in /home/chanut_g/rendu/PSU_2013_myftp/serveur
## 
## Made by Guillaume
## Login   <chanut_g@epitech.net>
## 
## Started on  Mon Apr  7 18:06:39 2014 Guillaume
## Last update Thu Apr 10 16:28:51 2014 Guillaume
##

NAME	= serveur

SRCS	= \
	src/main.c	\
	src/serveur.c	\

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Werror -Wextra -Iinclude

CC	= gcc -o

RM	= rm -f

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) $(NAME) $(OBJS)
	cp $(NAME) ..

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all
