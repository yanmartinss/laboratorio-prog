CC = gcc
CFLAGS = -Wall
INCLUDES = -I./include
SRC = ./src
BIN = ./bin
BUILD = ./build

OBJS = $(BUILD)/image.o $(BUILD)/compress.o $(BUILD)/utils.o

all: $(BIN)/compressor

$(BIN)/compressor: $(OBJS) $(BUILD)/main.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD)/image.o: $(SRC)/image.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD)/compress.o: $(SRC)/compress.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD)/utils.o: $(SRC)/utils.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(BUILD)/*.o $(BIN)/compressor
