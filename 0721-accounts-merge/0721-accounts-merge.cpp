class Solution {
    vector<int> parent;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootA] = rootB;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        unordered_map<string, int> emailToAccount;

        // Step 1: Build connections using email map
        for (int i = 0; i < n; ++i) {
            for (size_t j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                } else {
                    unite(i, emailToAccount[email]);
                }
            }
        }

        // Step 2: Group unique emails under the representative (root) account index
        unordered_map<int, vector<string>> mergedEmails;
        for (auto& [email, accIdx] : emailToAccount) {
            int root = find(accIdx);
            mergedEmails[root].push_back(email);
        }

        // Step 3: Format the output (sort emails and prepend account name)
        vector<vector<string>> result;
        for (auto& [rootIdx, emailList] : mergedEmails) {
            sort(emailList.begin(), emailList.end());
            
            vector<string> account = {accounts[rootIdx][0]};
            account.insert(account.end(), emailList.begin(), emailList.end());
            
            result.push_back(account);
        }

        return result;
    }
};