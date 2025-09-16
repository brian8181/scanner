/**
 * @brief settings for the Inflex project.
 * @brief settings for the Inflex project.
 */
// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
// * This file is part of the Inflex project.
// * It is subject to the license terms in the LICENSE file found in the top-level directory of this distribution.
// * No part of the Inflex project, including this file, may be copied, modified, or distributed except according to those terms.
// *

#pragma once
#ifndef CYGWIN
#define CYGWIN true
#endif
#ifndef DEBUG
#define DEBUG false
#endif
#ifndef VERSION
#define VERSION "0.1"
#endif
#ifndef BUILD_DATE
#define BUILD_DATE __DATE__
#endif
#ifndef BUILD_TIME
#define BUILD_TIME __TIME__
#endif
#ifndef DEFAULT_TEMPLATE_DIR
#define DEFAULT_TEMPLATE_DIR "/usr/local/share/inflex/templates"
#endif
#ifndef DEFAULT_CONFIG_FILE
#define DEFAULT_CONFIG_FILE "/etc/inflex.conf"
#endif
#ifndef DEFAULT_CACHE_DIR
#define DEFAULT_CACHE_DIR "/var/cache/inflex"
#endif
#ifndef DEFAULT_LOG_FILE
#define DEFAULT_LOG_FILE "/var/log/inflex.log"
#endif
#ifndef DEFAULT_LOG_LEVEL
#define DEFAULT_LOG_LEVEL 3
#endif
#ifndef MAX_INCLUDE_DEPTH
#define MAX_INCLUDE_DEPTH 10
#endif
#ifndef MAX_TEMPLATE_SIZE
#define MAX_TEMPLATE_SIZE 1048576 // 1 MB
#endif
#ifndef MAX_VARIABLES
#define MAX_VARIABLES 1000
#endif
#ifndef MAX_LOOP_ITERATIONS
#define MAX_LOOP_ITERATIONS 1000
#endif
#ifndef MAX_RECURSION_DEPTH
#define MAX_RECURSION_DEPTH 100
#endif
#ifndef CACHE_EXPIRY_TIME
#define CACHE_EXPIRY_TIME 3600 // 1 hour
#endif
#ifndef LOG_LEVEL_DEBUG
#define LOG_LEVEL_DEBUG 4
#endif
#ifndef LOG_LEVEL_INFO
#define LOG_LEVEL_INFO 3
#endif
#ifndef LOG_LEVEL_WARNING
#define LOG_LEVEL_WARNING 2
#endif
#ifndef LOG_LEVEL_ERROR
#define LOG_LEVEL_ERROR 1
#endif
#ifndef LOG_LEVEL_NONE
#define LOG_LEVEL_NONE 0
#endif

