# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 18:29:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/11/11 16:29:30 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
BUILD	= \e[38;5;225m
SEP		= \e[38;5;120m
DUCK	= \e[38;5;227m
RESET	= \033[0m

# COLORS


SRCS_DIR		= .
SRCS_FILES		= main.cpp \

SRCS			= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

O_DIR			= ./objs/

OBJS_FILES		:= ${SRCS_FILES:.cpp=.o}

OBJS			:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}

NAME			= ft_containers

CXX				= c++
AR				= ar rcs
MKDIR			= mkdir
RM				= rm -rf

CXXFLAGS		= -Wall -Wextra -Werror -Wshadow -std=c++98 -pedantic

TSEP			= ${SEP}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=${RESET}


all:			${NAME}

${NAME}:		${O_DIR} ${OBJS}
				@printf "\n"
				@printf "${TSEP}\n"
				@printf "\n${GREEN} 💻 Successfully compiled ${NAME} .o's${RESET} ✅\n"
				@${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}
				@printf "${GREEN} 💻 Successfully created ${NAME} executable${RESET} ✅\n"
				@printf "\n${TSEP}\n"

${O_DIR}:
				@${MKDIR} ${O_DIR}
				@printf "${BUILD}${O_DIR} Directory Created 📎${RESET}\n\n"

${O_DIR}%.o:%.cpp Makefile
				@${CXX} ${CXXFLAGS} -o $@ -c $<
				@printf "\e[1K\r${BUILD} 🚧 $@ from $<${RESET}"

clean :
				@${RM} ${O_DIR}
				@printf "\n${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n\n"

fclean : 		clean
				@${RM} ${NAME} ${NAME}.dSYM
				@printf "${RED} 💥 Deleted ${NAME} files${RESET} ❌\n\n"

re : 			fclean all

.PHONY : all clean fclean re
