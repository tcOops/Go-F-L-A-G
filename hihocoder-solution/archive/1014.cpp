#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[20];

typedef struct Trie{
    int val, cnt;
    Trie *next[26];
    Trie(){
        for(int i = 0; i < 26; ++i){
            next[i] = NULL;
        }
    }
}Trie;

Trie* buildTrieTree(Trie *root, char *dict){
    Trie *p = root, *q;
    int i = 0;
    while(dict[i] != '0'){
        int k = dict[i] - 'a';
        if(p->next[k] == NULL){
            q = new Trie();
       //     for(int j = 0; j < 26; ++j){
       //         q->next[j] = NULL;
       //     }
            q->val = k;
            q->cnt = 0;
            p->next[k] = q;
        }
        p = p->next[k];
        p->cnt += 1;
        ++i;
    }
    return root;
}

int query(Trie *root, char *dict){
    int p = 0;
    while(dict[p] != '0'){
        int k = dict[p] - 'a';
        if(root->next[k] != NULL){
            root = root->next[k];
        }
        else{
            return 0;
        }
        ++p;
    }
    return root->cnt;
}

int main(){
    int n, m;

    scanf("%d", &n);
    Trie *root = new Trie();
  //  for(int i = 0; i < 26; ++i){
  //      root->next[i] = NULL;
  //  }
    for(int i = 0; i < n; ++i){
        scanf("%s", s);
        root = buildTrieTree(root, s);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; ++i){
        scanf("%s", s);
        int ans = query(root, s);
        printf("%d\n", ans);
    }
    return 0;
}
