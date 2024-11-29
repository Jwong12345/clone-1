# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Output executable
TARGET = lets_vote

# Source files
SRCS = main.cpp \
       AgeIndexedVector.cpp \
       Voter.cpp \
       MaxHeap.cpp \
       LinkedList.cpp \
       VoterBST.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(TARGET) $(OBJS)
