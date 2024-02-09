# Rushabh Shah
# (rshah49)
# CSC 357
# functions inspired from GNU Make manual:
# https://www.gnu.org/software/make/manual/make.html#Rule-Introduction

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -ansi
ALL_C = IOstd.c safe_ops.c
ALL_O = $(ALL_C:.c=.o)

.PHONY: all clean

all: $(ALL_O)

%.o : %.c %.h include_all.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_O)