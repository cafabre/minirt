# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rshin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 16:02:20 by rshin             #+#    #+#              #
#    Updated: 2026/01/12 16:02:22 by rshin            ###   ########.fr        #
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

SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/utils.c 

SRC += $(SRC_DIR)/exec/render.c\
	   $(SRC_DIR)/exec/intersect.c \
	   $(SRC_DIR)/exec/exec_utils.c \
	   $(SRC_DIR)/exec/intersect_utils.c \
	   $(SRC_DIR)/exec/tracer.c \
	   $(SRC_DIR)/exec/shader.c \
	   $(SRC_DIR)/exec/controls.c 

SRC += $(SRC_DIR)/vec4/vec4_point.c \
	   $(SRC_DIR)/vec4/vec4_vector.c \
	   $(SRC_DIR)/vec4/vec4_color.c \
	   $(SRC_DIR)/vec4/vec4_add.c \
	   $(SRC_DIR)/vec4/vec4_sub.c \
	   $(SRC_DIR)/vec4/vec4_mul.c \
	   $(SRC_DIR)/vec4/vec4_cross_prod.c \
	   $(SRC_DIR)/vec4/vec4_dot_prod.c \
	   $(SRC_DIR)/vec4/vec4_scalar_prod.c \
	   $(SRC_DIR)/vec4/vec4_mat4_prod.c \
	   $(SRC_DIR)/vec4/vec4_scalar_div.c \
	   $(SRC_DIR)/vec4/vec4_len.c \
	   $(SRC_DIR)/vec4/vec4_neg.c \
	   $(SRC_DIR)/vec4/vec4_norm.c

SRC += $(SRC_DIR)/parsing/parsing.c \
		$(SRC_DIR)/parsing/parsing_utils.c \
		$(SRC_DIR)/parsing/dispatcher.c \
		$(SRC_DIR)/parsing/dispatch_obj.c \
		$(SRC_DIR)/parsing/dispatch_scene.c \
		$(SRC_DIR)/parsing/values_check.c \
		$(SRC_DIR)/parsing/coords_check.c \
		$(SRC_DIR)/parsing/misconfig.c \
		$(SRC_DIR)/parsing/misconfig_utils.c \
		$(SRC_DIR)/parsing/clean.c \
		$(SRC_DIR)/parsing/utils.c \
		$(SRC_DIR)/parsing/create_scene.c \
		$(SRC_DIR)/parsing/create_obj.c

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
