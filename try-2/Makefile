PROJECT   = SequenceList

ifeq ($(LLVM), 1)
CXX       = clang++
CXXFLAGS += -flto=thin
LDFLAGS  += -fuse-ld=lld
endif

ifdef N
FLAGS    += -D N=$(N)
endif

CXXFLAGS += -pipe -O2
LDFLAGS  += -I..
LDFLAGS  += -I../include
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
