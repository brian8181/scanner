// mylibrary_impl.cpp
#include "mylibrary.h"
#include <iostream>

// Internal C++ class
class LoggerImpl {
public:
    void log(const char* msg) {
        std::cout << "C++ implementation: " << msg << std::endl;
    }
};

// Global pointer for simplicity, or use a factory pattern
static LoggerImpl* g_logger = nullptr;

extern "C" {
    void create_logger() {
        if (g_logger == nullptr) {
            g_logger = new LoggerImpl();
        }
    }

    void log_message_c(const char* message) {
        if (g_logger != nullptr) {
            g_logger->log(message);
        }
    }

    void destroy_logger() {
        delete g_logger;
        g_logger = nullptr;
    }
}
