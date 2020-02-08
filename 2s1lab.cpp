#include "iostream"

struct Vector {
	const int ArrayRaiser = 50;
	int Count = 0;
	int ArrayCounter = ArrayRaiser;
	int *Array = new int[ArrayCounter];

	void Add(int item) {
		if (Count < ArrayCounter) {
			Array[Count] = item;
			Count++;
		}
		else {
			int* TempArray = new int[ArrayCounter + ArrayRaiser];
			for (int i = 0; i < Count; i++) {
				TempArray[i] = Array[i];
			}
			TempArray[Count] = item;
			ArrayCounter += ArrayRaiser;
			delete[] Array;
			Array = TempArray;
			Count++;
		}
	}

	int Index(int index) {
		return Array[index];
	}
};
int main(){
	Vector vector;
	for (int i = 0; i < 100; i++)
	{
		vector.Add(i);
	}

	for (int i = 0; i < vector.Count; i++)
	{
		printf("%i\n", vector.Index(i));
	}
	printf("\nCounter - %i", vector.Count);
}
