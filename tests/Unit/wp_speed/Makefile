SRCPATH = ../src
SRCOBJS = $(wildcard $(SRCPATH)/*.o)
TESTSRCS = $(wildcard *.c)

check: testsuite
	@echo Running tests...
	./testsuite

gcovcheck: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
gcovcheck: check
	gcov testsuite
	cd $(SRCPATH) && gcov calculateSpeed.c

gcovcheckb: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
gcovcheckb: check
	gcov -b -c testsuite
	cd $(SRCPATH) && gcov -b -c calculateSpeed.c

memcheck: EXTRAGCCFLAGS+= -g
memcheck: testsuite
	@echo Running tests under valgrind...
	valgrind --leak-check=full ./testsuite 

testsuite.o: $(TESTSRCS)
	gcc -c checkSpeed.c -o testsuite.o $(EXTRAGCCFLAGS)

testsuite: $(SRCOBJS) testsuite.o
	gcc $(SRCOBJS) testsuite.o -o testsuite $(EXTRAGCCFLAGS) -lcheck

clean:
	rm -f testsuite testsuite.exe testsuite.o *.gcov *.gcda *.gcno
