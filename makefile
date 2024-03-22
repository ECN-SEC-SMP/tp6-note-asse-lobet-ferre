CXX = g++
CXXFLAGS = -Wall
TARGET = out

all: $(TARGET)

$(TARGET): *.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: clean