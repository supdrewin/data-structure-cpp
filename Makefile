all:
	$(PWD)/build.sh $(PWD) $@ TOOLKIT=$(TOOLKIT)

clean:
	rm -rf $(PWD)/build
