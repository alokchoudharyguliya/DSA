// class Solution {
// public:
//     void splitString(string& input, char delimiter,
//                  vector<int>&arr, int& index)
// {
//     istringstream stream(input);

//     string token;

//     while (getline(stream, token, delimiter)) {
//         arr[index++] = token;
//     }
// }
//         int vowCount(string a){
//             int ans=0;
//             for(char ch:a){
//                 if(ch=='a'||ch=='o'||ch=='i'||ch=='e'||ch=='u')
//                 anss++;
//             }
//             return ans;
//         }
//     string reverseWords(string s) {
//         vector<int>arr;
//         int index;
//         splitString(s,' ',arr,index);
//         int vC=vowCount(arr[0]);
//         for(int i=1;i<index;i++){
//             if(vowCount(arr[i])==vC)
//             {
//                 arr[i]=reverse(arr[i].begin(),arr[i].end());
//             }
//         }
//         string res="";
//         for(int i=0;i<index;i++){
//             res+=arr[i];
//         }
//         cout<<res;
//         return "";
//     }
// };©leetcode


class Solution {
public:
    int vowCount(const string& word) {
        int ans = 0;
        for (char ch : word) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                ans++;
        }
        return ans;
    }

    string reverseWords(string s) {
        vector<string> words;
        string token;
        stringstream ss(s);

        // Split string by spaces
        while (ss >> token) {
            words.push_back(token);
        }

        // Count vowels in first word
        int firstVowelCount = vowCount(words[0]);

        // Reverse words having same vowel count
        for (int i = 1; i < words.size(); i++) {
            if (vowCount(words[i]) == firstVowelCount) {
                reverse(words[i].begin(), words[i].end());
            }
        }

        // Join words back into a string
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1)
                result += " ";
        }

        return result;
    }
};
