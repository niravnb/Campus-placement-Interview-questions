// Photo Album

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'photoAlbum' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY index
 *  2. INTEGER_ARRAY identity
 */

struct node{
    int val;
    struct node* next, *prev;
};

vector<int> photoAlbum(vector<int> index, vector<int> identity) {
    int n = index.size();
    vector<int> res;

    // struct node *head = new node();
    // head->val = 0;
    // head->next = NULL;
    // head->prev = NULL;
    // bool first = true;
    // struct node *root = head;

    // unordered_map<int, struct node*> mp;
    // int sames = 0;

    // for(int i =0; i<n; i++){
    //     int val = identity[i];
    //     int ind = index[i];

    //     if(mp.find(ind)==mp.end()){
    //         if(first){
    //             first = false;
    //             head->val = val;
    //             mp[ind] = head;
    //         }else{
    //             struct node *tmp = new node();
    //             tmp->next = NULL;
    //             tmp->val = val;
    //             head->next = tmp;
    //             head = head->next;
    //             mp[ind]=tmp;
    //         }
    //     }else{
    //         struct node * it = mp[ind];
    //         // cout << ind << "  " << it->val << endl;
    //         // sames++;
    //         int preVal = it->val;
    //         it->val = val;
    //         struct node *tmp = new node();
    //         tmp->next = NULL;
    //         tmp->val = preVal;
    //         struct node *nxt = it->next;
    //         it->next = tmp;
    //         tmp->next = nxt;
    //         mp[++ind] = tmp;
    //         // cout << ind << "  " << it->val << endl;
    //         // while(nxt){
    //         //     mp[++ind] = nxt;
    //         //     nxt = nxt->next;
    //         // }
    //     }

    // }

    // // for(auto it: mp){
    // //     cout << it.first << " " << it.second->val << endl;
    // // }
    // while(root != NULL){
    //     // cout << head->val << " ";
    //     res.push_back(root->val);
    //     root = root->next;
    // }

    for(int i =0; i<n; i++){
        int val = identity[i];
        int ind = index[i];

        res.insert(res.begin()+ind,val);
        // for(auto x: res) cout << x << " ";
        // cout << endl; 
    }
    return res;

}
int main()