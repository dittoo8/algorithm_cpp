#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<string> a, vector<string> b){
    string a1;
	string b1;
	for (int i = 0; i<a[0].size(); i++) {
		a1 += toupper(a[0][i]);
	}
	for (int i = 0; i<b[0].size(); i++) {
		b1 += toupper(b[0][i]);
	}
	if (a1.compare(b1) == 0) {
		return stoi(a[1])<stoi(b[1]);
	}
	if (a1.compare(b1)>0)
		return false;
	else
		return true;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string> > data(files.size(),vector<string>(3));
    int idx = 0;
    int j=0;
    for(int i=0;i<files.size();i++){
        j=0;
        idx=0;
        while(j<files[i].size()){
            //head
            if(files[i][j]<'0' || files[i][j]>'9'){
                data[i][idx]+=files[i][j];
            }else {
                idx++;
                break;
            }
            j++;
        }
        while(j<files[i].size()){
            //number
            if(files[i][j]>='0'&& files[i][j]<='9'){
                data[i][idx]+=files[i][j];
            }else {
                idx++;
                break;
            }
            j++;
        }
        while(j<files[i].size()){
            data[i][idx]+=files[i][j];
            j++;
        }
    }
    stable_sort(data.begin(),data.end(),cmp);
    for(int i=0;i<files.size();i++){
        answer.push_back(data[i][0]+data[i][1]+data[i][2]);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> v;
    v.push_back("img12.png");
    v.push_back("img10.png");
    v.push_back("img02.png");
    v.push_back("img1.png");
    v.push_back("IMG01.GIF");
    v.push_back("img2.JPG");
    vector<string> res;
    res = solution(v);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    } 
    return 0;
}