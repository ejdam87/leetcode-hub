from typing import List
from heapq import heappop, heappush, heapify


class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.q = []
        self.entries = {}
        self.task_to_user = {}
        for uid, tid, p in tasks:
            self.add(uid, tid, p)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.entries[taskId] = (priority, userId)
        self.task_to_user[taskId] = userId
        heappush(self.q, (-priority, -taskId, userId))

    def edit(self, taskId: int, newPriority: int) -> None:
        self.add(self.task_to_user[taskId], taskId, newPriority)

    def rmv(self, taskId: int) -> None:
        top_priority = self.q[0][0]
        self.edit(taskId, -top_priority + 1)
        self.execTop()
        self.entries[taskId] = "removed"
        self.task_to_user[taskId] = "removed"

    def execTop(self) -> int:
        while self.q:
            np, ntid, uid = heappop(self.q)
            if self.entries[-ntid] == (-np, uid):
                self.entries[-ntid] = "removed"
                self.task_to_user[-ntid] = "removed"
                return uid

        return -1

obj = TaskManager([[1,101,8],[2,102,20],[3,103,5]])
obj.add(4, 104, 5)
obj.edit(102, 9)
uid = obj.execTop()
print(uid)
obj.rmv(101)
obj.add(50, 101, 8)
uid = obj.execTop()
print(uid)
