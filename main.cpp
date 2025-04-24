#include <mutex>
#include <vector>
#include <iostream>

std::vector<int> some_list;
//std::mutex some_mutex;

void add_to_list(int new_value1, int new_value2)
{
	//std::lock_guard<std::mutex> guard(some_mutex);
	some_list.push_back(new_value1);
	std::cout << " ";
	some_list.push_back(new_value2);
}
bool list_count()
{
	//std::lock_guard<std::mutex> guard(some_mutex);
	if (some_list.size() == 1) {
		std::cout << "Race Condition triggered\n";
	}
	
	return true;
}

int main() {
	{
		for (int i = 1;i < 1000;i++) {
			
			std::thread t1{ add_to_list ,3,5 };
			std::thread t2{ list_count };
			t1.join();
			t2.join();
			some_list.clear();
			
		}
	}
}
