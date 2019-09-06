#include<iostream>
#include<vector>
#include<algorithm>
/*---------------------------------------*/
using namespace std;
void show(vector<vector<char>>&answer);
/*---------------------------------------*/
bool fill_board(vector<vector<char>>& board,vector<vector<int>>& empty_place,int position_number,const int& empty_place_number);
vector<char> look_for_possible(const vector<vector<char>>& board,const int row,const int column);
/*---------------------------------------*/
int main()
{
	vector<vector<char>> board;
	board.push_back(vector<char>({'.','7','.', '.','4','5', '.','.','.'}));
	board.push_back(vector<char>({'9','2','.', '.','.','.', '1','.','.'}));
	board.push_back(vector<char>({'.','.','5', '.','.','8', '.','.','7'}));
	
	board.push_back(vector<char>({'.','.','.', '.','.','.', '6','9','.'}));
	board.push_back(vector<char>({'.','.','.', '7','.','.', '.','.','.'}));
	board.push_back(vector<char>({'.','1','.', '4','5','.', '.','.','.'}));
	
	board.push_back(vector<char>({'2','.','.', '.','.','.', '4','6','.'}));
	board.push_back(vector<char>({'.','.','.', '.','.','.', '.','.','1'}));
	board.push_back(vector<char>({'6','9','.', '.','2','.', '.','3','.'}));
	//---------------在上述中修改初始化数独，空白处用英文'.'代替-----------------
	show(board);
	vector<vector<int>> empty_place;
    for (int i=0;i<9;++i)
        for (int j=0;j<9;++j)
            if (board.at(i).at(j)=='.')
                empty_place.push_back(vector<int>({i,j}));
	fill_board(board,empty_place,0,empty_place.size());
	cout<< "After solving" << endl;
	show(board);   
}
		
/*---------------------------------------*/
bool fill_board(vector<vector<char>>& board,vector<vector<int>>& empty_place,int position_number,const int& empty_place_number)
{
	if (position_number==empty_place_number)
		return true;
	vector<char> possible_char(look_for_possible(board,empty_place.at(position_number).at(0),empty_place.at(position_number).at(1)));
	int possible_char_size=possible_char.size();
	if (possible_char_size==0)
		return false;
	for (int i=0;i<possible_char_size;++i)
	{
		board.at(empty_place.at(position_number).at(0)).at(empty_place.at(position_number).at(1))=possible_char.at(i);
		if (fill_board(board,empty_place,position_number+1,empty_place_number))
			return true;
		else
			board.at(empty_place.at(position_number).at(0)).at(empty_place.at(position_number).at(1))='.';		
	}
	return false;	
}
vector<char> look_for_possible(const vector<vector<char>>& board,const int row,const int column)
{
	char value; 
	vector<int> possible_int;
	for (int i=0;i<9;++i)
	{
		value=board.at(row).at(i);
		if (value!='.')
			possible_int.push_back(int(value-'0'));
		value=board.at(i).at(column);
		if (value!='.')
			possible_int.push_back(int(value-'0'));
	}
	int row_left=row,row_right=row,column_left=column,column_right=column;
    while(row_left%3!=0)
    	--row_left;
    while((row_right+1)%3!=0)
    	++row_right;
    while(column_left%3!=0)
    	--column_left;
    while((column_right+1)%3!=0)
    	++column_right;
    for(;row_left<=row_right;++row_left)
		for(int i=column_left;i<=column_right;++i)
		{
			value=board.at(row_left).at(i);
			if (value!='.')
				possible_int.push_back(int(value-'0'));
		}
	vector<char> possible_char;
	for (int i=1;i<10;++i)
		if (find(possible_int.begin(),possible_int.end(),i)==possible_int.end())
			possible_char.push_back(char(i+'0'));
	return possible_char;
}


/*---------------------------------------*/
void show(vector<vector<char>>&answer)
{
	int answer_size=answer.size();
	int single_answer_size;
	cout << "-------" << endl;
	for (int i=0;i<answer_size;++i)
	{
		if (i!=0 &&i%3==0)
			cout << endl;
		single_answer_size=answer.at(i).size();
		for (int j=0;j<single_answer_size;++j)
		{
			if (j!=0 && j%3==0)
				cout<< "  ";
			cout << answer.at(i).at(j) << " ";
		}
			
		cout << endl;
	}
	cout << "-------" << endl;
}
