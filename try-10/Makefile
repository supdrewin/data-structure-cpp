PROJECT   = HuffmanTree
SHELL     = zsh
EXEC      = app

ifeq ($(LLVM), 1)
  CXX     = clang++
  FLAGS   = -fuse-ld=lld -flto=thin -stdlib=libc++
  MESSAGE = using LLVM-Clang toolkits
else
  FLAGS   = -flto -static
endif

ifeq ($(CROSS), 1)
  CXX     = x86_64-w64-mingw32-g++
  MESSAGE = with MinGW-w64 target
  EXEC    = exe
endif

INPUT     = || :
OUTPUT    = $(PWD)/$(PROJECT).$(EXEC)
FLAGS    += -finline-functions -Wall -g -O2 -pipe -o $(OUTPUT)

*.cpp: clean

all: *.cpp
	@echo '\e[33;1mCompiling $(MESSAGE)...\e[0;36m'
	$(CXX) $(FLAGS) $^ -I../include

.PHONY: test clean

test: all
	@echo '\e[33;1mNow testing...\e[0;36m'
	-[[ $(EXEC) = exe ]] || $(OUTPUT) $(INPUT)

clean: ;clear
	@echo '\e[33;1mClean up previous code...\e[0;36m'
	-rm -f $(OUTPUT)
