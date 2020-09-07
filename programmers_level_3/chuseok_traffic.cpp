#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> strtok(string str, char delim = ' '){
    vector<string> ret;
    int prev=0;
    for(int i=0;i<str.size();i++){
        if(str[i]==delim){
            ret.push_back(str.substr(prev,i-prev));
            prev=i+1;
        }
    }
    if(str.size()!=prev) ret.push_back(str.substr(prev,str.size()-prev));
    return ret;
}
int solution(vector<string> lines) {
    int answer = 0;
    vector<vector<double>> t_list;
    for(int i=0;i<lines.size();i++){
        vector<string> temp = strtok(lines[i]);
        vector<string> tstr = strtok(temp[1],':');
        double s = stod(tstr[0])*3600+stod(tstr[1])*60+stod(tstr[2]);
        double t = stod(strtok(temp[2],'s')[0]);

        t_list.push_back({s-t+0.001,s});
    }

    for(int i=0;i<t_list.size();i++){
        double begin = t_list[i][1];
        double end = begin+1.000;
        int cnt=0;
        for(int j=i;j<t_list.size();j++){
            double jStart = t_list[j][0];
            double jEnd = t_list[j][1];
            if((jStart>=begin && jStart<end) || (jEnd>=begin && jEnd<end) ||
            (jStart<=begin && jEnd>=end) || (jStart >= begin && jEnd <=end)  ) {
                cnt++;
            }
        }
        if(answer<cnt) answer=cnt;
    }
    return answer;
}
int main(){
    vector<string> v = {
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s"
    };
    cout << solution(v) << endl;
    return 0;
}