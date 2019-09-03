#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class knapsack_data
{
private:
	int _capacity;
	int _nObj;
	int *_profits;
	int *_weights;
	string _file;
public:
	knapsack_data(string pth);
	~knapsack_data();
	void print_data();
	int get_Capacity() { return _capacity; };
	int get_nObjs() { return _nObj; };
	int get_profit(int obj) { return _profits[obj]; };
	int get_weight(int obj) { return _weights[obj]; };
};

