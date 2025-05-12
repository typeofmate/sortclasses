#include <iostream>
#include <vector>
#include <algorithm>

class SortingStrategy 
{
	public:
	virtual void sort(std::vector<int>& data) = 0;// ���� ����� ���� �� ���������� ���������� � �������� �������
};

class BubbleSort : public SortingStrategy 
{
	public:
	void sort(std::vector<int>& data) override // override ��������� ���� �� ����� � ������������ ������
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

//����� ����������� ����� ��������� �����
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

//����� ������������ ���������
class Sorter 
{
	private:
	SortingStrategy* strategy; //���������� �� ��������� ����������
	public:
	Sorter(SortingStrategy* strat): strategy(strat){}

	void sortData(std::vector<int>& data) 
	{
		strategy->sort(data);//���������� ����� ���������� ��������� ���������
	}
};

int main() 
{
	std::vector<int> data = {5,2,9,1,5,6};//��������� ������ ������
	
	//��������� ���������
	BubbleSort bubbleStrategy;
	StdSort stdStrategy;
	InsertionSort insertionStrategy;

	//������ ����������� � ����������� �����������  � ������ ����
	Sorter bubbleSorter(&bubbleStrategy);
	bubbleSorter.sortData(data);

	std::cout << "BubbleSort: ";
	for (int num : data) std::cout << num << " ";
	std::cout << "\n";
	
	
	//������ ��������� ������ ������� ��� �����
	data = { 5,2,9,1,5,6 };
	

	//����������� �� ����������� ����������� �� ����������
	Sorter stdSorter(&stdStrategy);
	stdSorter.sortData(data);

	std::cout << "StdSort: ";
	for (int num : data) std::cout << num << " ";
	std::cout << "\n"
	//������ ������ � ����� ����� ����� ����������
	data = { 5,2,9,1,5,6 };

	Sorter insertionSorter(&insertionStrategy);
	insertionSorter.sortData(data);

	std::cout << "Insertion: ";
	for (int num : data) std::cout << num << " ";
	std::cout << "\n"

	return 0;
}
