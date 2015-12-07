object=test.o 

out:$(object)
	g++ -o out $(object)
test.o:test.cpp DList.h
	g++ -std=c++11 -c test.cpp

clean:
	rm *.o out
