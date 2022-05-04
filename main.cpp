#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol953;

/*
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
*/
tuple<vector<string>, string, bool>
testFixture1()
{
  auto words = vector<string>{"hello", "leetcode"};
  auto order = "hlabcdefgijkmnopqrstuvwxyz";
  return make_tuple(words, order, true);
}

/*
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language,
then words[0] > words[1], hence the sequence is unsorted.
*/
tuple<vector<string>, string, bool>
testFixture2()
{
  auto words = vector<string>{"word", "world", "row"};
  auto order = "worldabcefghijkmnpqstuvxyz";
  return make_tuple(words, order, false);
}

/*
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second
string is shorter (in size.) According to lexicographical
rules "apple" > "app", because 'l' > '∅', where '∅' is defined as
the blank character which is less than any other character (More info).
*/
tuple<vector<string>, string, bool>
testFixture3()
{
  auto words = vector<string>{"apple", "app"};
  auto order = "abcdefghijklmnopqrstuvwxyz";
  return make_tuple(words, order, false);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see " << get<2>(f)
       << ": " << sol.isAlienSorted(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see " << get<2>(f)
       << ": " << sol.isAlienSorted(get<0>(f), get<1>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  Solution sol;
  cout << "Expect to see " << get<2>(f)
       << ": " << sol.isAlienSorted(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}