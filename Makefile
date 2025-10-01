# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syukna <syukna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 17:37:30 by rshin             #+#    #+#              #
#    Updated: 2025/10/01 15:34:26 by syukna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

# === CONFIG ===

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

IFLAGS = -I $(INC) -I $(LIBMLX) -I $(LIBFT)/$(INC) -MMD -MP

RM = rm -rf

# === PATHING ===

SRC_DIR = src

BLD_DIR = .build

SRC = 	$(SRC_DIR)/main.c\
		$(SRC_DIR)/parse_scene.c\
		$(SRC_DIR)/parse_coor.c\
		$(SRC_DIR)/parse_color.c\
		$(SRC_DIR)/parse_utils.c\
		$(SRC_DIR)/print.c

INC = include

LIBMLX = minilibx-linux

LIBFT = libft

LIB_A = $(LIBMLX)/libmlx.a \
		$(LIBFT)/libft.a

OBJ = $(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(SRC))

DEP = $(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.d, $(SRC))

# === TARGET RULES ===

all: $(NAME)

$(NAME): $(OBJ) $(LIB_A)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LIB_A) -lX11 -lXext -lm -lz -o $(NAME)

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIB_A): FORCE
	make -C $(LIBFT)
	make -C $(LIBMLX)

clean:
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean
	$(RM) $(OBJ)

re: fclean all

fclean: clean
	$(RM) $(LIBFT)/$(BLD_DIR) $(LIB_A)
	$(RM) $(BLD_DIR) $(NAME)

FORCE:

-include $(DEP)

.PHONY: all clean fclean re FORCE
