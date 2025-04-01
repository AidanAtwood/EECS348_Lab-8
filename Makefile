matrix.exe: main.cpp matrix.cpp matrix.hpp
	g++ -Wall -Wextra main.cpp matrix.cpp matrix.hpp -o matrix.exe

clean:
	rm -f matrix.exe

run:
	./matrix.exe