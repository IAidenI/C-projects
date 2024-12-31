CC = gcc
CFLAGS = -Wall
TARGET = rootkit
SOURCES = rootkit.c ninja.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET) clean
	@echo "Binary ready !"

$(TARGET): $(OBJECTS)
	@echo "Compiling and linking $(TARGET)..."
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -f $(OBJECTS)
