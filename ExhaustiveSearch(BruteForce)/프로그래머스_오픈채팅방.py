# 예전에 실제로 코테 봤을때는 어려워서 못풀었던거 같은데 시간 지나고 푸니까 10분만에 풀었음
# 좀더 간결하게 나타낼 수도 있는데, 함수로 정의해서 코드 재사용성을 올림
def solution(record):
    answer = []
    userInfo = {}

    def EnterHandler(uid, nickname):
        userInfo[uid] = nickname
        answer.append([uid, "님이 들어왔습니다."])

    def LeaveHandler(uid):
        answer.append([uid, "님이 나갔습니다."])

    def ChangeHandler(uid, nickname):
        userInfo[uid] = nickname

    for s in record:
        command = list(s.split())
        if command[0] == "Enter":
            EnterHandler(command[1], command[2])
        elif command[0] == "Leave":
            LeaveHandler(command[1])
        elif command[0] == "Change":
            ChangeHandler(command[1], command[2])

    for i in range(len(answer)):
        answer[i][0] = userInfo[answer[i][0]]
        answer[i] = "".join(answer[i])
    # print(answer)
    return answer


# 짧게 만든 버전
# def solution(record):
#     answer = []
#     userInfo = {}
#
#     for s in record:
#         command = list(s.split())
#         if command[0] == "Enter":
#             userInfo[command[1]] = command[2]
#             answer.append([command[1], "님이 들어왔습니다."])
#         elif command[0] == "Leave":
#             answer.append([command[1], "님이 나갔습니다."])
#         elif command[0] == "Change":
#             userInfo[command[1]] = command[2]
#
#     for i in range(len(answer)):
#         answer[i][0] = userInfo[answer[i][0]]
#         answer[i] = "".join(answer[i])
#     # print(answer)
#     return answer

print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]))
# ["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]