CC = gcc
CFLAGS = -O2 # -I/opt/homebrew/Cellar/openssl@3/3.2.0_1/include
# LDFLAGS = -L/opt/homebrew/Cellar/openssl@3/3.2.0_1/lib
# LIBS = -lcrypto

SRC_FILES = a.c my_lib.c
EXECUTABLE = a.out

BENCH ?= 0
DEBUG ?= 0

ifeq ($(BENCH),0)
    CFLAGS += -DBENCH=0
else ifeq ($(BENCH),1)
    CFLAGS += -DBENCH=1
else
    $(error Invalid value for BENCH. Please use 0 or 1.)
endif

ifeq ($(DEBUG),0)
    CFLAGS += -DDEBUG=0
else ifeq ($(DEBUG),1)
    CFLAGS += -DDEBUG=1
else
    $(error Invalid value for DEBUG. Please use 0 or 1.)
endif

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(EXECUTABLE)