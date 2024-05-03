from typing import *
class Solution:
    def constructMap(self, wordList):
        def getKey(word): return [word[:i] + '*' + word[i + 1:] for i in range(len(word))]
        indexedWord = {}
        for word in wordList:
            for key in getKey(word):
                if key not in indexedWord:
                    indexedWord[key] = set()
                indexedWord[key].add(word)
        edge_map = {}
        for (key, value) in indexedWord.items():
            for node1 in value:
                node1_idx = self.idxer[node1]
                if node1_idx not in edge_map: edge_map[node1_idx] = set()
                for node2 in value:
                    node2_idx = self.idxer[node2]
                    if node1_idx == node2_idx: continue
                    edge_map[node1_idx].add(node2_idx)
        return edge_map
    
    def bfs(self, begin, end):
        end_idx = self.idxer[end]
        visited = [False] * len(self.idxer)
        level_bfs = [self.idxer[begin]]
        visited[self.idxer[begin]] = True
        step_cnt = 1
        while len(level_bfs) != 0:
            step_cnt += 1
            current_lengh = len(level_bfs)
            for i in range(current_lengh):
                if level_bfs[i] not in self.edge_map:
                    continue
                for j in self.edge_map[level_bfs[i]]:
                    if j == end_idx: return step_cnt
                    if visited[j]: continue
                    level_bfs.append(j)
                    visited[j] = True
            level_bfs = level_bfs[current_lengh:]
        return 0
    
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList: return 0
        full_word_list = wordList + ([beginWord] if beginWord not in wordList else [])
        self.idxer = {word : i for (i, word) in enumerate(full_word_list)}
        self.r_idxer = {value : key for (key, value) in self.idxer.items()}
        self.edge_map = self.constructMap(full_word_list)

        return self.bfs(begin=beginWord, end=endWord)