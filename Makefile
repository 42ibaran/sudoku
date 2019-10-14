# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 13:28:55 by ibaran            #+#    #+#              #
#    Updated: 2019/10/14 12:57:04 by ibaran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	sudoku

VPATH				:=	./sources/ ./objects/ ./includes/

SRC_NAME			:=	main.c			\
						utils.c			\
						parse.c			\
						solve.c

OBJ_NAME			:=	$(SRC_NAME:.c=.o)

HEAD_NAME			:=	sudoku.h
LIB_NAME			:=	libft.a

SRC_PATH			:=	./srcs
HEAD_PATH			:=	./includes
LIB_PATH			:=	./libft
OBJ_PATH			:=	./objs

CFLAGS				:=	-Wall -Wextra -Werror -O3

SRC					:=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ					:=	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
HEAD				:=	$(addprefix $(HEAD_PATH)/, $(HEAD_NAME))

LIBFT				:=	$(LIB_PATH)/$(LIB_NAME)

CC					:=	gcc
CPPFLAGS			:=	-I $(HEAD_PATH)								\
						-I $(LIB_PATH)/includes						

LIBS				:=	-L$(LIB_PATH) -lft

RED					:=	\033[0;31m
GREEN				:=	\033[0;32m
YELLOW				:=	\033[1;33m
DEFAULT				:=	\033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEAD)
	@$(CC) $(CFLAGS) $(LIBS) $(CPPFLAGS) $(OBJ) -o $@
	@echo "$(GREEN)[$@ Compiled]$(DEFAULT)"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HEAD)
	@echo [CC] $<
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIB_PATH)

norm:
	@norminette **/*.[ch]

clean:
	@$(MAKE) -C $(LIB_PATH) $@
	@rm -f $(OBJ)
	@echo "$(YELLOW)[Sudoku Objects Removed]$(DEFAULT)"

fclean: clean
	@$(MAKE) -C $(LIB_PATH) $@
	@rm -f $(ASM) $(VM)
	@echo "$(RED)[Sudoku exe Removed]$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re norm
