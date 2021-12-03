all:
	$(PWD)/build.sh $(PWD) $@ TOOLKIT=$(TOOLKIT)

lib:
	$(PWD)/build.sh $(PWD) $@ CROSS=$(CROSS)

test:
	$(PWD)/test.sh $(CROSS)

clean:
	rm -rf $(PWD)/build

.PHONY: lib test clean
