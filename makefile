test.o: test.h test.cpp
	g++ -pedantic-errors -std=c++11 -g -c test.cpp
generate.o: generate.h generate.cpp
	g++ -pedantic-errors -std=c++11 -g -c generate.cpp
calculate.o:calculate.cpp calculate.h test.h test.cpp
	g++ -pedantic-errors -std=c++11 -g -c calculate.cpp
customer.o:customer.cpp customer.h grocery.cpp grocery.h
	g++ -pedantic-errors -std=c++11 -g -c customer.cpp
grocery.o:grocery.cpp grocery.h
	g++ -pedantic-errors -std=c++11 -g -c grocery.cpp
interface.o:interface.cpp interface.h customer.cpp customer.h generate.cpp generate.h calculate.cpp calculate.h
	g++ -pedantic-errors -std=c++11 -g -c interface.cpp
main.o:main.cpp generate.cpp generate.h
	g++ -pedantic-errors -std=c++11 -g -c main.cpp
grocery_store:calculate.o customer.o grocery.o interface.o main.o generate.o test.o
	g++ -pedantic-errors -std=c++11 test.o calculate.o customer.o grocery.o interface.o main.o generate.o -g -o grocery_store
clean:
	rm *.txt *.o grocery_store
tar:
	tar -czvf grocery.tgz *.cpp *.h
