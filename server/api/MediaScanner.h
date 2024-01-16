// Aims to scan the media files from external storage


#ifndef MEDIASCANNER_H
#define MEDIASCANNER_H

#include <iostream>
#include <vector>

class MediaScanner {
public:
    MediaScanner();
    ~MediaScanner();

    void scan(const std::string& path);
    void showProgressBar(int percentage) const;
    void displayInformation() const;
    void help() const;

    const std::vector<std::string>& getMediaFiles() const;

private:
    std::vector<std::string> mediaFiles;
    bool isMediaFile(const std::string& extension) const;
};

#endif // MEDIASCANNER_H

