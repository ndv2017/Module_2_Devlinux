.PHONY: objs shared install

LIB_NAME    := shared_singleton

CUR_DIR     := .
INC_DIR     := $(CUR_DIR)/inc
SRC_DIR     := $(CUR_DIR)/src
OBJ_DIR     := $(CUR_DIR)/obj
$(shell mkdir -p $(OBJ_DIR))
BIN_DIR     := $(CUR_DIR)/bin
$(shell mkdir -p $(BIN_DIR))

LIB_DIR     := $(CUR_DIR)/libs
LIB_SHARED  := $(LIB_DIR)/shared
$(shell mkdir -p $(LIB_SHARED))

CC          := gcc
INC_FLAGS   := -I $(INC_DIR)
CFLAGS      := -c -fPIC -o

all: objs shared cp_lib
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_SHARED) -l$(LIB_NAME) -o $(BIN_DIR)/sensors_manager_app
	@echo "-----------------------------------------------------------------------"
	@echo "Run the application by run '$(BIN_DIR)/'sensors_manager_app or 'make run'"
	@echo "-----------------------------------------------------------------------"

run : all
	./$(BIN_DIR)/sensors_manager_app

objs:
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(CUR_DIR)/main.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/sensor_manager.o $(SRC_DIR)/sensor_manager.c $(INC_FLAGS)

shared:
	$(CC) -shared $(OBJ_DIR)/sensor_manager.o -o $(LIB_SHARED)/lib$(LIB_NAME).so

cp_lib:
	sudo cp -f $(LIB_SHARED)/lib$(LIB_NAME).so /usr/lib

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(LIB_SHARED)/*
	rm -rf $(BIN_DIR)/*
	sudo rm -rf /usr/lib/lib$(LIB_NAME).so

clean_all_dirs: clean
	rm -rf $(OBJ_DIR)
	rm -rf $(LIB_DIR)
	rm -rf $(BIN_DIR)
