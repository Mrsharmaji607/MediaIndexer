#include "MediaScanner.h"
#include "MediaExtractor.h"
#include "Songs.h"
#include <iostream>
#include <filesystem>

/*MediaScanner::MediaScanner(std::string st){

}*/

//MediaScanner::MediaScanner(std::vector<Song>& songsRef,const std::string& pathfolder)
  //  :songs(songsRef),folderPath(pathfolder) {}

void MediaScanner::scanMedia(const std::string& folderPath){
    int totalFiles = 0;
    int scannedFiles = 0;


    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".mp3" || entry.path().extension() == ".aac" || entry.path().extension() == ".flv") {
            totalFiles++;
        }
    }


    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
       if (entry.path().extension() == ".mp3" || entry.path().extension() == ".aac" || entry.path().extension() == ".flv") {
            std::string filePath = entry.path().string();
            Song song = MediaExtractor::extractMediaInfo(filePath);
            songs.emplace_back(song);
            //std::cout<<std::endl<<totalFiles<<std::endl;
            scannedFiles++;
            //std::cout<<std::endl<<scannedFiles<<std::endl;
            float progress = ((scannedFiles *100) / totalFiles);
            //std::cout<<std::endl<<progress<<std::endl;
           displayScanProgress(progress);
        }
    }

    std::cout << "\n Scan Completed!\n";
}



void MediaScanner::displayScanProgress(int percentage) const
{
    std::cout << "[" << percentage << "%] ";
    std::cout.flush();

}

void MediaScanner::displaySongInfo() const {

    for (const auto& entry:std::filesystem::directory_iterator(folderPath)) {
        const std::string filePath = entry.path().string();

        if (entry.is_regular_file()) {
            std::string fileExtension = getFileExtension(filePath);

            if (fileExtension == "mp3") {
                // Display information only for .mp3 files
                displayFileInfo(entry);
            }
        }
    }
}

void MediaScanner::displayFileInfo(const std::filesystem::directory_entry &entry) const
{
    
}

std::string MediaScanner::getFileExtension(const std::string &filePath) const
{
    size_t dotIndex = filePath.find_last_of('.');
    if (dotIndex != std::string::npos) {
        return filePath.substr(dotIndex + 1);
    }
    return "";
}
// void MediaScanner::displaySongInfo()const{
//     for (const auto& song : songs){
//         std::cout << "Name: " << song.name << "\n"
//                   << "Format: " << song.format << "\n"
//                   << "Path: " << song.path << "\n"
//                   << "Size: " << song.size << " bytes\n\n";
//     }
    
// }

void MediaScanner::displayHelp() const {
    std::cout << "Options:\n"
              << "1. Scan for songs\n"
              << "2. Display information of founded songs\n"
              << "3. Help\n"
              << "4. Exit\n";
}
