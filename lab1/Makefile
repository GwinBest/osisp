CC=gcc
CFLAGS=-std=c11 -pedantic -W -Wall -Wextra -Werror
SRC=src
BUILD=build
DEBUG=$(BUILD)/debug
RELEASE=$(BUILD)/release
DIST=$(DEBUG)

ifeq ($(MODE), release)
	CFLAGS = -std=c11 -pedantic -W -Wall -Wextra -Werror
	DIST = $(RELEASE)
endif

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(DIST)/%.o, $(SRCS))

$(DIST)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

all: my_dirwalk

my_dirwalk: $(OBJS)
	$(CC) $(CFLAGS) -o $(DIST)/my_dirwalk $^

clean:
	rm -rf $(BUILD)
