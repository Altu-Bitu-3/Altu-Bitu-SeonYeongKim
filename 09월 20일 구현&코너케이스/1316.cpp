#include <iostream>

using namespace std;

bool groupWord(string s){
    bool alphabet[26] = {false};
    
    //벡터(문자열)을 훑으며 알파벳이 나오면 해당 알파벳 배열을 true로 바꿈. 근데 이미 true면 false 리턴
    for(int j=0; j<s.length(); j++){
        if(alphabet[(int)s[j]-97] && s[j] != s[j-1]){
            return false;
        }
        alphabet[(int)s[j]-97] = true;
    }
    
    //다 돌았으면 true
    return true;
}

int main () {
    
    int t;
    cin >> t;
    int ans = 0;
    
    for(int i=0; i<t; i++){
        string s;
        cin >> s;
        
        if(groupWord(s)) ans++;
    }
    
    cout << ans;
    
    return 0;
}
