#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    class Node {
    public:
        int freq;
        char c;
        Node *left, *right;

        Node(int F, char name) {
            freq = F;
            c = name;
            left = right = NULL;
        }
    };

    class comp {
    public:
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq; // min-heap based on frequency
        }
    };

    void preorder(Node* root, string &temp, vector<string> &ans) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }

        temp.push_back('0');
        preorder(root->left, temp, ans);
        temp.pop_back();

        temp.push_back('1');
        preorder(root->right, temp, ans);
        temp.pop_back();
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, comp> pq;

        for (int i = 0; i < N; i++)
            pq.push(new Node(f[i], S[i]));

        while (pq.size() > 1) {
            Node* first = pq.top(); pq.pop();
            Node* second = pq.top(); pq.pop();

            Node* root = new Node(first->freq + second->freq, '$');
            root->left = first;
            root->right = second;

            pq.push(root);
        }

        Node* root = pq.top(); pq.pop();

        vector<string> ans;
        string temp = "";
        preorder(root, temp, ans);

        return ans;
    }
};

int main() {
    string S;
    int N;
    cout << "Enter number of characters: ";
    cin >> N;

    cout << "Enter the characters (as a string): ";
    cin >> S;

    vector<int> freq(N);
    cout << "Enter their frequencies: ";
    for (int i = 0; i < N; i++)
        cin >> freq[i];

    Solution obj;
    vector<string> codes = obj.huffmanCodes(S, freq, N);

    cout << "\nHuffman Codes:\n";
    for (int i = 0; i < N; i++)
        cout << S[i] << ": " << codes[i] << "\n";

    return 0;
}
