NAME = test

SRC = test.c jmain.c

all: $(NAME)

$(NAME): $(SRC)
	gcc $(SRC) -o $(NAME)

clean:
	rm $(NAME)