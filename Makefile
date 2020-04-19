##
## Makefile for cpp_myftp in /home/chanut_g/rendu/PSU_2013_myftp
## 
## Made by Guillaume
## Login   <chanut_g@epitech.net>
## 
## Started on  Tue Mar 25 16:22:10 2014 Guillaume
## Last update Sun Apr 13 17:03:07 2014 Guillaume
##

RM	= rm -f

all:
	make -C clnt/
	make -C srvr/

clean:
	make clean -C clnt/
	make clean -C srvr/

fclean:
	make fclean -C clnt/
	make fclean -C srvr/

re:
	make re -C clnt/
	make re -C srvr/

test:	all clean
