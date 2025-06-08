.PHONY: objs shared install

LIB_NAME    := shared

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
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_SHARED) -l$(LIB_NAME) -o $(BIN_DIR)/library_management_app
	@echo "-----------------------------------------------------------------------"
	@echo "Run the application by run '$(BIN_DIR)/library_management_app' or 'make run'"
	@echo "-----------------------------------------------------------------------"

run : all
	./$(BIN_DIR)/library_management_app

objs:
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(CUR_DIR)/main.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/book.o $(SRC_DIR)/book.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/borrow.o $(SRC_DIR)/borrow.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/error.o $(SRC_DIR)/error.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/search.o $(SRC_DIR)/search.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/user.o $(SRC_DIR)/user.c $(INC_FLAGS)

shared:
	$(CC) -shared $(OBJ_DIR)/book.o $(OBJ_DIR)/borrow.o $(OBJ_DIR)/error.o $(OBJ_DIR)/search.o $(OBJ_DIR)/user.o -o $(LIB_SHARED)/lib$(LIB_NAME).so

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
