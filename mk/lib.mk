#####################
# Project libraries #
#####################
LIBDIR   := libft\
            minilibx
LDLIBS   := -lft\
            -lm\
            -lmlx
MLXFLAGS := -framework OpenGL -framework AppKit

LDFLAGS := $(addprefix -L,$(LIBDIR)) $(MLXFLAGS) $(LDLIBS)

