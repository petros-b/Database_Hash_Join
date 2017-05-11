/* Author: Petros Besieris
Creation Date: 4/12/17
Modification Date: 4/18/17
Purpose: to implement hash function amongst 2 relational tables
*/
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<functional>
#include "Hash.h"
using namespace std;

const int R1_ROW = 5;
const int R1_COL = 3;


int main()
{
	string input;
	int in = 0;
	bool truth = true;
	Hash t1;


	vector<vector<string>> R1{
	{{"ID"},{"F_NAME"},{"L_NAME"},{"JOB_TITLE"}}, //First relational table
	{{"1"},{"JOHN"},{"SMITH"},{"DOCTOR"}},
	{{"2"},{"JOE"},{"LOUIS"},{"BOXER"} },
	{{"3"},{"PETROS"},{"BESIERIS"},{"DBA"}},
	{{"8"},{"JAMES"},{"BOND"},{"AGENT"}} };
	vector<vector<string>> R2{
		{{"ID"},{"HOURS"},{"SALARY"},{"JOB_LOC"},{"JOB_TITLE"} },  //second relational table
		{{"3"},{"40"},{"90000"},{"DETROIT"},{"DBA"}},
		{{"8"},{"25"},{"68000"},{"L.A."},{"ACTOR"}},
		{{"1"},{"40"},{"85760"},{"NEW YORK"},{"DOCTOR"}},
		{{"9"},{"60"},{"100000"},{"DETROIT"},{"IT DIRECTOR"}},
		{{"2"},{"20"},{"80000"},{"NEW YORK"},{"BOXER"}},
		{{"4"},{"90"},{"10000000"},{"LONDON"},{"AGENT"}} };

	vector < vector<string >> hash_table;  //hash table to hold tuples in accomidating buckets
	vector<vector<string>> join_table; //final join table result

	while (truth != false) //ask user to view tables or not
	{

		cout << "Would you like to view the tables(yes/no)?" << endl;
		cin >> input;

		if (input == "yes" || input == "y" || input == "Yes"|| input=="YES") // if user only wants tbl 1 printed
		{
			t1.print_table(R1, 1);
			t1.print_table(R2, 2);
			truth = false;
		}
		else if (input == "no"||input=="n" || input=="No" || input=="NO")// if user wants only table 2 printed
		{
			truth = false;
		}
		else
		{
			cout << "Invalid entry, please enter yes or no." << endl;
			cout << endl;
		}
	}

	t1.join_table(R1, R2, join_table); // create joined table 

	t1.get_hash(R1,R2,input,hash_table,join_table); //obtains the hashing key to divide the table's attr./col in appropriate bucket 
			
	system("pause");
	return 0;
}


