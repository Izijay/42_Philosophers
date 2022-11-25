# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 13:39:28 by mdupuis           #+#    #+#              #
#    Updated: 2022/02/10 14:29:08 by mdupuis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	        =		philo

SRCS            =       srcs/atoi_philo.c\
						srcs/checks.c\
						srcs/display.c\
						srcs/philo.c\
						srcs/routine_utils.c\
						srcs/start_philo.c\
						srcs/time.c\
						srcs/utils.c\
						srcs/init.c

INCLUDES_DIR     =       includes/

CC              =       gcc

OBJS            =       ${SRCS:.c=.o}

RM          =       rm -rf

FLAGS       =       -Werror -Wextra -Wall -pthread

.c.o:
					@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o ${<:.c=.o}
					@echo "\x1b[32m[[ LOADED ]]\033[0m ${<:.s=.o}"

all:			${NAME}

${NAME}:		${OBJS}

						@${CC} ${FLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS}
						@echo "philo has been created"

clean:
						@${RM} ${OBJS}
						@echo "\n *.o files deleted\n"

fclean:		clean
						@${RM} ${NAME}
						@echo "\nProgram philo have been deleted\n"

re:		fclean all

.PHONY:           all     clean   fclean  re
