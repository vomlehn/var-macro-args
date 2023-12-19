CFLAGS += -I.

CXXFLAGS += -I.

all: example-c example-cc

test: test-c test-cc
	./test-c
	./test-cc

example-c: example.c var-macro-args.h
	cc $(CFLAGS) -o $@ $(filter-out *.h,$^)

example-cc: example.cc var-macro-args.h
	cc $(CXXFLAGS) -o $@ $(filter-out *.h,$^)

example.cc: example.c
	cp $^ $@

test-c: test.c var-macro-args.h
	cc $(CFLAGS) -o $@ $(filter-out *.h,$^)

test-cc: test.cc var-macro-args.h
	cc $(CXXFLAGS) -o $@ $(filter-out *.h,$^)

test.cc: test.c
	cp $^ $@

.PHONY: clean
clean:
	rm -f example-c example-cc test-c test-cc
