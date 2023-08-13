/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    if(s[8] == 'P'){
        int time = (s[0]-'0')*10 + (s[1]-'0')+12;
        string t = to_string(time);
        if(t == "24") t = "12";
        return t+s.substr(2,6);
    }
    else{
        if(s[0] == '1' && s[1] == '2'){
            s[0] = '0';
            s[1] = '0';
        }
    }
    return s.substr(0,8);
}
