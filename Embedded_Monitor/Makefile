.PHONY: all clean run

CUR_DIR     := .
SRC_DIR     := $(CUR_DIR)/src
CONFIG_DIR  := $(CUR_DIR)/config
OBJ_DIR     := $(CUR_DIR)/obj
BIN_DIR     := $(CUR_DIR)/bin
LOG_DIR     := $(CUR_DIR)/log

$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))
$(shell mkdir -p $(LOG_DIR))

CXX         := g++
CC          := gcc
CXXFLAGS    := -std=c++17 -Wall -Wextra

CPP_SRCS := $(shell find $(SRC_DIR) -name "*.cpp")
C_SRCS   := $(shell find $(SRC_DIR) -name "*.c")
MAIN_SRC := $(SRC_DIR)/main.cpp

INCLUDES := $(sort $(dir $(CPP_SRCS) $(C_SRCS)))
INCLUDES := $(patsubst %, -I%, $(INCLUDES))         # Prefix each with -I, e.g: -Isrc/core/cpu_stats/
CXXFLAGS += $(INCLUDES)

CPP_OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(filter-out $(MAIN_SRC), $(CPP_SRCS)))
C_OBJS   := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_SRCS))
MAIN_OBJ := $(OBJ_DIR)/main.o

TARGET   := $(BIN_DIR)/monitor_app

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(CPP_OBJS) $(C_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

run: all
	@echo "Running monitor app..."
	@$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

clean_log:
	rm -rf $(LOG_DIR)

clean_all: clean clean_log
