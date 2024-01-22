#ifndef MEDIAEXTRACTOR_H
#define MEDIAEXTRACTOR_H

#include "Songs.h"

class MediaExtractor {
public:
    static Song extractMediaInfo(const std::string& filePath);
};

#endif // MEDIAEXTRACTOR_


