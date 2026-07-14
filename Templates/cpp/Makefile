CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = main
SRC = main.cpp

.PHONY: build clean run

all: clean build run

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	@if [ -f $(TARGET) ]; then \
		echo "Removing $(TARGET)..."; \
		rm -f $(TARGET); \
	else \
		echo "No executable to remove."; \
	fi

run:
	./$(TARGET)