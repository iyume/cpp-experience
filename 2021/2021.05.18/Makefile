INCLUDES   = -I/home/iyume/workplace/cppwork/
CXX        = clang++
CXXFLAGS   = -g -c -pthread ${INCLUDES}
OBJS       = main.o orderedCircularQueue.o


main: ${OBJS}
	${CXX} -o a.out ${OBJS}

main.o:
	${CXX} ${CXXFLAGS} main.cpp

linkedCircularQueue.o:
	${CXX} ${CXXFLAGS} linkedCircularQueue.cpp

clean:
	rm -f ${OBJS}
