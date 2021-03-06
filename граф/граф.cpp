// граф.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>

struct babies
{
	int num;

	std::vector <int> babies;
};



int height(std::vector <babies> & p, int start)
{
	if (start == -1) return 0;
	int res = 1;
	int n = p[start].babies.size();

	for (int i = 0; i < n; i++)
	{
		int temp = 1 + height(p, p[start].babies[i]);
		if (res < temp)
			res = temp;
	}
	return res;
}

int main()
{
    
	int n, start=-1;
	std::cin >> n;
	std::vector <babies> point(n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		std::cin >> temp;

		if (temp == -1) start = i;
		else
		{
			point[temp].babies.push_back(i);
		}
	}

	std::cout << height(point, start);

}

