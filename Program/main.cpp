// Lab_10.1
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int count_strs(FILE *stream) {
	char tmp[11], *pos2, *pos;
	int count = 0;
	while (!feof(stream)) {
		memset(tmp, 0, 11);
		fgets(tmp, 11, stream);
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
			fseek(stream, -2, SEEK_CUR);
	}
	return count;
}

void main() {
	char t[256];

	cout << "Input filename: "; cin >> t;

	FILE* fp;
	if ((fp = fopen(t, "r")) != NULL) {
		cout << "Count strs in file: " << count_strs(fp);
		fclose(fp);
	}
	else cout << "Incorrect file name!";
	
	cout << endl;
}