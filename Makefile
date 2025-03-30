CXX = g++
CXXFLAGS = -std=c++20

all: task

task: main.cpp Header.cpp
	$(CXX) $(CXXFLAGS) main.cpp Header.cpp -o task

clean:
	rm -f task database.json
