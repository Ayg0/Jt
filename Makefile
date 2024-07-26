NAME = test

# USE_COLORS = -DUSE_COLORS=1

SRC = test.c jmain.c

all: $(NAME)

$(NAME): $(SRC)
	gcc $(USE_COLORS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)
re: clean all