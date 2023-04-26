#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

#define TIMESTAMP_FORMAT ""

enum loglevel {
	LOG_ARMAGEDDON,
	LOG_HI,
	LOG_ERR,
	LOG_WARN,
	LOG_INFO,
	LOG_DEBUG,
	LOG_TRACE,
	// keep this last
	LOG_NUM_LEVELS,
};

int log_init(FILE *, enum loglevel);
void log_teardown(void);
void log_message(enum loglevel, const char *, int, const char *, const char *, ...);
void log_hexdump(enum loglevel, const void *, size_t);

#ifdef NDEBUG
# define LOG(level, fmt, ...)
#else
# define LOG(level, fmt, ...) do { \
		log_message((level), __FILE__, __LINE__, __func__, \
				(fmt), ##__VA_ARGS__); \
	} while (0)
#endif

#define LOG_H(...) LOG(LOG_HI, __VA_ARGS__)
#define LOG_E(...) LOG(LOG_ERR, __VA_ARGS__)
#define LOG_W(...) LOG(LOG_WARN, __VA_ARGS__)
#define LOG_I(...) LOG(LOG_INFO, __VA_ARGS__)
#define LOG_D(...) LOG(LOG_DEBUG, __VA_ARGS__)
#define LOG_T(...) LOG(LOG_TRACE, __VA_ARGS__)

#endif
