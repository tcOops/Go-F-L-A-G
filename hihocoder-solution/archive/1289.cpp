#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
const int N = 7000000;
struct Node{
    int lazy_tag;
    Node * next[2];
}node[N];

Node *allow_tree;
Node *deny_tree;
int node_counts = 0;

void buildTree(){
    allow_tree = &node[node_counts++];
    deny_tree = &node[node_counts++];
    for (int i = 0;i < N;i ++){
        node[i].lazy_tag = int(1e9);
        node[i].next[0] = node[i].next[1] = NULL;
    }
}

string IntToBinary(int num){
    string ret = "";
    for (int i = 7;i >= 0;i --){
        if (num & (1 << i)){
            ret += '1';
        }
        else{
            ret += '0';
        }
    }
    return ret;
}

string ConvertBiarnyString(const string &IP){
    //cout << "IP: " << IP << endl;
    string ret = "";
    int num = 0;
    for (int i = 0; i < IP.length(); i++){
        if (IP[i] != '.' && IP[i] != '/') {
            num = num * 10 + IP[i] - '0';
        }
        else{
            ret += IntToBinary(num);
            num = 0;
        }
    }
    if (ret.length() != 32){
        ret += IntToBinary(num);
    }
    else{
        ret = ret.substr(0, num);
    }
    //cout << "IP_string: " << ret << endl;
    return ret;
}

void add_node(Node *p, string IP_string, int ID){
    for (int i = 0;i < IP_string.length();i ++){
        int num = IP_string[i] - '0';
        if (p->next[num] == NULL){
            p->next[num] = &node[node_counts++];
        } 
        p = p->next[num];
        if (p->lazy_tag != int(1e9)){
            return ;
        }
    }
    p->lazy_tag = ID;
}

int WalkOnTee(Node *root, string IP_string){
    int ret = int(1e9);
    Node *p = root;
    if (p->lazy_tag != int(1e9)){
        return p->lazy_tag;
    }
    for (int i = 0;i < IP_string.length();i ++){
        int num = IP_string[i] - '0';
        if (p->next[num] == NULL){
            break;
        } 
        p = p->next[num];
        if (p->lazy_tag != int(1e9)){
            ret = min(ret, p->lazy_tag);
        }
    }
    return ret;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        buildTree();
        string operation, IP;
        for (int i = 0;i < n;i ++){
            cin >> operation >> IP;
            string IP_string = ConvertBiarnyString(IP);
            //cout << "IP " << IP << " length: " << IP_string.length() << endl;
            //cout << "operation: " << operation << endl;
            if (operation == "allow"){
                add_node(allow_tree, IP_string, i);
            } else if (operation == "deny"){
                add_node(deny_tree, IP_string, i);
            } else {
                cout << "unknow operation" << endl;
            }
        }
        for (int i = 0;i < m;i ++){
            cin >> IP;
            string IP_string = ConvertBiarnyString(IP);
            int allow_id = WalkOnTee(allow_tree, IP_string);
            int deny_id = WalkOnTee(deny_tree, IP_string);
            //cout << "allow_id: " << allow_id << endl;
            //cout << "deny_id: " << deny_id << endl;
            if (allow_id < deny_id || min(allow_id, deny_id) == int(1e9)){
                cout << "YES" << endl;
            } else{
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}