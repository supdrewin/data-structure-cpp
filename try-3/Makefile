PROJECT   = LinkedList

ifeq ($(LLVM), 1)
AR        = llvm-ar
CC        = clang
CXX       = clang++
CXXFLAGS += -flto=thin
LDFLAGS  += -fuse-ld=lld
endif

CXXFLAGS += -pipe -O2

_ARGS     = $(ARGS)
_ARGS    += -o $(PROJECT).out

all: *.cpp
	$(CXX)  $(CXXFLAGS) \
	        $(LDFLAGS) \
	        $(_ARGS) \
	        $<

.PHONY: test clean

test: all
	./$(PROJECT).out $(INPUT)

clean:
	rm -f $(PROJECT).out
