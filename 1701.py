from typing import *
class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        total_wait_time = 0
        last_finished_time = 0
        for i, (arrive_time, cost_time) in enumerate(customers):
            if last_finished_time > arrive_time:
                total_wait_time += last_finished_time - arrive_time
            start_time = max(arrive_time, last_finished_time)
            end_time = start_time + cost_time
            last_finished_time = end_time
            total_wait_time += cost_time
        return total_wait_time / len(customers)