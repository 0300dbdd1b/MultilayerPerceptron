CC=				g++

CFLAGS=			-Wall -Wextra -Werror

BUFFER_SIZE=	16

NAME=			MultilayerPerceptron

INCLUDES:=		-I ./includes/ 

FILES=			./srcs/main.c\

OBJS=			$(FILES:.c=.o)

LIB=			

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -D BUFFER_SIZE=$(BUFFER_SIZE) -o $@ $<

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean:
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
re: fclean $(NAME)

