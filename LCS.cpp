#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


void lenLCS(char*, char*, char*, int, int, int);


int main(){

	string input1 = "6541254939322816220209974565477289648317";
	string input2 = "3142522751761601737419090933147067701840";
	string input3 = "2807030561290354259513570160162463275171";
	
	
	//Change into c_string
	char *str1 = new char[input1.length()];
	char *str2 = new char[input2.length()];
	char *str3 = new char[input3.length()];
	strcpy(str1, input1.c_str());
	strcpy(str2, input2.c_str());
	strcpy(str3, input3.c_str());
	
	int strlen1 = input1.length();
	int strlen2 = input2.length();
	int strlen3 = input3.length();
	
	lenLCS(str1, str2, str3, strlen1, strlen2, strlen3);
	
	return 0;
}

void lenLCS(char *str1, char *str2, char *str3, int len1, int len2, int len3){

	int length = 0;
	
	int lcs[len1+1][len2+1][len3+1];
		
		
	for(int x=0; x<=len1;x++){
		for(int y=0; y<=len2; y++){
			for(int z=0; z<=len3; z++){
			
				if(x==0||y==0||z==0){
					lcs[x][y][z] = 0;
				
				}else if(x>0 && y>0 && z>0 && str1[x-1] == str2[y-1] && str1[x-1] == str3[z-1] && str2[y-1] == str3[z-1]){
					lcs[x][y][z] = lcs[x-1][y-1][z-1]+1;
				
				}else{
				
					int max1 = max(lcs[x-1][y][z], lcs[x][y-1][z]);
					int max2 = max(max1, lcs[x][y][z-1]);
					
					lcs[x][y][z] = max2;
			
				}
			}
		}
	}
	
	
	//print out length of LCS
	length = lcs[len1][len2][len3];
	cout << "length of LCS is " << length << endl;
	
	
	////////////////////////////////////////////////////////////////////////////////////////
	
	
	vector <char> str;

	int i=len1;
	int j=len2;
	
		for(int k=len2; k>0;k--){
		
			if((lcs[i][j][k] != lcs[i][j][k-1])){
				if((lcs[i][j][k] != lcs[i-1][j][k])){
					if(lcs[i][j][k] != lcs[i][j-1][k]){
						str.push_back(str3[k-1]);
						i=i-1;
						j=j-1;
					}else{
						j=j-1;
						k=k+1;					
					}
				}else{
					i=i-1;	
					k=k+1;			
				}
			}
		}
		
	
	//print LCS
	int size = str.size();
	cout << "The LCS is: ";
	for(int i=0; i<size;i++){
		cout << str.back();
		str.pop_back();
	}cout << endl;	
	
	
}
