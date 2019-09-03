#pragma once
#include "knapsack_data.h"
#include <ilconcert/iloenv.h>
#include <ilcplex/ilocplex.h>

class knapsack_model
{
private:
	knapsack_data *_ks;
	IloEnv _env;
	IloCplex _cplex;

	IloModel _model;

	IloObjective _obj;
	IloRange _cap;
	IloNumVarArray _x;


public:
	knapsack_model(knapsack_data *ks);
	~knapsack_model();
	void solve();
};

