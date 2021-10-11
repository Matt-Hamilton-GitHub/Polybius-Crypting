
//                                            ********* Writer: Matt Hamilton      *********
 //                                             ******** Class: CS 136             ******** 
 //                                              ******* Professor: Brian Dauzat   *******
 //                                                ***** Quiz 4                    *****
 //                                                 **** ========================= ****
 //                                                   **  *** *** *** *** *** *** **



#include <iostream>
#include <vector>
#include <string>

using namespace std;





void decrypt();

int main()
{
	
	
	decrypt();
	
	system("pause");
	return 0;
	
}

void decrypt(){
	
//in order for the program to check the spelling (to understand which of the two letters is intended, Z or Y),
// the program must know all the words that contain Z or Y
//since it is impossible to check whether a word should contain z or y, We just separate the two letters, so the message is going to be clear
//so z corresponds to 55 and y corresponds to 61
	const vector<vector<char>> dec_board  {
{'A','B','C','D','E'},
{'F','G','H','I','J'},
{'K','L','M','N','O'},
{'P','Q','R','S','T'},
{'U','V','W','X','Y'},
{'Z'},
};



	
    string mess_inc;
	string mess_dec;
	string mess_inc_no_spaces;
	
	cout << "\t\n\nPlease Enter Your Encrypted Message: " ;
	getline(cin, mess_inc);
	
	cout << "\t\n\n\n             0% ***********Decrypting Initiated ************\n\n\n";
	
	
	//the variables below contain every two numbers from the input array of characters
	unsigned int temp1{0};
	unsigned int temp2{1};
	
	//the variables below contain the two indexes to search for a letter in the matrix
	// atoi function converts the data type from string to integer
	string str1;
	string str2;
	
	//in order to avoid any possible errors, let's exclude any spaces in between the numbers
	for(unsigned int idx{0}; idx < mess_inc.length(); idx++){
		if(mess_inc[idx] != ' '){
			mess_inc_no_spaces+=mess_inc[idx];
		}
	}
	
	
	
	for(unsigned int count {0};count < mess_inc_no_spaces.length()-1; count++){
		
		
		if(str1 != " " && str2 != " "){//check if the input is not a blank space
		str1 = mess_inc_no_spaces[temp1];
		str2 = mess_inc_no_spaces[temp2];
			if(temp2 <= mess_inc_no_spaces.length()){//make sure that we did not reach the end of the input string
			
			//now we can start building the decrypted message
			//the matrix takes two indexes, the first for a row, and the second for a column, like dec_board[0][0] and so on
			//we convert every sequence of two numbers from a string to an integer, subtract 1 from each of them
			//(since the initial indexes of complex data types start from 0 not from 1, we subtract one)
			mess_dec+= dec_board[stoi(str1)-1][stoi(str2)-1];
			temp1+=2;
			temp2+=2;
			}
		
		}else{
			temp1+=2;
			temp2+=2;
		}
		
	}


cout << "\t 100%  *********** Successfully Decrypted  ************\n\n\n";
cout << " \t ----------------------------------------------\n";
cout << "\t          |" + mess_inc << " -> " << mess_dec  << " |"<< endl;
cout << " \t ----------------------------------------------\n";
cout << "\t\n                     ***********  ************\n\n\n";
}