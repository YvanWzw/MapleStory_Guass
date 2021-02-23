#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstdlib>
#include <ctime>
#include<vector>
#include<algorithm>
#include <windows.h>
#include<iomanip>
using namespace std;

//總條目數
const int totalItem = 19;

class node
{
public:
	int firstNum;
	int secondNum;
	int thridNum;
	int forthNum;
};

vector<node> vec;
vector<node> deg;

void test()
{
	vector<int> ans;
	//第一次隨機，1`totalItem
	int firstItem = (rand() % (totalItem - 1 + 1)) + 1;
	ans.push_back(firstItem);


	//第二次隨機
	int secondItem = 0;
	if (firstItem == 1)
	{
		secondItem = (rand() % (totalItem - 2 + 1)) + 2;
	}
	else if (firstItem == totalItem)
	{
		secondItem = (rand() % (totalItem - 1 - 1 + 1)) + 1;
	}
	else
	{
		int sed = rand() % 2;
		if (sed == 0)
		{
			secondItem = (rand() % (firstItem - 1 - 1 + 1)) + 1;
		}
		else
		{
			secondItem = (rand() % (totalItem - (firstItem + 1) + 1)) + (firstItem + 1);
		}
	}
	ans.push_back(secondItem);
	sort(ans.begin(), ans.end());

	//第三次隨機
	int thridItem = 0;
	int randVal1 = ans[0] - 1 - 1 + 1;//1`(ans[0]-1)
	int randVal2 = ans[1] - 1 - (ans[0] + 1) + 1;//(ans[0]+1)`(ans[1]-1)
	int randVal3 = totalItem - (ans[1] + 1) + 1;//(ans[1]+1)`totalItem
	int randNum = 0;
	int randVN1, randVN2, randVN3 = 0;
	if (randVal1 != 0)
	{
		randVN1 = (rand() % (ans[0] - 1 - 1 + 1)) + 1;
		randNum++;
	}
	if (randVal2 != 0)
	{
		randVN2 = (rand() % (ans[1] - 1 - (ans[0] + 1) + 1)) + (ans[0] + 1);
		randNum++;
	}
	if (randVal3 != 0)
	{
		randVN3 = (rand() % (totalItem - (ans[1] + 1) + 1)) + (ans[1] + 1);
		randNum++;
	}
	int sed = rand() % randNum;
	if (randVal1 == 0 && randVal2 == 0)
		thridItem = randVN3;
	else if (randVal2 == 0 && randVal3 == 0)
		thridItem = randVN1;
	else if (randVal1 == 0 && randVal3 == 0)
		thridItem = randVN2;
	else if (randVal1 == 0)
		thridItem = sed == 0 ? randVN2 : randVN3;
	else if (randVal2 == 0)
		thridItem = sed == 0 ? randVN1 : randVN3;
	else if (randVal3 == 0)
		thridItem = sed == 0 ? randVN1 : randVN2;
	else
	{
		if (sed == 0)
			thridItem = randVN1;
		else if (sed == 1)
			thridItem = randVN2;
		else if (sed == 2)
			thridItem = randVN3;
	}
	ans.push_back(thridItem);
	sort(ans.begin(), ans.end());

	//第四次隨機
	int forthItem = 0;
	randVal1 = ans[0] - 1 - 1 + 1;//1`(ans[0]-1)
	randVal2 = ans[1] - 1 - (ans[0] + 1) + 1;//(ans[0]+1)`(ans[1]-1)
	randVal3 = ans[2] - 1 - (ans[1] + 1) + 1;//(ans[1]+1)`ans[2]-1
	int randVal4 = totalItem - (ans[2] + 1) + 1;//(ans[2]+1)`totalItem
	randNum = 0;
	randVN1 = 0;
	randVN2 = 0;
	randVN3 = 0;
	int randVN4 = 0;
	if (randVal1 != 0)
	{
		randVN1 = (rand() % (ans[0] - 1 - 1 + 1)) + 1;
		randNum++;
	}
	if (randVal2 != 0)
	{
		randVN2 = (rand() % (ans[1] - 1 - (ans[0] + 1) + 1)) + (ans[0] + 1);
		randNum++;
	}
	if (randVal3 != 0)
	{
		randVN3 = (rand() % (ans[2] - 1 - (ans[1] + 1) + 1)) + (ans[1] + 1);
		randNum++;
	}
	if (randVal4 != 0)
	{
		randVN4 = (rand() % (totalItem - (ans[2] + 1) + 1)) + (ans[2] + 1);
		randNum++;
	}
	sed = rand() % randNum;
	if (randVal1 == 0 && randVal2 == 0 && randVal3 == 0)
		forthItem = randVN4;
	else if (randVal1 == 0 && randVal2 == 0 && randVal4 == 0)
		forthItem = randVN3;
	else if (randVal1 == 0 && randVal3 == 0 && randVal4 == 0)
		forthItem = randVN2;
	else if (randVal2 == 0 && randVal3 == 0 && randVal4 == 0)
		forthItem = randVN1;
	else if (randVal1 == 0 && randVal2 == 0)
		forthItem = sed == 0 ? randVN3 : randVN4;
	else if (randVal1 == 0 && randVal3 == 0)
		forthItem = sed == 0 ? randVN2 : randVN4;
	else if (randVal1 == 0 && randVal4 == 0)
		forthItem = sed == 0 ? randVN2 : randVN3;
	else if (randVal2 == 0 && randVal3 == 0)
		forthItem = sed == 0 ? randVN1 : randVN4;
	else if (randVal2 == 0 && randVal4 == 0)
		forthItem = sed == 0 ? randVN1 : randVN3;
	else if (randVal3 == 0 && randVal4 == 0)
		forthItem = sed == 0 ? randVN1 : randVN2;
	else if (randVal1 == 0)
	{
		if (sed == 0)
			forthItem = randVN2;
		else if (sed == 1)
			forthItem = randVN3;
		else if (sed == 2)
			forthItem = randVN4;
	}
	else if (randVal2 == 0)
	{
		if (sed == 0)
			forthItem = randVN1;
		else if (sed == 1)
			forthItem = randVN3;
		else if (sed == 2)
			forthItem = randVN4;
	}
	else if (randVal3 == 0)
	{
		if (sed == 0)
			forthItem = randVN1;
		else if (sed == 1)
			forthItem = randVN2;
		else if (sed == 2)
			forthItem = randVN4;
	}
	else if (randVal4 == 0)
	{
		if (sed == 0)
			forthItem = randVN1;
		else if (sed == 1)
			forthItem = randVN2;
		else if (sed == 2)
			forthItem = randVN3;
	}
	else
	{
		if (sed == 0)
			forthItem = randVN1;
		else if (sed == 1)
			forthItem = randVN2;
		else if (sed == 2)
			forthItem = randVN3;
		else if (sed == 3)
			forthItem = randVN4;
	}
	ans.push_back(forthItem);
	sort(ans.begin(), ans.end());



	node nod;
	nod.firstNum = ans[0];
	nod.secondNum = ans[1];
	nod.thridNum = ans[2];
	nod.forthNum = ans[3];
	vec.push_back(nod);
}


