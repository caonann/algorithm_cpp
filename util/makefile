CXXFLAGS=-g -Wall -pthread

BINARIES=util_unittest

all: $(BINARIES)

util_unittest: util_unittest.cpp util.cpp

$(BINARIES):
	g++ -std=c++11 $(CXXFLAGS) $(LDFLAGS) $(filter %.cpp,$^) -o $@

clean:
	rm -f $(BINARIES)
