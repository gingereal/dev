CC = gcc
CFLAGS = -Iinclude
SRCDIR = src
BUILDDIR = build
SOURCES = $(wildcard $(SRCDIR)/*.c) src/test/test.c
EXECUTABLE = $(BUILDDIR)/program

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(EXECUTABLE)