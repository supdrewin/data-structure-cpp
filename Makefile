all:
	$(PWD)/build.sh $(PWD) $@ TOOLKIT=$(TOOLKIT)

lib:
	$(PWD)/build.sh $(PWD) $@ CROSS=$(CROSS)

clean:
	rm -rf $(PWD)/build

.PHONY: lib clean
