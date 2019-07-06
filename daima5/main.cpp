#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#define n 28
using namespace std;
struct student{
    string num;
    string college;
    string name;
    int score[7]={0};
    double average_score;
};
struct caipan{
    string tname;
};
struct zuida{
    int e;
    int max;
};
struct zuixiao{
    int w;
    int min;
};
int main (){
    int y=0;
    student m[n];
    caipan w[7];
    zuida a[n];
    zuixiao b[n];
    ifstream outf("/Users/s20181106279/Desktop/tttt.txt");
    ifstream out("/Users/s20181106279/Desktop/ttt.txt");
    for(int i=0;i<n;i++){
        out>>m[i].num>>m[i].name>>m[i].college;
    }
    for(int i=1;i<=n+1;i++){
        if(i==1){
            for(int j=0;j<7;j++){
                outf>>w[j].tname;
            }
        }
        else{
            for(int k=0;k<7;k++){
                outf>>m[i-2].score[k];
            }
        }
    }
    //  for(int i=0;i<7;i++){
    //    cout<<w[i].tname<<" ";
    // }
    for(int i=0;i<n;i++){
        a[i].max=m[i].score[0];
        a[i].e=0;
        b[i].min=m[i].score[0];
        b[i].w=0;
        for(int j=1;j<7;j++){
            if(a[i].max<m[i].score[j]){
                a[i].max=m[i].score[j];
                a[i].e=j;
            }
            if(b[i].min>m[i].score[j]){
                b[i].min=m[i].score[j];
                b[i].w=j;
            }
        }
    }
    for(int i=0;i<n;i++){
        double v=0;
        for(int k=0;k<7;k++){
            if(k!=a[i].e&&k!=b[i].w){
                v=v+m[i].score[k];
            }
        }
        m[y].average_score=v*1.0/5;
        y++;
    }
    string num1;
    string college1;
    string name1;
    int score1[8]={0};
    double average_score1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(m[j].average_score<m[j+1].average_score){
                average_score1=m[j].average_score;
                m[j].average_score=m[j+1].average_score;
                m[j+1].average_score=average_score1;
                num1=m[j].num;
                m[j].num=m[j+1].num;
                m[j+1].num=num1;
                college1=m[j].college;
                m[j].college=m[j+1].college;
                m[j+1].college=college1;
                name1=m[j].name;
                m[j].name=m[j+1].name;
                m[j+1].name=name1;
                for(int k=0;k<7;k++){
                    score1[k]=m[j].score[k];
                    m[j].score[k]=m[j+1].score[k];
                    m[j+1].score[k]=score1[k];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++){
            cout<<w[j].tname;
            cout<<" ";
            cout<<m[i].score[j];
            cout<<" ";
        }
        cout<<endl;
    }
    ofstream in("/Users/s20181106279/Desktop/ttttt.txt");
    if(in.is_open())
    {
        for(int i=0;i<n;i++){
            in<<left<<setw(10)<<m[i].num<<left<<setw(10)<<m[i].college<<left<<setw(10)<<m[i].name
            <<"排名:"<<left<<setw(10)<<i+1<<"平均分:"<<left<<setw(10)<<m[i].average_score;
            for(int j=0;j<7;j++){
                in<<w[j].tname;
                in<<" ";
                in<<m[i].score[j];
                in<<" ";
            }
            in<<endl;
        }
        in.close();
    }
    return 0;
    
}





