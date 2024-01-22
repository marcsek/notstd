CC = gcc
CFLAGS = -g -Wall

SRC=src
OBJ=obj
MAIN=obj/main.o
EXE=app

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

all: $(OBJ) $(MAIN) $(EXE)

run: all
	@./$(OBJ)/app

test: $(TEST)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

$(EXE): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) -o $(OBJ)/$@

$(OBJS): $(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN): $(OBJ)/%.o: ./%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/bin/%: $(TEST)/%.c
	$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lcriterion

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

clean:
	rm $(OBJ)/* 
	rm -rf $(TEST)/bin
