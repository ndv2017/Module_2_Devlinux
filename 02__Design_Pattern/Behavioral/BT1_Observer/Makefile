.PHONY: objs shared install

LIB_NAME    := shared_observer

CUR_DIR     := .
INC_DIR     := $(CUR_DIR)/inc
INC_PUB     := $(INC_DIR)/publishers
INC_SUB     := $(INC_DIR)/subscribers
SRC_DIR     := $(CUR_DIR)/src
SRC_PUB     := $(SRC_DIR)/publishers
SRC_SUB     := $(SRC_DIR)/subscribers
OBJ_DIR     := $(CUR_DIR)/obj
$(shell mkdir -p $(OBJ_DIR))
BIN_DIR     := $(CUR_DIR)/bin
$(shell mkdir -p $(BIN_DIR))

LIB_DIR     := $(CUR_DIR)/libs
LIB_SHARED  := $(LIB_DIR)/shared
$(shell mkdir -p $(LIB_SHARED))

CC          := gcc
INC_FLAGS   := -I $(INC_DIR) -I $(INC_PUB) -I $(INC_SUB)
CFLAGS      := -c -fPIC -o

all: objs shared cp_lib
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_SHARED) -l$(LIB_NAME) -o $(BIN_DIR)/smart_home_event_system_app
	@echo "-----------------------------------------------------------------------"
	@echo "Run the application by run '$(BIN_DIR)/'smart_home_event_system_app or 'make run'"
	@echo "-----------------------------------------------------------------------"

run : all
	./$(BIN_DIR)/smart_home_event_system_app

objs:
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(CUR_DIR)/main.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/alarm_system_controller.o $(SRC_SUB)/alarm_system_controller.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/event_logger.o $(SRC_SUB)/event_logger.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/mobile_app_notifier.o $(SRC_SUB)/mobile_app_notifier.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/observer.o $(SRC_DIR)/observer.c $(INC_FLAGS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/door_sensor.o $(SRC_PUB)/door_sensor.c $(INC_FLAGS)

shared:
	$(CC) -shared $(OBJ_DIR)/alarm_system_controller.o $(OBJ_DIR)/event_logger.o $(OBJ_DIR)/mobile_app_notifier.o $(OBJ_DIR)/observer.o $(OBJ_DIR)/door_sensor.o -o $(LIB_SHARED)/lib$(LIB_NAME).so

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
