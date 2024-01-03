#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int m, n, k; cin >> m >> n >> k;
        vector<int> emails(n);
        for(int &i: emails) {cin >> i; i--;}
        vector<int> needs(m); // how many emails are associated w/ this folder
        vector<int> cur_filled(m); // how many emails are in this folder already
        for(int i = 0; i < n; ++i){
            needs[emails[i]]++;
        }

        int cur_folder = 0;
        int first_email = 0;
        int last_email = -1;
        multiset<int> cur_emails;
        deque<int> window; // emails by insertion time for removal purposes
        vector<int> num_removed(n); // used to determine which emails to put on skipped emails
        stack<int> skipped_emails;
        int total_filed = 0;
        
        while(true){
            if(total_filed == n) break;
            while(cur_emails.size() < k && n - total_filed > cur_emails.size()){
                if(total_filed == n) break;
                int email = -1;
                if(last_email + 1 != n){
                    last_email++;
                    email = emails[last_email];
                } else if(skipped_emails.size()){
                    email = skipped_emails.top();
                    skipped_emails.pop();
                }
                if(cur_folder <= email && email < cur_folder + k){
                    cur_filled[email]++;
                    total_filed++;
                } else {
                    cur_emails.insert(email);
                    window.push_back(email);
                }
            }
            while(cur_folder < m && needs[cur_folder] == cur_filled[cur_folder]){
                if(total_filed == n) break;
                cur_folder++;
                int new_folder = cur_folder + k - 1;
                while(cur_emails.find(new_folder) != cur_emails.end()){
                    cur_emails.erase(cur_emails.find(new_folder));
                    cur_filled[new_folder]++;
                    total_filed++;
                    num_removed[new_folder]++;
                }
            }
            if(cur_emails.size() == k){
                if(last_email + 1 == n) break; // can't do anything anymore
                bool b = true;
                while(b && window.size()){
                    int front = window.front();
                    window.pop_front();
                    if(num_removed[front]){
                        num_removed[front]--;
                    } else {
                        cur_emails.erase(cur_emails.find(front));
                        skipped_emails.push(front);
                        b = false;
                    }
                }
                
            }
        }
        cout << (total_filed == n ? "YES" : "NO") << endl;
    }
}