#include <string>
#include <iostream>
#include <sstream>
#include <vector>
char dec(char c, int num) {
    int i;
    std::vector<char>vec;
    for (i = 0; i < 26; i++)
        if (num * i % 26 == c - 'a')
            vec.push_back(i + 'a');
    if (vec.size() != 1)
        return -1;
    return vec[0];
}
std::string encode(std::string s, int n) {
    std::string res = "";
    int i;
    long long ch;
    for (i = 0; i < s.length(); i++) {
        ch = s[i] - 'a';
        ch *= n;
        ch %= 26;
        res += ch + 'a';
    }
    res = std::to_string(n) + res;
    return res;
}
std::string decode(const std::string& r)
{
    std::string res = "";
    std::string enc;
    int num;
    std::string n = "";
    int i;
    char ch;
    for (i = 0; i < r.length() && r[i] >= '0' && r[i] <= '9'; i++)
        n += r[i];
    std::stringstream s(n);
    s >> num;
    for (; i < r.length(); i++) {
        ch = dec(r[i], num);
        if (ch == -1)
            return "Impossible to decode";
        res += ch;
    }
    enc = encode(res, num);
    if (enc != r)
        return "Impossible to decode";
    return res;
}
void run() {
    int i;
    int num;
    std::string text;
    while (true) {
        std::cout << "\nEncode 1\nDecode 2\nother exit\n";
        std::cin >> i;
        if (i > 2 || i < 1)
            break;
        switch (i) {
            case 1:
                std::cout << "Enter key\n";
                std::cin >> num;
                std::cout << "Enter text only a-z\n";
                std::cin >> text;
                std::cout <<"Encoded: "+ encode(text, num)+"\n";
                break;
            case 2:
                std::cout << "Enter text only a-z\n";
                std::cin >> text;
                std::cout << "Decoded: " + decode(text) + "\n";
                break;
        }
    }

}
int main()
{
    run();
    std::cout << "Good Bye\n";
    system("pause");
}
