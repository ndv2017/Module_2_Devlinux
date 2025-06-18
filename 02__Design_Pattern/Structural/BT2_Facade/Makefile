.PHONY: objs shared install

LIB_NAME    := shared_facade

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
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_SHARED) -l$(LIB_NAME) -o $(BIN_DIR)/smart_home_control_test_app
	@echo "-----------------------------------------------------------------------"
	@echo "Run the application by run '$(BIN_DIR)/'smart_home_control_test_app or 'make run'"
	@echo "-----------------------------------------------------------------------"

run : all
	./$(BIN_DIR)/smart_home_control_test_app

objs:
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(CUR_DIR)/main.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/smart_home_facade.o $(SRC_DIR)/smart_home_facade.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/hvac_system.o $(SRC_DIR)/hvac_system.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/lighting_system.o $(SRC_DIR)/lighting_system.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/security_system.o $(SRC_DIR)/security_system.c $(INC_FLAGS)

shared:
	$(CC) -shared $(OBJ_DIR)/smart_home_facade.o $(OBJ_DIR)/hvac_system.o $(OBJ_DIR)/lighting_system.o $(OBJ_DIR)/security_system.o -o $(LIB_SHARED)/lib$(LIB_NAME).so

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
