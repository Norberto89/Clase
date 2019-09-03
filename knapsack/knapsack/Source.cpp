#include "knapsack_data.h"
#include "knapsack_model.h"

int main(){

	knapsack_data *ks_data;
	ks_data = new knapsack_data("f1_l-d_kp_10_269");

	knapsack_model *ks_model;
	ks_model = new knapsack_model(ks_data);

	ks_model->solve();

	delete ks_data;
	delete ks_model;
	system("pause");
	return 0;
}