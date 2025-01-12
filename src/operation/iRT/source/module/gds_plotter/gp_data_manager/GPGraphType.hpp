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
#pragma once

#include "Logger.hpp"

namespace irt {

enum class GPGraphType
{
  kNone,
  kOpen,
  kClose,
  kInfo,
  kNeighbor,
  kKey,
  kScaleAxis,
  kPath,
  kBlockage,
  kOtherPanelResult,
  kSelfPanelResult,
  kPanelResult,
  kOtherBoxResult,
  kSelfBoxResult
};

struct GetGPGraphTypeName
{
  std::string operator()(const GPGraphType& data_type) const
  {
    std::string data_type_name;
    switch (data_type) {
      case GPGraphType::kNone:
        data_type_name = "none";
        break;
      case GPGraphType::kOpen:
        data_type_name = "open";
        break;
      case GPGraphType::kClose:
        data_type_name = "close";
        break;
      case GPGraphType::kInfo:
        data_type_name = "info";
        break;
      case GPGraphType::kNeighbor:
        data_type_name = "neighbor";
        break;
      case GPGraphType::kKey:
        data_type_name = "key";
        break;
      case GPGraphType::kScaleAxis:
        data_type_name = "scale_axis";
        break;
      case GPGraphType::kPath:
        data_type_name = "path";
        break;
      case GPGraphType::kBlockage:
        data_type_name = "blockage";
        break;
      case GPGraphType::kOtherPanelResult:
        data_type_name = "other_panel_result";
        break;
      case GPGraphType::kSelfPanelResult:
        data_type_name = "self_panel_result";
        break;
      case GPGraphType::kPanelResult:
        data_type_name = "panel_result";
        break;
      case GPGraphType::kOtherBoxResult:
        data_type_name = "other_box_result";
        break;
      case GPGraphType::kSelfBoxResult:
        data_type_name = "self_box_result";
        break;
      default:
        LOG_INST.error(Loc::current(), "Unrecognized type!");
        break;
    }
    return data_type_name;
  }
};

}  // namespace irt
