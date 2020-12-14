// Lab_10.1
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int count_strs(ifstream &stream) {
	char tmp[11], *pos2, *pos;
	int count = 0;
	while (!stream.eof()) {
		memset(tmp, 0, 11);
		stream.read(tmp, 10);
		pos2 = tmp;
		while (pos = strchr(pos2, ',')) {
			if (pos - tmp < strlen(tmp) - 2) {
				if (*(pos + 2) == '-') {
					count++;
					pos2 = pos + 3;
					continue;
				}
				pos2 = pos + 1;
			}
			else break;
		}
		if (strlen(tmp) == 10)
			stream.seekg(-2, ios_base::cur);
	}
	return count;
}

void main() {
	string t;

	cout << "Input filename: "; cin >> t;

	ifstream stream(t);
	if (stream.is_open()) {
		cout << "Count strs in file: " << count_strs(stream);
		stream.close();
	}
	else cout << "Incorrect file name!";
	cout << endl;
}