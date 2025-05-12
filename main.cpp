#include <iostream>
#include <vector>
#include <algorithm>

class SortingStrategy 
{
	public:
	virtual void sort(std::vector<int>& data) = 0;// если равно нулю то реализация происходит в дочерних классах
};

class BubbleSort : public SortingStrategy 
{
	public:
	void sort(std::vector<int>& data) override // override проверяет есть ли метод в родительском классе
	{ 
		for (size_t i = 0; i < data.size(); i++) 
		{
			for (size_t j = 0; j < data.size() - 1; j++)
			{
				if (data[j] > data[j + 1]) {
					std::swap(data[j], data[j + 1]);
				}
			}
		}
	}
};

class StdSort : public SortingStrategy 
{
	public:
	void sort(std::vector<int>& data) override 
	{
		std::sort(data.begin(), data.end());
	}
};

//класс добавленный через отдельную ветку
class InsertionSort : public SortingStrategy 
{
	public:
		void sort(std::vector<int>& data) override 
		{
			for (size_t i = 1; i < data.size(); i++) 
			{
				int key = data[i];
				int j = i - 1;
				while (j >= 0 && data[j] > key) 
				{
					data[j + 1] = data[j];
					j--;
				}
				data[j + 1] = key;
			}
		}
};

//класс использующий стратегию
class Sorter 
{
	private:
	SortingStrategy* strategy; //укказатель на стратегию сортировки
	public:
	Sorter(SortingStrategy* strat): strategy(strat){}

	void sortData(std::vector<int>& data) 
	{
		strategy->sort(data);//Вызывается метод сортировки выбранной стратегии
	}
};

int main() 
{
	std::vector<int> data = {5,2,9,1,5,6};//рандомный пример данных
	
	//создаются стратегии
	BubbleSort bubbleStrategy;
	StdSort stdStrategy;
	InsertionSort insertionStrategy;

	//Создам сортировщик с пузырьковой сортировкой  и выведу резы
	Sorter bubbleSorter(&bubbleStrategy);
	bubbleSorter.sortData(data);

	std::cout << "BubbleSort: ";
	for (int num : data) std::cout << num << " ";
	std::cout << "\n";
	
	
	//вернул начальный массив который сам задал
	data = { 5,2,9,1,5,6 };
	

	//сортировщик со стандартной сортировкой из алгоритмов
	Sorter stdSorter(&stdStrategy);
	stdSorter.sortData(data);

	std::cout << "StdSort: ";
	for (int num : data) std::cout << num << " ";
	std::cout << "\n"
	//вернул массив и провёл через новую сортировку
	data = { 5,2,9,1,5,6 };

	Sorter insertionSorter(&insertionStrategy);
	insertionSorter.sortData(data);

	std::cout << "Insertion: ";
	for (int num : data) std::cout << num << " ";
	std::cout << "\n"

	return 0;
}
