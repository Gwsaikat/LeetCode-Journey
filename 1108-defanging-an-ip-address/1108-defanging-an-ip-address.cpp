class Solution {
public:
    string defangIPaddr(string address) {
        string defangedIP = "";

        for ( char ch : address ){
            if ( ch == '.'){
                defangedIP += "[.]";
            } else {
                defangedIP += ch ;
            }
        }

        return defangedIP;
    }
};