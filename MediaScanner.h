#ifndef MEDIASCANNER_H
#define MEDIASCANNER_H

#include "MediaDatabse.h"
#include "MediaExtractor.h"
#include <vector>
#include <string>
#include "Songs.h"
#include <filesystem>

class MediaScanner {
   
private:
   
    //MediaExtractor mediaExtractor;
    std::string folderPath;
    std::vector<Song> songs; //reference member
  

public:
    // Constructor that takes the folder path as an argument
    //MediaScanner(std::vector<Song>& songsRef, const std::string& Pathfolder);
    void displayFileInfo(const std::filesystem::directory_entry& entry) const;
    //std::string getFileExtension(const std::string& filePath) const;
    //MediaScanner(std::string st);

    void scanMedia(const std::string& folderPath);
    //void scanMedia();
    void displayScanProgress(int percentage) const;
    void displaySongInfo() const;
    void displayHelp() const;
};

#endif // MEDIASCANNER_H