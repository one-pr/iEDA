/*
 * @Author: your name
 * @Date: 2021-09-14 20:20:00
 * @LastEditTime: 2021-12-13 14:41:45
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置:
 * https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /iEDA/src/iUtility/log/Log.hh
 */
/**
 * @file Log.h
 * @author simin tao (taosm@pcl.ac.cn)
 * @brief The file is designed for log utility tool.
 * @version 0.1
 * @date 2020-11-12
 *
 * @copyright Copyright (c) 2020 PCL EDA
 *
 */

#pragma once

#include <glog/logging.h>

namespace ieda {

/**
 * @brief The log module is a wrapper of glog.The glog define a bunch of macros
 * for logging.We may be build our log module.The user guide of log can be found
 * from glog.
 *
 */
class Log {
  enum class LogServerity : int {
    kInfo = 0,
    kWarning = 1,
    kError = 2,
    KFatal = 3
  };

 public:
  static void init(char* argv[]);
  static void end();
  static void setVerboseLogLevel(const char* module_name, int level);
};

/*The log print category of info warning error fatal. */
#define LOG_INFO LOG(INFO)
#define LOG_WARNING LOG(WARNING)
#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)

/*The debug log print category, that would not print in relase mode.*/
#define DLOG_INFO DLOG(INFO)
#define DLOG_WARNING DLOG(WARNING)
#define DLOG_ERROR DLOG(ERROR)
#define DLOG_FATAL DLOG(FATAL)

/*conditional log*/
#define LOG_INFO_IF(condition) LOG_IF(INFO, condition)
#define LOG_WARNING_IF(condition) LOG_IF(WARNING, condition)
#define LOG_ERROR_IF(condition) LOG_IF(ERROR, condition)
#define LOG_FATAL_IF(condition) LOG_IF(FATAL, condition)

/*periodically log*/
#define LOG_INFO_EVERY_N(n) LOG_EVERY_N(INFO, n)
#define LOG_WARNING_EVERY_N(n) LOG_EVERY_N(WARNING, n)
#define LOG_ERROR_EVERY_N(n) LOG_EVERY_N(ERROR, n)
#define LOG_FATAL_EVERY_N(n) LOG_EVERY_N(FATAL, n)

/*conditional and periodically log*/
#define LOG_INFO_IF_EVERY_N(condition, n) LOG_IF_EVERY_N(INFO, condition, n)
#define LOG_WARNING_IF_EVERY_N(condition, n) \
  LOG_IF_EVERY_N(WARNING, condition, n)
#define LOG_ERROR_IF_EVERY_N(condition, n) LOG_IF_EVERY_N(ERROR, condition, n)
#define LOG_FATAL_IF_EVERY_N(condition, n) LOG_IF_EVERY_N(FATAL, condition, n)

/*print only first n*/
#define LOG_INFO_FIRST_N(n) LOG_FIRST_N(INFO, n)
#define LOG_WARNING_FIRST_N(n) LOG_FIRST_N(WARNING, n)
#define LOG_ERROR_FIRST_N(n) LOG_FIRST_N(ERROR, n)
#define LOG_FATAL_FIRST_N(n) LOG_FIRST_N(FATAL, n)

/*print in debug mode below. */
#define DLOG_INFO_IF(condition) DLOG_IF(INFO, condition)
#define DLOG_WARNING_IF(condition) DLOG_IF(WARNING, condition)
#define DLOG_ERROR_IF(condition) DLOG_IF(ERROR, condition)
#define DLOG_FATAL_IF(condition) DLOG_IF(FATAL, condition)

#define DLOG_INFO_EVERY_N(n) DLOG_EVERY_N(INFO, n)
#define DLOG_WARNING_EVERY_N(n) DLOG_EVERY_N(WARNING, n)
#define DLOG_ERROR_EVERY_N(n) DLOG_EVERY_N(ERROR, n)
#define DLOG_FATAL_EVERY_N(n) DLOG_EVERY_N(FATAL, n)

#define DLOG_INFO_IF_EVERY_N(condition, n) DLOG_IF_EVERY_N(INFO, condition, n)
#define DLOG_WARNING_IF_EVERY_N(condition, n) \
  DLOG_IF_EVERY_N(WARNING, condition, n)
#define DLOG_ERROR_IF_EVERY_N(condition, n) DLOG_IF_EVERY_N(ERROR, condition, n)
#define DLOG_FATAL_IF_EVERY_N(condition, n) DLOG_IF_EVERY_N(FATAL, condition, n)

#define DLOG_INFO_FIRST_N(n) LOG_FIRST_N(INFO, n)
#define DLOG_WARNING_FIRST_N(n) LOG_FIRST_N(WARNING, n)
#define DLOG_ERROR_FIRST_N(n) LOG_FIRST_N(ERROR, n)
#define DLOG_FATAL_FIRST_N(n) LOG_FIRST_N(FATAL, n)

// verbose log
#define DVERBOSE_VLOG(verbose_level) VLOG(verbose_level)
#define VERBOSE_LOG(verbose_level) VLOG(verbose_level)

#define DVERBOSE_VLOG_IF(verbose_level, condition) \
  VLOG_IF(verbose_level, condition)
#define VERBOSE_LOG_IF(verbose_level, condition) \
  VLOG_IF(verbose_level, condition)

#define DVERBOSE_VLOG_EVERY_N(verbose_level, n) VLOG_EVERY_N(verbose_level, n)
#define VERBOSE_VLOG_EVERY_N(verbose_level, n) VLOG_EVERY_N(verbose_level, n)

#define DVERBOSE_VLOG_IF_EVERY_N(verbose_level, condition, n) \
  VLOG_IF_EVERY_N(verbose_level, condition, n)
#define VERBOSE_VLOG_IF_EVERY_N(verbose_level, condition, n) \
  VLOG_IF_EVERY_N(verbose_level, condition, n)

}  // namespace ieda
