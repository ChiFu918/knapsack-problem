#include <iostream>
#include <vector>
#include <utility>
#include <string>

class greedy_knapsack {
	public:
		greedy_knapsack(int _task_number, int _dram_capacity);
		
		void set_task(int *_task_capacity, float *_task_dram_execution_time, float *_task_pmem_execution_time);
		//int generate_unique_number();
		void bubble_sort();
		void approxiamtion_knapsack();
		void print_task_information();	
		~greedy_knapsack();
	private:
		int max_unique_number = 0;

		int *unique_number;
		int task_number;
		int dram_capacity;
		int *task_capacity;
		float *task_dram_execution_time;
		float *task_pmem_execution_time;
		float *greedy_ratio;	
		std::vector<std::pair<int, std::string>> task_location;
			
};
