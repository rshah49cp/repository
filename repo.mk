# Rushabh Shah
# (rshah49)
# CSC 357
# functions inspired from GNU Make manual:
# https://www.gnu.org/software/make/manual/make.html#Rule-Introduction

REPO_CC = gcc
REPO_CFLAGS = -Wall -Wextra -Werror -pedantic -ansi
REPO_C = IOstd.c safe_ops.c
REPO_O = $(REPO_C:.c=.o)
REPO_H = $(REPO_C:.c=.h) include_all.h

.PHONY: all clean

repo: $(REPO_O)

IOstd.o: IOstd.c $(REPO_H) safe_ops.o
	$(REPO_CC) $(REPO_CFLAGS) -c $< -o $@

safe_ops.o: safe_ops.c safe_ops.h include_all.h
	$(REPO_CC) $(REPO_CFLAGS) -c $< -o $@

clean:
	rm -f *.o