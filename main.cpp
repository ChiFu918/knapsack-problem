#include "greedy_knapsack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;

void load_data(int * task_capacity, float * task_dram_execution_time , float * task_pmem_execution_time, char* file_name_){
	fstream file;
	
	int count = 0;

	file.open(file_name_, ios::in);
	if(!file){
		cerr << "Can't open file" << endl;
		exit(1);
	}


	while(file >> task_capacity[count] >> task_dram_execution_time[count] >> task_pmem_execution_time[count]){
		count += 1;
	}

	file.close();
}

int main(int argc, char* argv[]){
	int task_number_ = 0;
	int total_memory_size = 0;
	istringstream aa (argv[1]);
	if(!(aa >> task_number_)){
		cerr << "Invalid number: " << argv[1] << '\n';
	} else if(!aa.eof()){
		cerr << "Trailing characters after number: " << argv[1] << '\n';
	}

	istringstream bb (argv[2]);
	if(!(bb >> total_memory_size)){
		cerr << "Invalid number: " << argv[2] << '\n';
	} else if(!bb.eof()){
		cerr << "Trailing characters after number: " << argv[2] << '\n';
	}


	char* file_name = argv[3];
	char* file_output = argv[4];
	
	
	greedy_knapsack greedy_knapsack(task_number_,total_memory_size);
	int _task_capacity_[task_number_];
	float _task_dram_execution_time_[task_number_];
	float _task_pmem_execution_time_[task_number_];
	
	load_data(_task_capacity_, _task_dram_execution_time_, _task_pmem_execution_time_, file_name);
	


	//cout << "---------- seting ----------" << endl;
	greedy_knapsack.set_task(_task_capacity_, _task_dram_execution_time_, _task_pmem_execution_time_);
	//greedy_knapsack.print_task_information();

	//auto start_time = std::chrono::steady_clock::now();
	//cout << "---------- sorting ----------" << endl;
	greedy_knapsack.bubble_sort();
	//greedy_knapsack.print_task_information();

	//cout << "---------- greedy algorithm ----------" << endl;
	auto start_time = std::chrono::steady_clock::now();
	greedy_knapsack.approxiamtion_knapsack();
	auto end_time = std::chrono::steady_clock::now();

	cout << endl;
	
	fstream file_out;
	file_out.open(file_output ,ios::app);

	auto dif_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
	//cout << "Spend time : " << dif_time << endl;
	file_out << dif_time << "\n";
	
	file_out.close();
	return 0;

}
