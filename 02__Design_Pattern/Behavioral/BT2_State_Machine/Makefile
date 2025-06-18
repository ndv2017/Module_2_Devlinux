.PHONY: objs shared install

LIB_NAME    := shared_state_machine

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
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_SHARED) -l$(LIB_NAME) -o $(BIN_DIR)/music_player_app
	@echo "-----------------------------------------------------------------------"
	@echo "Run the application by running '$(BIN_DIR)/music_player_app' or 'make run'"
	@echo "-----------------------------------------------------------------------"

run : all
	./$(BIN_DIR)/music_player_app

objs:
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(CUR_DIR)/main.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/music_player.o $(SRC_DIR)/music_player.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/playing_state.o $(SRC_DIR)/playing_state.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/paused_state.o $(SRC_DIR)/paused_state.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/stopped_state.o $(SRC_DIR)/stopped_state.c $(INC_FLAGS)

shared:
	$(CC) -shared $(OBJ_DIR)/music_player.o $(OBJ_DIR)/playing_state.o $(OBJ_DIR)/paused_state.o $(OBJ_DIR)/stopped_state.o -o $(LIB_SHARED)/lib$(LIB_NAME).so

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
