# **************************************************************************** #
#                                 LIBRARY NAME                                 #
# **************************************************************************** #
NAME = miniRT

# **************************************************************************** #
#                                 CONFIG & FLAGS                               #
# **************************************************************************** #
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
IFLAGS = $(INC) -MMD -MP
RM = rm -rf

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = ./minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a

INC = -Iinclude -I$(LIBFT_DIR)/headers -I$(MLX_DIR)

SRC_DIR     = src
OBJ_DIR     = .build

# **************************************************************************** #
#                                    SOURCES                                   #
# **************************************************************************** #
# Core files
CORE_FILES  = main.c \
              utils.c

# Execution files
EXEC_DIR    = exec/
EXEC_FILES  = render.c \
              intersect.c \
              exec_utils.c \
              intersect_utils.c \
              tracer.c \
              shader.c \
              controls.c

# Vector math files
VEC_DIR     = vec4/
VEC_FILES   = vec4_point.c \
              vec4_vector.c \
              vec4_color.c \
              vec4_add.c \
              vec4_sub.c \
              vec4_mul.c \
              vec4_cross_prod.c \
              vec4_dot_prod.c \
              vec4_scalar_mul.c \
              vec4_mat4_prod.c \
              vec4_scalar_div.c \
              vec4_len.c \
              vec4_neg.c \
              vec4_norm.c

# Parsing files
PARS_DIR    = parsing/
PARS_FILES  = parsing.c \
              parsing_utils.c \
              dispatcher.c \
              dispatch_obj.c \
              dispatch_scene.c \
              values_check.c \
              coords_check.c \
              misconfig.c \
              misconfig_utils.c \
              clean.c \
              utils.c \
              create_scene.c \
              create_obj.c

# **************************************************************************** #
#                                 COMPILATION                                  #
# **************************************************************************** #
SRC_FILES   = $(CORE_FILES) \
              $(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
              $(addprefix $(VEC_DIR), $(VEC_FILES)) \
              $(addprefix $(PARS_DIR), $(PARS_FILES))

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS        = $(OBJS:.o=.d)

# **************************************************************************** #
#                                    COLORS                                    #
# **************************************************************************** #
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

# **************************************************************************** #
#                                     RULES                                    #
# **************************************************************************** #
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lX11 -lXext -lm -lz -o $(NAME)
	@echo "$(GREEN)✨ $(NAME) compiled successfully!$(RESET)"

$(LIBFT):
	@echo "🛠️  Compiling Libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "📥 Cloning MinilibX..."; \
		git clone --depth 1 https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@echo "🛠️  Compiling MinilibX..."
	@$(MAKE) -C $(MLX_DIR) --no-print-directory > /dev/null 2>&1

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# **************************************************************************** #
#                                 CLEAN RULES                                  #
# **************************************************************************** #
clean:
	@echo "🧹 Cleaning objects..."
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory
	@if [ -d "$(MLX_DIR)" ]; then \
		$(MAKE) clean -C $(MLX_DIR) --no-print-directory; \
	fi
	@echo "$(RED)Objects and dependencies cleaned.$(RESET)"

fclean: clean
	@echo "🗑️  Full clean..."
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory
	@$(RM) -rf $(MLX_DIR)
	@echo "$(RED)Everything removed (including MLX source).$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re