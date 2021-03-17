# project name
TAG := tsa

# compiler name
CC := g++

# source
SRC := main.cpp
SRC += tools.cpp
SRC += algorithms.cpp

# include
INC := -I.

# library
LIB := -lpthread

# flag
CFLAG := -Wall
CFLAG += -std=c++11
CFLAG += -stdlib=libc++

# mode list
.PHONY: release release-thread debug debug-thread clean

# release mode
release: build/release/$(TAG)

build/release/$(TAG): $(SRC)
	@echo "[RELEASE]"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) $(INC) $(LIB) -O3 $^ -o $@

# release-thread mode
release-thread: build/release-thread/$(TAG)

build/release-thread/$(TAG): $(SRC:main.cpp=main_thread.cpp)
	@echo "[RELEASE-THREAD]"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) $(INC) $(LIB) -O3 $^ -o $@

# debug mode
debug: build/debug/$(TAG)

build/debug/$(TAG): $(SRC)
	@echo "[DEBUG]"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) $(INC) $(LIB) -g $^ -o $@

# debug-thread mode
debug-thread: build/debug-thread/$(TAG)

build/debug-thread/$(TAG): $(SRC:main.cpp=main_thread.cpp)
	@echo "[DEBUG-THREAD]"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) $(INC) $(LIB) -g $^ -o $@

# clean mode
clean:
	@echo "[CLEAN]"
	@rm -r build/
