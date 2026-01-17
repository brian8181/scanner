// ILogger.h
class ILogger {
public:
    virtual ~ILogger() = default; // Essential for proper memory management

    // Pure virtual functions (interface methods)
    virtual void log_info(const char* message) = 0;
    virtual void log_error(const char* message) = 0;
};
