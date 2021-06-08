CXX        = clang++
CXXFLAGS   = -g -c -pthread ${INCLUDES}
OBJS       = main.o
DEPS       = functions.h
EXECUTABLE = math 


main: ${OBJS}
	${CXX} -o a.out ${OBJS}

main.o:
	clang++ ${CXXFLAGS} main.cpp

clean:
	rm -f ${OBJS}
