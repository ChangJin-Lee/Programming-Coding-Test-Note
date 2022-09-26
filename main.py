def solution(jobs):
    answer = 0
    n = len(jobs)
    jobs = sorted(jobs, key=lambda x: x[0])
    while jobs:
        init = jobs.pop(0)
        zeropoint = init[1]+init[0]
        answer += init[1]
        mjobs = sorted(jobs, key=lambda x: (x[1]))
        for job in mjobs:
            if job[0] <= zeropoint:
                jobs.pop(jobs.index(job))
                answer += zeropoint - job[0] + job[1]
                zeropoint += job[1]
                break
        if len(jobs) == 1:
            answer += jobs[0][1]
            break
    return answer // n


if __name__ == "__main__":
    print(solution([[0, 3], [1, 10], [2, 8]]))
    print(solution([[0, 3], [1, 9], [2, 6]]))
