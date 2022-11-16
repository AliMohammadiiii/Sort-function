CC = g++ -std=c++11

MergeSort.out : MergeSort.o
	$(CC) MergeSort.o -o MergeSort.out
	
	
MergeSort.o:
	$(CC) -c MergeSort.cpp -o MergeSort.o

clean:
	rm *.o MergeSort.out
