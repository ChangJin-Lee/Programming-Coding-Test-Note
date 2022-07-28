from collections import deque


def solution(n, weak, dist):
    dist.sort(reverse=True)  # 멀리갈 수 있는 친구순

    q = deque([weak])
    visited = set()
    visited.add(tuple(weak))

    for i in range(len(dist)):
        d = dist[i]
        # print(d, q)
        for _ in range(len(q)):
            current = q.popleft()
            for p in current:
                l = p
                r = (p + d) % n
                # print(l, r)
                if l < r:
                    temp = tuple(filter(lambda x: x < l or x > r, current))
                else:
                    temp = tuple(filter(lambda x: x < l and x > r, current))

                # print(temp)
                if len(temp) == 0:
                    return i + 1
                elif temp not in visited:
                    visited.add(temp)
                    q.append(list(temp))
    return -1