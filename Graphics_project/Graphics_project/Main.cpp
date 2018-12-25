#include"Display.h"

using namespace std;

int main() {
	cout<<"following are the controls \n D=default load\n w/s= rotate in x\nup/down=rotate in z \nleft/right rotate in y\n -/= zoom in out \n i/j/k/l pan\n r to 		input rotation rx ry rz\n t to translate x y z\n y to scalebut i doubt you will use it"<<endl;
	char x;
	cin >> x;
	Display display;
	display.entrypoint();
}