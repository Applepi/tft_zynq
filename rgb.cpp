#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
using namespace std;
int main()
{
	// 0x00000 to 0x5DC00 
	// 5:0 r 11:6 g 15:11 RGB565 
	int r = 0; // 0 - 31
	int g = 0; // 0 - 63
	int b = 0; // 0 - 31
	int x = 800; // 0 - 799 0x320
	int y = 480; // 0 - 479 0x1E0
	int addr = 0;
	int data[0x5DC00];
	srand(time(NULL)); // bloat
	for (int i=0; i < y; i++)
	{
		for (int j=0; j < x; j++)
		{
			r = rand()%31; // needs better solution
			g = rand()%63; // "
			b = rand()%31; // "
			//r = 0b11111;
			//g = 0b111111;
			//b = 0b11111;
			addr++;
			int buffer = 0;
			buffer = ((((buffer ^ r) << 6) ^ g )<< 5 )^ b; // bitsift concat into buffer
			cout << bitset <16> (buffer) << endl; // debug output 
			data[j] = buffer;
			cout << data[j] << endl; // debug output
		}


	}

	cout << addr << endl; // final addr debug output
	return 0; 
}
