# PROJECT   = Decimal2other
PROJECT   = CheckBrackets

ifeq ($(LLVM), 1)
AR        = llvm-ar
CC        = clang
CXX       = clang++
CXXFLAGS += -flto=thin
LDFLAGS  += -fuse-ld=lld
endif

CXXFLAGS += -pipe -O2

_ARGS     = $(ARGS)
_ARGS    += -o $(PROJECT)

all: clean
	$(CXX)  $(CXXFLAGS) \
	        $(LDFLAGS) \
	        $(_ARGS) \
	        $(PROJECT).cpp

.PHONY: test clean

test: all
# ./$(PROJECT) $(INPUT)
	./$(PROJECT) "$(INPUT)"

clean:
	rm -f $(PROJECT)
