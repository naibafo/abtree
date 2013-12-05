#Vars

CC = g++

O = -o

C = -c -Wall

tupletest : tupletest.cpp tuple.hpp
	$(CC) $(O) tupletest.exe tupletest.cpp

test: test.cpp
	$(CC) $(O) test.exe test.cpp

main: main.cpp
	$(CC) $(O) main.exe main.cpp
	
treetest: treetest.cpp
	$(CC) $(O) treetest.exe treetest.cpp

#General rule for compiling .cpp files and creating executable
.cpp: 
	$(CC) $(O) $*.exe $@

#General rule for creating portable network graphics image from .gv file.
test.gv: test.gv 
	dot -Tpng test.gv -o test.png

test3.gv: test3.gv 
	dot -Tpng test3.gv -o test3.png

test4.gv: test4.gv 
	dot -Tpng test4.gv -o test4.png

	
