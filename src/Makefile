PROJECT  = utility
SHELL    = bash

AR       = llvm-ar
ARFLAGS  = --rsp-quoting=$(PLATFORM) rc

PLATFORM = posix
CXX      = clang++

ifeq ($(CROSS), 1)
TARGET   = x86_64-w64-mingw32
PLATFORM = windows
CXX      = $(TARGET)-g++
endif

CXXFLAGS = -I../include -pipe -O2
OUTPUT   = ../lib/$(PLATFORM)/lib$(PROJECT).a

all: *.o; @mkdir -p ../lib/$(PLATFORM)
	@echo -e "\e[33;1mMaking $^ using $(AR)...\e[0;36m"
	$(AR) $(ARFLAGS) $(OUTPUT) $^
	@rm -f $^

clean: ; @clear
	@echo -e "\e[33;1mClean up for $(PLATFORM)...\e[0;36m"
	-rm -f $(OUTPUT)

*.cpp: clean
	@echo -e "\e[33;1mMaking $@ using $(CXX)...\e[0;36m"
	$(CXX) $(CXXFLAGS) -c $@

*.o: *.cpp

test: all

.PHONY: *.o test
