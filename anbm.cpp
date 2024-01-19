// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
int initialState(char c){
    if(c=='a')
        return 1;
    else
        return 3;
        
}

int state1(char c){
    if(c=='a')
        return 1;
    else if(c=='b')
        return 2;
}

int finalstate(char c){
    if(c=='a')
        return 3;
    else if(c=='b')
        return 2;
}

int deadstate(char c){
    if(c=='a'|| c=='b'){
        return 3;
    }    
}

int main() {
    string input="aaaaaabbbb";
    int state[]={0};
    int nxtstate = initialState(input[0]);
    for(int i = 1;i<input.length();i++){
        state[i]=nxtstate;
        if(nxtstate==1){
            nxtstate=state1(input[i]);
            state[i]=nxtstate;
        }
        if(nxtstate==2){
            nxtstate=finalstate(input[i]);
            state[i]=nxtstate;
        }
        if(nxtstate==3){
            nxtstate=deadstate(input[i]);
            state[i]=nxtstate;
            break;
        }
    }
    if(nxtstate==2){
        cout<<"String accepted";
    }
    else{
        cout<<"Not Accepted";}
    
    return 0;
}
