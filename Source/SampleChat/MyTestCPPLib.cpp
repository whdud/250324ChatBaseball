#include "MyTestCPPLib.h"
#include "Math/UnrealMathUtility.h"



FString UMyTestCPPLib::GenerateRandomAnswer() {
    TArray<int32> Numbers;
    for (int32 i = 1; i <= 9; ++i) Numbers.Add(i); // 1���� 9���� ���� �߰�
    for (int32 i = Numbers.Num() - 1; i > 0; --i) {
        int32 j = FMath::RandRange(0, i); // ������ �ε��� ����
        Numbers.Swap(i, j); // ���� ����
    }
    Numbers.SetNum(3); // �� 3�� ���ڸ� ���

    FString Answer;
    for (int32 Number : Numbers) {
        Answer += FString::FromInt(Number); // ���ڸ� ���ڿ��� ��ȯ
    }
    return Answer;
}

// ��Ʈ����ũ(S), ��(B) ���
FString UMyTestCPPLib::CalculateSB(const FString& Input, const FString& Answer) {
    // �Է°����� '/' ��ġ ã��
    int32 SlashIndex;
    if (!Input.FindChar('/', SlashIndex)) return TEXT(""); // '/'�� ������ �� ���ڿ� ��ȯ

    // '/' ���� ���ڿ� ����
    FString CleanInput = Input.Mid(SlashIndex + 1);

    // �Է°� ��ȿ�� �˻�: ���� 3, ���ڸ�, �ߺ� ����
    if (CleanInput.Len() != 3 || !CleanInput.IsNumeric()) return TEXT("Invalid input");

    TSet<char> UniqueChars;
    for (char c : CleanInput) {
        if (c == '0' || UniqueChars.Contains(c)) return TEXT("Invalid input");
        UniqueChars.Add(c);
    }

    // S/B ���
    int32 Strikes = 0, Balls = 0;
    for (int32 i = 0; i < 3; ++i) {
        int32 Digit = CleanInput[i] - '0'; // ���ڸ� ���ڷ� ��ȯ
        int32 AnswerDigit = Answer[i] - '0';
        if (AnswerDigit == Digit)
            Strikes++;
        else {
            int32 Index;
            if (Answer.FindChar(CleanInput[i], Index)) // FindChar�� ���� ���� ���� Ȯ��
                Balls++;
        }
    }

    // ���λ� ���� (��: "Host:/123" -> "Host")
    FString Prefix = Input.Left(SlashIndex);

    // ��� ��ȯ
    if (Strikes == 3) {
        return Prefix + TEXT(": 3Strkes!!! win!!");
    }
    else {
        return Prefix + TEXT(": ") + FString::Printf(TEXT("%dS %dB"), Strikes, Balls);
    }
}