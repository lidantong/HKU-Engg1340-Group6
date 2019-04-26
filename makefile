calculate.o:calculate.cpp calculate.h 
	g++ -pedantic-errors -std=c++11 -g -c calculate.cpp
customer.o:customer.cpp customer.h
	g++ -pedantic-errors -std=c++11 -g -c customer.cpp
grocery.o:grocery.cpp grocery.h
	g++ -pedantic-errors -std=c++11 -g -c grocery.cpp
interface.o:interface.cpp interface.h
	g++ -pedantic-errors -std=c++11 -g -c interface.cpp
main.o:main.cpp
	g++ -pedantic-errors -std=c++11 -g -c main.cpp
grocery_store:calculate.o customer.o grocery.o interface.o main.o
	g++ -pedantic-errors -std=c++11 calculate.o customer.o grocery.o interface.o main.o -g -o grocery_store