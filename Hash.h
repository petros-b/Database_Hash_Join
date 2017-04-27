#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;
#pragma once
class Hash
{
public:
	
	void get_hash(vector<vector<string>>vec, vector<vector<string>>vec2, string f, vector<vector<string>>& h_table, vector<vector<string>> &j_tbl);

	void print_table(vector<vector<string>> vec,int n);

	bool check_hash_result(vector<vector<string>> r1, vector<vector<string>> r2, vector<vector<string>> r3, int k1, int k2);

	void join_table(vector<vector<string>> rel_1, vector<vector<string>> rel_2, vector<vector<string>> &rel_3);


	Hash();
	~Hash();
};

