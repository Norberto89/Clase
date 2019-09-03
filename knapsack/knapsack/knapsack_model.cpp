#include "knapsack_model.h"



knapsack_model::knapsack_model(knapsack_data *ks)
{
	_ks = ks;
	_model = IloModel(_env);
	_cplex = IloCplex(_model);

	_x = IloNumVarArray(_env);
	for (int i = 0; i < ks->get_nObjs(); i++) {
		_x.add(IloNumVar(_env, 0, 1, ILOINT));
	}

	_obj = IloAdd(_model, IloMaximize(_env, 0));
	for (int i = 0; i < ks->get_nObjs(); i++) {
		_obj.setLinearCoef(_x[i], ks->get_profit(i));
	}

	IloExpr exp(_env);
	for (int i = 0; i < ks->get_nObjs(); i++) {
		//exp.setLinearCoef(_x[i],ks->get_weight(i));
		exp += ks->get_weight(i)*_x[i];
	}
	_cap = IloRange(_env,0,exp,ks->get_Capacity(),"Cap");
	exp.end();
	_model.add(_cap);


}


knapsack_model::~knapsack_model()
{
	_model.end();
	_cplex.end();
}

void knapsack_model::solve() {
	_cplex.solve();

	cout << "F.O.: " << _cplex.getObjValue() << endl;
	cout << "Solucion: " << endl;
	for (int i = 0; i < _ks->get_nObjs() ; i++) {
		cout << _cplex.getValue(_x[i]) << endl;
	}
}