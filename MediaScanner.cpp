#include "MediaScanner.h"
#include "MediaExtractor.h"
#include "Songs.h"
#include <iostream>
#include <filesystem>
#include <fstream>

bool isMP3(const std::string &filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cout << "Error opening file: " << filePath << "\n";
        return false;
    }

    // Read the first few bytes of the file (MP3 file header)
    const int bufferSize = 3;
    std::vector<char> buffer(bufferSize);
    file.read(buffer.data(), bufferSize);

    // Check for the MP3 file header signature
    bool isMP3 = (buffer[0] == 'I' && buffer[1] == 'D' && buffer[2] == '3');

    return isMP3;
}

void MediaScanner::scanMedia(const std::string& folderPath) {
    int totalFiles = 0;
    int scannedFiles = 0;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            totalFiles++;
        }
    }

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            if (extension == ".mp3" || extension == ".aac" || extension == ".flv" || extension == ".txt") {

                // checking if the file size is greater than 0 and is an MP3 file
                if (entry.file_size() > 0 && isMP3(entry.path().string())) {
                    Song song = MediaExtractor::extractMediaInfo(entry.path().string());
                    songs.emplace_back(song);

                    scannedFiles++;
                } else {
                    scannedFiles++;
                    // Skip files with zero bytes or non-MP3 files
                    //std::cout << "Skipping file: " << entry.path().filename() << std::endl;
                }

                float progress = (static_cast<float>(scannedFiles) / totalFiles) * 100;
                displayScanProgress(progress);
            }
        }
    }

    std::cout << "\n Scan Completed!\n";
}

// void MediaScanner::scanMedia(const std::string& folderPath) {
//     int totalFiles = 0;
//     int scannedFiles = 0;

//     for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
//         if (entry.is_regular_file()) {
//             std::string extension = entry.path().extension().string();
//             if (extension == ".mp3" || extension == ".aac" || extension == ".flv" || extension == ".txt") {
//                 totalFiles++;

//                 // checking if the file size is greater than 0 and is an MP3 file
//                 if (entry.file_size() > 0 && isMP3(entry.path().string())) {
//                     Song song = MediaExtractor::extractMediaInfo(entry.path().string());
//                     songs.emplace_back(song);

//                     scannedFiles++;

//                     float progress = ((scannedFiles * 100) / totalFiles);
//                     displayScanProgress(progress);
//                 } else {
//                     // Skip files with zero bytes or non-MP3 files
//                     //std::cout << "Skipping file: " << entry.path().filename() << std::endl;
//                 }
//             }
//         }
//     }

//     std::cout << "\n Scan Completed!\n";
// }


// void MediaScanner::scanMedia(const std::string& folderPath){
//     int totalFiles = 0;
//     int scannedFiles = 0;


//     // for (const auto& entry:std::filesystem::directory_iterator(folderPath)) {
//     //     if (entry.path().extension() == ".mp3" || entry.path().extension() == ".aac" || entry.path().extension() == ".flv") {
//     //         totalFiles++;
//     //     }
//     // }


//     // for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
//     //    if (entry.path().extension() == ".mp3" || entry.path().extension() == ".aac" || entry.path().extension() == ".flv"
//     //      || entry.path().extension() == ".txt" ) {
//     //         std::string filePath = entry.path().string();





//     bool isMP3(const std::string &filePath){
//     std::ifstream file(filePath, std::ios::binary);
//     if (!file) {
//         std::cout << "Error opening file: " << filePath << "\n";
//         return false;
//     }

//     // Read the first few bytes of the file (MP3 file header)
//     const int bufferSize = 3;
//     std::vector<char> buffer(bufferSize);
//     file.read(buffer.data(), bufferSize);

//     // Check for the MP3 file header signature
//     bool isMP3 = (buffer[0] == 'I' && buffer[1] == 'D' && buffer[2] == '3');

//     return isMP3;
// }

//             //checking if the file size is greater than 0
//             if(entry.file_size()>0){

//             Song song = MediaExtractor::extractMediaInfo(filePath);
//             songs.emplace_back(song);
            
//             scannedFiles++;
            
//             float progress = ((scannedFiles *100) / totalFiles);
//             //float progress = std::min(static_cast<float>(scannedFiles) / totalFiles *100, 100.0f);
//             displayScanProgress(progress);

           
//             }
               
//          else  {
//                 // Skip files with zero bytes
//                 std::cout << "Skipping file with zero bytes: "<<std::endl;
//             }

//         std::cout << "\n Scan Completed!\n";

 
// } 
             
    
void MediaScanner::displayScanProgress(int percentage) const
{
    std::cout << "[" << percentage << "%] ";
    std::cout.flush();

}

void MediaScanner::displaySongInfo()const{
    for (const auto& song : songs){
        std::cout << "Name: " << song.name << "\n"
                  << "Format: " << song.format << "\n"
                  << "Path: " << song.path << "\n"
                  << "Size: " << song.size << " bytes\n\n";
    }
    
}

void MediaScanner::displayHelp() const {
    std::cout << "Pls Choose From the Below  Options:\n\n"
              << "1. Scan for songs\n"
              << "2. Display information of founded songs\n"
              << "3. Help\n"
              << "4. Exit\n";
}
