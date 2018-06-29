#include <iostream>
#include <vector>
#include <string>

std::vector<int> parse(int inp) {
  std::vector<int> out(4);
  for(auto &x : out) {
    x = inp % 10;
    inp /= 10;
  }
  std::reverse(out.begin(), out.end());
  return out;
}

class Op
{
public:
  int id;
  Op(int inp_id) {
    id = inp_id > 0 ? 1 : 0;
  }

  Op(){
    id = 0;
  }

  static std::string get_p(Op p) {
    if(p.id == 0) return "+";
    return "-";
  }

  int act(int left, int right) {
    if(id == 0) return left + right;
    return left - right;
  }
};

  std::ostream& operator<< (std::ostream& os, const Op& o) {
    os << Op::get_p(o.id);
    return os;
  }

bool check_seven(std::vector<int> a, std::vector<Op> o) {
  int sum = a[0];
  for(int i = 0; i < 3; i++) {
    sum = o[i].act(sum , a[i + 1]);
  }
  return sum == 7;
}

void parse_op(int pattern, std::vector<Op> &op) {
  for(int i = 0; i < 3; i++) {
    op[i].id = (pattern & (1 << i)) ? 1 : 0;
  }
}

int main(void) {
  int inp;
  std::cin >> inp;
  std::vector<int> abcd = parse(inp);
  std::vector<Op> op(3);

  for(int i = 0;i < 8; i++) {
    parse_op(i, op);
    if(check_seven(abcd, op)) break;
  }

  for(int i = 0; i < 3; i++) {
    std::cout << abcd[i] << op[i];
  }
  std::cout << abcd[3] << "=7" << std::endl;
  return 0;
}
