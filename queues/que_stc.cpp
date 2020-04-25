#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Write your code here
    private:
        vector<char> stack  = {};
        vector<char> queue = {};
        int stackCursor = 0;
        int queueCursor = 0;
    public: 
    void pushCharacter(char c) {
        stack.push_back(c);
    }

    void enqueueCharacter(char c) {
        queue.push_back(c);
        queueCursor++;
    }
    
    char popCharacter() {
        return stack[stackCursor];
        stackCursor++;
    }
    char dequeueCharacter() {
        return queue[queueCursor - 1];
        queueCursor - 1;
    }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}
