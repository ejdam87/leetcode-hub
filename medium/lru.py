
class LRUNode(object):
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None
    
    def __repr__(self):
        return str(self.val)


class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.fst = None
        self.lst = None
        self.storage = {}

    def _shift_back(self, nd):
        before = nd.prev
        after = nd.next

        if nd == self.fst:
            self.fst = after
        else:
            before.next = after
        
        after.prev = before

        l = self.lst
        l.next = nd
        nd.prev = l
        self.lst = nd

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.storage:
            return -1

        nd = self.storage[key]
        if nd == self.lst:
            return nd.val

        self._shift_back(nd)
        return nd.val

    def _insert(self, key, val):
            nd = LRUNode(key, val)
            if self.fst is None:
                self.fst = nd
                self.lst = nd
            else:
                nd.prev = self.lst
                self.lst.next = nd
                self.lst = nd

            self.storage[key] = nd

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """

        present = True if self.get(key) != -1 else False

        if len(self.storage) == self.capacity and (not present):
            nd = self.fst
            self.fst = self.fst.next
            if self.fst is None:
                self.lst = None
            else:
                self.fst.prev = None
            del self.storage[nd.key]
            self._insert(key, value)
        elif present:
            self.storage[key].val = value
        else:
            self._insert(key, value)


cache = LRUCache(1)
cache.put(1, 1)
cache.put(2, 2)
cache.put(3, 3)

print(cache.storage)
