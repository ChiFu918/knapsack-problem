#include "greedy_knapsack.h"
#include <iostream>
using namespace std;

greedy_knapsack::greedy_knapsack(int _task_number, int _dram_capacity){
	task_number = _task_number;
	dram_capacity = _dram_capacity;
	task_capacity = new int[task_number];
	task_dram_execution_time = new float[task_number];
	task_pmem_execution_time = new float[task_number];
	greedy_ratio = new float[task_number];
	unique_number = new int[task_number];
}

void greedy_knapsack::set_task(int *_task_capacity, float *_task_dram_execution_time, float *_task_pmem_execution_time){
	for (int i = 0; i < task_number; i++){
		unique_number[i] = max_unique_number;
		max_unique_number += 1;
		task_capacity[i] = _task_capacity[i];
		task_dram_execution_time[i] = _task_dram_execution_time[i];
		task_pmem_execution_time[i] = _task_pmem_execution_time[i];
		greedy_ratio[i] = (task_pmem_execution_time[i] - task_dram_execution_time[i])/task_capacity[i];
	}
}

void greedy_knapsack::bubble_sort(){
	for(int i = 0; i < task_number-1; i++){
		for(int j = 0; j < task_number -i -1; j++){
			if(greedy_ratio[j] < greedy_ratio[j+1]){
				int tmp = unique_number[j];
				unique_number[j] = unique_number[j+1];
				unique_number[j+1] = tmp;
				
				int tmp_1 = task_capacity[j];
				task_capacity[j] = task_capacity[j+1];
				task_capacity[j+1] = tmp_1;

				float tmp_2 = task_dram_execution_time[j];
				task_dram_execution_time[j] = task_dram_execution_time[j+1];
				task_dram_execution_time[j+1] = tmp_2;

				float tmp_3 = task_pmem_execution_time[j];
				task_pmem_execution_time[j] = task_pmem_execution_time[j+1];
				task_pmem_execution_time[j+1] = tmp_3;

				float tmp_4 = greedy_ratio[j];
				greedy_ratio[j] = greedy_ratio[j+1];
				greedy_ratio[j+1] = tmp_4;
			}
		}
	}
}

void greedy_knapsack::print_task_information(){
	for(int i = 0; i < task_number; i ++){
		cout << "Task " << unique_number[i] << endl;
		cout << "---" << "task_capacity : " << task_capacity[i] << endl;
		cout << "---" << "task_dram_execution_time : " << task_dram_execution_time[i] << endl;
		cout << "---" << "task_pmem_execution_time : " << task_pmem_execution_time[i] << endl;
		cout << "---" << "greedy_ratio : " << greedy_ratio[i] << endl;
		//cout << "---" << "" <<  << endl;
		cout << endl;
	}
}

void greedy_knapsack::approxiamtion_knapsack(){
	int total_capacity = 0;
	
	for(int i = 0; i < task_number; i++){// filter
		if(greedy_ratio[i] > 0){
			task_location.push_back(make_pair(unique_number[i],"DRAM"));
		}else{
			task_location.push_back(make_pair(unique_number[i],"PMEM"));
		}
	}
	for(int i = 0; i < task_number; i++){
		if(task_location[i].second == "DRAM"){
			total_capacity += task_capacity[i];
			if(total_capacity <= dram_capacity){
				continue;
			}else{
				task_location[i].second = "PMEM";
			}

			
		}

	}
	/*
	vector<pair<int,string>>::iterator iter;
	for(iter = task_loaction.begin(); iter != task_location.end(); iter ++){
		if((*iter).second == "DRAM"){
			total_capacity += task_capacity[i];
			
			if(total_capacity <= dram_capacity){
				continue;
			}eles{
				(*iter).second = "PMEM";
			}
		}
	}
	*/ 
	/*
	for(int i = 0; i < task_number; i++)
		if(task_location[i].second == "DRAM")
			cout << "TASK " << task_location[i].first << " in DRAM" << endl;

	*/
}

greedy_knapsack::~greedy_knapsack(){
	delete [] task_capacity;
	delete [] task_dram_execution_time;
	delete [] task_pmem_execution_time;
	delete [] unique_number;
}
