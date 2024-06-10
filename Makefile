CC=				g++

CFLAGS=		-std=c++11

NAME=			MultilayerPerceptron

INCLUDES:=		-I ./includes/ 

FILES=			./srcs/main.cpp						\

OBJS=			$(FILES:.cpp=.o)

LIB=			

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIB)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(OBJS)

re: fclean $(NAME) clean

