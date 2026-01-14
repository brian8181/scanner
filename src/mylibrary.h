// mylibrary.h
#ifdef __cplusplus
extern "C" {
#endif

// C-compatible function declarations
void create_logger();
void log_message_c(const char* message);
void destroy_logger();

#ifdef __cplusplus
}
#endif
