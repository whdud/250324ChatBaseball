#include "MyTestCPPLib.h"
#include "Math/UnrealMathUtility.h"



FString UMyTestCPPLib::GenerateRandomAnswer() {
    TArray<int32> Numbers;
    for (int32 i = 1; i <= 9; ++i) Numbers.Add(i); // 1부터 9까지 숫자 추가
    for (int32 i = Numbers.Num() - 1; i > 0; --i) {
        int32 j = FMath::RandRange(0, i); // 무작위 인덱스 선택
        Numbers.Swap(i, j); // 숫자 섞기
    }
    Numbers.SetNum(3); // 앞 3개 숫자만 사용

    FString Answer;
    for (int32 Number : Numbers) {
        Answer += FString::FromInt(Number); // 숫자를 문자열로 변환
    }
    return Answer;
}

// 스트라이크(S), 볼(B) 계산
FString UMyTestCPPLib::CalculateSB(const FString& Input, const FString& Answer) {
    // 입력값에서 '/' 위치 찾기
    int32 SlashIndex;
    if (!Input.FindChar('/', SlashIndex)) return TEXT(""); // '/'가 없으면 빈 문자열 반환

    // '/' 뒤의 문자열 추출
    FString CleanInput = Input.Mid(SlashIndex + 1);

    // 입력값 유효성 검사: 길이 3, 숫자만, 중복 없음
    if (CleanInput.Len() != 3 || !CleanInput.IsNumeric()) return TEXT("Invalid input");

    TSet<char> UniqueChars;
    for (char c : CleanInput) {
        if (c == '0' || UniqueChars.Contains(c)) return TEXT("Invalid input");
        UniqueChars.Add(c);
    }

    // S/B 계산
    int32 Strikes = 0, Balls = 0;
    for (int32 i = 0; i < 3; ++i) {
        int32 Digit = CleanInput[i] - '0'; // 문자를 숫자로 변환
        int32 AnswerDigit = Answer[i] - '0';
        if (AnswerDigit == Digit)
            Strikes++;
        else {
            int32 Index;
            if (Answer.FindChar(CleanInput[i], Index)) // FindChar로 문자 포함 여부 확인
                Balls++;
        }
    }

    // 접두사 추출 (예: "Host:/123" -> "Host")
    FString Prefix = Input.Left(SlashIndex);

    // 결과 반환
    if (Strikes == 3) {
        return Prefix + TEXT(": 3Strkes!!! win!!");
    }
    else {
        return Prefix + TEXT(": ") + FString::Printf(TEXT("%dS %dB"), Strikes, Balls);
    }
}