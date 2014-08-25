##
## Makefile for Makefile in /home/Epitech
##
## Made by moriss_h
## Login   <moriss_h@epitech.net>
##
## Started on  Sun Jun  9 03:35:24 2013 Hugues
## Last update Fri Jul 11 23:36:09 2014 Jean Gravier
##

UNAME_S 	:= 	$(shell uname -s)

SRC         =	main.cpp \
                Engine.cpp \
                ATransformation.cpp \
                Geometry.cpp \
                Cube.cpp \
                Shader.cpp \
                Texture.cpp \
                Clock.cpp \
                Camera.cpp

ifeq ($(UNAME_S), Darwin)
    CC          =   clang++
else
    CC          =	g++
endif

FILETYPE	=	.cpp

RM          =	rm -f

NAME		=	randomgl

OBJDIR		=	obj/
SRCDIR		=	src/
INCDIR		=	include/
LIBDIR      =   libs/

CFLAGS		+=	-I$(INCDIR)
CFLAGS		+=	-Wall -Wextra -Winit-self
CFLAGS		+=	-g3

ifneq ($(UNAME_S), Darwin)
	LDFLAGS	+=	-Wl,-O1
    LDFLAGS += -lSDL2
else
    LDFLAGS +=  -F/Library/Frameworks -framework SDL2 -framework SDL2_Image -framework OpenGL
    CFLAGS +=  -F/Library/Frameworks -framework SDL2 -framework SDL2_Image -framework OpenGL
endif

OBJ         =	$(patsubst %${FILETYPE},${OBJDIR}%.o, $(SRC))
DEPS		=	$(patsubst %${FILETYPE}, ${OBJDIR}%.d, $(SRC))

PRINTFLAGS	=	0

dummy		:=	$(shell test -d $(OBJDIR) || mkdir -p $(OBJDIR))
dummy		:=	$(shell test -d $(SRCDIR) || mkdir -p $(SRCDIR))
dummy		:=	$(shell test -d $(INCDIR) || mkdir -p $(INCDIR))

$(OBJDIR)%.o:		$(patsubst %${FILETYPE}, ${SRCDIR}%${FILETYPE}, %${FILETYPE})
			@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
ifneq ("$(shell tty)", "not a tty")
			@if [ $(PRINTFLAGS) = "0" ]; then \
			echo -e "Compile flags { $(CFLAGS) }" | sed 's/^-e //' \
			| sed 's/[-a-zA-Z]\+/\x1B[31m&\x1B[0m/g' \
			| sed 's/[A-Z]\+/\x1B[32m&\x1B[0m/g' \
			| sed 's/[{}]/\x1B[34m&\x1B[0m/g'; fi
			$(eval PRINTFLAGS = 1)
			@echo -e "Compiling $< $(patsubst %.o, %.d, $@)" | sed 's/^-e //' \
			| sed 's/[-a-zA-Z]\+/\x1B[31m&\x1B[0m/g' \
			| sed 's/[A-Z]\+/\x1B[32m&\x1B[0m/g' | sed 's/d/\x1B[35m&\x1B[0m/'
			@$(CC) $(CFLAGS) -c $< -o $@
			@$(CC) $(CFLAGS) -MM -MF $(patsubst %.o, %.d, $@) -MT $@ -MT $(patsubst %.o, %.d, $@) -c $<
else
			$(CC) $(CFLAGS) -c $< -o $@
			$(CC) $(CFLAGS) -MM -MF $(patsubst %.o, %.d, $@) -MT $@ -MT $(patsubst %.o, %.d, $@) -c $<
endif

$(NAME):	$(OBJ)
ifneq ("$(shell tty)", "not a tty")
		@echo -e "Linking $@ { $(LDFLAGS) }" | sed 's/^-e //' \
		| sed 's/[-a-zA-Z]\+/\x1B[34m&\x1B[0m/g'
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
#		@cp -f $(NAME) ../$(NAME)
else
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
#		@cp -f $(NAME) ../$(NAME)
endif

-include $(DEPS)

all:	$(NAME)

clean:
ifneq ("$(shell tty)", "not a tty")
	@echo -e "Removing object !" | sed 's/^-e //' \
	| sed 's/[-a-zA-Z]\+/\x1B[35m&\x1B[0m/g'
	@$(RM) $(OBJ) $(DEPS)
else
	$(RM) $(OBJ) $(DEPS)
endif

fclean:	clean
ifneq ("$(shell tty)", "not a tty")
	@echo -e "Removing ${NAME} !" | sed 's/^-e //' \
	| sed 's/[-a-zA-Z]\+/\x1B[36m&\x1B[0m/g'
	@$(RM) $(NAME)
else
	$(RM) $(NAME)
endif

re:	fclean all

help:
	@echo -e "\033[37mTarget available: all, ${NAME}, clean, fclean\033[00m" | sed 's/^-e //'

.PHONY:	all clean fclean re help

