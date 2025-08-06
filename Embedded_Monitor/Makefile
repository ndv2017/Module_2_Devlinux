# Project: Embedded System Monitor
.PHONY: all clean run

# Folders
CUR_DIR     := .
SRC_DIR     := $(CUR_DIR)/src
CORE_DIR    := $(SRC_DIR)/core
ALERT_DIR   := $(SRC_DIR)/alert
UTIL_DIR    := $(SRC_DIR)/util
LEGACY_DIR  := $(SRC_DIR)/c_legacy

OBJ_DIR     := $(CUR_DIR)/obj
BIN_DIR     := $(CUR_DIR)/bin

# Create dirs if they don't exist
$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))

# Compiler & flags
CXX         := g++
CXXFLAGS    := -std=c++17 -Wall -Wextra -I$(CORE_DIR) -I$(ALERT_DIR) -I$(UTIL_DIR)

# Sources and objects
CPP_SRCS := $(wildcard $(CORE_DIR)/*.cpp)
CPP_OBJS := $(patsubst $(CORE_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPP_SRCS))

MAIN_SRC := $(SRC_DIR)/main.cpp
MAIN_OBJ := $(OBJ_DIR)/main.o

# Executable
TARGET := $(BIN_DIR)/monitor_app

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(CPP_OBJS)
	$(CXX) $(MAIN_OBJ) $(CPP_OBJS) -o $(TARGET)

$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CORE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	@echo "Running monitor_app..."
	@$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*
