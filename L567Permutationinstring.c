#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkInclusion(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2)
    {
        return false;
    }

    int count1[26] = {0};
    int count2[26] = {0};

    // Count frequencies for s1 and the first window of s2
    for (int i = 0; i < len1; i++)
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    // Check initial window
    bool match = true;
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            match = false;
            break;
        }
    }
    if (match)
        return true;

    // Slide the window through s2
    for (int i = len1; i < len2; i++)
    {
        count2[s2[i] - 'a']++;
        count2[s2[i - len1] - 'a']--;

        match = true;
        for (int j = 0; j < 26; j++)
        { // Fixed inner loop variable (j++)
            if (count1[j] != count2[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            return true;
    }

    return false;
}

int main()
{
    /* printf("case1:s1=ab;s2=eidbaooo");
     char s1[] = "ab";
     char s2[] = "eidbaooo";

     bool result = checkInclusion(s1, s2);*/
    printf("case2:s1=ab;s2=eidboaoo");
    char s1[] = "ab";
    char s2[] = "eidboaoo";
    bool result = checkInclusion(s1, s2);
    if (result)
    {
        printf("Output: true\nExplanation: s2 contains a permutation of s1.\n");
    }
    else
    {
        printf("Output: false\nExplanation: s2 does not contain a permutation of s1.\n");
    }

    return 0;
}