string readTxt(string file)
{
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open());

	string s;
	getline(infile, s);
	infile.close();
	return s;
}



int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	string weapon[19] = {
		"STR","DEX","INT","LUK","STR+DEX","STR+INT","STR+LUK","DEX+INT","DEX+LUK",
		"INT+LUK","HP上限","MP上限","裝備需求等級減少","防御力","攻擊力","魔法攻擊力",
		"BOSS","總傷害","全屬性"
	};



	//string circleTimeStr = readTxt("circleTimeStr.txt");

	//int circleTime = atoi(circleTimeStr.c_str());

	int circleTime = 10000;

	for (int i = 0; i < circleTime; i++)
	{
		test();
	}

	for (int i = 0; i < circleTime; i++)
	{
		int randDeg = rand() % 100 + 1;
		node nod;
		if (randDeg >0&&randDeg<4)
			nod.firstNum = 7;
		else if (randDeg >= 4 && randDeg < 10)
			nod.firstNum = 6;
		else if (randDeg >=10 && randDeg < 22)
			nod.firstNum = 5;
		else if (randDeg >=22 && randDeg < 46)
			nod.firstNum = 4;
		else
			nod.firstNum = 3;


		randDeg = rand() % 100 + 1;
		if (randDeg > 0 && randDeg < 4)
			nod.secondNum = 7;
		else if (randDeg >= 4 && randDeg < 10)
			nod.secondNum = 6;
		else if (randDeg >= 10 && randDeg < 22)
			nod.secondNum = 5;
		else if (randDeg >= 22 && randDeg < 46)
			nod.secondNum = 4;
		else
			nod.secondNum = 3;

		randDeg = rand() % 100 + 1;
		if (randDeg > 0 && randDeg < 4)
			nod.thridNum = 7;
		else if (randDeg >= 4 && randDeg < 10)
			nod.thridNum = 6;
		else if (randDeg >= 10 && randDeg < 22)
			nod.thridNum = 5;
		else if (randDeg >= 22 && randDeg < 46)
			nod.thridNum = 4;
		else
			nod.thridNum = 3;

		randDeg = rand() % 100 + 1;
		if (randDeg > 0 && randDeg < 4)
			nod.forthNum = 7;
		else if (randDeg >= 4 && randDeg < 10)
			nod.forthNum = 6;
		else if (randDeg >= 10 && randDeg < 22)
			nod.forthNum = 5;
		else if (randDeg >= 22 && randDeg < 46)
			nod.forthNum = 4;
		else
			nod.forthNum = 3;

		deg.push_back(nod);
	}


	int count1 = 0;//mg
	int count2 = 0;//mg+boss
	int count3 = 0;//t7 mg
	int count4 = 0;//t4up mg
	int count5 = 0;//t4up boss
	int count6 = 0;//t4up mg+boss
	int count7 = 0;//t3up mg + t4up boss

	for (int i = 0; i < circleTime; i++)
	{
		if (vec[i].firstNum == 16 || vec[i].secondNum == 16 || vec[i].thridNum == 16 || vec[i].forthNum == 16)
		{
			count1++;
			if ((deg[i].firstNum >= 3 && vec[i].firstNum == 16) || (deg[i].secondNum >= 3 && vec[i].secondNum == 16) || (deg[i].thridNum >= 3 && vec[i].thridNum == 16) || (deg[i].forthNum >= 3 && vec[i].forthNum == 16))
			{
				if ((deg[i].firstNum >= 4 && vec[i].firstNum == 17) || (deg[i].secondNum >= 4 && vec[i].secondNum == 17) || (deg[i].thridNum >= 4 && vec[i].thridNum == 17) || (deg[i].forthNum >= 4 && vec[i].forthNum == 17))
				{
					count7++;
				}
			}
			if ((deg[i].firstNum >= 4 && vec[i].firstNum == 16) || (deg[i].secondNum >= 4 && vec[i].secondNum == 16) || (deg[i].thridNum >= 4 && vec[i].thridNum == 16) || (deg[i].forthNum >= 4 && vec[i].forthNum == 16))
			{
				count4++;
				if ((deg[i].firstNum >= 4 && vec[i].firstNum == 17) || (deg[i].secondNum >= 4 && vec[i].secondNum == 17) || (deg[i].thridNum >= 4 && vec[i].thridNum == 17) || (deg[i].forthNum >= 4 && vec[i].forthNum == 17))
				{
					count6++;
				}
			}
			if (vec[i].firstNum == 17 || vec[i].secondNum == 17 || vec[i].thridNum == 17 || vec[i].forthNum == 17)
			{
				count2++;
			}
			if ((deg[i].firstNum ==7 && vec[i].firstNum == 16) || (deg[i].secondNum == 7 && vec[i].secondNum == 16) || (deg[i].thridNum == 7 && vec[i].thridNum == 16) || (deg[i].forthNum == 7 && vec[i].forthNum == 16))
			{
				count3++;
			}
		}
		if ((deg[i].firstNum >= 4 && vec[i].firstNum == 17) || (deg[i].secondNum >= 4 && vec[i].secondNum == 17) || (deg[i].thridNum >= 4 && vec[i].thridNum == 17) || (deg[i].forthNum >= 4 && vec[i].forthNum == 17))
		{
			count5++;
		}
	}

	for (int i = 0; i < circleTime; i++)
	{
		if ((deg[i].firstNum >= 4 && vec[i].firstNum == 16) || (deg[i].secondNum >= 4 && vec[i].secondNum == 16) || (deg[i].thridNum >= 4 && vec[i].thridNum == 16) || (deg[i].forthNum >= 4 && vec[i].forthNum == 16))
		{
			cout << "※";
		}
		if ((deg[i].firstNum >= 4 && vec[i].firstNum == 17) || (deg[i].secondNum >= 4 && vec[i].secondNum == 17) || (deg[i].thridNum >= 4 && vec[i].thridNum == 17) || (deg[i].forthNum >= 4 && vec[i].forthNum == 17))
		{
			cout << "※";
		}
		cout << i + 1 << ":  ";
		cout<<"(T"<<deg[i].firstNum<<")"<< weapon[vec[i].firstNum - 1] << "   ";
		cout << "(T" << deg[i].secondNum << ")" << weapon[vec[i].secondNum - 1] << "   ";
		cout << "(T" << deg[i].thridNum << ")" << weapon[vec[i].thridNum - 1] << "   ";
		cout << "(T" << deg[i].forthNum << ")" << weapon[vec[i].forthNum - 1] << endl;
	}



	cout << "共出現魔法攻擊力次數計:" << count1 << "次" << endl;
	cout << "共出現魔法攻擊力結合BOSS次數計:" << count2 << "次" << endl;
	cout << "共出現T7魔法攻擊力次數計:" << count3 << "次" << endl;
	cout << "共出現T4以上BOSS次數計" << count5 << "次" << endl;
	cout << "共出現T4以上魔法攻擊力次數計:" << count4 << "次" << endl;
	cout << "共出現t4以上魔法攻擊力結合BOSS次數計:" << count6 << "次" << endl;
	cout << "共出現T3及以上魔法攻擊力結合T4及以上BOSS次數計" << count7 << "次" << endl;


	system("pause");
	return 0;
}