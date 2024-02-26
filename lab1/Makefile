CC=gcc
CFLAGS=-g -std=c11 -W -Wall -Wextra
SRC=src
BUILD=build
DIST=bin

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

all: my_dirwalk

my_dirwalk: $(OBJS)
	@mkdir -p $(DIST)
	$(CC) $(CFLAGS) -o $(DIST)/my_dirwalk $^

clean:
	rm -rf $(BUILD) $(DIST)
