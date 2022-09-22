from collections import defaultdict


def solution(genres, plays):
    answer = []
    dic = defaultdict(dict)
    totaldic = defaultdict(int)
    for (genre, play) in zip(genres, plays):
        dic[genre].update({plays.index(play): play})

    print(dic)
    for m in dic.items():
        total = sum((m[1].values()))
        totaldic[m[0]] = total

    genre_rankings = sorted(totaldic, key=lambda x: x[1], reverse=True)

    for genre_ranking in genre_rankings:
        tmp = dic[genre_ranking]
        print(tmp)
        song_rankings = sorted(tmp, key=lambda x: x[1], reverse=True)
        print(song_rankings)
    return answer


if __name__ == "__main__":
    solution(["classic", "pop", "classic", "classic", "pop"],
             [500, 600, 150, 800, 2500])
