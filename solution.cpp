#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol953;
using namespace std;

/*takeaways
  - map the words back to our order and use our sorting
    mechanism
  - words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
    - using our order the aliens are saying
      ["agbbo","bggteofg"]
    - we can just check if these words are sorted

*/
bool Solution::isAlienSorted(vector<string> &words, string order)
{
  auto map = unordered_map<char, char>();
  /* mapping between alien order and ours */
  for (auto i = 0; i < order.size(); i++)
    map[order[i]] = char('a' + i);

  /*translate  */
  for (auto &w : words)
    for (auto i = 0; i < w.size(); i++)
      w[i] = map[w[i]];

  /* use the sorting method we have  */
  return is_sorted(begin(words), end(words));
}