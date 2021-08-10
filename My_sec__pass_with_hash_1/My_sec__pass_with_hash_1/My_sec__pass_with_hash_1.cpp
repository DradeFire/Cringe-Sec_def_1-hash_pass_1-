#include <iostream>
using namespace std;

/*
* 1.1 - create 8 4-el blocks (32 sym all) 
* 1.2 - take 2 sym from input str + 2 random sym
* 2 - xor every str with some 4-sym-str
* 3 - swap 1-8,2-7,3-6,4-5 blocks
* 4 - swap 1-3,2-4 sym
* 5 - nice
*/
void hashing(char * h_str)
{
	char hash[33], tmp_c;
	int tmp = 0;
	char xorus[5] = "KtSn";

	hash[0] = h_str[0]; hash[1] = h_str[1];
	hash[4] = h_str[2];hash[5] = h_str[3];
	hash[8] = h_str[4];hash[9] = h_str[5];
	hash[12] = h_str[6];hash[13] = h_str[7];
	hash[16] = h_str[8];hash[17] = h_str[9];
	hash[20] = h_str[10];hash[21] = h_str[11];
	hash[24] = h_str[12];hash[25] = h_str[13];
	hash[28] = h_str[14];hash[29] = h_str[15];

	for (int i = 0;i < 32;i++) //1
	{
		tmp++;
		if (tmp == 3)
		{
			hash[i] = '\r';
			continue;
		}
		if (tmp == 4)
		{
			hash[i] = '\n';
			tmp = 0;
			continue;
		}
	}

	for (int i = 0; i < 32;) //2
	{
		for (int j = 0; j < 4; j++)
		{
			hash[i] = hash[i] xor xorus[j];
			i++;
		}
	}

	for (int i = 0; i < 32; i++)
	{
		tmp_c = hash[i];
		hash[i] = hash[31 - i];
		hash[31 - i] = tmp_c;
	}

	for (int i = 0; i < 32;) //4
	{
		tmp_c = hash[i + 1];
		hash[i + 1] = hash[i + 3];
		hash[i + 3] = tmp_c;
		i+=4;
	}
	cout << hash << endl;

	if(strcmp(hash, "!d^8d^") == 0) 
		cout << "Take your cookie";
}


int main()
{
	char lol[17];
	cout << "Give me pass(16 sym)\n";
	gets_s(lol);
	hashing(lol);

}
