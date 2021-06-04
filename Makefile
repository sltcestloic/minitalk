# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:40:32 by lbertran          #+#    #+#              #
#    Updated: 2021/06/04 12:27:46 by lbertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

all:
	@${MAKE} -C ./libft	
	@${MAKE} -C ./srcs/common
	@${MAKE} -C ./srcs/client
	@${MAKE} -C ./srcs/server
	@cp srcs/client/client ./client
	@cp srcs/server/server ./server

clean:
	@${MAKE} clean -C ./libft
	@${MAKE} clean -C ./srcs/common
	@${MAKE} clean -C ./srcs/client
	@${MAKE} clean -C ./srcs/server

fclean: clean
	@${MAKE} fclean -C ./libft
	@${MAKE} fclean -C ./srcs/common
	@${MAKE} fclean -C ./srcs/client
	@${MAKE} fclean -C ./srcs/server
	@rm client
	@rm server

re: fclean all
	
.PHONY: all clean fclean re .c.o
