CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

TARGET = reverse_shell
SRCS = main.cpp ReverseShell.cpp Connection.cpp Socket.cpp SystemInfo.cpp Persistence.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
