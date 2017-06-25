#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int N;

	cout << "Welcome to the Receipt Splitter! How many people are spitting the cost? ";
	cin >> N;
	while (N < 2) {
		cout << "You must have at least two people. How many people are spitting the cost? ";
		cin >> N;
	}
	double totals[N], total = 0;
	string names[N];

	for (int i = 0; i < N; i++) {
		totals[i] = 0;
		cout << "Enter a name: ";
		cin >> names[i];
	}
	cout << "----------" << endl;
	for (int i = 0; i < N; i++) {
		cout << i << ": " << names[i] << endl;
	}
	cout << "----------" << endl;

	double cost, quantity;

	char *buffer = NULL;
	size_t size = 0;
	ssize_t chars;

	while (true) {
		cout << "Enter the cost of the next item or -1 to finish: ";
		cin >> cost;
		if (cost < 0) {
			break;
		}
		cout << "How many of this item were purchased? ";
		cin >> quantity;
		printf("%d items were purchased at $%.2f each, for a total of $%.2f.\nWho paid for the item? Enter their comma-delimited numbers: ", (int) quantity, cost, cost * quantity);

		total += cost * quantity;

		cin.ignore();

		char *buffer = NULL;
		size_t size = 0;
		ssize_t chars = getline(&buffer, &size, stdin);
		int buyers = 1;
		int people[N];

		if (chars > 0 && buffer[chars-1] == '\n') 
			buffer[chars-1] = '\0';
		char* nums = strtok(buffer, " ,.");
		do {
			people[buyers - 1] = stoi(nums);
			buyers++;
		}
		while((nums = strtok(NULL, " ,.")));
		buyers--;

		for (int i = 0; i < buyers; i++) {
		 	cout << names[people[i]] << " ";
		 	totals[people[i]] += cost * quantity / buyers;
		}
		cout << "paid." << endl;
	}

	printf("The total came out to be $%.2f. The breakdown is\n", total);

	for (int i = 0; i < N; i++) {
		cout << names[i];
		printf(": $%.2f\n", totals[i]);
	}

	return 0;
}
