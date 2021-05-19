CXX        = clang++
CXXFLAGS   = -g -c -pthread ${INCLUDES}
OBJS       = main.o csvreader.o func.o
DEPS       = functions.h
EXECUTABLE = math 


main: ${OBJS}
	${CXX} -o a.out ${OBJS}

main.o:
	clang++ ${CXXFLAGS} main.cpp

csvreader.o:
	${CXX} ${CXXFLAGS} csvreader/csvreader.cpp

func.o:
	${CXX} ${CXXFLAGS} func/func.cpp

clean:
	rm -f ${OBJS}
