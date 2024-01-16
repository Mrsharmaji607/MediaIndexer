
#include "MediaScanner.h"
#include <filesystem>
#include <iomanip>
#include<iostream>

namespace fs = std::filesystem;

MediaScanner::MediaScanner() {}

MediaScanner::~MediaScanner() {}

void MediaScanner::scan(const std::string& path) {
    std::cout << "Scanning path: " << path << std::endl;

    int fileCount = 0;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file() && isMediaFile(entry.path().extension().string())) {
            // Collect file details
            std::string filePath = entry.path().string();
            std::string fileName = entry.path().filename().string();
            std::string fileFormat = entry.path().extension().string();
            uintmax_t fileSize = fs::file_size(entry.path());

            mediaFiles.push_back("Name: " + fileName + ", Format: " + fileFormat +
                                 ", Path: " + filePath + ", Size: " + std::to_string(fileSize) + " bytes");

            fileCount++;
        }
    }

    // Display progress bar
    showProgressBar(100);

    std::cout << "Scanning completed. Found " << fileCount << " media files." << std::endl;
}

void MediaScanner::showProgressBar(int percentage) const {
    const int barWidth = 50;
    int pos = barWidth * percentage / 100;

    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << percentage << "%\r";
    std::cout.flush();
}

void MediaScanner::displayInformation() const {
    // Display information about the scanned media files
    std::cout << "Information about scanned media files:" << std::endl;
    for (const auto& file : mediaFiles) {
        std::cout << file << std::endl;
    }
}

void MediaScanner::help() const {
    // Display help information
    std::cout << "Help: Use the scan command to scan a specified path for media files." << std::endl;
}

bool MediaScanner::isMediaFile(const std::string &extension) const
{
    return false;
}
