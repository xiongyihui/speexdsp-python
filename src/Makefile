

SWIG := swig

CXXFLAGS :=  -fPIC -std=c++11 -I. $(shell pkg-config --cflags speexdsp)  $(shell python-config --cflags)
LDFLAGS := -shared $(shell pkg-config --libs speexdsp) $(shell python-config --ldflags)
CXX := g++


all: _speexdsp.so

speexdsp_wrap.cpp: speexdsp.i
	$(SWIG) -I. -c++ -python -o $@ $^

_speexdsp.so: speexdsp_wrap.o echo_canceller.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	-rm -f speexdsp_wrap.cpp *.o _speexdsp.so speexdsp.py *.pyc 
