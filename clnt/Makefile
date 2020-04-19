##
## Makefile for myftp in /home/chanut_g/rendu/PSU_2013_myftp/client
## 
## Made by Guillaume
## Login   <chanut_g@epitech.net>
## 
## Started on  Wed Apr  9 16:07:28 2014 Guillaume
## Last update Thu Apr 10 16:28:02 2014 Guillaume
##

NAME	= client

SRCS	= \
	src/main.c	\
	src/client.c	\

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
