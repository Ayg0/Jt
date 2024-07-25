NAME = test

SRC = test.c

all: $(NAME)

$(NAME): $(SRC)
	gcc $(SRC) -o $(NAME)

clean:
	rm $(NAME)