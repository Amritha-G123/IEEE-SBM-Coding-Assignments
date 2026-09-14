#include <stdio.h>
#include <string.h>

int characterReplacement(char *s, int k)
{
    int count[26] = {0};

    int left = 0;
    int right;
    int maxCount = 0;
    int maxLength = 0;

    int n = strlen(s);

    for (right = 0; right < n; right++)
    {
        count[s[right] - 'A']++;

        if (count[s[right] - 'A'] > maxCount)
        {
            maxCount = count[s[right] - 'A'];
        }

        // Number of characters that need replacement
        while ((right - left + 1) - maxCount > k)
        {
            count[s[left] - 'A']--;
            left++;
        }

        if (right - left + 1 > maxLength)
        {
            maxLength = right - left + 1;
        }
    }

    return maxLength;
}

int main()
{
    char s[] = "AABABBA";
    int k = 1;

    int answer = characterReplacement(s, k);

    printf("Longest length = %d\n", answer);

    return 0;
}