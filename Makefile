# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 14:07:52 by yachebla          #+#    #+#              #
#    Updated: 2023/05/30 17:59:45 by yachebla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server

CLIENT_NAME = client

SERVER_NAME_BONUS = server_bonus

CLIENT_NAME_BONUS = client_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = minitalk_utilise.c

HEADER = minitalk.h

OBJECTS = $(FILES:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : server.c $(HEADER)
	 		$(CC) $(CFLAGS) server.c $(FILES) -o server

$(CLIENT_NAME) : client.c $(HEADER)
			$(CC) $(CFLAGS) client.c $(FILES) -o client
			
bonus: $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

$(SERVER_NAME_BONUS) : server_bonus.c $(HEADER)
	 		$(CC) $(CFLAGS) server_bonus.c $(FILES) -o server_bonus

$(CLIENT_NAME_BONUS) : client_bonus.c $(HEADER)
			$(CC) $(CFLAGS) client_bonus.c $(FILES) -o client_bonus

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean all