#include <stdio.h>
#include <assert.h>
#include "modularity.h"


enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair color_Pair;
    color_Pair.majorColor = MajorColorNames[(pairNumber / numberOfMinorColors)];
    color_Pair.minorColor = MinorColorNames[(pairNumber % numberOfMinorColors)];
    return color_Pair;
}
void print_console(int pairnum, const char* majorColor,const char* minorColor)
{
	printf("%d | %s | %s\n", pairnum, majorColor, minorColor);
	
}

void testNumberToPair(int pairNumber,
    const char* expectedMajor,
    const char* expectedMinor)
{
	pairNumber= pairNumber-1;
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
	printf("%s, %s, %s ,%s\n",colorPair.majorColor,expectedMajor,colorPair.minorColor,expectedMinor);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
	int pair_num;
	const char* major_color;
	const char* minor_color;
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
			pair_num = i * 5 + j+1;
			major_color = majorColor[i];
			minor_color = minorColor[j];
			print_console(pair_num,major_color,minor_color);
			testNumberToPair(pair_num,major_color,minor_color);
        }
    }
    return i * j;
    
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
