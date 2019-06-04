#####################
# Project libraries #
#####################
LIBDIR   := libft\
            minilibx
LDLIBS   := -lft\
            -lmlx
MLXFLAGS := -framework OpenGL -framework AppKit

LDFLAGS := $(addprefix -L,$(LIBDIR)) $(LDLIBS) $(MLXFLAGS)

