
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void decrypt(string mess_enc);
void encrypt(string input);
void testing();

int main()
{
	
	
testing();
	
	
	//USER IN PUT 
	
//	int choice;
//  string mess_enc;
//	
//	cout<<"\n\n\t**************** MENU ***************\n";
//	cout << "\tPress 1 To decrypt message\n";
//	cout << "\tOR\n";
//	cout << "\tPress 2 To ecrypt message\n";
//	cout << "Enter: ";
//	cin >> choice;
//	cout<<"\t*******************************\n\n\n";
//	
//	
//	switch(choice){
//		case 1:
//			cout << "\t\n\nPlease Enter Encrypted Message: " ;
//			cin.ignore();
//			getline(cin, mess_enc);
//			decrypt(mess_enc);
//			break;
//		case 2:
//			cout << "\t\n\nPlease Enter Message You Would Like to Encrypt: " ;
//			cin.ignore();
//			getline(cin, mess_enc);
//			encrypt(mess_enc);
//			break; 
//	}
//	
	
	
	system("pause");
	return 0;
	
}

void decrypt(string mess_enc){
	
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



	
	string mess_dec;
	string mess_enc_no_spaces;
	
	
	
	//the variables below contain every two numbers from the input array of characters
	unsigned int temp1{0};
	unsigned int temp2{1};
	
	//the variables below contain the two indexes to search for a letter in the matrix
	// atoi function converts the data type from string to integer
	string str1;
	string str2;
	
	//in order to avoid any possible errors, let's exclude any spaces in between the numbers
	for(unsigned int idx{0}; idx < mess_enc.length(); idx++){
		if(mess_enc[idx] != ' '){
			mess_enc_no_spaces+=mess_enc[idx];
		}
	}
	
	
	for(unsigned int count {0};count < mess_enc_no_spaces.length()-1; count++){
		
		
		if(str1 != " " && str2 != " "){//check if the input is not a blank space
		str1 = mess_enc_no_spaces[temp1];
		str2 = mess_enc_no_spaces[temp2];
			if(temp2 <= mess_enc_no_spaces.length()){//make sure that we did not reach the end of the input string
			
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



cout <<"\n\t Decrypted: " << mess_enc << " -> " << mess_dec  << endl << endl;
}

void encrypt(string mess_enc){
		
map<char, string> encr_board{
	{'A',"11"}, {'B',"12"},{'C',"13"}, {'D',"14"},{'E',"15"}, 
	{'F',"21"},{'G',"22"}, {'H',"23"},{'I',"24"}, {'J',"25"},
	{'K',"31"}, {'L',"32"},{'M',"33"}, {'N',"34"},{'O',"35"}, 
	{'P',"41"}, {'Q',"42"},{'R',"43"}, {'S',"44"},{'T',"45"}, 
	{'U',"51"}, {'V',"52"},{'W',"53"}, {'X',"54"},{'Y',"55"}, 
	{'Z',"61"},
};
	
	
string encrypted;

for(unsigned int idx{0};idx < mess_enc.length();idx++){
	
	   for(const auto &elem: encr_board){
		   
        if(elem.first == toupper(mess_enc[idx])){
			encrypted+= elem.second + " ";
		}
    }
   
	
}

cout <<"\n\t Encrypted: " << mess_enc << " -> " << encrypted  << endl << endl;

}


void testing(){
	
	//encrypting messages test
	encrypt("HELLO");
	encrypt("secret");
	encrypt("attantion");
	encrypt("fingers");
	encrypt("abcdefghijklmnopqrstuvwxyz");
	
	
	//decrypting messages test
	
  decrypt("23 15 32 32 35 ");
  decrypt("44 15 13 43 15 45 ");
  decrypt(" 11 45 45 11 34 45 24 35 34");
  decrypt("21 24 34 22 15 43 44");
  decrypt("11 12 13 14 15 21 22 23 24 25 31 32 33 34 35 41 42 43 44 45 51 52 53 54 55 61");
	
	
}