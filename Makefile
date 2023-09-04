# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 19:07:38 by msoriano          #+#    #+#              #
#    Updated: 2023/09/04 19:13:27 by msoriano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = cc -Wall -Werror -Wextra

SERVER = server
CLIENT = client

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)
$(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		${CCFLAGS} ${OBJS_SERVER} -o ${SERVER}
		${CCFLAGS} ${OBJS_CLIENT} -o ${CLIENT}

clean:
		$(MAKE) clean
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT}
fclean:	clean
		$(MAKE) fclean
		rm -rf $(SERVER) $(CLIENT)
re:	fclean all
