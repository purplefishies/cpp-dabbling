#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/fileappender.h>

class CustomLayout : public log4cxx::PatternLayout {
public:
    CustomLayout() : log4cxx::PatternLayout( (std::getenv("GEODETICS_LOG_FMT") == nullptr ? "%d{yyyy-MM-dd HH:mm:ss.SSS} %-5p [%t] %f:%M: %Y %m%n%y" : std::getenv("GEODETICS_LOG_FMT"))) {
      
    }
};

// Define macros for logging

// #define LOG_DEBUG(logger, message) { LOG4CXX_DEBUG(logger, message); }
// #define LOG_INFO(logger, message)  { LOG4CXX_INFO(logger, message); }
#define LOG_ERROR(msg)     { log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger()); LOG4CXX_ERROR(logger, msg); }
#define LOG_DEBUG(message) { log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger()); LOG4CXX_DEBUG(logger, message); }
#define LOG_INFO(message)  { log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger()); LOG4CXX_INFO(logger,message ); }

int main() {
    // Configure log4cxx with the custom layout
    log4cxx::LayoutPtr layout = std::make_shared<CustomLayout>();
    log4cxx::ConsoleAppenderPtr appender = std::make_shared<log4cxx::ConsoleAppender>(layout);
    log4cxx::BasicConfigurator::configure(appender);

    // Configure FileAppender
    log4cxx::FileAppenderPtr fileAppender = std::make_shared<log4cxx::FileAppender>(layout, "foo.txt");
    log4cxx::BasicConfigurator::configure(fileAppender);

    // Get the root logger
    log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger());

    // Use the custom macros
    // LOG_DEBUG(logger, "This is a debug message.");
    // LOG_INFO(logger, "This is an info message.");
    LOG_DEBUG( "A debug message");
    LOG_INFO( "An info message");
    LOG_ERROR("Big error");

    return 0;
}


