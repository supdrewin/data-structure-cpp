PROJECT = SequenceStack
include ../Templates/template.make

$(TEST).cpp: clean

$(TEST): $(TEST).cpp
	@echo '\e[33;1mMaking $^ using $(CXX)...\e[0;36m'
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $^ $(LDFLAGS)
