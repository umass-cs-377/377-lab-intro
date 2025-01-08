.PHONY : all
all : process whoami

.DEFAULT_GOAL := all

clean:
	rm process whoami

process: process.cpp
	g++ -o process process.cpp

whoami: whoami.cpp
	g++ -o whoami whoami.cpp
