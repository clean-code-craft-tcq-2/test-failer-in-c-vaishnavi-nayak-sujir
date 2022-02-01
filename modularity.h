typedef struct {
    const char* majorColor;
    const char* minorColor;
} ColorPair;

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

int numberOfMajorColors =
    sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

int numberOfMinorColors = 
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

const int MAX_COLORPAIR_NAME_CHARS = 16;
