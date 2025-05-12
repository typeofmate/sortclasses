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
	void sort(std::vector<int>& data) override { // override ��������� ���� �� ����� � ������������ ������
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

	return 0;
}
