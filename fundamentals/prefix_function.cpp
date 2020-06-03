#include <string>
#include <vector>
#include <iostream>

std::vector<int> prefix_function(std::string s) {
    int len = (int) s.length();
    std::vector<int> pi(len); 
    pi[0] = 0;
    for (int i=1; i<len; i++) {
        int j = pi[i-1];
        while (j != 0 && s[j] != s[i]){
            j = pi[j-1];
        }
        pi[i] = s[i]==s[j]? j+1:0;
    }
    return pi;
}

std::vector<bool> find_substring(std:: string s, std::string sub) {
    std::vector<int> pi((int)s.length());
    std::vector<bool> index_found((int)s.length());
    s = sub + '#' + s;
    pi = prefix_function(s);
    for (int i=2*(int)sub.length() ; i<(int)pi.size() ; i++) {
        if (pi[i] == (int) sub.length())
            index_found[i - 2*(int)sub.length()] = true;
        else
            index_found[i - 2*(int)sub.length()] = false;
    }
    return index_found;
}

int main() { /* TEST */

    std::string s = "abcabkabcabc";
    std::vector<int> pi = prefix_function(s);

    printf(".:: PREFIX FUNCTION FOR \"%s\" ::.\n", "abcabkabcabc");
    for (int i=0; i<(int)s.length(); i++) {
        printf("%d ", pi[i]);
    }
    printf("\n");

    printf(".:: FIND SUBSTRING \"%s\" IN \"%s\" ::.\n", "aa", "aaaa");
    std::vector<bool> founds = find_substring("aaaa","aa");
    for (int i=0; i<(int)founds.size(); i++) {
        if (founds[i])
            printf("found in pos: %d\n", i);
    }
    printf("\n");

}
