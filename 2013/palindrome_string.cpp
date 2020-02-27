/*
回文串问题
时间限制: 1 Sec  内存限制: 128 MB
- 题目描述
“回文串”是一个正读和反读都一样的字符串，字符串由数字和小写字母组成，比如“level”或者“abcdcba”等等就是回文串。请写一个程序判断读入的字符串是否是“回文”。
- 输入
输入包含多个测试实例，每一行对应一个字符串，串长最多100字母。
- 输出
对每个字符串，输出它是第几个，如第一个输出为"case1:"；如果一个字符串是回文串，则输出"yes",否则输出"no"，在yes/no之前用一个空格。
- 样例输入
level
abcde
noon
haha
- 样例输出
case1: yes
case2: no
case3: yes
case4: no
提示
请使用scanf进行输入。
*/
#include <iostream>
#include <string>

std::string IsPalindromeString(std::string const& s) {
  int tail = s.size() - 1, head = 0;
  while (tail > head && s[tail] == s[head]) {
    tail--;
    head++;
  }
  if (tail > head) {
    return "no";
  } else {
    return "yes";
  }
}

int main() {
  std::string s;
  int i = 1;

  while (std::cin >> s) {
    std::cout << "case" << i++ << ": " << IsPalindromeString(s) << std::endl;
  }
  return 0;
}
