# name project
TAG = tsa

# name compiler
CC = g++

# source parametres
SRCS  = main.cpp
SRCS += tools.cpp
SRCS += algorithms.cpp

# flag parametres
CFLAGS  = -Wall
CFLAGS += -std=c++11


# mode list
.PHONY: release release-thread debug debug-thread clean


# release mode
release: build/release/$(TAG)

build/release/$(TAG): $(SRCS)
	@echo "[RELEASE]"
	@mkdir -p build/
	@mkdir -p build/release/
	@$(CC) $(CFLAGS) $^ -o $@


# release-thread mode
release-thread: build/release-thread/$(TAG)

build/release-thread/$(TAG): $(SRCS:main.cpp=main_thread.cpp)
	@echo "[RELEASE-THREAD]"
	@mkdir -p build/
	@mkdir -p build/release-thread/
	@$(CC) $(CFLAGS) -lpthread $^ -o $@


# debug mode
debug: build/debug/$(TAG)

build/debug/$(TAG): $(SRCS)
	@echo "[DEBUG]"
	@mkdir -p build/
	@mkdir -p build/debug/
	@$(CC) $(CFLAGS) -g $^ -o $@


# debug-thread mode
debug-thread: build/debug-thread/$(TAG)

build/debug-thread/$(TAG): $(SRCS:main.cpp=main_thread.cpp)
	@echo "[DEBUG-THREAD]"
	@mkdir -p build/
	@mkdir -p build/debug-thread/
	@$(CC) $(CFLAGS) -lpthread -g $^ -o $@


# clean mode
clean:
	@echo "[CLEAN]"
	@rm -r build/
