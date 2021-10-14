ifeq ($(TYPE),cpp)
CC = clang++
else
CC = clang
endif

SHELL = bash

$(NAME): clean
	@echo Start Compiling $(NAME) using $(CC)...
	$(CC) -fuse-ld=lld -flto=thin -pipe -O2\
	      -o $(NAME) $(NAME).$(TYPE) $(LIBS)

test: $(NAME)
	@echo Now the program is running...
	./$(NAME) $(ARGS)

.PHONY: new test clean format

new:
	@echo -e Using template \`template.$(TYPE)\`...
	cp ~/Templates/template.$(TYPE) $(NAME).$(TYPE)

clean:
	@echo Remove previous build files...
	rm -f $(NAME)

format:
	@echo -e Running \`clang-format\`...
	clang-format -i $(NAME).$(TYPE)
