#include<iostream>
#include<set>

using namespace std;
int main()
{
    std::set<int> mySetOfIntegers;
    mySetOfIntegers.insert(1);
    mySetOfIntegers.insert(2);
    mySetOfIntegers.insert(3);
    mySetOfIntegers.insert(1);

    // Chỉ 3 phần tử được thêm vào "mySetOfIntegers"
    std::cout<<"Số lượng phần tử: "<<mySetOfIntegers.size()<<std::endl;
	for(int i=0;i<mySetOfIntegers.size();i++){
		cout << mySetOfIntegers[i];
	}
    return 0;
}