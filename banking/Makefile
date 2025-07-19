CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = banking_system
SRCDIR = .
INCDIR = include

# Source files
SOURCES = main.c accounts.c transactions.c storage.c auth.c
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET) accounts.dat

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
