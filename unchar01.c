#include <stdio.h>
#include <uchar.h>

size_t UTF16StrLen(const char16_t *utf16String)
{
    if(utf16String == NULL)
        return 0;

    size_t index;
    for(index = 0; utf16String[index] != u'\0'; index++);
    return index;
}

size_t UTF16ToUTF8(char *mbBuffer, const char16_t *utf16String)
{
    if(mbBuffer == NULL || utf16String == NULL)
        return 0;
        
    mbstate_t state = { };
        
    size_t mbIndex = 0;
    for(int utf16Index = 0; utf16String[utf16Index] != u'\0'; utf16Index++)
    {
        const size_t length = c16rtomb(&mbBuffer[mbIndex], utf16String[utf16Index], &state);
        mbIndex += length;
    }
    
    mbBuffer[mbIndex] = '\0';
    
    return mbIndex;
}

int main(int argc, char *argv[])
{  
    char16_t ch = u'好';
    char chBuffer[64];
    mbstate_t state = { };
    
    size_t length = c16rtomb(chBuffer, ch, &state);
    chBuffer[length] = '\0';
    
    printf("The UTF-8 character length is: %zu, and the character is: %s\n", length, chBuffer);
    
    const char *utf8Str = u8"你好， 世界。";
    printf("The UTF-8 string is: %s\n", utf8Str);
    
    const char16_t *utf16Str = u"你好， 世界。";
    printf("The utf16 string length is: %zu\n", UTF16StrLen(utf16Str));
    
    length = UTF16ToUTF8(chBuffer, utf16Str);
    
    printf("The UTF-8 string length is: %zu, and the content is: %s\n", length, chBuffer);
    
    printf("If the converted UTF-8 string is equal to the original one? %s\n", strcmp(chBuffer, utf8Str) == 0? "YES" : "NO");
}