#include <iostream>
#include <vector>
 
struct block
{
	int id;
	int prev, next;
	int size;
};
 
int main()
{
	int t, m;
	std::cin >> t >> m;
 
	std::vector < struct block > bytes(m);
	bytes[0].id = 0;
	bytes[0].prev = -1;
	bytes[0].next = m;
	bytes[0].size = m;
 
	std::vector<int> map(1);
 
	bool debug = false;
	
  if (debug)
  {
		std::cout << "bytes:" << std::endl;
		for (auto byte: bytes)
		{
				std::cout << byte.id << " " << byte.next << " " << byte.size << " " << byte.prev << std::endl;
		}
 
		std::cout << "map:" << std::endl;
		for (int j = 1; j < map.size(); ++j)
		{
			std::cout << j << ": " << map[j] << " ";
		}
 
		std::cout << std::endl << std::endl;
	}
 
	for (int i = 0; i < t; ++i)
	{
		std::string op;
		std::cin >> op;
		if (op.compare("alloc") == 0)
		{
			int n;
			std::cin >> n;
 
			if (debug)
			{
				std::cout << op << " " << n << std::endl;
			}
 
			int cur = 0;
			bool added = false;
			while (cur != m)
			{
				if (bytes[cur].id == 0 && bytes[cur].size >= n)
				{
					if (bytes[cur].next < m)
					{
						bytes[bytes[cur].next].prev = cur + n;
					}
 
					int nextId = cur + n;
					if (nextId != m)
					{
            if (bytes[nextId].id == 0) {
              bytes[nextId].size = bytes[cur].size - n;
              bytes[nextId].next = bytes[cur].next;
              bytes[nextId].prev = cur;
            }
					}
 
					bytes[cur].id = map.size();
					bytes[cur].size = n;
					bytes[cur].next = cur + n;
					map.push_back(cur);
 
					std::cout << (map.size() - 1) << std::endl;
					added = true;
					break;
				}
				else
				{
					cur = bytes[cur].next;
				}
			}
 
			if (!added)
			{
				std::cout << "NULL" << std::endl;
			}
 
			if (debug)
			{
				std::cout << "bytes:" << std::endl;
				for (auto byte: bytes)
				{
          std::cout << byte.id << " " << byte.next << " " << byte.size << " " << byte.prev << std::endl;
				}
 
				std::cout << "map:" << std::endl;
				for (int j = 1; j < map.size(); ++j)
				{
					std::cout << j << ": " << map[j] << " ";
				}
 
				std::cout << std::endl << std::endl;
			}
		}
		else if (op.compare("erase") == 0)
		{
			int x;
			std::cin >> x;
 
			if (debug)
			{
				std::cout << op << " " << x << std::endl;
			}
 
			if (x >= map.size() || x <= 0 || map[x] == -1)
			{
				std::cout << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
			}
			else
			{
				bytes[map[x]].id = 0;
				int prevId = bytes[map[x]].prev;
				int nextId = bytes[map[x]].next;
				if (debug) {
				  std::cout << "prevId = " << prevId << " nextId = " << nextId << std::endl;
				}
				if (nextId != m)
				{
					if (bytes[nextId].id == 0)
					{
						bytes[map[x]].size += bytes[nextId].size;
						bytes[map[x]].next = bytes[nextId].next;
						if (bytes[map[x]].next != m)
						{
							bytes[bytes[map[x]].next].prev = map[x];
						}
					}
				}
				if (prevId != -1)
				{
					if (bytes[prevId].id == 0)
					{
						bytes[prevId].size += bytes[map[x]].size;
						bytes[prevId].next = bytes[map[x]].next;
						if (bytes[map[x]].next != m)
						{
							bytes[bytes[map[x]].next].prev = prevId;
						}
					}
				}
 
				map[x] = -1;
			}
      if (debug) {
				std::cout << "bytes:" << std::endl;
				for (auto byte: bytes)
				{
          std::cout << byte.id << " " << byte.next << " " << byte.size << " " << byte.prev << std::endl;
				}
 
				std::cout << "map:" << std::endl;
				for (int j = 1; j < map.size(); ++j)
				{
					std::cout << j << ": " << map[j] << " ";
				}
 
				std::cout << std::endl << std::endl;
			}
		}
		else
		{
			if (debug)
			{
				std::cout << op << std::endl;
			}
 
			std::vector < struct block > copy(m);
			int curBytes = 0, curCopy = 0;
			int prevCopy = -1;
			copy[0].prev = -1;
			while (curBytes != m)
			{
				if (bytes[curBytes].id != 0)
				{
					copy[curCopy] = bytes[curBytes];
					copy[curCopy].prev = prevCopy;
					copy[curCopy].next = curCopy + copy[curCopy].size;
					if (prevCopy != -1)
					{
						copy[prevCopy].next = curCopy;
					}
 
					prevCopy = curCopy;
					map[copy[curCopy].id] = curCopy;
					curCopy += copy[curCopy].size;
				}
 
				curBytes = bytes[curBytes].next;
			}
 
			if (curCopy != m)
			{
				copy[curCopy].next = m;
				copy[curCopy].size = m - curCopy;
			}
 
			bytes = copy;
 
			if (debug)
			{
				std::cout << "bytes:" << std::endl;
				for (auto byte: bytes)
				{
          std::cout << byte.id << " " << byte.next << " " << byte.size << " " << byte.prev << std::endl;
				}
 
				std::cout << "map:" << std::endl;
				for (int j = 1; j < map.size(); ++j)
				{
					std::cout << j << ": " << map[j] << " ";
				}
 
				std::cout << std::endl << std::endl;
			}
		}
	}
 
	return 0;
}
