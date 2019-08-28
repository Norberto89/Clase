#include <iostream>
#include<ilcplex/ilocplex.h>
#include<ilconcert/iloenv.h>

using namespace std;

int main() {

	IloEnv env; //Este es el ambiente a utilizar
	IloModel modelo; //Este es el modelo.
	IloCplex cplex; //Este es el solver.

	modelo = IloModel(env);
	cplex = IloCplex(modelo);

	IloNumVar x1, x2;
	IloObjective obj;
	IloRange R1, R2, R3;

	//Definición de variables de decisión.
	x1 = IloNumVar(env, 0, IloInfinity, "x1");
	x2 = IloNumVar(env, 0, IloInfinity, "x2");

	//Definición de función Objetivo.
	obj = IloAdd(modelo, IloMaximize(env, 3 * x1 + 5 * x2));

	//Denición de Restricciones
	R1 = IloRange(env, -IloInfinity, x1, 4, "R1");
	R2 = IloRange(env, -IloInfinity, 2 * x2, 12, "R2");
	R3 = IloRange(env, -IloInfinity, 3 * x1 + 2 * x2, 18, "R3");

	modelo.add(R1);
	modelo.add(R2);
	modelo.add(R3);
	//Exportar el modelo
	cplex.exportModel("PrimerModelo.lp");

	//Solucionar el modelo
	cplex.solve();

	//Imprimir la solución

	cout << "f.o. = " << cplex.getObjValue() << endl;
	cout << "x1 = " << cplex.getValue(x1) << endl;
	cout << "x2 = " << cplex.getValue(x2) << endl;

	//Análisis de sensibilidad.

	IloNumArray lower(env), upper(env);
	IloRangeArray restricciones(env);

	restricciones.add(R1);
	restricciones.add(R2);
	restricciones.add(R3);

	cplex.getRHSSA(lower, upper, restricciones);

	//Imprimir información lados derechos
	cout << "Limite inferior \t Limite superior" << endl;
	for (int i = 0; i < 3; i++) {
		cout << lower[i] << "\t" << upper[i] << endl;
	}


	IloNumArray Cupper(env), Clower(env);
	IloNumVarArray variables(env);

	variables.add(x1);
	variables.add(x2);

	cplex.getObjSA(Clower, Cupper, variables);

	//Imprimir información de Coef. en F.O.
	cout << "Limite inferior \t Limite superior" << endl;
	for (int i = 0; i < 2; i++) {
		cout << Clower[i] << "\t" << Cupper[i] << endl;
	}



	system("pause");
	return 0;
}