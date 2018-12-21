#include"Display.h"

using namespace std;

int main() {
	Display* display= new Display(1280,720);
	display->entrypoint();
}