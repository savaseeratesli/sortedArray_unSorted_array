#include <iostream>

using namespace std;

class Array
{
protected:
	int* data;
	int size;
	int capacity;

public:
	Array(int user_capacity = 5)
	{
		capacity = user_capacity;
		data = new int[capacity];//yer ayýrdýk
		size = 0;

		cout << "Yeni array kapasitesi olustu " << capacity << endl;
	}

	~Array()
	{
		delete[] data;

		cout << "Array silindi" << endl;
	}

	Array(const Array& copyArray)
	{
		size = copyArray.size;
		capacity = copyArray.capacity;
		data = new int[capacity];

		for (int i = 0; i < copyArray.size; i++)
		{
			data[i] = copyArray.data[i];
		}

		cout << "Array kopyalandi" << endl;
	}

	void printItems()
	{
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				cout << data[i] << "-";
			}
		}
		cout << "\n" << "Kapasite: " << capacity << " Boyut: " << size << endl;
	}

	void removeIndexItem(int index)
	{
		if (index<0 || index>capacity)
		{
			cout << "Hata indexte deger yok " << index << endl;
			return;
		}

		for (int i = index; i < size; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
		cout << "Item silindi" << endl;

	}

	void removeItem(int number)
	{
		int counter = 0;
		for (int i = 0; i <= size; i++)
		{
			if (data[i] == number)
			{
				for (int j = i; j < size; j++)
				{
					data[j] = data[j + 1];
				}
				counter++;
			}
		}
		cout<<counter<<"items("<<number<<")"<< "Arrayden silindi"<<endl;
		size -= counter;
	}

	int findIndex(int a, int b = 0)
	{
		for (int i = b; i < size; i++)
		{
			if (data[i] == a)
			{
				return i;
			}
		}
		return -1;
	}

	void addItem(int number)
	{
		if (capacity == size)
		{
			int* temp_data = new int[capacity * 2];
			for (int i = 0; i < size; i++)
			{
				temp_data[i] = data[i];
			}
			delete[] data;
			data = temp_data;
			capacity *= 2;
		}
		data[size] = number;
		size++;
	}

};

//miraslý Sýrasýz Array
class unsortedArray :public Array
{
public:
	unsortedArray(int user_capacity = 5) :Array(user_capacity)
	{
		//Yukarýdaki yer ayýrma yeterli
	};

	unsortedArray(const unsortedArray& oth) :Array(oth)
	{

	};

	void printItems()
	{
		cout << "Unsorted Array: " << endl;
		Array::printItems();
	}
};


//miraslý Sýralý Array
class sortedArray :public Array
{
public:
	sortedArray(int user_capacity = 5) :Array(user_capacity)
	{

	};
	sortedArray(const sortedArray& oth) :Array(oth)
	{

	};
	void addItem(int number)
	{
		int i;
		if (capacity == size)
		{
			int* temp_data = new int[capacity * 2];//Kap iki kat arttý

			//Ekli elemanlarý yeni diziye atýyor
			for (int i = 0; i < size; i++)
			{
				temp_data[i] = data[i];
			}

			delete[] data;
			data = temp_data;
			capacity *= 2;
		}

		//10 20 30 40 ->33   10 20 30    40  - 10 20 30 33 40 - 30 33den küçük
		for (i = size - 1; (i >= 0 && data[i] > number); i--)
		{
			data[i + 1] = data[i];
		}

		data[i + 1] = number;
		size++;
	}
	void printItems()
	{
		cout << "Sorted Array: " << endl;
		Array::printItems();
	}
};












