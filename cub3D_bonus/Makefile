#≻───░⋆ ✪ DEFAULTS ✪ ⋆░──────────────────────────────────────────────────────≺#
NAME				=	cub3D
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
#≻───░file's paths
SRCS				=	$(addprefix $(SRC_DIR)/,				\
							main.c)
SRCS				+=	$(addprefix $(SRC_DIR)/controls/,		\
							door.c								\
							mouse.c								\
							time.c								\
							movements.c)
SRCS 				+=	$(addprefix $(SRC_DIR)/import/,			\
							errors.c							\
							get_elements.c						\
							get_map.c							\
							import.c							\
							map_validations.c					\
							validations.c)
SRCS				+=	$(addprefix $(SRC_DIR)/minimap/,		\
							map_drawing.c						\
							minimap.c)
SRCS				+=	$(addprefix $(SRC_DIR)/raycasting/,		\
							raycasting.c						\
							textures.c)
SRCS				+=	$(addprefix $(SRC_DIR)/render/,			\
							init_destroy.c						\
							render.c)
SRCS				+=	$(addprefix $(SRC_DIR)/utils/,			\
							colors.c							\
							rotate.c							\
							texture_fill.c)
OBJS	 			=	$(SRCS:%.c=%.o)
BUILDS				=	$(addprefix $(BUILD_DIR)/, $(OBJS))

#≻───░⋆ ✪ LIBFT EXTRA ✪ ⋆░───────────────────────────────────────────────────≺#
LIBFT_LIB_NAME		=	libft.a
LIBFT_DIR			=	libft
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/include
LIBFT_LIB			=	$(LIBFT_DIR)/$(LIBFT_LIB_NAME)
LIBFT_LIBS			=	-lft
LIBFT_CC			=	-I./$(LIBFT_INCLUDE_DIR)	\
						-L./$(LIBFT_DIR)			\
						$(LIBFT_LIBS)

#≻───░⋆ ✪ MLX42 ✪ ⋆░─────────────────────────────────────────────────────────≺#
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

#≻───░⋆ ✪ FUNCTIONS ✪ ⋆░─────────────────────────────────────────────────────≺#

define compile
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<				\
	  -I./$(INCLUDE_DIR)		\
	  -I./$(MLX42_INCLUDE_DIR)	\
	  -I./$(LIBFT_INCLUDE_DIR)	\
	  -o $@						\
	  $(CC_FLAGS)
endef

define create_objects_dir
	@ mkdir -p $(dir $@)
endef

#≻───░⋆ ✪ RULES ✪ ⋆░─────────────────────────────────────────────────────────≺#
.PHONY: all clean fclean clear re

all: $(NAME)

$(NAME): $(MLX42_LIB) $(LIBFT_LIB) $(BUILDS) $(INCLUDES)
	@ $(CC) -o $(NAME)	\
	  $(BUILDS)			\
	  -I./$(INCLUDE_DIR)\
	  $(MLX42_CC)		\
	  $(LIBFT_CC)		\
	  $(CC_FLAGS)
	@ printf "$(GREEN)$@$(DEFAULT) successfully generated\n"

$(BUILD_DIR)/%.o: %.c
	$(call create_objects_dir)
	$(call compile)

clean_cub3d:
	@ rm -rf $(BUILD_DIR)

clean: clean_MLX clean_cub3d

fclean: fclean_MLX fclean_libft fclean_cub3d

re: fclean all

$(LIBFT_LIB): $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR)

$(MLX42_LIB): $(MLX42_DIR)
	@ cd $(MLX42_DIR) &&												\
	  cmake -B build &&													\
	  cmake --build build -j4

clean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) clean

clean_MLX: $(MLX42_DIR)
	@ if [ -d $(MLX42_BUILD_DIR) ]; then				\
		find $(MLX42_BUILD_DIR) -mindepth 1 !			\
		-name '$(MLX42_LIB_NAME)' -exec rm -rf {} +;	\
	  fi

fclean_cub3d: clean_cub3d
	@ rm -rf $(NAME)

fclean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) fclean

fclean_MLX: $(MLX42_DIR)
	@ rm -rf $(MLX42_BUILD_DIR)

clear_MLX:
	@ rm -rf $(MLX42_DIR)

clear_libft:
	@ rm -rf $(LIBFT_DIR)

clear: clear_MLX clear_libft fclean
