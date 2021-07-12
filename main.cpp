#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

int main(){

	vector<int> numbers;

	cout << "Welcome to the Number Tool" << endl;
	
	bool run_program {true};
	char user_choice {};

	while (run_program) {
		cout << endl;
		cout << "P - print numbers" << endl;
		cout << "A - add a number" << endl;
		cout << "C - clear the list" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number" << endl;
		cout << "N - Count occurence of a number" << endl;
		cout << "Q - Quit" << endl;
		cout << "Enter your choice : " ;
		cin >> user_choice;
//		cout << endl;
		switch (user_choice) {
			case 'P':
			case 'p':
			{
				cout << "The current list of numbers: ";
				if (numbers.size() != 0) {
					for (auto num: numbers) {
						cout << num << " ";
					}					
				}
				else {
					cout << "[] - The list is empty." << endl;
				}

				cout << endl;
				break;
				
			}
			case 'A':
			case 'a':
			{
				int number_to_add;
				cout << "Enter new number: ";
				cin >> number_to_add;
				numbers.push_back(number_to_add);
				break;
				
			}
			case 'C':
			case 'c':
			{
				numbers.clear();
				cout << "Number list cleared." << endl;
				break;
			}
			case 'M':
			case 'm':
			{
				if (numbers.size() != 0) {
					cout << fixed;
					cout << setprecision(1);
					cout << "The mean of the numbers is " << accumulate(numbers.begin(),numbers.end(),0.0)/numbers.size() << endl;
				}
				else {
					cout << "Unable to determine mean. The list is empty." << endl;
				}
				break;
			}
			case 'S':
			case 's':
			{
				int small_num {};
				int num {};
				if (numbers.size() != 0) {
					for (int i {0};i<numbers.size();++i) {
						num = numbers.at(i);
						if (i == 0 || num < small_num) {
							small_num = num;
						}
					}
					cout << "The smallest number is " << small_num << endl;	
				}
				else {
					cout << "Unable to determine the smallest number. List is empty." << endl;
				}
				
				break;
			}				
			case 'L':
			case 'l':
			{
				int large_num {};
				if (numbers.size() != 0) {
					for (auto num: numbers) {
						if (num > large_num)
							large_num = num;
					}
					cout << "The largest number is " << large_num << endl;	
				}
				else {
					cout << "Unable to determine the largest number. List is empty." << endl;
				}
				
				break;
			}
			case 'Q':
			case 'q':
			{
				run_program = false;
				break;
				
			}
			case 'N':
			case 'n':
			{
				int number_to_search;
				cout << "Enter number to search for: ";
				cin >> number_to_search;
				int number_count {};
				for (auto num: numbers) {
					if (num == number_to_search) {
						number_count += 1;
					}
				}
				cout << "The number " << number_to_search << " appears " << number_count << " times in the list." << endl;
				break;
			}
			default:
				cout << "Unknown selection, please try again" << endl;
			
				
		}
	}

	

	std::cout << "hello testing..." << std::endl;
	return 0;
}