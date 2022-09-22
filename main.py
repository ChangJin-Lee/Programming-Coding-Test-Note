from collections import defaultdict


def solution(genres, plays):
    answer = []
    dic = defaultdict(dict)
    totaldic = defaultdict(int)
    for (genre, play) in zip(genres, plays):
        dic[genre].update({plays.index(play): play})

    for m in dic.items():
        total = sum((m[1].values()))
        totaldic[m[0]] = total
    genre_rankings = sorted(totaldic, key=lambda x: x[1], reverse=True)

    for genre_ranking in genre_rankings:
        tmp = dict(dic[genre_ranking])
        song_rankings = sorted(
            tmp.items(), key=lambda x: x[1], reverse=True)[0:2]
        for k in song_rankings:
            answer.append(k[0])
    return answer


if __name__ == "__main__":
    print(solution(["classic", "pop", "classic", "classic", "pop"],
                   [500, 600, 150, 800, 2500]))
