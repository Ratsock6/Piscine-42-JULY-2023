# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 15:57:10 by rvandepu          #+#    #+#              #
#    Updated: 2023/07/22 18:01:50 by aallou-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR := src
OBJ_DIR := bin

BIN := rush-02

SOURCES := main.c\
		   ft_parser.c\
		   ft_read_utils.c\
		   ft_parse_utils.c\
		   ft_utils.c\
		   ft_algo.c\

SRC := $(SOURCES:%=$(SRC_DIR)/%)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS += -Iinclude
CFLAGS   += -Wall -Wextra -Werror
LDFLAGS  +=
LDLIBS   +=

.PHONY: all clean fclean re

all: $(BIN)

clean:
	$(RM) -f $(OBJ)
	$(RM) -d $(OBJ_DIR)

fclean: clean
	$(RM) -f $(BIN)

re: fclean all

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@
