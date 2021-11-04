PROJECT   = # TODO

ifeq ($(LLVM), 1)
CXX       = clang++
CXXFLAGS += -flto=thin
LDFLAGS  += -fuse-ld=lld
endif

CXXFLAGS += -pipe -O2
LDFLAGS  += -I..
FLAGS    += -g -o $(PROJECT).out

all: *.cpp clean
	$(CXX) $(CXXFLAGS) \
	       $(LDFLAGS) \
	       $(FLAGS) \
	       $<

.PHONY: test clean

test: all
	./$(PROJECT).out $(INPUT)

clean:
	rm -f $(PROJECT).out
