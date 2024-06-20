#include <iostream>
#include <vector>

struct block {
  int id;
  int prev, next;
  int size;
};

int main() {
  int t, m;
  std::cin >> t >> m;

  std::vector<struct block> blocks(m);
  blocks[0].id = 0;
  blocks[0].prev = -1;
  blocks[0].next = m;
  blocks[0].size = m;

  std::vector<int> map(1);

  bool debug = false;

  if (debug) {
    std::cout << "blocks:" << std::endl;
    for (auto block : blocks) {
      std::cout << block.id << " " << block.next << " " << block.size << " "
                << block.prev << std::endl;
    }

    std::cout << "map:" << std::endl;
    for (int j = 1; j < map.size(); ++j) {
      std::cout << j << ": " << map[j] << " ";
    }

    std::cout << std::endl << std::endl;
  }

  for (int i = 0; i < t; ++i) {
    std::string op;
    std::cin >> op;
    if (op.compare("alloc") == 0) {
      int n;
      std::cin >> n;

      if (debug) {
        std::cout << op << " " << n << std::endl;
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

          std::cout << (map.size() - 1) << std::endl;
          added = true;
          break;
        } else {
          cur = blocks[cur].next;
        }
      }

      if (!added) {
        std::cout << "NULL" << std::endl;
      }

      if (debug) {
        std::cout << "blocks:" << std::endl;
        for (auto block : blocks) {
          std::cout << block.id << " " << block.next << " " << block.size << " "
                    << block.prev << std::endl;
        }

        std::cout << "map:" << std::endl;
        for (int j = 1; j < map.size(); ++j) {
          std::cout << j << ": " << map[j] << " ";
        }

        std::cout << std::endl << std::endl;
      }
    } else if (op.compare("erase") == 0) {
      int x;
      std::cin >> x;

      if (debug) {
        std::cout << op << " " << x << std::endl;
      }

      if (x >= map.size() || x <= 0 || map[x] == -1) {
        std::cout << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
      } else {
        blocks[map[x]].id = 0;
        int prevId = blocks[map[x]].prev;
        int nextId = blocks[map[x]].next;
        if (debug) {
          std::cout << "prevId = " << prevId << " nextId = " << nextId
                    << std::endl;
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
        std::cout << "blocks:" << std::endl;
        for (auto block : blocks) {
          std::cout << block.id << " " << block.next << " " << block.size << " "
                    << block.prev << std::endl;
        }

        std::cout << "map:" << std::endl;
        for (int j = 1; j < map.size(); ++j) {
          std::cout << j << ": " << map[j] << " ";
        }

        std::cout << std::endl << std::endl;
      }
    } else {
      if (debug) {
        std::cout << op << std::endl;
      }

      std::vector<struct block> copy(m);
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
        std::cout << "blocks:" << std::endl;
        for (auto block : blocks) {
          std::cout << block.id << " " << block.next << " " << block.size << " "
                    << block.prev << std::endl;
        }

        std::cout << "map:" << std::endl;
        for (int j = 1; j < map.size(); ++j) {
          std::cout << j << ": " << map[j] << " ";
        }

        std::cout << std::endl << std::endl;
      }
    }
  }

  return 0;
}
