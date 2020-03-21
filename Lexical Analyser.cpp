#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <typeinfo>
using namespace std;
class Lex{
	public:
		//method to load from csv file to 2d array/vector
		vector< vector<string> > loadCsv(){
			vector< vector<string> > TT;
			string currLine;
			ifstream fileOpener("TransitionTable.csv");
			string line, field;  
		    vector<string> v;                
		    while ( getline(fileOpener,line) ){
		        v.clear();
		        stringstream ss(line);
		        while (getline(ss,field,',')){
		            v.push_back(field);
		        }
		        TT.push_back(v); 
		    }
		    return TT;
			
		}
		//method to print symbols
		void printOperator(int state){
			switch (state){
				case 3:
					cout<<" GT ";
					break;
				case 5:
					cout<<" GTE ";
					break;
				case 7:
					cout<<" LT ";
					break;
				case 9:
					cout<<" LTE ";
					break;
				case 11:
					cout<<" NE ";
					break;	
				case 13:
					cout<<" EQ ";
					break;
				case 15:
					cout<<" ID ";
					break;
				default:
					break;
					
			}
					
		}
		void analyser(vector< vector<string> > table,string line){
			int state = 1;
			int cols = table[0].size();
			//this loop reapeats (the number of character of line) times
			for(int i=0; i<line.length(); i++){
				//this loop repeats the number of colums of transition table times
				for(int col=0; col<cols; col++){
					//just converting the type from character to string
					string currChar(1,line[i]);
					//checking if current line character == current table character
					if(currChar == table[0][col]){
						//again just type chasting the current position in table and setting it equal to state
						state = atoi(table[state][col].c_str() );
						//calling the print function to print according to the state
						printOperator(state);
						break;
					}
				}
			}
			//new line after every line
			cout<<"\n";
			
		}
	
};
int main(){
	Lex lex;
	//the 2d array(vector)
	vector< vector<string> > table = lex.loadCsv();
	string currLine;
	ifstream fileOpener("code.txt");
	//calling the method line by line
	while(getline(fileOpener,currLine)){
		lex.analyser(table,currLine);
	}
	
	
	return 0;
}
