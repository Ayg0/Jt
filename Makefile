NAME = testExamples
LIB_NAME = jtest.a

USE_COLORS = -DUSE_COLORS=1

SRC = testExamples.c jmain.c

all: $(NAME)

$(NAME): $(SRC)
	gcc $(USE_COLORS) $(SRC) -o $(NAME)

lib:
	gcc -fPIC $(USE_COLORS) -c jmain.c -o jmain.o
	ar rcs $(LIB_NAME) jmain.o

clean:
	rm -rf $(NAME) $(LIB_NAME) jmain.o
re: clean all