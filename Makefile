# Makefile for test var-macro-args.h. Checks with C and C++

CFLAGS += -Iinclude
CFLAGS += -g -ggdb

CXXFLAGS += -Iinclude
CXFLAGS += -g -ggdb

# Kind of a cheat
$(shell mkdir -p bin src)

all: bin/example-c bin/example-cc

.PHONY: test
test: bin/test-c bin/test-cc
	bin/test-c
	bin/test-cc

bin/example-c: src/example.c include/var-macro-args.h
	cc $(CFLAGS) -o $@ $(filter-out *.h,$^)

bin/example-cc: src/example.cc include/var-macro-args.h
	cc $(CXXFLAGS) -o $@ $(filter-out *.h,$^)

src/example.c: tests/example.cc
	cp $^ $@

src/example.cc: tests/example.cc
	cp $^ $@

bin/test-c: src/test.c include/var-macro-args.h
	cc $(CFLAGS) -o $@ $(filter-out *.h,$^)

bin/test-cc: src/test.cc include/var-macro-args.h
	cc $(CXXFLAGS) -o $@ $(filter-out *.h,$^)

src/test.cc: tests/test.c
	cp $^ $@

src/test.c: tests/test.c
	cp $^ $@

.PHONY: clean
clean:
	rm -rf src bin
