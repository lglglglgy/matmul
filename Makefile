CXX = g++

CXXFLAGS =  -g -fopenmp

INCLUDE = -I./include

SRC = src/main.cpp src/file_operations.cpp src/matrix_operations.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = matmul_main

all: $(TARGET)
	@echo "编译完成，$(TARGET) 为最后生成目标"

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -f $(OBJ) $(TARGET) result.txt
