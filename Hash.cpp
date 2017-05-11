#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<functional>
#include "Hash.h"
using namespace std;

void Hash:: get_hash(vector<vector<string>>vec, vector<vector<string>> vec2, string f, vector<vector<string>> &h_table, vector<vector<string>> &join_tble) //accept which attribute(column) user wants to perform & obtain hash value for algorithm
{
	int final_val = 0;
	int var = vec[0].capacity();
	int var2 = vec2[0].capacity();//ask which column from 1st table to perform 
	cout << "Which column" << "(" << "1" << "-" << var << ")" << " would you like to select to do a join from table 1? i.e. 1 =" << " " << vec[0][0] << " " << "etc." << endl;
	cin.clear();
	cin >> f; //user enters which row they want to perform join on
	int val = stoi(f)-1;
	int val2 = 0;
	int h_val = 0,h_val2=0;
	bool truth = true;
	string get_val = "";
	bool test = true;
	h_table.resize(11, vector<string>(vec[0].capacity())); //creating hash table size based on tables being used for hash function 


	cout << "Which column" << "(" << "1" << "-" << var2 << ")" << " would you like to select to do a join from table 2? i.e. 1 =" << " " << vec2[0][0] << " " << "etc." << endl;
	cin >> val2;
	val2--;
	int counter = 0;

	while (truth != false)
	{

		if (val <= var) //check if user's input is within the col. size of the table
		{
			test=check_hash_result(vec, vec2, join_tble,val,val2); //check if eqi-join is possible from user's selected attr. from rel. 1 + 2
			if (test != true)
			{
				break;
			}
			
			for (int row=1; row < vec.size(); row++) // begin build phase 
			{
				size_t h = hash<string>{}(vec[row][val]); //obtain hash key from tuple's selected attr. needed to make join
				h_val = h % 10; 

				for (int col = 0; col < vec[0].capacity(); col++)
				{
					while (h_table[h_val][col] != "") // if cluster occurs, add tuple to next availalbe bucket in hash table (linear probing)
					{
						if (h_val == h_table.size())// if value reaches end of bucket, start at the beginning 
						{
							h_val = 0;
						}
						else 
						{
							h_val++;
						}
					}
					h_table[h_val][col] = vec[row][col]; //store tuple in the bucket of the hash table 
				}
			}

				for (int i = 1; i < h_table.size(); i++) // begin probe phase 
				{
					for (int row = 1; row < vec2.size(); row++)
					{
						size_t h2 = hash<string>{}(vec2[row][val2]); //obtain hash key from tuple's selected attr. needed to make join
						h_val2 = h2 % 10;

						if (h_table[i-1][val]!="" && h_table[i-1][val] == vec2[row][val2])
						{
							int a=row;
								for(int b=0;b<vec[0].capacity();b++) //insert all attr. from 1st relation
								{
									join_tble[a][b] = h_table[i-1][b];
									
								}
								for (int c = vec[0].capacity(); c < join_tble[0].capacity(); c++) //insert all attr. from 2nd relation into the joined table
								{
									join_tble[a][c] = vec2[row][counter];
									counter++;
								}
								counter = 0;
							
						} // end of if statement
						
					} // end of for loop
					
				} //end of for loop
				print_table(join_tble, 3);
			
			break; // end while loop after build phase 
		}

		else //if user doesn't answer an appropriate attr. number, repromt user to enter valid attr. no. 
		{
			cout << "invalid entry, please enter column 1 -" << " " << var << endl;
			cin >> f;
			val = stoi(f)-1;
		}
	}
}

void Hash::print_table(vector<vector<string>> vec, int num)
{
	int count = 0;
	cout << "Table" << " " << num << ":" << endl;
	cout << endl;
	for (int i = 0; i < vec[0].capacity(); i++)
	{
		cout <<setw(8)<< vec[0][i]<< "|";
	}
	cout << endl;
	cout << setw(8) << "---------------------------------------------------------------------------------" << endl;

	for (int j = 1; j < vec.size(); j++)
	{
		if (vec[j][0] == "" && j<vec.size())
		{
			j++;
			
		}
		
		for (int i = 0; i < vec[1].capacity(); i++)
		{
			if (j >= vec.size())
			{
				j--;
			}
			cout <<setw(8)<< vec[j][i] << "|";
			count++;
		}
		cout << endl;
		cout << setw(8) << "---------------------------------------------------------------------------------" << endl;
	}
}

bool Hash::check_hash_result(vector<vector<string>> r1, vector<vector<string>> r2, vector<vector<string>> r3, int key1, int key2)
{
	string col1, col2 = "";
	col1 = r1[0][key1];
	col2 = r2[0][key2];
	int i = 0;


	if (col1 != col2) //check if join operation is possible based on columns selected from table 1 + 2
	{
		cout << "join has returned no results:" << " " <<"table 1."<< r1[0][key1] << " " << " +" << " " <<"table 2."<< r2[0][key2] << endl;
		print_table(r3, 3);
		i++;
		return false;
	}
	else
	{
		return true; // if join is possible b/t both attr from relations 1 + 2 return true to continue on w/ join alg.
	}
	
	
}

void Hash::join_table(vector<vector<string>> rel_1, vector<vector<string>> rel_2, vector<vector<string>>& rel_3)
{
	int table_size = rel_1.size() + rel_2.size();
	int col_size = rel_1[0].capacity() + rel_2[0].capacity();

	rel_3.resize(table_size, vector<string>(col_size)); //creates all joined attributes/table size for equi-join

		for (int j = 0; j < rel_1[0].capacity(); j++) //populate the attr. from relation 1
		{
			rel_3[0][j] = rel_1[0][j];

		}
		int count = 0;
		for (int k = rel_1[0].capacity(); k < rel_3[0].capacity(); k++) //populate the attr. from relation 2 
		{
			
			rel_3[0][k] = rel_2[0][count];
			count++;
		}
	
}


Hash::Hash()
{
}


Hash::~Hash()
{
}
