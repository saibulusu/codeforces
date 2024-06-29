#include <iostream>
#include <vector>

using namespace std;

struct block {
  int id;
  int prev, next;
  int size;
};

int main() {
  int t, m;
  cin >> t >> m;

  vector<struct block> blocks(m);
  blocks[0].id = 0;
  blocks[0].prev = -1;
  blocks[0].next = m;
  blocks[0].size = m;

  vector<int> map(1);

  bool debug = false;

  if (debug) {
    cout << "blocks:" << endl;
    for (auto block : blocks) {
      cout << block.id << " " << block.next << " " << block.size << " "
           << block.prev << endl;
    }

    cout << "map:" << endl;
    for (int j = 1; j < map.size(); ++j) {
      cout << j << ": " << map[j] << " ";
    }

    cout << endl << endl;
  }

  for (int i = 0; i < t; ++i) {
    string op;
    cin >> op;
    if (op.compare("alloc") == 0) {
      int n;
      cin >> n;

      if (debug) {
        cout << op << " " << n << endl;
      }

      int cur = 0;
      bool added = false;
      while (cur != m) {
        if (blocks[cur].id == 0 && blocks[cur].size >= n) {
          if (blocks[cur].next < m) {
            blocks[blocks[cur].next].prev = cur + n;
          }

          int nextId = cur + n;
          if (nextId != m) {
            if (blocks[nextId].id == 0) {
              blocks[nextId].size = blocks[cur].size - n;
              blocks[nextId].next = blocks[cur].next;
              blocks[nextId].prev = cur;
            }
          }

          blocks[cur].id = map.size();
          blocks[cur].size = n;
          blocks[cur].next = cur + n;
          map.push_back(cur);

          cout << (map.size() - 1) << endl;
          added = true;
          break;
        } else {
          cur = blocks[cur].next;
        }
      }

      if (!added) {
        cout << "NULL" << endl;
      }

      if (debug) {
        cout << "blocks:" << endl;
        for (auto block : blocks) {
          cout << block.id << " " << block.next << " " << block.size << " "
               << block.prev << endl;
        }

        cout << "map:" << endl;
        for (int j = 1; j < map.size(); ++j) {
          cout << j << ": " << map[j] << " ";
        }

        cout << endl << endl;
      }
    } else if (op.compare("erase") == 0) {
      int x;
      cin >> x;

      if (debug) {
        cout << op << " " << x << endl;
      }

      if (x >= map.size() || x <= 0 || map[x] == -1) {
        cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
      } else {
        blocks[map[x]].id = 0;
        int prevId = blocks[map[x]].prev;
        int nextId = blocks[map[x]].next;
        if (debug) {
          cout << "prevId = " << prevId << " nextId = " << nextId << endl;
        }
        if (nextId != m) {
          if (blocks[nextId].id == 0) {
            blocks[map[x]].size += blocks[nextId].size;
            blocks[map[x]].next = blocks[nextId].next;
            if (blocks[map[x]].next != m) {
              blocks[blocks[map[x]].next].prev = map[x];
            }
          }
        }
        if (prevId != -1) {
          if (blocks[prevId].id == 0) {
            blocks[prevId].size += blocks[map[x]].size;
            blocks[prevId].next = blocks[map[x]].next;
            if (blocks[map[x]].next != m) {
              blocks[blocks[map[x]].next].prev = prevId;
            }
          }
        }

        map[x] = -1;
      }
      if (debug) {
        cout << "blocks:" << endl;
        for (auto block : blocks) {
          cout << block.id << " " << block.next << " " << block.size << " "
               << block.prev << endl;
        }

        cout << "map:" << endl;
        for (int j = 1; j < map.size(); ++j) {
          cout << j << ": " << map[j] << " ";
        }

        cout << endl << endl;
      }
    } else {
      if (debug) {
        cout << op << endl;
      }

      vector<struct block> copy(m);
      int curblocks = 0, curCopy = 0;
      int prevCopy = -1;
      copy[0].prev = -1;
      while (curblocks != m) {
        if (blocks[curblocks].id != 0) {
          copy[curCopy] = blocks[curblocks];
          copy[curCopy].prev = prevCopy;
          copy[curCopy].next = curCopy + copy[curCopy].size;
          if (prevCopy != -1) {
            copy[prevCopy].next = curCopy;
          }

          prevCopy = curCopy;
          map[copy[curCopy].id] = curCopy;
          curCopy += copy[curCopy].size;
        }

        curblocks = blocks[curblocks].next;
      }

      if (curCopy != m) {
        copy[curCopy].next = m;
        copy[curCopy].size = m - curCopy;
      }

      blocks = copy;

      if (debug) {
        cout << "blocks:" << endl;
        for (auto block : blocks) {
          cout << block.id << " " << block.next << " " << block.size << " "
               << block.prev << endl;
        }

        cout << "map:" << endl;
        for (int j = 1; j < map.size(); ++j) {
          cout << j << ": " << map[j] << " ";
        }

        cout << endl << endl;
      }
    }
  }

  return 0;
}
