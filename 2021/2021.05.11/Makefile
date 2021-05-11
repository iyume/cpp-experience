INCLUDES   = -I/home/iyume/workplace/cppwork/2021/2021.04.20-exp-coop
CXX        = clang++
CXXFLAGS   = -g -c -pthread ${INCLUDES}
OBJS       = main.o linkedCircularList.o


main: ${OBJS}
	${CXX} -o a.out ${OBJS}

main.o:
	${CXX} ${CXXFLAGS} main.cpp

linkedCircularList.o:
	${CXX} ${CXXFLAGS} linkedCircularList.cpp

clean:
	rm -f ${OBJS}
