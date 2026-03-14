CC = gcc
CFLAGS = -Wall -g

TARGET = array_queue

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean

clean:
	rm -f $(TARGET)

