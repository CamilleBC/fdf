#####################
# Project libraries #
#####################
LIBDIR   := libft\
            minilibx
LDLIBS   := -lft\
            -lm\
            -lmlx\
            -lX11\
            -lXext

LDFLAGS := $(addprefix -L,$(LIBDIR)) $(LDLIBS)

