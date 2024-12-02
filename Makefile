# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Target executable name
TARGET = $(BIN_DIR)/zebrapass

# Source files
SRC = $(SRC_DIR)/zebrapass.c

# Object files
OBJ = $(BUILD_DIR)/zebrapass.o

# Default target to compile the program
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile the source file to object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean the build files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Install target (optional)
install:
	@echo "Installing ZebraPass..."
	@cp $(TARGET) /usr/local/bin/zebrapass

# Phony targets
.PHONY: all clean install
 