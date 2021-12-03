CXX       = clang++
LDFLAGS  += -fuse-ld=lld -flto=thin

include $(PREFIX)/Templates/template.mk

CXXFLAGS += -stdlib=libc++
LDFLAGS  += -lpthread
