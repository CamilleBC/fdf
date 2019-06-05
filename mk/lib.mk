#####################
# Project libraries #
#####################
LIBDIR   := -Llibft\
            -Lminilibx
LDLIBS   := -lft\
            -lm\
            -lmlx\
            -lX11\
            -lXext

LDFLAGS := $(LIBDIR) $(LDLIBS)

