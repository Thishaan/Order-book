CXX = g++
CXXFLAGS = -Wall -g
TARGET = order_book_simulator
DIR=sources
SOURCES = $(wildcard $(DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all:	$(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS) $(TARGET)