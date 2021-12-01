SHELL     = zsh

PLATFORM    = posix
EXEC        = app
CXX         = clang++
CXXFLAGS    = -I../include -std=c++2a -O2 -pipe
LDFLAGS     = -fuse-ld=lld -flto=thin

ifeq ($(CROSS), 1)
  TARGET    = x86_64-w64-mingw32
  PLATFORM  = windows
  EXEC      = exe
  CXX       = $(TARGET)-g++
  CXXFLAGS ?=
  LDFLAGS   =
endif

CXXFLAGS   += -finline-functions -Wall -g
LDFLAGS    += -L../lib/$(PLATFORM) -static -lutility

INPUT       = || :
OUTPUT      = ./$(PROJECT).$(EXEC)

*.cpp: clean

all: *.cpp
	@echo '\e[33;1mMaking $^ using $(CXX)...\e[0;36m'
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $^ $(LDFLAGS)

.PHONY: test clean

test: all
	@echo '\e[33;1mNow testing...\e[0;36m'
	-[[ $(EXEC) = exe ]] || $(OUTPUT) $(INPUT)

clean: ; clear
	@echo '\e[33;1mClean up for $(PLATFORM)...\e[0;36m'
	-rm -f $(OUTPUT)
