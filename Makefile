CC      ?= cc
TARGET  := branchless
SRC     := branchless.c

# Optimization level: O0, O1, O2, O3, Ofast (maps to -O0 .. -Ofast)
OPT     ?= O2

CFLAGS  := -Wall -Wextra -$(OPT)

.PHONY: all run asm clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

asm: $(TARGET)
	objdump -d --no-show-raw-insn $(TARGET)

clean:
	rm -f $(TARGET)
