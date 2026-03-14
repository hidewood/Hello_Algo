CC = gcc
CFLAGS = -Wall -g

TARGET = linkedlist_queue

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean

clean:
	rm -f $(TARGET)

