CXX=g++
CFLAGS= -I. -I../cute -lm
DEPS = *.h
OBJ = Test.o SLLSet.o SLLNode.o

%.o: %.cpp $(DEPS)
	$(CXX) -I. -I../cute $(CFLAGS) -c -o $@ $< 

Lab5: $(OBJ)
	$(CXX) -I. -I../cute -lm $(CFLAGS) -o $@ $^ 
#testCompile: Test.cpp Matrix.cpp
#	g++ -o Test.cpp Matrix.cpp
test:	testLab5
testLab5:
# next line must start with a real TAB (ASCII 9)
	./run.sh

.PHONY: clean

clean:
	$(RM) *.o Lab5
