#include <iostream>
using namespace std;
int main(int q, char* argv[], char* env[]) {
	int i;
	cout << "Command line arguments: " << endl;
	for (i = 0; i < q; i++) {
		cout << i + 1 << ": " << argv[i] << endl;
	}
	cout << "Environment Variables: " << endl;
	for (i = 0; env[i]; i++) {
		cout << i + 1 << ": " << env[i] << endl;
	}
	return 0;
}