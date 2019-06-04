########################
# Project source files #
########################
SRC := error.c\
       events.c\
       fdf.c\
       free.c\
       init.c
# display module
SRC += draw.c\
       projection.c\
       window.c
# parser module
SRC += parser.c\
       parser_checker.c
# virtual path used to find the sources when building objects
VPATH += $(SRC_ROOT)
VPATH += $(foreach module, $(MODULES), $(addprefix $(SRC_ROOT)/, $(module)))
