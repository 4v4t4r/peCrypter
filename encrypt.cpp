//encrypt shellcode prior to storing in stub
//store in shellcodeEncrypted.txt
//copy into runPE.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Real PE shellcode dump here - fix length also
const int length = 2;
unsigned char rawData[length] = {
	0x00, 0xff
};


void crypt(unsigned char rawData[], int length)
{
	char key = 0x42;
	for (int i = 0; i < length; i++)
	{
		rawData[i] = (char)(rawData[i] ^ key);
	}
}

struct HexCharStruct
{
	unsigned char c;
	HexCharStruct(unsigned char _c) : c(_c) { }
};

inline std::ostream& operator<<(std::ostream& o, const HexCharStruct& hs)
{
	return (o << std::hex << (int)hs.c);
}

inline HexCharStruct hex(unsigned char _c)
{
	return HexCharStruct(_c);
}

int main()
{
	ofstream output;
	output.open("shellcodeEncrypted.txt");
	crypt(rawData, length);
	output << "unsigned char rawData[" << to_string(length) << "]" \
		<< " = { ";
	for (int i = 0; i < length; i++)
	{
		output << "0x" << hex(rawData[i]) << ",";
		if (i % 20 == 0)
		{
			output << endl;
		}
	}
	output << "};";
}

