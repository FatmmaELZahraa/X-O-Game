#include<iostream>
using namespace std;
char arr[3][3] = { {'1','2','3'},
				   { '4', '5', '6'},
				   {   '7', '8', '9' } };
void display() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
char player = 'x';
void play() {
	cout << "choose your place" << " " << player;
	char z;
	cin >> z;
	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			if (arr[i][j] == z)
				arr[i][j] = player;

		}
	}
	if (player == 'x') {

		player = 'o';
	}
	else if (player == 'o') {

		player = 'x';

	}
}
char winner_ROWS() {

	for (int i = 0; i < 3; i++) {
		int cx = 0;
		int co = 0;
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == 'x') {
				cx++;

			}
			else if (arr[i][j] == 'o') {
				co++;

			}
			if (cx == 3)
				return 'x';
			else if (co == 3)
				return 'o';

		}

	}
	for (int i = 0; i < 3; i++) {
		int cx = 0;
		int co = 0;
		for (int j = 0; j < 3; j++) {

			if (arr[j][i] == 'x') {
				cx++;

			}
			else if (arr[j][i] == 'o') {
				co++;

			}
			if (cx == 3)
				return 'x';
			else if (co == 3)
				return 'o';

		}

	}
	int cx = 0;
	int co = 0;
	for (int i = 0; i < 3; i++) {

		if (arr[i][i] == 'x') {
			cx++;
		}
		else if (arr[i][i] == 'o') {
			co++;
		}
		if (cx == 3)
			return 'x';
		else if (co == 3)
			return 'o';

	}
	cx = 0;
	co = 0;
	for (int i = 0, j = 2; i < 3; i++, j--) {


		if (arr[i][j] == 'x')
			cx++;
		else if (arr[i][j] == 'o')
			co++;

		if (cx == 3)

			return 'x';
		else if (co == 3)
			return 'o';
	}
	int pos = 0;
	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			if (arr[i][j] != 'x' && arr[i][j] != 'o') {
				pos++;

			}



		}

	}
	if (pos == 0) {

		return 'N';


	}
	else {
		return '.';
	}

}
int main() {
	while (1) {

		system("cls");
		display();
		play();
		display();
		if (winner_ROWS() == 'x') {
			cout << "  X The Winner  ";
			break;
		}
		else if (winner_ROWS() == 'o') {
			cout << " O The Winner  ";
			break;
		}
		else if (winner_ROWS() == 'N') {
			cout << " NO WINNER";
			break;
		}
	}
}
