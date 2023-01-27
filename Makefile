CXX = g++
# CXX = clang++

CXXFLAGS= -Wall -Wno-uninitialized -DWITHOUT_NUMPY -I/usr/local/include/opencv4 -Bstatic -lopencv_core -lopencv_imgcodecs -lopencv_highgui -g -O0 


OBJECTFILES = main.o
TARGET = compareImg

all: ${TARGET}

${TARGET}: ${OBJECTFILES}
	$(CXX) -o ${TARGET} ${OBJECTFILES} ${CXXFLAGS}

clean:
	/bin/rm -f ${TARGET} *.o
	/bin/rm -f *.png