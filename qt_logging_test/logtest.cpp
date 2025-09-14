#ifdef LOG4CXX

#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/fileappender.h>
#include <string>
#include <cstring>

#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_HEX_D78787 "\x1b[38;2;215;135;135m" // Custom color using RGB


class CustomLayout : public log4cxx::PatternLayout {
public:
    CustomLayout() : log4cxx::PatternLayout( (std::getenv("GEODETICS_LOG_FMT") == nullptr ? "%d %-5p [%t] %f:%M: %Y %m%n%y" : std::getenv("GEODETICS_LOG_FMT"))) {
      
    }
};

class ColoredPatternLayout : public log4cxx::PatternLayout {
public:
    ColoredPatternLayout(const log4cxx::LogString& pattern) : PatternLayout(pattern) {}

    virtual void format(log4cxx::LogString& output, const log4cxx::spi::LoggingEventPtr& event, log4cxx::helpers::Pool& p) const override {
        log4cxx::LogString message;
        PatternLayout::format(message, event, p);

        std::string convertedMessage;
        log4cxx::helpers::Transcoder::encode(message, convertedMessage);

        // Apply colors based on the log level
        std::string levelStr;
        log4cxx::helpers::Transcoder::encode(event->getLevel()->toString(), levelStr);

        if (levelStr == "DEBUG") {
            convertedMessage = ANSI_COLOR_BLUE + convertedMessage + ANSI_COLOR_RESET;
        } else if (levelStr == "ERROR") {
            convertedMessage = ANSI_COLOR_HEX_D78787 + convertedMessage + ANSI_COLOR_RESET;
        }

        // Timestamp and function in green
        size_t pos = convertedMessage.find('%');
        if (pos != std::string::npos) {
            convertedMessage.insert(pos, ANSI_COLOR_GREEN);
            convertedMessage += ANSI_COLOR_RESET;
        }

        log4cxx::helpers::Transcoder::decode(convertedMessage, output);
    }
};


#define LOG_ERROR(msg)     { log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger()); LOG4CXX_ERROR(logger, msg); }
#define LOG_FATAL(msg)     { log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger()); LOG4CXX_FATAL(logger, msg); }
#define LOG_DEBUG(message) { log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger()); LOG4CXX_DEBUG(logger, message); }
#define LOG_INFO(message)  { log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger()); LOG4CXX_INFO(logger,message ); }
#define LOG_WARN(message)  { log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger()); LOG4CXX_WARN(logger,message ); }


#else
#define _CRT_SECURE_NO_WARNINGS

#include <QLoggingCategory>
#include <QDebug>
#include <QString>
#include <stdio.h>
#include <stdlib.h>

#define LOG_DEBUG(...) \
    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug().noquote() << __VA_ARGS__

#define LOG_INFO(...) \
    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).info().noquote() << __VA_ARGS__

#define LOG_WARN(...) \
    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).warning().noquote() << __VA_ARGS__

#define LOG_ERROR(...) \
    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).critical().noquote() << __VA_ARGS__

#define LOG_FATAL(...) \
    QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).fatal(__VA_ARGS__)


// #define LOG_FATAL(...)							\
//     QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).fatal() << __VA_ARGS__

// #define LOG_DEBUG(...) { qDebug(__VA_ARGS__); }
// #define LOG_INFO(...)  { qInfo(__VA_ARGS__); }
// #define LOG_WARN(...)  { qWarning(__VA_ARGS__); }
// #define LOG_ERROR(...) { qCritical(__VA_ARGS__); }
// #define LOG_FATAL(...)  { qFatal(__VA_ARGS__); }

#endif

// Define macros for logging

// #define LOG_DEBUG(logger, message) { LOG4CXX_DEBUG(logger, message); }
// #define LOG_INFO(logger, message)  { LOG4CXX_INFO(logger, message); }

void do_something_else()
{
  LOG_DEBUG("Another place");

  LOG_WARN("Something is strange...");
}
void do_fatal()
{
  LOG_FATAL("CAn't continue....");
}


void do_something()
{
  LOG_DEBUG("Here i am");
  do_something_else();
  LOG_ERROR("Oops...a problem");
  LOG_INFO("An info message");
  do_fatal();
}
#ifdef LOG4CXX

#else

QtMessageHandler originalHandler = nullptr;


void logToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString message = qFormatLogMessage(type, context, msg);
    static FILE *f = fopen("log.txt", "a");
    fprintf(f, "%s\n", qPrintable(message));
    fflush(f);

    if (originalHandler) {
        (*originalHandler)(type, context, msg);
    }
}
#endif

int main() {
#ifdef LOG4CXX
    // Configure log4cxx with the custom layout
    // log4cxx::LayoutPtr layout = std::make_shared<CustomLayout>();
    log4cxx::LayoutPtr layout = std::make_shared<ColoredPatternLayout>(
        std::getenv("GEODETICS_LOG_FMT") == nullptr ? "%d %-5p [%t] %f:%M: %Y %m%n%y" :
        log4cxx::LogString(std::getenv("GEODETICS_LOG_FMT"), std::getenv("GEODETICS_LOG_FMT") + strlen(std::getenv("GEODETICS_LOG_FMT")))
        );

    log4cxx::ConsoleAppenderPtr appender = std::make_shared<log4cxx::ConsoleAppender>(layout);
    log4cxx::BasicConfigurator::configure(appender);

    // Configure FileAppender
    log4cxx::FileAppenderPtr fileAppender = std::make_shared<log4cxx::FileAppender>(layout, "log.txt");
    log4cxx::BasicConfigurator::configure(fileAppender);

    // Get the root logger
    log4cxx::LoggerPtr logger(log4cxx::Logger::getRootLogger());
#else
    originalHandler = qInstallMessageHandler(logToFile);
#endif

 

    // Use the custom macros
    // LOG_DEBUG(logger, "This is a debug message.");
    // LOG_INFO(logger, "This is an info message.");
    LOG_DEBUG( "A debug message");
    LOG_INFO( "An info message");
    LOG_ERROR("Big error");
    
    do_something();
    return 0;
}


