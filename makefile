BinarySearchTreeTest.o: BinarySearchTreeTest.cpp
	gcc BinarySearchTreeTest.cpp -lstdc++ -o bin/BinarySearchTreeTest

clean:
	rm -f BinarySearchTreeTest.o