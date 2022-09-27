from collections import defaultdict


def solution(genres, plays):
    answer = []
    dic = defaultdict(dict)
    totaldic = defaultdict(int)
    for i, (genre, play) in enumerate(zip(genres, plays)):
        dic[genre].update({i: play})

    print(dic)
    for m in dic.items():
        total = sum((m[1].values()))
        print(total)
        totaldic[m[0]] = total
        print(totaldic)
    genre_rankings = sorted(totaldic.items(), key=lambda x: x[1], reverse=True)
    print(genre_rankings)

    for genre_ranking in genre_rankings:
        tmp = dict(dic[genre_ranking[0]])
        song_rankings = sorted(
            tmp.items(), key=lambda x: x[1], reverse=True)[0:2]
        print(song_rankings)
        if len(song_rankings) == 2:
            a = song_rankings[0]
            b = song_rankings[1]
            if a[1] == b[1]:
                if a[0] > b[0]:
                    answer.append(b[0])
                    answer.append(a[0])
                else:
                    answer.append(a[0])
                    answer.append(b[0])
            else:
                answer.append(a[0])
                answer.append(b[0])
        else:
            answer.append(song_rankings[0][0])

    return answer


if __name__ == "__main__":
    print(solution(["classic", "pop", "classic", "classic", "pop", "dance", "trtr"],
                   [500, 600, 150, 800, 2500, 500, 500]))
