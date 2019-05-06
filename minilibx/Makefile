#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "[Building ${YELLOW}minilibx${NC}]"
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@echo "[Cleaning ${YELLOW}minilibx${NC}]"
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all

#################
# Customization #
#################
# echo output colours
RED	= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m
NC	= \033[0m