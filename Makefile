CC=				g++

CFLAGS=		-std=c++11

NAME=			MultilayerPerceptron

INCLUDES:=		-I ./includes/ 

FILES=			./srcs/main.cpp						\

OBJS=			$(FILES:.cpp=.o)

LIB=			

ELU_ALPHA=		0.001
TRELU_TRESHOLD=	2
LRELU_ALPHA=	1.00

CFLAGS+= -DELU_ALPHA=$(ELU_ALPHA) -DTRELU_TRESHOLD=$(TRELU_TRESHOLD) -DLRELU_ALPHA=$(LRELU_ALPHA)

all: $(NAME)


$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIB)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME) clean


