INCLUDES   = -I/home/iyume/workplace/cppwork/2021/2021.04.20-exp-coop
CXX        = clang++
CXXFLAGS   = -g -pthread ${INCLUDES}
OBJS       = csvreader.o func.o
DEPS       = functions.h
EXECUTABLE = math 


main.exe: main.o
	clang++ -o main.exe main.o

main.o: ${objects}
	clang++ ${objects} -o main.o

csvreader.o: linearlist.o
	(cd csvreader && clang++ -g -c -pthread csvreader.cpp)

linearlist.o:
	(cd linearlist && clang++ -g -c -pthread linearlist.cpp)

func.o:
	(cd func && clang++ -g -c -pthread func.cpp)

clean:
	rm -f ${objects}
