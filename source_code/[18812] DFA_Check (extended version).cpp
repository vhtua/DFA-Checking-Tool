// Full name: Vu Hoang Tuan Anh
// ID: 18812
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ================= prototype functions ==================
void print_table(int** arTrans, int row, int col, char arEdgeVal[]);
void print_final_state_info(int arFinalState[], int sizeF);
bool validS(int q0, string s, int arFinalState[], int sizeF, int **arTrans, char arEdgeVal[], int sizeE, int* stop_state);

// ================== MAIN WORKSPACE =====================
int main() {
	int m, n;		
	cout << "(?) Enter numbers of rows of Transition Table: " << endl;
	cout << "Rows = ";			cin >> m;
	cout << "Columns = ";		cin >> n;
	int** arTrans = new int* [m];
		for (int i = 0; i < m; ++i)
			arTrans[i] = new int[n];

	// input array elements
	for (int i = 0; i < m; ++i)
		for(int j = 0; j < n; j++) {
			cout << "ArTrans[row " << i + 1 << "][col " << j + 1 << "] = ";
			cin >> arTrans[i][j];
			if (arTrans[i][j] >= m) {
				cout << "\n--> Invalid state value! Program exited!" << endl;
				system("pause");
				return 1;
			}
		}

	// generate arEdgeVal[]
	char arEdgeVal[n]; 
	for (int i = 0; i < n; ++i) {
		arEdgeVal[i] = 'a' + i;
	}

	// input the final state arr
	int sizeF;
	cout << "(?) Enter the number of final states: ";		
	cin >> sizeF;

	int arFinalState[sizeF];
	for (int i = 0; i < sizeF; ++i) {
		cout << "Enter final state q#: ";						
		cin >> arFinalState[i];			 
	}

    // input string
    string str;
    cout << "\n(?) Enter the string: ";		
    cin >> str;


    // DFA Working
    // output
    cout << "\n======================= Result =======================" << endl;
    print_table(arTrans, m, n, arEdgeVal);
    //print_final_state_info(arFinalState, sizeF);

    int stop_state;
    bool a_res = validS(0, str, arFinalState, sizeF, arTrans, arEdgeVal, n, &stop_state);
    cout << "\n--> The DFA stop at state q" << stop_state << endl;
    //cout << a_res << endl;
    if (a_res == 1) {
    	cout << "--> The string is accpeted by the given DFA!\n";
    }
    else {
        cout << "--> The string is not accpeted by the given DFA!\n";
    }
  

	// clean the memory
	for (int i = 0; i < m; ++i) {
		delete[] arTrans[i];
	}
	
	system("pause");
	return 0;
}


// =================== DETAILED FUNCTIONS =========================================
void print_table(int** arTrans, int row, int col, char arEdgeVal[]) {
	cout << "--> The Transition Table: " << endl;
	cout << "      ";
	for (int i = 0; i < col; ++i) {
		cout << arEdgeVal[i] << "     ";
	}
	cout << endl;

	for (int i = 0; i < row; ++i) {
		cout << "q" << i << "    ";
        for (int j = 0; j < col; ++j) 
			cout << "q" << arTrans[i][j] << "    ";
		cout << endl;
    }

}

void print_final_state_info(int arFinalState[], int sizeF) {
	cout << "(Final States Array) =  ";
	for (int i = 0; i < sizeF; ++i)
        cout << "q" << arFinalState[i] << " ";
    puts("\n");
}


bool validS(int q0, string s, int arFinalState[], int sizeF, int **arTrans, char arEdgeVal[], int sizeE, int* stop_state) {
	bool res = false;
	int len = s.size();
	int qt = q0;
	int i, j;

	for (i = 0; i < len; i++) { 			//traverse S
		for (j = 0; j < sizeE; j++) 		//find s[i]
			if (arEdgeVal[j] == s.at(i)) 
				break;
		
		int next_vertex = arTrans[qt][j];
		qt = next_vertex;
	}

	*stop_state = qt;
	//check if qt in arFinalState
	for(i = 0; i < sizeF; i++)
		if(qt == arFinalState[i]) break;
	
	if(i < sizeF) return true;

	return res;
}
