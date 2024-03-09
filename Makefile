#≻───░⋆ ✪ DEFAULTS ✪ ⋆░──────────────────────────────────────────────────────≺#
NAME				=	cub3d
CC					=	cc
CC_FLAGS			=	-Wall		\
						-Wextra		\
						-Werror		\
						-pedantic	\
						-g3

#≻───░⋆ ✪ PROJECT DIRECTORIES & FILES ✪ ⋆░───────────────────────────────────≺#
SRC_DIR				=	src
INCLUDE_DIR			=	include
INCLUDE_FILES		=	cub3d.h		\
						import.h
INCLUDES			=	$(addprefix $(INCLUDE_DIR)/, $(INCLUDE_FILES))
BUILD_DIR			=	build
IMPORT_FILES		=	error_msg.c		\
						get_elements.c	\
						import.c		\
						validation.c
SRC_FILES			=	main.c
SRCS				=	$(addprefix $(SRC_DIR)/, SRC_FILES) 					\
						$(addprefix $(SRC_DIR)/import/, IMPORT_FILES)
OBJS				=	$(SRC_FILES:.c=.o)
BUILDS				=	$(addprefix $(BUILD_DIR)/, $(OBJS))

#≻───░⋆ ✪ LIBFT EXTRA ✪ ⋆░───────────────────────────────────────────────────≺#
LIBFT_REPO			=	https://github.com/brmoretti/42_libft_extra.git
LIBFT_LIB_NAME		=	libft.a
LIBFT_DIR			=	libft
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/include
LIBFT_LIB			=	$(LIBFT_DIR)/$(LIBFT_LIB_NAME)
LIBFT_LIBS			=	-lft
LIBFT_CC			=	-I./$(LIBFT_INCLUDE_DIR)	\
						-L./$(LIBFT_DIR)			\
						$(LIBFT_LIBS)

#≻───░⋆ ✪ MLX42 ✪ ⋆░─────────────────────────────────────────────────────────≺#
MLX42_REPO			=	https://github.com/codam-coding-college/MLX42.git
MLX42_LIB_NAME		=	libmlx42.a
MLX42_DIR			=	MLX42
MLX42_INCLUDE_DIR	=	$(MLX42_DIR)/include/MLX42
MLX42_BUILD_DIR		=	$(MLX42_DIR)/build
MLX42_LIB			=	$(MLX42_BUILD_DIR)/$(MLX42_LIB_NAME)
MLX42_LIBS			=	-lmlx42		\
						-ldl		\
						-lglfw		\
						-pthread	\
						-lm
MLX42_CC			=	-I./$(MLX42_INCLUDE_DIR)	\
						-L./$(MLX42_BUILD_DIR)		\
						$(MLX42_LIBS)

#≻───░⋆ ✪ COLORS ✪ ⋆░────────────────────────────────────────────────────────≺#
BLUE				=	\033[0;34m
MAGENTA				=	\033[0;35m
GREEN				=	\033[0;32m
DEFAULT 			=	\033[0:0m

#≻───░⋆ ✪ RULES ✪ ⋆░─────────────────────────────────────────────────────────≺#
.PHONY: all bonus clean fclean clear re

all: $(NAME)

bonus: $(NAME)

debug: clean_cub3d
debug: CC_FLAGS += -DDEBUG
debug: NAME = cub3d_debug
debug: all

$(NAME): $(MLX42_LIB) $(LIBFT_LIB) $(BUILD_DIR) $(BUILDS) $(INCLUDES)
	@ $(CC) -o $(NAME)	\
	  $(BUILDS)			\
	  -I./$(INCLUDE_DIR)\
	  $(MLX42_CC)		\
	  $(LIBFT_CC)		\
	  $(CC_FLAGS)
	@ printf "$(GREEN)$@$(DEFAULT) successfully generated\n"

$(BUILD_DIR):
	@ mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<				\
	  -I./$(INCLUDE_DIR)		\
	  -I./$(MLX42_INCLUDE_DIR)	\
	  -I./$(LIBFT_INCLUDE_DIR)	\
	  -o $@						\
	  $(CC_FLAGS)

clean_cub3d:
	@ rm -rf $(BUILD_DIR)

clean: clean_MLX clean_libft clean_cub3d

fclean: fclean_MLX fclean_libft clean
	@ rm -rf $(NAME)

re: fclean all

$(LIBFT_LIB): $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR)

$(MLX42_LIB): $(MLX42_DIR)
	@ cd $(MLX42_DIR) &&												\
	  sed -i 's/cmake_minimum_required (VERSION 3.18.0)/				\
	  	cmake_minimum_required (VERSION 3.16.0)/g' CMakeLists.txt && 	\
	  cmake -B build &&													\
	  cmake --build build -j4

$(LIBFT_DIR):
	@ git clone $(LIBFT_REPO) $(LIBFT_DIR)

$(MLX42_DIR):
	@ git clone $(MLX42_REPO) $(MLX42_DIR)

clean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) clean

clean_MLX: $(MLX42_DIR)
	@ if [ -d $(MLX42_BUILD_DIR) ]; then				\
		find $(MLX42_BUILD_DIR) -mindepth 1 !			\
		-name '$(MLX42_LIB_NAME)' -exec rm -rf {} +;	\
	  fi

fclean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) fclean

fclean_MLX: $(MLX42_DIR)
	@ rm -rf $(MLX42_BUILD_DIR)

clear_MLX:
	@ rm -rf $(MLX42_DIR)

clear_libft:
	@ rm -rf $(LIBFT_DIR)

clear: clear_MLX clear_libft
	@ rm -rf fractol
