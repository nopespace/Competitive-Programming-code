from queue import PriorityQueue
class NumberContainers:
    # lst: list
    dic: dict
    inverse_dic: dict
    removed: dict # {number: pq(index)}
        
    def __init__(self):
        self.dic = dict()
        self.inverse_dic = dict()
        
    def change(self, index: int, number: int) -> None:
        self.dic[index] = number;
        
        if number in self.inverse_dic.keys():
            self.inverse_dic[number].put(index);
        else:
            self.inverse_dic[number] = PriorityQueue();
            self.inverse_dic[number].put(index);

    def find(self, number: int) -> int:
        if(number not in self.inverse_dic.keys()):
            return -1
        
        while True:
            cur_index = self.inverse_dic[number].get() if not self.inverse_dic[number].empty() else -1
            if cur_index == -1:
                return cur_index
            if self.dic[cur_index]==number:
                self.inverse_dic[number].put(cur_index)
                return cur_index