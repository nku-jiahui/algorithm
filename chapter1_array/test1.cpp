#include<iostream>

void test_array(){
    int array[2][3]{
        {2,3,1},
        {4,5,6}
    };
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            std::cout<<&array[i][j]<<"  ";
        }
        std::cout<<"\n";
    }
}

int main(){
    test_array();
    return 0;
}