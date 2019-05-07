# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 12:29:40 by cbaillat          #+#    #+#              #
#    Updated: 2019/05/07 11:08:33 by cbaillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################
# EDITABLE VARIABLES #
######################
EXEC	=	fdf

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror $(IFLAGS)
DBGFLAGS	=	-Wall -Wextra -DDEBUG -g $(IFLAGS) 

SRCDIR		=	srcs
SRCFILES	=	fdf.c \
				error.c \
				draw.c \
				events.c \
				parser.c

OBJDIR		=	objs
OBJFILES	:= 	$(SRCFILES:%.c=$(OBJDIR)/%.o)

IDIR	=	includes \
			libft/includes \
			minilibx
IFLAGS	=	$(addprefix -I,$(IDIR))

DEPDIR		=	deps
DEPFILES	:= 	$(SRCFILES:%.c=$(DEPDIR)/%.d)
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

LIBDIR			=	libft \
					minilibx
LIBDIRFLAGS		=	$(addprefix -L,$(LIBDIR))
LIBFILES		=	ft \
					mlx

MLXFLAGS	=	-framework OpenGL -framework AppKit

LIBFILESFLAGS	=	$(addprefix -l,$(LIBFILES))
LDFLAGS = $(LIBDIRFLAGS) $(LIBFILESFLAGS)

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

.PHONY: all clean fclean re

all		: $(EXEC)

$(EXEC)	: $(OBJFILES)
	@make -C ./libft/
	@make -C ./minilibx/
	@echo "Compiling ${GREEN}$@${NC} executable..."
	@${CC} $(MLXFLAGS) $(LDFLAGS) -o $@ $^

$(OBJFILES)	: $(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPDIR)/%.d
	@echo "Compiling ${BLUE}$(@F)${NC}..."
	@mkdir -p $(OBJDIR) ${DEPDIR}
	@$(CC) -o $@ -c $< $(CFLAGS) $(DEPFLAGS)

$(DEPDIR)/%.d: ;
# Make dep directory precious so that .d files don't get destroy in intermediate builds
.PRECIOUS: $(DEPDIR)/%.d

debug	:	CFLAGS = $(DBGFLAGS)
debug	:	$(EXEC)

clean	:
	@make clean -C ./libft/
	@make clean -C ./minilibx/
	@echo "Cleaning ${RED}build artifacts${NC}..."
	@rm -rf $(OBJDIR) $(DEPDIR)

fclean	: clean
	@make fclean -C ./libft/
	@echo "Cleaning ${RED}executable${NC}..."
	@rm -rf $(EXEC)

re		: fclean all

-include $(DEPFILES)

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