TARGET = ./tar/mylib.a

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc
TAR_DIR = ./tar



SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CC = gcc
AR = ar
AS = as


default:$(OBJ_DIR) $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)

all: clean default

$(OBJ_DIR):
	mkdir -p $@
	mkdir -p $(TAR_DIR)

$(TARGET): $(OBJS)
	$(AR) -r $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)


.PHONY: all clean
