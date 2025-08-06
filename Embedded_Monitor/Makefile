# Project: Embedded System Monitor
.PHONY: all clean run

CUR_DIR     := .
SRC_DIR     := $(CUR_DIR)/src
CORE_DIR    := $(SRC_DIR)/core
ALERT_DIR   := $(SRC_DIR)/alert
UTIL_DIR    := $(SRC_DIR)/util
LEGACY_DIR  := $(SRC_DIR)/c_legacy

OBJ_DIR     := $(CUR_DIR)/obj
BIN_DIR     := $(CUR_DIR)/bin
LOG_DIR     := $(CUR_DIR)/log

$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))
$(shell mkdir -p $(LOG_DIR))

# Compiler & flags
CXX         := g++
CXXFLAGS    := -std=c++17 -Wall -Wextra -I$(CORE_DIR) -I$(ALERT_DIR) -I$(UTIL_DIR) -I$(LEGACY_DIR)

# Sources and objects
CPP_SRCS := $(wildcard $(CORE_DIR)/*.cpp) $(wildcard $(UTIL_DIR)/*.cpp)
CPP_OBJS := $(patsubst $(CORE_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(CORE_DIR)/%.cpp,$(CPP_SRCS))) \
            $(patsubst $(UTIL_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter $(UTIL_DIR)/%.cpp,$(CPP_SRCS)))

C_OBJS := $(OBJ_DIR)/logger.o

MAIN_SRC := $(SRC_DIR)/main.cpp
MAIN_OBJ := $(OBJ_DIR)/main.o

# Executable
TARGET := $(BIN_DIR)/monitor_app

all: clean $(TARGET)

$(TARGET): $(MAIN_OBJ) $(CPP_OBJS) $(C_OBJS)
	$(CXX) $^ -o $@

$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CORE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTIL_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/logger.o: $(LEGACY_DIR)/logger.c
	$(CC) -c $< -o $@

run: all
	@echo "Running monitor_app..."
	@$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*

clean_log:
	rm -rf $(LOG_DIR)/*

clean_all_dirs:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
