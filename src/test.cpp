bool isWindows(){
    #ifdef _WIN32
    bool os = true;
    #elif __unix__ || __unix || unix || __APPLE__ || __MACH__ || __linux__
    bool os = false;
    #else
    std::cout << "Unknown OS\n";
    exit;
    #endif
    return os;
}