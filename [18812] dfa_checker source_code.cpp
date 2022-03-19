// Full name: Vu Hoang Tuan Anh
// ID: 18812

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ================= prototype functions ==================
void print_table(int** arr_2d, int rows);
void print_final_state_info(vector<int> f_state);
int dfa(int** arTrans, int rows, string str, vector<int> f_state);
void dfa_res(int current_state, vector<int> f_state);


// ================== MAIN WORKSPACE =====================

int main() {
	int m, n = 2;		
	// row m
	// col n = 2 (Default --> 0 and 1)
	cout << "(?) Enter numbers of rows of Transition Table: " << endl;
	cout << "Rows = ";			cin >> m;
	//cout << "Columns = ";		cin >> n;
	int** arTrans = new int* [m];
		for (int i = 0; i < m; ++i)
			arTrans[i] = new int[n];

	// input array elements
	for (int i = 0; i < m; ++i)
		for(int j = 0; j < n; j++) {
			cout << "ArTrans[row " << i + 1 << "][col " << j + 1 << "] = ";
			cin >> arTrans[i][j];

			/* --> uncomment to strict the number of states
			if (arTrans[i][j] >= m) {
				cout << "\n--> Invalid state value! Program exited!" << endl;
				return 1;
			}

			*/
		}

	/*  --> uncomment to see the raw data of the transition table
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << arTrans[i][j] << " ";
		cout << endl;
	}
	*/

	int final_state_num;
	int f_input;
	vector<int> final_state;
	cout << "(?) Enter the number of final states: ";		cin >> final_state_num;

	for (int i = 0; i < final_state_num; ++i) {
		cout << "Enter final state q_";						cin >> f_input;
		final_state.push_back(f_input); 				 
	}

    // input string
    string str;
    cout << "\n(?) Enter the string: ";		cin >> str;		//cout << str;


    // DFA Working
    // output
    cout << "\n======================= Result =======================" << endl;
    print_table(arTrans, m);
    print_final_state_info(final_state);
    dfa_res(dfa(arTrans, m, str, final_state), final_state);
    

	// clean the memory
	for (int i = 0; i < m; ++i) {
		delete[] arTrans[i];
	}
	
	system("pause");

	return 0;
}


// =================== DETAILED FUNCTIONS =========================================
void print_table(int** arr_2d, int rows) {
	cout << "\n---> Transition Table:" << endl;
	printf("+---------+-------+-------+\n");
    printf("| States  |   a   |   b   |\n");
    printf("+---------+-------+-------+\n");

    for (int i = 0; i < rows; ++i) {
        printf("| q%-6d |  q%-4d|  q%-4d|\n", i, arr_2d[i][0], arr_2d[i][1]); 
    }
    printf("+---------+-------+-------+\n");
}



void print_final_state_info(vector<int> f_state) {
	cout << "--> Final States are: ";
	for (int i = 0; i < f_state.size(); ++i)
        cout << "q" << f_state[i] << " ";
    puts("\n");
}


int dfa(int** arTrans, int rows, string str, vector<int> f_state) {
	int current_state = 0;
	//int pre_state = 0;
	//cout << str.size();

	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'a') 
			current_state = arTrans[current_state][0];
		else if (str[i] == 'b')
			current_state = arTrans[current_state][1]; 
	}

	return current_state;	
}


void dfa_res(int current_state, vector<int> f_state) {
		cout << "\n--> The DFA stopped at state q" << current_state;

		if (count(f_state.begin(), f_state.end(), current_state))
        	cout << "\n--> The string is accpeted by the given DFA!\n";
    	else
        	cout << "\n--> The string is not accpeted by the given DFA!\n";
}
