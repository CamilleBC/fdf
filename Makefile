# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 12:29:40 by cbaillat          #+#    #+#              #
#    Updated: 2019/06/04 15:47:03 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


######################
# EDITABLE VARIABLES #
######################
EXEC = fdf

# sources, directories, libraries,... should be edited in the corresponding .mk
include mk/colours.mk\
        mk/dir.mk\
        mk/lib.mk\
        mk/src.mk

# TOOLS
CC    := gcc
ECHO  := @echo
MKDIR := @mkdir -p
MAKE  := @make
RM    := @rm -f

# FLAGS
CFLAGS   := -Wall -Wextra -Werror #-std=c89
DBGFLAGS := -g -DDEBUG
IFLAGS = $(foreach idir, $(INC_DIR), $(addprefix -I, $(idir)))


OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

DEP      := $(SRC:%.c=$(BUILD_DIR)/%.d)
DEPFLAGS = -MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d

###############
# DO NOT EDIT #
###############

# Automatic variables: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
# Implicit rule: https://www.gnu.org/software/make/manual/html_node/Implicit-Rules.html#Implicit-Rules
#
# In this rule [all: library.cpp main.cpp]
# 	$@ evaluates to all
#	$< evaluates to library.cpp
#	$^ evaluates to library.cpp main.cpp
#   $* The stem with which an implicit rule matches
#		If the target is dir/a.foo.b and the target pattern is a.%.b
#		then the stem is dir/foo.
# 		In a static pattern rule, the stem is part of the file name
#		that matched the ‘%’ in the target pattern.

.PHONY: all clean fclean re mkdirs debug

all: mkdirs $(EXEC)

debug: CFLAGS += $(DBGFLAGS)
debug: all

$(EXEC): $(OBJ)
	$(MAKE) -C ./libft/
	$(MAKE) -C ./minilibx/
	$(ECHO) "Compiling ${GREEN}$@${NC} executable..."
	$(ECHO) $(INC_DIR)
	@$(CC) $(MLXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ): $(BUILD_DIR)/%.o: %.c $(BUILD_DIR)/%.d
	$(ECHO) "Compiling ${BLUE}$(@F)${NC}..."
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $< $(DEPFLAGS)

$(BUILD_DIR)/%.d: ;
# Make dep directory precious so that .d files don't get destroy in intermediate builds
.PRECIOUS: $(BUILD_DIR)/%.d

clean:
	$(MAKE) clean -C ./libft/
	$(MAKE) clean -C ./minilibx/
	$(ECHO) "Cleaning ${RED}build artifacts${NC}..."
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft/
	$(ECHO) "Cleaning ${RED}executable${NC}..."
	$(RM) $(EXEC)

re: fclean all

mkdirs:
	$(MKDIR) $(BUILD_DIR)

-include $(DEPFILES)

