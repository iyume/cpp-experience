CXX        =  clang++
CXXFLAGS   =  -g -c ${INCLUDES}
LIBDIR     =  lib
BUILDDIR   =  build
SRCS       =  main.cpp ${wildcard ${LIBDIR}/*.cpp}
OBJS       =  ${SRCS:%.cpp=%.o}

ALL: ${OBJS}
	${CXX} -o a.out ${foreach obj,${OBJS},build/${obj}}

${OBJS}: %.o: %.cpp
	mkdir -p build/lib
	${CXX} ${CXXFLAGS} $< -o build/$@

clean:
	rm -rf ${BUILDDIR}
