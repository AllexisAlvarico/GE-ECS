BUILD_DIR	:= ./bin
SRC_DIR		:= ./src

OUTPUT_NAME	:= "firstApp"
COMP_FILES	:= ${SRC_DIR}/*.cpp 

INCLUDE		:= "C:/msys64/mingw64/include/SDL2"
LIB			:= "C:/msys64/mingw64/bin"
DLL			:= "-lmingw32" "-lSDL2main" "-lSDL2" "-lSDL2_image" "-lSDL2_ttf"

MSG_START	:= "Build Started"
MSG_END		:= "Build Complete"
MSG_CLEAN	:= "Cleaning up"

all			:= build

build:
	@echo ${MSG_START}

	#remove directory if it exits and then create directory
	rm -rf ${BUILD_DIR} || true

	#create bin directory
	mkdir ${BUILD_DIR}

	g++ -o ${BUILD_DIR}/${OUTPUT_NAME} ${COMP_FILES} -I${INCLUDE} -I./include -I. -L${LIB} $(DLL)
	@echo ${MSG_END}