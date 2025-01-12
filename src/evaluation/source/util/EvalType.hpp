// ***************************************************************************************
// Copyright (c) 2023-2025 Peng Cheng Laboratory
// Copyright (c) 2023-2025 Institute of Computing Technology, Chinese Academy of Sciences
// Copyright (c) 2023-2025 Beijing Institute of Open Source Chip
//
// iEDA is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
// http://license.coscl.org.cn/MulanPSL2
//
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
//
// See the Mulan PSL v2 for more details.
// ***************************************************************************************
#ifndef SRC_EVALUATOR_SOURCE_UTIL_COMMON_EVALTYPE_HPP_
#define SRC_EVALUATOR_SOURCE_UTIL_COMMON_EVALTYPE_HPP_

namespace eval {
enum class NET_TYPE
{
  kNone,
  kSignal,
  kClock,
  kReset,
  kFakeNet
};

enum class PIN_TYPE
{
  kNone,
  kInstancePort,
  kIOPort,
  kFakePin
};

enum class PIN_IO_TYPE
{
  kNone,
  kInput,
  kOutput,
  kInputOutput
};

enum class INSTANCE_TYPE
{
  kNone,
  kNormal,
  kOutside,
  kFakeInstance
};

}  // namespace eval

#endif  // SRC_EVALUATOR_SOURCE_UTIL_COMMON_EVALTYPE_HPP_
