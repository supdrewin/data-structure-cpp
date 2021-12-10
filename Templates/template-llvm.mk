CXX       = clang++
LDFLAGS  += -fpie -fuse-ld=lld -rtlib=compiler-rt \
            -stdlib=libc++ -unwindlib=libunwind \
            -Wl,--as-needed

include $(PREFIX)/Templates/template.mk

CXXFLAGS += -flto=thin -glldb
LDFLAGS  += -lpthread -lgcc
