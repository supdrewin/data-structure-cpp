SHELL     = bash

PLATFORM ?= posix
EXEC     ?= app

CXXFLAGS += -std=c++2a -pipe -I$(PREFIX)/include
CXXFLAGS += -Wall -Weffc++ -Wextra -Wsign-conversion -Werror
CXXFLAGS += -finline-functions -fstack-protector-strong
CXXFLAGS += -pedantic-errors -g -O2

LDFLAGS  ?= -flto
LDFLAGS  += -L$(PREFIX)/lib/$(PLATFORM) -static -lutility

INPUT     = || :
OUTPUT    = $(PREFIX)/build/$(PROJECT).$(EXEC)

all: *.cpp; @mkdir -p $(PREFIX)/build
	@echo -e "\e[33;1m`date` - Making $^($(PROJECT)) using $(CXX)...\e[0;36m"
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $^ $(LDFLAGS)

.PHONY: test clean

test: all
	@echo -e "\e[33;1m`date` - Now testing for $(PLATFORM)...\e[0;36m"
	-[[ $(EXEC) = exe ]] || $(OUTPUT) $(INPUT)

clean:
	@echo -e "\e[33;1m`date` - Clean up for $(PLATFORM)...\e[0;36m"
	-rm -f $(OUTPUT)
