###
# Note!!!
# This is a Makefile template.
###

INCLUDES   =  -I/path/to/library
CXX        =  clang++
CXXFLAGS   =  -g -c ${INCLUDES}
LIBDIR     =  lib
BUILDDIR   =  build
SRCS       =  main.cpp ${wildcard ${LIBDIR}/*.cpp}
OBJS       =  ${SRCS:%.cpp=%.o}

# build active file by object files
ALL: ${OBJS}
	${CXX} -o a.out ${foreach obj,${OBJS},build/${obj}}

# compile source file to object file
${OBJS}: %.o: %.cpp
	mkdir -p build/lib
	${CXX} ${CXXFLAGS} $< -o build/$@

# remove build/
clean:
	rm -rf ${BUILDDIR}
