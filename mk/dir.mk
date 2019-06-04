#######################
# Project directories #
#######################
MODULES   := parser display utils
BUILD_DIR := build
INC_ROOT  := inc
SRC_ROOT  := src

# BUILD_DIRS := $(foreach module, $(MODULES), $(addprefix $(BUILD_ROOT)/, $(module)))
INC_DIR += $(INC_ROOT)\
           ./libft/includes\
           ./minilibx\
           /usr/include
INC_DIR += $(foreach module, $(MODULES), $(addprefix $(INC_ROOT)/, $(module)))
