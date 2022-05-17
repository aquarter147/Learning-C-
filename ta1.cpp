#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>

#include <sstream>


using namespace std;

string Read (){
	std::ifstream f("C:/Users/admin/Documents/t.a/nhat.txt");
    int count =0;
	if (f.fail())
	{
		std::cout << "Failed to open this file!" ;
	}
    string line;
    string data;
	while (!f.eof())
	{
		getline(f, line);
        data += line;
        data.push_back(' ');
	}
	std::cout << std::endl;

	f.close();

	return data ;
}

int get_Amount(){
    ifstream f("C:/Users/admin/Documents/t.a/nhat.txt");
    int count =0;
    if(f.fail()){
        cout << "fail";
    }
    string line;
    while(!f.eof()){
        getline(f, line);
        count ++;
    }
    f.close();
    return count;
}

int count_comma(string input){
    int count =0 ;
    for ( int i=0 ; i<input.length();i++){
        if(input[i]== ',') count ++;
    }
    return count;
}

string get_type(string input){
    if(input[0] == 'S') return "Shape";
    else return "Edge";
}

char get_type2(string input){
    int m;
    for(int i=0;i<input.length();i++){
        if(input[i] == '{'){
            m=i;
            continue;
        }
    }
    return input[m+1];
}

int str2int(string input){
    stringstream x(input);
    int output =0;
    x >> output;
    return output;
}

float str2f(string input){
    stringstream x(input);
    float output =0.0;
    x >> output;
    return output;
}

// string int2str(int input){
//     stringstream ss;
//     ss << input;
//     return ss.str();
// }


// string f2str(float input){
//     stringstream ss;
//     ss << input;
//     return ss.str();
// }

float get_x(string input){
    string s;
    int i=0,count =0;
    while (count < 2){
        if(input[i] ==',') count ++;
        if(count == 1 && input[i+1] != ',') s.push_back(input[i+1]);
        ++i;
    }
    return str2f(s);
}
float get_y(string input){
    string s;
    int i=0,count =0;
    while (count < 3){
        if(input[i] ==',') count ++;
        if(count == 2 && input[i+1] != ',') s.push_back(input[i+1]);
        ++i;
    }
    return str2f(s);
}

float get_c1(string input){
     string s;
    int i=0,count =0;
    while (count < 4){
        if(input[i] ==',') count ++;
        if(count == 3 && input[i+1] != ',') s.push_back(input[i+1]);
        ++i;
    }
    return str2f(s);
}

float get_c2(string input){
    string s;
    int i=0, count =0;
    if(count_comma(input)==5) return 0;
    if(count_comma(input)==6 ||count_comma(input)==7){
        while (count < 5){
        if(input[i] ==',') count ++;
        if(count == 4 && input[i+1] != ',') s.push_back(input[i+1]);
        ++i;
        }
    }
    return str2f(s);
}

float get_c3(string input){
    string s;
    int i=0, count = 0;
    if(count_comma(input)==5 || count_comma(input)==6) return 0;
    if(count_comma(input)==7){
        while (count < 6){
        if(input[i] ==',') count ++;
        if(count == 5 && input[i+1] != ',') s.push_back(input[i+1]);
        ++i;
        }
    }
    return str2f(s);
}

string get_color(string input){
    string s;
    int i=0, count =0;
    while (count < count_comma(input)){
        if(input[i] ==',') count ++;
        if(count == (count_comma(input)-1) && input[i+1] != ',') s.push_back(input[i+1]);
        ++i;
    }
    return s;
}

float get_thickness(string input){
    string s;
    int i=0, count =0;
    while(count < count_comma(input)+1){
        if(input[i] ==',') count ++;
        if(count == count_comma(input) && input[i+1] != ',') s.push_back(input[i+1]);
        ++i;
    }
    return str2f(s);
}


int get_index1(string input){
   string s;
   s.push_back(input[5]);
    return str2int(s);
}

int get_index2(string input){
   string s;
   s.push_back(input[7]);
   return str2int(s);
}   

string get_color2(string input){
   string s;
    int i=0,count =0;
    while (count < 3){
        if(input[i] ==',') count ++;
        if(count == 2 && input[i+1] != ',') s.push_back(input[i+1]);
        ++i;
    }
    return s;
}   

float get_thickness2(string input){
   string s;
    int i=0,count =0;
    while (count < 4){
        if(input[i] ==',') count ++;
        if(count == 3 && input[i+1] != '}') s.push_back(input[i+1]);
        ++i;
    }
    return str2f(s);
}   






int main(){
    string b;
    b = Read();
    cout << b;
    int a;
    cout << get_index1("edge{1,2,green,8}");
    cin >> a;
    
}